#include "DataSetRegister.h"
#include <stack>

using namespace std;

void AddTestsByKryukova(stack<DataSet>& tests)
{
    tests.push({ "Kryukova_favorable", -5, 127,
        {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
         31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
         73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127} });

    tests.push({ "Kryukova_typical", 210, 251,
        {211, 223, 227, 229, 233, 239, 241, 251} });

    tests.push({ "Kryukova_unfavorable", 1000000, 1000040,
        {1000003, 1000033, 1000037, 1000039} });
}