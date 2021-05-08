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
    unsigned short price;
    Pizza(string name, string description, unsigned short priceOnSize)
    {
        this->name = move(name);
        this->description = move(description);
        this->size = size;
        this->priceOnSize = priceOnSize;
    }

    unsigned short checkSize(unsigned short size)
    {
        if (!(size >= 25 && size <= 40 && size % 5 == 0))
            throw logic_error("Неверный размер пиццы. Пожалуйста, укажите один из вариантов: 25, 30, 35, 40.");
        return priceOnSize * size;
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
                     20);
    }

    virtual void chooseSizeOfPizza(unsigned short size)
    {
        this->size = checkSize(size);
    }

    virtual void addSalt(unsigned short amt)
    {
        salt += amt;
    }

    virtual void addCheese(unsigned short amt)
    {
        cheese += amt;
        price += 20 * amt;
    }

    virtual void print()
    {

    }

    virtual void getListOfPizzas() {};

};

const vector<string> Pizza::pizzas = {"Браво", "Вирджиния"};

class Order : public Pizza
{
private:
    vector<Pizza> order;

    void addSalt(unsigned short amt) override {}
    void addCheese(unsigned short amt) override {}

public:
    Order() = default;
    //~Order() override = default;

    void print() override
    {
        for (auto & pizza : order)
            pizza.print();
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
        if (num < 0 || num > pizzas.size())
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

};