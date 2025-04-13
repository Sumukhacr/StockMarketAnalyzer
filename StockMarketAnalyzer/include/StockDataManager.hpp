#ifndef STOCK_DATA_MANAGER_HPP
#define STOCK_DATA_MANAGER_HPP

#include "Stock.hpp"
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

class StockDataManager {
private:
    std::unordered_map<std::string, std::vector<Stock>> stockMap;

public:
    void addStock(const Stock& stock);
    void displayStockHistory(const std::string& symbol);
    void displayTopK(int k);
    void movingAverage(const std::string& symbol, int days);
    void loadFromCSV(const std::string& path);
    void exportStockData(const std::string& symbol, const std::string& filename);
    void plotStockChart(const std::string& symbol);
};

#endif
