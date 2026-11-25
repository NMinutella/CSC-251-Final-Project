#include <stdio.h>
#include <stdbool.h>

void addToOrder();
void editOrder();
void completeOrder();
void printBill();
void checkScanBuffer();

const float TAX_RATE = 1.0725;

const char *FOOD_NAMES[10] = { "Burger", "Cheeseburger", "Hot Dog", "Burrito", "Chicken Tenders", "Pizza", "Salad", "Fries", "Onion Rings", "Mac & Cheese" };
const int FOOD_COUNT = 10;
//                        f1    f2    f3    f4    f5    f6    f7    f8    f9   f10
float FOOD_PRICES[10] = {7.49, 7.99, 6.99, 8.99, 6.49, 10.99, 5.99, 3.99, 5.49, 5.99};
int foodQuantities[10] = {0};

const char *DRINK_NAMES[5] = { "Water", "Soda", "Lemonade", "Iced Tea", "Smoothie" };
const int DRINK_COUNT = 5;
//                        d1    d2    d3    d4    d5
float DRINK_PRICES[5] = {0.00, 2.99, 3.99, 3.99, 5.99};
int drinkQuantities[5] = {0};

int gScanVal = 0;

int main(void)
{
    bool systemActive = true;
    int userInput;

    printf("Welcome!");

    while(systemActive)
    {
        userInput = -1;

        printf("\nWhat would you like to do?\n");
        printf("1) Add to Order\n2) Edit Order\n3) Complete Order\n0) Exit\n\n");
        gScanVal = scanf("%d", &userInput);

        switch(userInput)
        {
            case 1:
                addToOrder();
                break;
            case 2:
                editOrder();
                break;
            case 3:
                completeOrder();
                break;
            case 0:
                printf("Have a nice day!\n");
                systemActive = false;
                break;
            default:
                printf("Error: Invalid Input! Please Try Again\n\n");
                break;
        }

        checkScanBuffer();
    }
    return 0;
}


void addToOrder()
{
    int choice, item, quantity = 0;
    int addingItem = 1;

    while (addingItem)
    {
        checkScanBuffer();

        printf("\nWould you like Food or Drink?\n");
        printf("1) Food\n");
        printf("2) Drink\n");
        printf("0) Exit\n\n");
        printf("Enter choice: ");
        gScanVal = scanf("%d", &choice);

        if (choice == 0)
        {
            return;
        }

        if (choice == 1)
        {
            printf("\n--- Food Menu ---\n");
            for(int i = 0; i < FOOD_COUNT; i++)
            {
                printf("%2d) %-15s - $%.2f\n", i+1, FOOD_NAMES[i], FOOD_PRICES[i]);
            }

            printf("Choose a food item: ");
            gScanVal = scanf("%d", &item);

            if (item < 1 || item > FOOD_COUNT)
            {
                printf("Invalid food choice!\n");
                continue;
            }

            printf("How many would you like? ");
            gScanVal = scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Invalid quantity!\n");
                continue;
            }

            foodQuantities[item-1] += quantity;

            printf("Food added to order!\n");
        }
        else if (choice == 2)
        {
            printf("\n--- Drink Menu ---\n");
            for(int i = 0; i < DRINK_COUNT; i++)
            {
                printf("%2d) %-8s - $%.2f\n", i+1, DRINK_NAMES[i], DRINK_PRICES[i]);
            }

            printf("Choose a drink: ");
            gScanVal = scanf("%d", &item);

            if (item < 1 || item > DRINK_COUNT)
            {
                printf("Invalid drink choice!\n");
                continue;
            }

            printf("How many would you like? ");
            gScanVal = scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Invalid quantity!\n");
                continue;
            }

            drinkQuantities[item-1] += quantity;

            printf("Drink added to order!\n");
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        addingItem = 0;
        printf("\nWould you like to add another item?\n1) Yes\n0) No\n\n");
        gScanVal = scanf("%d", &addingItem);

        checkScanBuffer();
    }

    printf("\nReturning to main menu...\n");
}


bool editItems(const char *itemType, const char *itemNames[], float itemPrices[], int itemQuantities[], int itemCount)
{
    int optCount = 0;

    for (int i = 0; i < itemCount; ++i)
    {
        if (itemQuantities[i] == 0) continue;
        ++optCount;
        break;
    }

    if (optCount == 0)
    {
        printf("\nThere are no %ss in your order.\n", itemType);
        return false;
    }

    printf("\nEdit quantity of %s\n", itemType);

    optCount = 0;
    printf("     Item           Quantity   Total Price\n");

    for (int i = 0; i < itemCount; ++i)
    {
        if (itemQuantities[i] == 0)
            continue;
        printf("%d) %-15s    %3d        $%.2f\n", ++optCount, itemNames[i], itemQuantities[i], itemQuantities[i] * itemPrices[i]);
    }

    printf("0) Exit\n\n");
    int opt;
    gScanVal = scanf("%d", &opt);

    if (opt == 0)
        return false;

    int itemIdx = -1;
    optCount = 0;

    for (int i = 0; i < itemCount; ++i)
    {
        if (itemQuantities[i] == 0)
            continue;
        if (opt == ++optCount)
        {
            itemIdx = i;
            break;
        }
    }

    if (itemIdx == -1)
    {
        printf("\nUnknown option, please choose from listed choices!\n");
    }
    else
    {
        printf("\nEnter new quantity of %s: ", itemNames[itemIdx]);
        int newQuantity = -1;
        gScanVal = scanf("%d", &newQuantity);
        if (newQuantity >= 0)
        {
            itemQuantities[itemIdx] = newQuantity;
        }
        else
        {
            printf("\nFailed to set quantity!\n");
        }
    }

    checkScanBuffer();

    return true;
}

void editOrder()
{
    while(true)
    {
        printf("\nWould you like to edit amount of food or drinks?\n1) Food\n2) Drinks\n0) Exit\n\n");
        int opt = 0;
        gScanVal = scanf("%d", &opt);

        switch (opt)
        {
            case 0:
                return;
            case 1:
                while (editItems("Food", FOOD_NAMES, FOOD_PRICES, foodQuantities, FOOD_COUNT));
                break;
            case 2:
                while (editItems("Drink", DRINK_NAMES, DRINK_PRICES, drinkQuantities, DRINK_COUNT));
                break;
            default:
                printf("Unknown option, please choose from listed choices!\n");
                break;
        }

        checkScanBuffer();
    }
}


// Returns true if the order has at least one item in it
bool orderHasItems()
{
    for (int i = 0; i < FOOD_COUNT; i++)
    {
        if (foodQuantities[i] > 0)
            return true;
    }

    for (int i = 0; i < DRINK_COUNT; i++)
    {
        if (drinkQuantities[i] > 0)
            return true;
    }

    return false;
}


void completeOrder()
{
    if (!orderHasItems())
    {
        printf("\nYour order is empty! Please add some items first.\n");
        return;
    }

    printBill();

    printf("\nWould you like to complete this order?\n1) Yes\n0) No\n\n");
    int confirm = -1;
    gScanVal = scanf("%d", &confirm);

    if (confirm != 1)
    {
        printf("\nReturning to main menu...\n");
        return;
    }

    printf("\nOrder complete! Thank you!\n");

    // Clear the order so the next one starts fresh
    for (int i = 0; i < FOOD_COUNT; i++)
        foodQuantities[i] = 0;

    for (int i = 0; i < DRINK_COUNT; i++)
        drinkQuantities[i] = 0;

    printf("You can start a new order from the main menu, or press 0 to exit.\n");
}


// Prints every item with quantity > 0 and returns the section's total
float printItems(const char *names[], float prices[], int quantities[], int count)
{
    float sectionTotal = 0;

    for (int i = 0; i < count; i++)
    {
        if (quantities[i] == 0)
            continue;

        float lineTotal = quantities[i] * prices[i];
        printf("%-15s    %3d        $%6.2f\n", names[i], quantities[i], lineTotal);
        sectionTotal += lineTotal;
    }

    return sectionTotal;
}


void printBill()
{
    float subtotal = 0;

    printf("\n=============== YOUR BILL ===============\n");
    printf("Item           Quantity     Price\n");
    printf("-----------------------------------------\n");

    subtotal += printItems(FOOD_NAMES, FOOD_PRICES, foodQuantities, FOOD_COUNT);
    subtotal += printItems(DRINK_NAMES, DRINK_PRICES, drinkQuantities, DRINK_COUNT);

    float tax = subtotal * (TAX_RATE - 1);
    float total = subtotal + tax;

    printf("-----------------------------------------\n");
    printf("Subtotal:                    $%6.2f\n", subtotal);
    printf("Tax (7.25%%):                 $%6.2f\n", tax);
    printf("Total:                       $%6.2f\n", total);
    printf("=========================================\n");
}


// Check to prevent infinite loops occuring from invalid char inputs
void checkScanBuffer()
{
    if(gScanVal != 1)
    {
        char dummyChar[50];
        gScanVal = scanf("%s", dummyChar);
    }
}
