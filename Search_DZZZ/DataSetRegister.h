#pragma once

#include <stack>
#include <string>

struct DataSet
{
    std::string description;
    int left;
    int right;
};

inline std::stack<DataSet> GenerateDataSets()
{
    std::stack<DataSet> tests;

    tests.push({ "Large range", 1, 100000 });
    tests.push({ "Range 10000", 1, 10000 });
    tests.push({ "Range 1000", 1, 1000 });
    tests.push({ "Range 100", 1, 100 });
    tests.push({ "Invalid range", 20, 10 });
    tests.push({ "No primes", 14, 16 });
    tests.push({ "Negative range", -5, 10 });
    tests.push({ "Small range", 10, 20 });
    tests.push({ "Single prime", 2, 2 });
    tests.push({ "Zero and one", 0, 1 });

    return tests;
}
