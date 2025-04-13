# StockMarketAnalyzer

A simple C++ console application for analyzing stock market data, implemented in a single `main.cpp` file. Built with Code::Blocks on Windows using only the C++ Standard Template Library (STL), this project showcases data structures and algorithms skills for beginners.

## Features

- **Stock Data**: Store symbol, date (YYYY-MM-DD), and price in a `Stock` struct.
- **Stock Management**: Use a `StockManager` class to:
  - Add new stock entries.
  - View price history by symbol.
  - Display top K stocks by price.
  - Calculate N-day moving average for a stock.
- **Interface**: Interactive console menu.
- **Tech**: Uses `std::vector` for storage and `std::sort` for ranking stocks.
