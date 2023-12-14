#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

class NumberProcessor
{
public:
    static void RemoveNegativeNumbers(std::vector<double> &numbers)
    {
        auto new_end = std::remove_if(numbers.begin(), numbers.end(), [](double n)
                                      { return n < 0; });
        numbers.erase(new_end, numbers.end());
    }

    static void PrintEvenOrOdd(const std::vector<double> &numbers)
    {
        for (const auto &n : numbers)
        {
            std::cout << n << " is " << (static_cast<int>(n) % 2 == 0 ? "even" : "oneven") << std::endl;
        }
    }

    static void CalculateStatistics(const std::vector<double> &numbers,
                                    double &sum, double &avg, double &product)
    {
        sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
        avg = numbers.empty() ? 0 : sum / numbers.size();
        product = std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());
    }
};
