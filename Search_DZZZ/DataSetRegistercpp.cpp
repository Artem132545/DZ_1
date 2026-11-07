
#include "DataSetRegister.h"

std::stack<DataSet> GenerateDataSets()
{
    std::stack<DataSet> tests;

    tests.push({ "Range 100", 1, 100,
        {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
         31, 37, 41, 43, 47, 53, 59, 61, 67,
         71, 73, 79, 83, 89, 97} });

    tests.push({ "Range 50", 1, 50,
        {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
         31, 37, 41, 43, 47} });

    tests.push({ "Invalid range", 20, 10, {} });
    tests.push({ "No primes", 14, 16, {} });
    tests.push({ "Negative range", -5, 10, {2, 3, 5, 7} });
    tests.push({ "Small range", 10, 20, {11, 13, 17, 19} });
    tests.push({ "Single prime", 2, 2, {2} });
    tests.push({ "Composite", 4, 4, {} });
    tests.push({ "Zero and one", 0, 1, {} });

    //AddTestsByShafikov(tests);
    //AddTestsByKryukova(tests);
    //AddTestsByDavaasuren(tests);          после того как участники сделают свои тесты в отдельном cpp
    //AddTestsByDrach(tests);
    //AddTestsByMilovanov(tests);
    //AddTestsByKorolev(tests);

    return tests;
}
