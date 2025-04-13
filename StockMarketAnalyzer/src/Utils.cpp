#include "../include/Utils.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Stock> Utils::loadStockDataFromCSV(const std::string& filepath) {
    std::ifstream file(filepath);
    std::vector<Stock> stocks;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath << "\n";
        return stocks;
    }

    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string symbol, date, priceStr;
        double price;

        std::getline(ss, symbol, ',');
        std::getline(ss, date, ',');
        std::getline(ss, priceStr, ',');

        try {
            price = std::stod(priceStr);
            stocks.emplace_back(symbol, date, price);
        } catch (...) {
            std::cerr << "Skipping invalid line: " << line << "\n";
        }
    }

    return stocks;
}
