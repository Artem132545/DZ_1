#include "DataSetRegister.h"

void AddTestsByShafikov(std::stack<DataSet>& tests)
{

    tests.push({"Shafikov_1", 1, 30,
        {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}});

    tests.push({"Shafikov_2", 100, 200,
        {101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
         157, 163, 167, 173, 179, 181, 191, 193, 197, 199}});

    tests.push({"Shafikov_3", 2147483600, 2147483647,
        {2147483629, 2147483647}});
}
