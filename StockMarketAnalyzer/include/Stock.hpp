#ifndef STOCK_HPP
#define STOCK_HPP

#include <string>

class Stock {
public:
    std::string symbol;
    std::string date;
    double price;

    Stock(std::string symbol, std::string date, double price);
    void display() const;
};

#endif
