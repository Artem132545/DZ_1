
#include <vector>
#include <chrono>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "DataSetRegister.h"
#include "Participants.h"

using namespace std;

static string teammate = "";
static string dataset = "";
static vector<string> logs;

void Run(string method_name, Participant p, const DataSet& data)
{
    auto start = chrono::steady_clock::now();

    vector<int> res = p(data.left, data.right);

    auto stop = chrono::steady_clock::now();

    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    ostringstream oss;

    oss << '"' << dataset << '"' << '\t'
        << data.left << '\t'
        << data.right << '\t'
        << teammate << '\t'
        << method_name << '\t'
        << res.size() << '\t'
        << ((res == data.expected) ? to_string(time) : "-1");

    logs.push_back(oss.str());
   
    cout << oss.str() << '\n';
}

#define RUN(x) Run(#x, x, data)

int main()
{
    string header = "dataset\tleft\tright\tteammate\tmethod\tcount\ttime_us";

    cout << header << '\n';
    logs.push_back(header);

    auto dataSets = GenerateDataSets();

    int count = 0;

    while (!dataSets.empty())
    {
        auto& data = dataSets.top();

        dataset = data.description;


        teammate = "Shafikov";
        // RUN(findPrimesTrialDivision);

        teammate = "Kryukova";
        // RUN(findPrimesEratosthenes);

        teammate = "Davaasuren";
        // RUN(findPrimesSegmented);

        teammate = "Drach";
        // RUN(findPrimesSundaram);

        teammate = "Milovanov";
        // RUN(findPrimesAtkinBernstein);

        teammate = "Korolev";
        // RUN(findPrimesMillerRabin);

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

    cout << "Prepared datasets: " << count << '\n';
    cout << "Algorithms are not connected yet.\n";

    return 0;
}
