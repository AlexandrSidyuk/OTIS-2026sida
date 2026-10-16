#ifndef MODEL_1_6_H
#define MODEL_1_6_H

#include "Model.h"

class Model1_6 : public Model {
    double a1, a2, a3, b_coef;
public:
    Model1_6(double a1, double a2, double a3, double b);
    double calculateNext(double u, int step) override;
};

#endif // MODEL_1_6_H