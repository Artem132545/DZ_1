#include "DataSetRegister.h"
#include <stack>

void AddTestsByKorolev(std::stack<DataSet>& tests)
{
    // Favorable: 64 consecutive composite integers.
    // Each odd candidate fails the very first base (2).
    tests.push({"Korolev_1", 25325864, 25325927, {}});

    // Typical: 64 integers with a mix of even / odd composites and primes.
    // The reference list was generated independently by trial division.
    tests.push({"Korolev_2", 25325200, 25325263,
        {25325227, 25325239, 25325243}});

    // Unfavorable: three primes and the composite 25326001,
    // which passes bases 2, 3, 5 and fails only at base 7.
    tests.push({"Korolev_3", 25325966, 25326029,
        {25325969, 25325981, 25326023}});
}
