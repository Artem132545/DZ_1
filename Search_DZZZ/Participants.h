#pragma once

#include <vector>

using Participant = std::vector<int>(*)(int, int);

std::vector<int> findPrimesTrialDivision(int left, int right);
std::vector<int> findPrimesEratosthenes(int left, int right);
std::vector<int> findPrimesSegmented(int left, int right);
std::vector<int> findPrimesSundaram(int left, int right);
std::vector<int> findPrimesAtkinBernstein(int left, int right);
std::vector<int> findPrimesMillerRabin(int left, int right);

