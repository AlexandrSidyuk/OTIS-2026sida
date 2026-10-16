#include "Model3_4.h"

Model3_4::Model3_4(double a, double dt) : Model(0,0,0), alpha(a), dt(dt) {}

double Model3_4::calculateNext(double u, int /*step*/) {
    // Дифференциальное уравнение: dy/dt = -a * y^2[cite: 3]
    // Метод Эйлера: y_{tau+1} = y_tau + dt * (-a * y_tau^2) + u_tau
    double derivative = -alpha * (y_prev1 * y_prev1);
    double nextY = y_prev1 + dt * derivative + u; 
    return nextY;
}