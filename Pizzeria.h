#pragma once

#include <string>
#include <vector>
#include <exception>

using namespace std;

class Order;

class Pizza
{
private:
    string name;
    string description;
    unsigned short size;
    unsigned short salt = 0;
    unsigned short cheese = 0;
    unsigned short price;
    Pizza(string name, string description, unsigned short size, unsigned short price)
    {
        this->name = move(name);
        this->description = move(description);
        this->size = size;
        this->price = price;
    }

    static unsigned short checkSize(unsigned short size, unsigned short priceOnSize)
    {
        if (!(size >= 25 && size <= 40 && size % 5 == 0))
            throw logic_error("Неверный размер пиццы. Пожалуйста, укажите один из вариантов: 25, 30, 35, 40.");
        return priceOnSize * size;
    }

public:
    static Pizza createBravo(unsigned short size)
    {
        unsigned short price = checkSize(size, 20);
        return Pizza("Браво", "Острое блюдо. Соус томатный, бекон домашний, фарш говяжий, лук, перец сладкий, лук, томаты, острый соус, сыр моцарелла.", size, price);
    }

    static Pizza createVirginia(unsigned short size)
    {
        unsigned short price = checkSize(size, 20);
        return Pizza("Вирджиния", "Острое блюдо. Соус томатный, острый соус, сыр моцарелла, колбаски охотничьи, перец болгарский, кукуруза, томаты, бекон.", size, price);
    }

    void addSalt(unsigned short amt)
    {
        salt += amt;
    }

    void addCheese(unsigned short amt)
    {
        cheese += amt;
        price += 20 * amt;
    }

};

class Order : public Pizza
{
private:
    vector<Pizza> order;

public:


};