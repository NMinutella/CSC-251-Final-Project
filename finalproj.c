#include <stdio.h>
#include <stdbool.h>

int addToOrder();
int editOrder();
int completeOrder();
int printBill();

    const float TAX_RATE = 1.0725;

    const float FOOD1_COST = 0.00;
    const float FOOD2_COST = 0.00;
    const float FOOD3_COST = 0.00;
    // ...

    const float DRINK1_COST = 0.00;
    const float DRINK2_COST = 0.00;
    const float DRINK3_COST = 0.00;
    // ...

    int food1Count, food2Count, food3Count = 0;
    int drink1Count, drink2Count, drink3Count = 0;

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
