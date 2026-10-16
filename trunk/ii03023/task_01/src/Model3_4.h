#ifndef MODEL_3_4_H
#define MODEL_3_4_H

#include "Model.h"

class Model3_4 : public Model {
    double alpha;
    double dt; // Шаг дискретизации методом Эйлера
public:
    Model3_4(double a, double dt = 0.1);
    double calculateNext(double u, int step) override;
};

#endif // MODEL_3_4_H