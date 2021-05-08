#include <iostream>

#include "Pizzeria.h"

using namespace std;

void makeOrder()
{
    Order order;

    cout << "Пожалуйста, выберете пиццу(1-" << Pizza::pizzas.size() << "):" << endl;
    order.getListOfPizzas();

    int selectionNumber;
    cin >> selectionNumber;
    //добавить try catch
    order.addToOrder(selectionNumber);

    bool flag;
    do
    {
        try
        {
            cout << "Укажите размер пиццы(25, 30, 35, 40):" << endl;
            cin >> selectionNumber;
            order.chooseSizeOfPizza(selectionNumber);
            flag = false;
        }
        catch (logic_error& error)
        {
            cout << error.what() << endl;
            flag = true;
        }
    } while (flag);
}

int main()
{
    makeOrder();

    return 0;
}
