#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

class StringProcessor
{
public:
    static void SplitBeforeAndAfterPurple(const std::vector<std::string> &colours,
                                          std::vector<std::string> &beforePurple,
                                          std::vector<std::string> &afterPurple)
    {
        std::partition_copy(colours.begin(), colours.end(),
                            std::back_inserter(beforePurple),
                            std::back_inserter(afterPurple),
                            [](const std::string &s)
                            { return s < "purple"; });
    }

    static void ConvertToUppercase(std::vector<std::string> &colours)
    {
        std::transform(colours.begin(), colours.end(), colours.begin(),
                       [](std::string &s)
                       {
                           std::transform(s.begin(), s.end(), s.begin(), ::toupper);
                           return s;
                       });
    }

    static void RemoveDuplicates(std::vector<std::string> &colours)
    {
        std::sort(colours.begin(), colours.end());
        auto last = std::unique(colours.begin(), colours.end());
        colours.erase(last, colours.end());
    }
};
