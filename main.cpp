#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Stock struct to hold stock data
struct Stock {
    string symbol;
    string date; // Format: YYYY-MM-DD
    double price;

    Stock(const string& sym, const string& dt, double pr)
        : symbol(sym), date(dt), price(pr) {}
};

// StockManager class to manage stock data and operations
class StockManager {
private:
    vector<Stock> stocks;

public:
    // Add a new stock entry
    void addStock(const string& symbol, const string& date, double price) {
        stocks.emplace_back(symbol, date, price);
        cout << "Added stock: " << symbol << " on " << date << " at $" 
             << fixed << setprecision(2) << price << endl;
    }

    // View history of a specific stock by symbol
    void viewStockHistory(const string& symbol) const {
        cout << "\nStock History for " << symbol << ":\n";
        cout << "--------------------------------\n";
        bool found = false;
        for (const auto& stock : stocks) {
            if (stock.symbol == symbol) {
                cout << "Date: " << stock.date << ", Price: $" 
                     << fixed << setprecision(2) << stock.price << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No history found for " << symbol << endl;
        }
    }

    // Display top K stocks by price
    void displayTopKStocks(int k) const {
        if (stocks.empty()) {
            cout << "No stocks available.\n";
            return;
        }

        vector<Stock> sortedStocks = stocks;
        sort(sortedStocks.begin(), sortedStocks.end(), 
             [](const Stock& a, const Stock& b) { return a.price > b.price; });

        cout << "\nTop " << k << " Stocks by Price:\n";
        cout << "--------------------------------\n";
        for (int i = 0; i < min(k, (int)sortedStocks.size()); ++i) {
            cout << i + 1 << ". " << sortedStocks[i].symbol 
                 << " on " << sortedStocks[i].date 
                 << ": $" << fixed << setprecision(2) << sortedStocks[i].price << endl;
        }
    }

    // Calculate N-day moving average for a specific stock
    double calculateMovingAverage(const string& symbol, int n) const {
        vector<double> prices;
        for (const auto& stock : stocks) {
            if (stock.symbol == symbol) {
                prices.push_back(stock.price);
            }
        }

        if (prices.size() < n || n <= 0) {
            cout << "Not enough data or invalid N for " << symbol << endl;
            return 0.0;
        }

        double sum = 0.0;
        for (int i = prices.size() - n; i < prices.size(); ++i) {
            sum += prices[i];
        }
        double average = sum / n;
        cout << n << "-day moving average for " << symbol << ": $" 
             << fixed << setprecision(2) << average << endl;
        return average;
    }
};

// Display the menu for user interaction
void displayMenu() {
    cout << "\nStock Market Analyzer\n";
    cout << "1. Add Stock\n";
    cout << "2. View Stock History\n";
    cout << "3. Display Top K Stocks\n";
    cout << "4. Calculate N-Day Moving Average\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

// Main function with menu-driven interface
int main() {
    StockManager manager;
    int choice;
    string symbol, date;
    double price;
    int k, n;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case 1: // Add Stock
                cout << "Enter symbol: ";
                getline(cin, symbol);
                cout << "Enter date (YYYY-MM-DD): ";
                getline(cin, date);
                cout << "Enter price: ";
                cin >> price;
                manager.addStock(symbol, date, price);
                break;

            case 2: // View Stock History
                cout << "Enter symbol: ";
                getline(cin, symbol);
                manager.viewStockHistory(symbol);
                break;

            case 3: // Display Top K Stocks
                cout << "Enter K: ";
                cin >> k;
                manager.displayTopKStocks(k);
                break;

            case 4: // Calculate N-Day Moving Average
                cout << "Enter symbol: ";
                cin.ignore();
                getline(cin, symbol);
                cout << "Enter N: ";
                cin >> n;
                manager.calculateMovingAverage(symbol, n);
                break;

            case 5: // Exit
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
