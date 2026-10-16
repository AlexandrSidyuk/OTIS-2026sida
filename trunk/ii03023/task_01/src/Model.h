#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include <cmath>

// Перечисление типов входных воздействий (пункт 10 ТЗ)
enum class InputType {
    STEP,       // Стуенчатое (u = const)
    IMPULSE,    // Импульсное (u_0 = 1, u_tau>0 = 0)
    HARMONIC    // Гармоническое (u = sin(tau))
};

class Model {
protected:
    double y_prev1; // y(tau)
    double y_prev2; // y(tau - 1)
    double y_prev3; // y(tau - 2)
    double a, b, c; // Параметры модели

public:
    Model(double paramA, double paramB, double paramC = 0.0)
        : y_prev1(0.0), y_prev2(0.0), y_prev3(0.0), a(paramA), b(paramB), c(paramC) {}
    
    virtual ~Model() = default;

    // Метод сброса состояния перед новым экспериментом
    virtual void reset(double initialY = 0.0) {
        y_prev1 = initialY;
        y_prev2 = initialY;
        y_prev3 = initialY;
    }

    // Чисто виртуальный метод расчета следующего шага (пункт 9 ТЗ)
    virtual double calculateNext(double u, int step) = 0;

    // Метод генерации входного воздействия (пункт 10 ТЗ)
    double generateInput(InputType type, int step) const {
        switch (type) {
            case InputType::STEP:
                return 1.0; // Константа
            case InputType::IMPULSE:
                return (step == 0) ? 1.0 : 0.0; // Импульс в начале
            case InputType::HARMONIC:
                return std::sin(step * 0.1); // Гармоническое воздействие
        }
        return 0.0;
    }

    // Запуск симуляции на n шагов (пункт 6 ТЗ)
    std::vector<double> simulate(int steps, InputType inputType) {
        reset();
        std::vector<double> results;
        results.reserve(steps);

        for (int i = 0; i < steps; ++i) {
            double u = generateInput(inputType, i);
            double nextY = calculateNext(u, i);
            results.push_back(nextY);
            
            // Сдвиг истории состояний
            y_prev3 = y_prev2;
            y_prev2 = y_prev1;
            y_prev1 = nextY;
        }
        return results;
    }
};

#endif // MODEL_H