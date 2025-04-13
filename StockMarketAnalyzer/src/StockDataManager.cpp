#include "../include/StockDataManager.hpp"
#include "../include/Utils.hpp"
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

void StockDataManager::addStock(const Stock& stock) {
    stockMap[stock.symbol].push_back(stock);
}

void StockDataManager::displayStockHistory(const std::string& symbol) {
    if (stockMap.find(symbol) == stockMap.end()) {
        std::cout << "Stock not found.\n";
        return;
    }

    for (const auto& s : stockMap[symbol]) {
        s.display();
    }
}

void StockDataManager::displayTopK(int k) {
    std::priority_queue<std::pair<double, Stock>> maxHeap;

    for (auto& [symbol, stocks] : stockMap) {
        for (const auto& stock : stocks) {
            maxHeap.push({stock.price, stock});
        }
    }

    std::cout << "Top " << k << " Stocks by Price:\n";
    for (int i = 0; i < k && !maxHeap.empty(); ++i) {
        auto [price, stock] = maxHeap.top();
        maxHeap.pop();
        stock.display();
    }
}

void StockDataManager::movingAverage(const std::string& symbol, int days) {
    if (stockMap.find(symbol) == stockMap.end()) {
        std::cout << "Stock not found.\n";
        return;
    }

    const auto& stocks = stockMap[symbol];
    if (stocks.size() < days) {
        std::cout << "Not enough data points.\n";
        return;
    }

    std::queue<double> window;
    double sum = 0;

    std::cout << "Moving average (" << days << "-day):\n";

    for (size_t i = 0; i < stocks.size(); ++i) {
        sum += stocks[i].price;
        window.push(stocks[i].price);

        if (window.size() > days) {
            sum -= window.front();
            window.pop();
        }

        if (window.size() == days) {
            std::cout << stocks[i].date << " -> " << (sum / days) << "\n";
        }
    }
}

void StockDataManager::loadFromCSV(const std::string& path) {
    auto stocks = Utils::loadStockDataFromCSV(path);
    for (const auto& stock : stocks) {
        addStock(stock);
    }
}

void StockDataManager::exportStockData(const std::string& symbol, const std::string& filename) {
    if (stockMap.find(symbol) == stockMap.end()) {
        std::cout << "Stock not found.\n";
        return;
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }

    file << "Date,Price\n";
    for (const auto& s : stockMap[symbol]) {
        file << s.date << "," << s.price << "\n";
    }

    file.close();
    std::cout << "Exported stock data to " << filename << "\n";
}

void StockDataManager::plotStockChart(const std::string& symbol) {
    if (stockMap.find(symbol) == stockMap.end()) {
        std::cout << "Stock not found.\n";
        return;
    }

    const auto& data = stockMap[symbol];

    std::cout << "\nASCII Chart for " << symbol << ":\n";
    for (const auto& s : data) {
        int barLength = static_cast<int>(s.price / 2);
        std::cout << s.date << " | " << std::string(barLength, '*') << " (" << s.price << ")\n";
    }
}
