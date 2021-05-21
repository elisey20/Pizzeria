#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

class Pizza
{
private:
    string name;
    string description;
    unsigned short size;
    unsigned short salt = 0;
    unsigned short cheese = 0;
    unsigned short priceOnSize;
    unsigned short price = 0;
    Pizza(string name, string description, unsigned short priceOnSize)
    {
        this->name = move(name);
        this->description = move(description);
        this->priceOnSize = priceOnSize;
    }

    unsigned short checkSize(unsigned short size)
    {
        if (!(size >= 25 && size <= 40 && size % 5 == 0))
            throw logic_error("Неверный размер пиццы. Пожалуйста, укажите один из вариантов: 25, 30, 35, 40.");
        return size;
    }

protected:
    Pizza() = default;

public:
    //virtual ~Pizza() = default;

    static const vector<string> pizzas;

    static Pizza createBravo()
    {
        return Pizza(pizzas[0], "Острое блюдо. Соус томатный, бекон домашний, фарш говяжий, лук, перец сладкий, лук, томаты, острый соус, сыр моцарелла.",
                     20);
    }

    static Pizza createVirginia()
    {
        return Pizza(pizzas[1], "Острое блюдо. Соус томатный, острый соус, сыр моцарелла, колбаски охотничьи, перец болгарский, кукуруза, томаты, бекон.",
                     22);
    }

    virtual void chooseSizeOfPizza(unsigned short size)
    {
        this->size = checkSize(size);
        price += size * priceOnSize;
    }

    virtual void addSalt(int amt)
    {
        if (amt < 0 || amt > 100)
            throw logic_error("Количество соли не может быть отрицательным или слишком большим!");
        salt += amt;
    }

    virtual void addCheese(int amt)
    {
        if (amt < 0 || amt > 100)
            throw logic_error("Количество сыра не может быть отрицательным или слишком большим!");
        cheese += amt;
        price += 10 * amt;
    }

    virtual void print()
    {
        cout << name << endl;
        cout << description << endl;
        cout << "соли(" << salt << "), сыра(" << cheese << ')' << endl;
        cout << "размер - " << size << endl;
        cout << "----- Стоимость пиццы = " << price << " -----" << endl;
    }

    int getPrice()
    {
        return price;
    }

    virtual void getListOfPizzas() {};

};

const vector<string> Pizza::pizzas = {"Браво", "Вирджиния"};

class Order : public Pizza
{
private:
    vector<Pizza> order;

public:
    Order() = default;
    //~Order() override = default;

    void print() override
    {
        int finalPrice = 0;
        for (int i = 0; i < order.size(); i++)
        {
            cout << i << "  ";
            order[i].print();

            finalPrice += order[i].getPrice();
        }
        cout << "---------- Итоговая стоимость заказа равна " << finalPrice << " ----------" << endl;
    }

    void getListOfPizzas() override
    {
        for (int i = 0; i < pizzas.size(); i++)
            cout << i + 1 << ": " << pizzas[i] << endl;
    }

    void chooseSizeOfPizza(unsigned short size) override
    {
        if (!order.empty())
            order.back().chooseSizeOfPizza(size);
        else
            throw logic_error("Список заказа пуст!");
    }

    void addToOrder(int num)
    {
        if (num < 1 || num > pizzas.size())
            throw logic_error("Неверная цифра!");

        switch (num)
        {
            case 1:
                order.push_back(Pizza::createBravo());
                break;
            case 2:
                order.push_back(Pizza::createVirginia());
                break;
        }
    }

    void addSalt(int amt) override
    {
        order.back().addSalt(amt);
    }

    void addCheese(int amt) override
    {
        order.back().addCheese(amt);
    }


};