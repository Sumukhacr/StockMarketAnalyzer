#include "../include/Stock.hpp"
#include "../include/StockDataManager.hpp"
#include "../include/Utils.hpp"
#include <iostream>

int main() {
    StockDataManager manager;
    int choice;

    do {
        std::cout << "\n--- Stock Market Analyzer ---\n";
        std::cout << "1. Add Stock Entry\n";
        std::cout << "2. View Stock History\n";
        std::cout << "3. View Top K Stocks\n";
        std::cout << "4. Moving Average\n";
        std::cout << "5. Load From CSV\n";
        std::cout << "6. Export Stock Data\n";
        std::cout << "7. View ASCII Chart\n";
        std::cout << "8. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string symbol, date;
            double price;
            std::cout << "Enter symbol, date (YYYY-MM-DD), price: ";
            std::cin >> symbol >> date >> price;
            manager.addStock(Stock(symbol, date, price));
        } else if (choice == 2) {
            std::string symbol;
            std::cout << "Enter symbol: ";
            std::cin >> symbol;
            manager.displayStockHistory(symbol);
        } else if (choice == 3) {
            int k;
            std::cout << "Enter K: ";
            std::cin >> k;
            manager.displayTopK(k);
        } else if (choice == 4) {
            std::string symbol;
            int days;
            std::cout << "Enter symbol and window size: ";
            std::cin >> symbol >> days;
            manager.movingAverage(symbol, days);
        } else if (choice == 5) {
            std::string path;
            std::cout << "Enter CSV file path: ";
            std::cin >> path;
            manager.loadFromCSV(path);
        } else if (choice == 6) {
            std::string symbol, filename;
            std::cout << "Enter symbol and output filename: ";
            std::cin >> symbol >> filename;
            manager.exportStockData(symbol, filename);
        } else if (choice == 7) {
            std::string symbol;
            std::cout << "Enter symbol: ";
            std::cin >> symbol;
            manager.plotStockChart(symbol);
        }
    } while (choice != 8);

    return 0;
}
