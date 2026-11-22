
#include <vector>
#include <chrono>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "DataSetRegister.h"
#include "Participants.h"

using namespace std;

static string teammate = "";
static string dataset = "";
static vector<string> logs;

static int testsTotal = 0;
static int testsPassed = 0;

void Run(string method_name, Participant p, const DataSet& data)
{
    auto start = chrono::steady_clock::now();

    vector<int> res = p(data.left, data.right);

    auto stop = chrono::steady_clock::now();

    auto time = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

    bool passed = (res == data.expected);

    testsTotal++;

    if (passed)
        testsPassed++;

    ostringstream oss;

    oss << '"' << dataset << '"' << '\t'
        << data.left << '\t'
        << data.right << '\t'
        << teammate << '\t'
        << method_name << '\t'
        << res.size() << '\t'
        << time << '\t'
        << (passed ? "PASS" : "FAIL");

    logs.push_back(oss.str());

    cout << std::left
        << setw(25) << dataset
        << setw(13) << data.left
        << setw(13) << data.right
        << setw(14) << teammate
        << setw(30) << method_name
        << setw(8) << res.size()
        << setw(14) << time
        << (res == data.expected ? "PASS" : "FAIL")
        << '\n';
}

#define RUN(x) Run(#x, x, data)

int main()
{
    string header = "dataset\tleft\tright\tteammate\tmethod\tcount\ttime_ns\tstatus";

    logs.push_back(header);

    cout << std::left
        << setw(25) << "Dataset"
        << setw(13) << "Left"
        << setw(13) << "Right"
        << setw(14) << "Teammate"
        << setw(30) << "Method"
        << setw(8) << "Count"
        << setw(14) << "Time(ns)"
        << "Status"
        << '\n';

    cout << string(107, '-') << '\n';

    auto dataSets = GenerateDataSets();

    int count = 0;

    while (!dataSets.empty())
    {
        auto& data = dataSets.top();

        dataset = data.description;

        teammate = "Shafikov";
        RUN(findPrimesTrialDivision);

        teammate = "Kryukova";
        RUN(findPrimesEratosthenes);

        teammate = "Davaasuren";
        // RUN(findPrimesSegmented);

        teammate = "Drach";
        RUN(findPrimesSundaram);

        teammate = "Milovanov";
        // RUN(findPrimesAtkinBernstein);

        teammate = "Korolev";
        RUN(findPrimesMillerRabin);

        ++count;

        dataSets.pop();
    }

    ofstream fout("result.txt");

    if (!fout)
    {
        cerr << "Cannot create result.txt\n";
        return 1;
    }

    for (const string& line : logs)
        fout << line << '\n';

    cout << string(107, '-') << '\n';

    cout << "Prepared datasets: " << count << '\n';
    cout << "Total tests: " << testsTotal << '\n';
    cout << "Passed: " << testsPassed << '\n';
    cout << "Failed: " << testsTotal - testsPassed << '\n';

    return 0;
}
