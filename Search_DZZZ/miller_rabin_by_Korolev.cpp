#include "Participants.h"
#include <cstdint>
#include <vector>

namespace
{
    using u64 = std::uint64_t;

    // Binary modular exponentiation. All residues are less than n.
    // For a positive 32-bit int, their product fits in uint64_t.
    u64 powMod(u64 a, u64 d, u64 n)
    {
        u64 result = 1;
        a %= n;

        while (d > 0)
        {
            if (d % 2 == 1)
                result = (result * a) % n;

            a = (a * a) % n;
            d /= 2;
        }
        return result;
    }

    // True means that n passes the test for this base.
    bool checkBase(u64 n, u64 a, u64 d, int s)
    {
        u64 x = powMod(a, d, n);

        if (x == 1 || x == n - 1)
            return true;

        for (int r = 1; r < s; ++r)
        {
            x = (x * x) % n;

            if (x == n - 1)
                return true;
            if (x == 1)
                return false;
        }
        return false;
    }

    bool isPrime(int value)
    {
        if (value < 2)
            return false;
        if (value % 2 == 0)
            return value == 2;

        const u64 n = static_cast<u64>(value);
        u64 d = n - 1;
        int s = 0;

        // n - 1 = d * 2^s, with d odd.
        while (d % 2 == 0)
        {
            d /= 2;
            ++s;
        }

        // These four bases suffice for n < 3215031751,
        // covering the entire positive range of a 32-bit signed int.
        const u64 bases[] = {2, 3, 5, 7};
        for (u64 a : bases)
        {
            if (a >= n)
                continue;
            if (!checkBase(n, a, d, s))
                return false;
        }
        return true;
    }
}

std::vector<int> findPrimesMillerRabin(int left, int right)
{
    std::vector<int> primes;

    if (left > right || right < 2)
        return primes;

    if (left <= 2)
        primes.push_back(2);

    // Skip all even numbers greater than 2.
    // A 64-bit counter avoids overflow past INT_MAX.
    std::int64_t start = left < 3 ? 3 : left;
    if (start % 2 == 0)
        ++start;

    for (std::int64_t n = start; n <= right; n += 2)
    {
        if (isPrime(static_cast<int>(n)))
            primes.push_back(static_cast<int>(n));
    }

    return primes;
}
