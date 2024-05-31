
#include "AlphaLevelFuzzy.hpp"
#include <iostream>

class AlphaLevelFuzzy {
private:
    static const int LN = 10;
    struct Level {
        double mf;
        double lv;
        double rv;
    } level[LN];

public:
    AlphaLevelFuzzy() {};

    void Triang2AlphaLevel(double a, double b, double c) {
        std::cout << "a\tb\tc\tMF\tLV\tRV" << std::endl;
        for (int i = 0; i < LN; ++i) {
            double alpha = static_cast<double>(i) / (LN - 1);
            double mf = alpha;
            double lv = a * alpha * alpha + b * alpha + c - 10; // Пример операции вычитания
            double rv = a * alpha * alpha + b * alpha + c + 20; // Пример операции вычитания
            level[i] = { mf, lv, rv };
            std::cout << a << "\t" << b << "\t" << c << "\t" << mf << "\t" << lv << "\t" << rv << std::endl;
        }
    }

    double defuzzify() {
        double maxVal = 0.0;
        for (int i = 0; i < LN; ++i) {
            double mid = (level[i].lv + level[i].rv) / 2;
            maxVal = std::max(maxVal, level[i].mf * mid);
        }
        return maxVal;
    }

    void print() {
        std::cout << "Alpha Level\tMF\tLV\tRV" << std::endl;
        for (int i = 0; i < LN; ++i) {
            std::cout << i << "\t" << level[i].mf << "\t" << level[i].lv << "\t" << level[i].rv << std::endl;
        }
        std::cout << "Defuzzified value: " << defuzzify() << std::endl;
    }
};

int main() {
    AlphaLevelFuzzy fuzzyObj;
    fuzzyObj.Triang2AlphaLevel(1, 2, 3); // Параметры треугольной функции
    fuzzyObj.print();

    return 0;
}

