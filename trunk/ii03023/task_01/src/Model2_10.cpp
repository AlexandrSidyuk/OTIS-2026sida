#include "Model2_10.h"
#include <cmath>

Model2_10::Model2_10(double a, double b) : Model(0,0,0), alpha(a), beta(b) {}

double Model2_10::calculateNext(double u, int /*step*/) {
    // Формула: y_{tau+1} = a * tanh(y_tau) + b * u_tau^3[cite: 2]
    double nextY = alpha * std::tanh(y_prev1) + beta * std::pow(u, 3);
    return nextY;
}