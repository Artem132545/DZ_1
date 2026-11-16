#include "Participants.h"
#include <cstddef>
#include <vector>

using namespace std;

vector<int> findPrimesEratosthenes(int left, int right)
{
    vector<int> primes;

    if (left > right || right < 2)
        return primes;
    if (left <= 2)
        primes.push_back(2);

    vector<bool> composite(static_cast<size_t>(right / 2) + 1, false);

    for (long long p = 3; p * p <= right; p += 2)
    {
        if (composite[p / 2])
            continue;
        for (long long j = p * p; j <= right; j += 2 * p)
            composite[j / 2] = true;
    }

    long long n = left < 3 ? 3 : left;

    if (n % 2 == 0)
        ++n;
    for (; n <= right; n += 2)
    {
        if (!composite[n / 2])
            primes.push_back(static_cast<int>(n));
    }

    return primes;
}