#include "Participants.h"

std::vector<int> findPrimesSundaram(int left, int right)
{
    std::vector<int> result;

    if (left > right) return result;
    if (right < 2)    return result;

    int lo = (std::max)(left, 2);
    int hi = right;

    int n = (hi - 1) / 2;

    std::vector<bool> marked(n + 1, false);


    for (int i = 1; i <= n; ++i) {
        long long j_max = (n - i) / (2LL * i + 1);
        if (j_max < i) break;
        for (long long j = i; j <= j_max; ++j) {
            long long k = i + j + 2LL * i * j;
            marked[k] = true;
        }
    }

    if (lo <= 2 && 2 <= hi) result.push_back(2);

    int k_start = (std::max)(1, (lo - 1) / 2);
    for (int k = k_start; k <= n; ++k) {
        if (!marked[k]) {
            int p = 2 * k + 1;
            if (p >= lo && p <= hi) result.push_back(p);
        }
    }

    return result;   
}


