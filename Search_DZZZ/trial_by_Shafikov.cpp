#include "Participants.h"
// Метод пробного деления:

std::vector<int> findPrimesTrialDivision(int left, int right)
{
    std::vector<int> primes;

    if (left > right || right < 2)
        return primes;

    if (left < 2)
        left = 2;

    for (int n = left; ; n++)
    {
        bool isPrime = true;

        if (n > 2 && n % 2 == 0)
        {
            isPrime = false; 
        }
        else
        {
            for (int d = 3; d <= n / d; d += 2)
            {
                if (n % d == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime)
            primes.push_back(n);

        if (n == right)
            break;
    }

    return primes;
}
