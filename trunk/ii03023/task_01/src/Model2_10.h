#ifndef MODEL_2_10_H
#define MODEL_2_10_H

#include "Model.h"

class Model2_10 : public Model {
    double alpha, beta;
public:
    Model2_10(double a, double b);
    double calculateNext(double u, int step) override;
};

#endif // MODEL_2_10_H