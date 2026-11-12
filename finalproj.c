#include <stdio.h>
#include <stdbool.h>

int addToOrder();
int editOrder();
int completeOrder();
int printBill();

    const float TAX_RATE = 1.0725;

    const float FOOD1_INDEX = 0;
    const float FOOD2_INDEX = 1;
    const float FOOD3_INDEX = 2;
    //...

    const float DRINK1_INDEX = 0;
    const float DRINK2_INDEX = 1;
    const float DRINK3_INDEX = 2;
    //...

    //                         f1    f2    f3    f4    f5    f6    f7    f8    f9   f10
    int foodCosts[10]      = {0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
    int foodQuantities[10] = {0};

    //                         d1    d2    d3    d4    d5
    int drinkCosts[5]      = {0.00, 0.00, 0.00, 0.00, 0.00};
    int drinkQuantities[5] = {0};

int main(void)
{
    bool systemActive = true;
    int userInput = 0;

    printf("Welcome to ___ Restaurant!\n");

    while(systemActive)
    {
        printf("What would you like to do?\n");
        printf("1) Add to Order\n2) Edit Order\n3) Complete Order\n0) Exit\n\n");
        scanf("%d", &userInput);

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
    }
    return 0;
}


int addToOrder()
{
    // TODO
    // Should prompt user for..
    //    1) Add Food or Drink?
    //    2) Which Food/Drink? (list available options + prices)
    //    3) How many of selected Food/Drink?
    //    4) Add another item?
}


int editOrder()
{
    // TODO
    // Let user either..
    //    1) Edit quantity of an item
    //        a) Item to modify
    //        b) New quantity
    //    2) Remove an item
    //        a) Item to remove
    //        b) Confirm y/n
}


int completeOrder()
{
    // TODO
    // Call printBill() to display user's current order
    // Prompt to Complete Order y/n
    // Prompt to make another order or exit
}


int printBill()
{
    // TODO
    // Print out the user's current order
    // Should include:
    //    1) Food/Drink Name
    //    2) Quantity of Item
    //    3) Price of Item(s)
    //    4) Subtotal
    //    5) Tax
    //    6) Total (Subtotal + Tax)
}
