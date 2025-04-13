#include "../include/Stock.hpp"
#include <iostream>

Stock::Stock(std::string symbol, std::string date, double price)
    : symbol(symbol), date(date), price(price) {}

void Stock::display() const {
    std::cout << symbol << " | " << date << " | $" << price << std::endl;
}
