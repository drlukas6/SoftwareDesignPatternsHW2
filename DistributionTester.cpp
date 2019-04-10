//
// Created by Lukas Sestic on 2019-04-10.
//

#include <iostream>
#include <vector>
#include <random>
#include "WholeNumberGenerators.h"
#include "PercentileCalculators.h"

#pragma mark Context

class DistributionTester {
private:
    WholeNumberGenerator *numberGenerator;
    PercentileCalculator *percentileCalculator;
public:
    DistributionTester(WholeNumberGenerator *numberGenerator, PercentileCalculator *percentileCalculator) {
        this->numberGenerator = numberGenerator;
        this->percentileCalculator = percentileCalculator;
    }

    std::vector<int> *generatePercentiles() {
        auto series = numberGenerator->generate();
        auto *toReturn = new std::vector<int>();

        for (int i = 10; i <= 90; i += 10) {
            toReturn->emplace_back(percentileCalculator->calculatePercentile(series, i));
        }

        return toReturn;
    }
};

#pragma mark Main

int main() {
    double mean = 5.0, dev = 2.0;
    int numberOfElements = 20;
    auto *sequentialNumberGenerator = new NormalDistributionGenerator(mean, dev, numberOfElements);
    auto *closestPercentileCalculator = new InterpolatedPercentileCalculator();

    auto *distributionTester = new DistributionTester(sequentialNumberGenerator, closestPercentileCalculator);
    auto calculatedPercentiles = distributionTester->generatePercentiles();

    for(auto const &value: *calculatedPercentiles) {
        std::cout << "---> " << value << "\n";
    }

    return 0;
}