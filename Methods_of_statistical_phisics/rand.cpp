#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <vector>
#include <fstream>

int main() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator (seed);
    std::normal_distribution<double> distribution (0.0, 1.0);

    for (size_t i = 0; i < 1001; i++)
    {
        std::cout << "i = " << distribution(generator) << std::endl;
    }
    
}