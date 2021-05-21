#include <iostream>

#include "Pizzeria.h"

using namespace std;

void makeOrder()
{
    Order order;

    bool flag = true;
    do
    {
        order.getListOfPizzas();
        do
        {
            try
            {
                int selectionNumber;
                cout << "Пожалуйста, выберите пиццу(1-" << Pizza::pizzas.size() << "): ";
                cin >> selectionNumber;
                //добавить try catch
                order.addToOrder(selectionNumber);
                flag = false;
            }
            catch (logic_error& error)
            {
                cout << error.what() << endl;
            }
        } while (flag);

        do
        {
            try
            {
                int selectionNumber;
                cout << "Укажите размер пиццы(25, 30, 35, 40): ";
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

        do
        {
            try
            {
                int amt;
                cout << "Укажите, сколько соли добавить в пиццу: ";
                cin >> amt;
                order.addSalt(amt);
                flag = false;
            }
            catch (logic_error& error)
            {
                cout << error.what() << endl;
                flag = true;
            }
        } while (flag);

        do
        {
            try
            {
                int amt;
                cout << "Укажите, сколько сыра добавить в пиццу: ";
                cin >> amt;
                order.addCheese(amt);
                flag = false;
            }
            catch (logic_error& error)
            {
                cout << error.what() << endl;
                flag = true;
            }
        } while (flag);

        string message;
        cout << "Хотите заказать ещё пиццу?(y/n): ";
        cin >> message;
        if (message == "y")
            flag = true;
        else
            flag = false;
    } while (flag);

    order.print();
}

int main()
{
    makeOrder();

    return 0;
}
