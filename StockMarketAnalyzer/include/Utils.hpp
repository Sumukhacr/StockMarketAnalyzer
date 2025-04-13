#ifndef UTILS_HPP
#define UTILS_HPP

#include "Stock.hpp"
#include <string>
#include <vector>

namespace Utils {
    std::vector<Stock> loadStockDataFromCSV(const std::string& filepath);
}

#endif
