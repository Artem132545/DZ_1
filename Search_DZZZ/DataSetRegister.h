#pragma once

#include <stack>
#include <string>
#include <vector>

struct DataSet
{
    std::string description;
    int left;
    int right;
    std::vector<int> expected;
};

std::stack<DataSet> GenerateDataSets();
//void AddTestsByShafikov(std::stack<DataSet>& tests);
//void AddTestsByKryukova(std::stack<DataSet>& tests);
//void AddTestsByDavaasuren(std::stack<DataSet>& tests);
//void AddTestsByDrach(std::stack<DataSet>& tests);             объявления тестов
//void AddTestsByMilovanov(std::stack<DataSet>& tests);
//void AddTestsByKorolev(std::stack<DataSet>& tests);