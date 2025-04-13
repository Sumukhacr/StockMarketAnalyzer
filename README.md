
```mark
# Stock Market Analyzer

A C++ project that showcases core Data Structures and Algorithms (DSA) concepts by analyzing stock market data.

## Features
- Add and store stock data using hash maps and vectors
- View historical stock data
- Display top-K stocks by price using a max heap
- Calculate moving averages with a sliding window queue
- Load stock data from CSV files
- Export stock data to CSV
- Plot ASCII-based stock price charts

## Technologies Used
- **C++17**
- **Standard Template Library (STL)**
- Data Structures: `unordered_map`, `vector`, `priority_queue`, `queue`
- Algorithms: Sorting, Searching, Sliding Window

## Project Structure
```
StockMarketAnalyzer/
│
├── include/                  # Header files
│   ├── Stock.hpp
│   ├── StockDataManager.hpp
│   └── Utils.hpp
│
├── src/                      # Source code
│   ├── Stock.cpp
│   ├── StockDataManager.cpp
│   ├── Utils.cpp
│   └── main.cpp
│
├── data/
│   └── sample_stock_data.csv
│
├── Makefile                  # Build configuration
└── README.md                 # Project documentation
```

## How to Run
1. **Build the Project**
   ```bash
   make
   ```

2. **Run the Executable**
   ```bash
   ./main
   ```

3. **Follow the Menu to Use the App**

## Sample CSV Format
```
Symbol,Date,Price
AAPL,2024-03-01,180.5
AAPL,2024-03-02,182.0
MSFT,2024-03-01,299.2
```

## DSA Concepts in Action
| Feature                  | Data Structure Used     |
|--------------------------|--------------------------|
| Store stock records      | `unordered_map<string, vector<Stock>>` |
| Top-K stock analysis     | `priority_queue` (max heap) |
| Moving average           | `queue` (sliding window) |
| CSV loading              | File I/O and `stringstream` |
| Chart visualization      | ASCII representation     |


```

---

