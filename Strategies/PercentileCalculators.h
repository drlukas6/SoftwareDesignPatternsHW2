//
// Created by Lukas Sestic on 2019-04-10.
//

#ifndef INC_2_LAB_PERCENTILECALCULATORS_H
#define INC_2_LAB_PERCENTILECALCULATORS_H

class PercentileCalculator {

public:
    virtual int calculatePercentile(std::vector<int> *numberSeries, int percentile) =0;
};

class ClosestPositionPercentileCalculator: public PercentileCalculator {
public:
    int calculatePercentile(std::vector<int> *numberSeries, int percentile) override {
        std::sort(numberSeries->begin(), numberSeries->end());


        auto position = static_cast<unsigned int>(
                round(((float)numberSeries->size() * percentile) / 100 + 0.5) - 1);

        return numberSeries->at(position);
    }
};

class InterpolatedPercentileCalculator: public PercentileCalculator {
public:
    int calculatePercentile(std::vector<int> *numberSeries, int percentile) override {
        if (numberSeries->empty()) return 0;

        auto numberOfElements = numberSeries->size();
        std::sort(numberSeries->begin(), numberSeries->end());

        // Don't forget to use (-1) as this starts from 1.
        auto index = static_cast<unsigned int>(floor(((float)numberOfElements * percentile) / 100 + 0.5));

        // Edge cases
        if (index < 1) return numberSeries->at(0);
        if (index >= numberOfElements) return numberSeries->at(numberOfElements - 1);

        //p(v[i]) = 100*(i-0.5)/N
        //v(p) = v[i] + N * (p-p(v[i]))*(v[i+1]-v[i])/100
        auto indexInSeries = index - 1;
        auto pOfIndex = 100 * (index - 0.5) / numberOfElements;
        auto calculatedValue = static_cast<int>(numberSeries->at(indexInSeries) + numberOfElements * (percentile - pOfIndex) * (numberSeries->at(index) - numberSeries->at(indexInSeries)) / 100);

        return calculatedValue;
    }
};

#endif //INC_2_LAB_PERCENTILECALCULATORS_H
