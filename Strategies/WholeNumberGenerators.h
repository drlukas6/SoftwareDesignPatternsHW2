//
// Created by Lukas Sestic on 2019-04-10.
//

#ifndef INC_2_LAB_WHOLENUMBERGENERATORS_H
#define INC_2_LAB_WHOLENUMBERGENERATORS_H

class WholeNumberGenerator {
public:
    virtual std::vector<int> *generate() = 0;
};

class SequentialNumberGenerator: public WholeNumberGenerator {
private:
    int _start, _end, _step;
public:
    SequentialNumberGenerator(int &start, int &end, int &step) {
        this->_start = start;
        this->_end = end;
        this->_step = step;
    }

    std::vector<int> *generate() override {
        auto *toReturn = new std::vector<int>();

        for (int i = _start; i <= _end; i+=_step) {
            toReturn->emplace_back(i);
        }

        return toReturn;
    }
};

class NormalDistributionGenerator: public WholeNumberGenerator {
private:
    double _mean, _stdDev;
    int _numberOfElements;
public:
    NormalDistributionGenerator(double &mean, double &stdDev, int &numberOfElements) {
        this->_mean = mean;
        this->_stdDev = stdDev;
        this->_numberOfElements = numberOfElements;
    }

    std::vector<int> *generate() override {
        auto *toReturn = new std::vector<int>();

        std::default_random_engine generator;
        std::normal_distribution<double> distribution(_mean, _stdDev);

        for (int i = 0; i < _numberOfElements; ++i) {
            toReturn->emplace_back(round(distribution(generator)));
        }

        return toReturn;
    }
};

class FibonacciDistributionGenerator: public WholeNumberGenerator {
private:
    int _numberOfElements;
public:
    explicit FibonacciDistributionGenerator(int &numberOfElements) {
        this->_numberOfElements = numberOfElements;
    }

    std::vector<int> *generate() override {
        auto *toReturn = new std::vector<int>();

        int first = 0, second = 1, next;

        for (int i = 0; i < _numberOfElements; ++i) {
            toReturn->emplace_back(first);
            next = first + second;
            first = second;
            second = next;
        }

        return toReturn;
    }
};

#endif //INC_2_LAB_WHOLENUMBERGENERATORS_H
