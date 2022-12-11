//
// Created by warcr on 2022-12-09.
//
#include "Random.h"
#include <random>

class Generator {
public:
    Generator() : g(time(nullptr)) {}

    std::mt19937 g;
};

static Generator generator;

int random_int(int min, int max) {
    std::uniform_int_distribution<int>dist(min, max);
    return dist(generator.g);
}