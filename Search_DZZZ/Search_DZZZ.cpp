#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "Participants.h"
#include "DataSetRegister.h"

std::vector<int> FindPrimesReference(int left, int right)
{
    std::vector<int> primes;

    for (long long number = std::max(left, 2); number <= right; ++number)
    {
        bool isPrime = true;

        for (long long d = 2; d <= number / d; ++d)
        {
            if (number % d == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            primes.push_back(static_cast<int>(number));
    }

    return primes;
}

void Run(const std::string& method, Participant algorithm,
    const DataSet& data, const std::vector<int>& expected,
    std::vector<std::string>& logs)
{
    std::chrono::steady_clock::time_point start =
        std::chrono::steady_clock::now();

    std::vector<int> result = algorithm(data.left, data.right);

    std::chrono::steady_clock::time_point finish =
        std::chrono::steady_clock::now();

    long long time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            finish - start).count();

    bool correct = (result == expected);

    std::ostringstream output;

    output << data.description << '\t'
        << data.left << '\t'
        << data.right << '\t'
        << method << '\t'
        << result.size() << '\t'
        << time << '\t'
        << (correct ? "OK" : "FAIL");

    logs.push_back(output.str());

    std::cout << output.str() << '\n';
}

#define RUN(x) Run(#x, x, data, expected, logs)

int main()
{
    std::stack<DataSet> tests = GenerateDataSets();

    std::vector<std::string> logs;

    int left, right;

    std::cout << "Enter left and right boundaries: ";

    if (!(std::cin >> left >> right))
    {
        std::cerr << "Invalid input\n";
        return 1;
    }

    tests.push({ "User range", left, right });

    std::cout
        << "dataset\tleft\tright\tmethod\tcount\ttime_us\tstatus\n";

    while (!tests.empty())
    {
        DataSet data = tests.top();
        tests.pop();

        std::vector<int> expected =
            FindPrimesReference(data.left, data.right);

        RUN(FindPrimesReference);

        // RUN(findPrimesTrialDivision);
        // RUN(findPrimesEratosthenes);
        // RUN(findPrimesSegmented);
        // RUN(findPrimesSundaram);
        // RUN(findPrimesAtkinBernstein);
        // RUN(findPrimesMillerRabin);
    }

    std::ofstream file("result.txt");

    file << "dataset\tleft\tright\tmethod\tcount\ttime_us\tstatus\n";

    for (size_t i = 0; i < logs.size(); ++i)
        file << logs[i] << '\n';

    return 0;
}
