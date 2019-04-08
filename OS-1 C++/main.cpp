#include <iostream>
#include <cmath>

using namespace std;

/*Необходимо реализовать неполную бета-функцию.*/

//Данный метод очищает поток после неверно введённых значений
void ClearInputStream(istream &in) {
    in.clear();
    while (in.peek()!= '\n' && in.peek()!=EOF){
        in.get();
    }
}

/*Класс Бета-Функции
 * Данный класс не будет иметь каких-либо полей,
 * он будет уметь только вычислять интеграл на отрезке [0; x]
 * с двумя параметрами: 'а' и 'b'.
*/
class BetaFunction {
public:

    //Данный метод вычисляет подинтегральное выражение
    double getFunctionValue (double t, double a, double b) {
        return pow(t, a-1)*pow((1-t),b-1);
    }

    //Интегрирование производится методом трапеций
    double integrate (double x, double a, double b, double discreteStep) {
        //Необходимая проверка корректности входных данных
        if (x < 0 || x > 1 || a <= 0 || b <= 0 || discreteStep <= 0 || discreteStep >= 1)
            throw "Incorrect arguments!";
        double integralSum = 0, temp = 0;

        while(temp + discreteStep < x) {
            integralSum += this->getFunctionValue(temp, a, b) * discreteStep +
                           (this->getFunctionValue(temp + discreteStep, a, b) -  this->getFunctionValue(temp, a, b))* discreteStep / 2;
            temp += discreteStep;
        }
        //На области интегрирования находится отрезок, меньший чем дискретный шаг (discreteStep)
        double end = x - temp;
        integralSum += this->getFunctionValue(temp, a, b) * end +
                       (this->getFunctionValue(temp + end, a, b) -  this->getFunctionValue(temp, a, b))* end / 2;
        return  integralSum;
    }
};

int main() {

    while (true) {
        cout << "Please, enter the arguments to the beta function (B[x](a,b)).\n";
        cout << "ATTENTION!! ------------------------"
                << "\nX must belong to the segment [0; 1]. \na > 0 \nb > 0 \n"
                << "------------------------------------\n";
        try {
            double a, b, x;
            cin >> x;
            cin >> a;
            cin >> b;
            BetaFunction beta;
            printf("B[%f](%f, %f) = %f\n", x, a, b, beta.integrate(x, a, b, 0.001));
            return 0;
        }
        catch (...) {
            cout << "Incorrect data entered!\n";
            ClearInputStream(cin);
        }
    }
}