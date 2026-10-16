#include "Model1_6.h"

Model1_6::Model1_6(double a1, double a2, double a3, double b)
    : Model(0, 0, 0), a1(a1), a2(a2), a3(a3), b_coef(b) {}

double Model1_6::calculateNext(double u, int /*step*/) {
    // Формула: y_{tau+1} = a1*y_tau + a2*y_{tau-1} + a3*y_{tau-2} + b*u_tau[cite: 1]
    double nextY = a1 * y_prev1 + a2 * y_prev2 + a3 * y_prev3 + b_coef * u;
    return nextY;
}