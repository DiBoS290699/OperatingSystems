import java.util.Scanner;
import static java.lang.Math.pow;

/* Необходимо реализовать неполную бета-функцию. */

/** Класс неполной Бета-Функции - интеграла на отрезке [0; x] с двумя параметрами: 'a' и 'b'
 *
 * @author Borisov Dmitriy
 */
public class BetaFunction {
    /** Правая граница области интегрирования и два параметра соответственно */
    private double x, a, b;

    /** Конструктор по умолчанию */
    public BetaFunction() {
        this.x = 1;
        this.a = 1;
        this.b = 1;
    }

    /** Конструктор инициализации */
    public BetaFunction(double x1, double a1, double b1) {
        if (x1 < 0 || x1 > 1 || a1 <= 0 || b1 <= 0)
            throw new IllegalArgumentException();
        this.x = x1;
        this.a = a1;
        this.b = b1;
    }

    /** Гетер поля а */
    public double getA() {
        return a;
    }

    /** Гетер поля b */
    public double getB() {
        return b;
    }

    /** Гетер поля x */
    public double getX() {
        return x;
    }

    /** Функция вычисления подинтегрального выражения */
    public double getFunctionValue (double t, double a, double b) {
        return pow(t, a-1)*pow((1-t),b-1);
    }

    /** Функция, вычисляющая интеграл методом трапеций */
    public double integrate (double discreteStep) throws IllegalArgumentException {
        //Необходимая проверка корректности входных данных
        if (discreteStep <= 0 || discreteStep >= 1)
            throw new IllegalArgumentException();
        double integralSum = 0, temp = 0;


        while(temp + discreteStep < x) {
            integralSum += getFunctionValue(temp, a, b) * discreteStep +
                    (getFunctionValue(temp + discreteStep, a, b) -  getFunctionValue(temp, a, b))* discreteStep / 2;
            temp += discreteStep;
        }
        //На области интегрирования находится отрезок, меньший чем дискретный шаг (discreteStep)
        double end = x - temp;
        integralSum += getFunctionValue(temp, a, b) * end +
                (getFunctionValue(temp + end, a, b) -  getFunctionValue(temp, a, b))* end / 2;
        return  integralSum;
    }

    /** Функция чтения аргументов 'х', 'a', 'b' с консоли*/
    public void readArguments() throws IllegalArgumentException{
        try {
            System.out.println("Please, enter the arguments to the beta function (B[x](a,b)).");
            System.out.println("ATTENTION!! ------------------------");
            System.out.println("X must belong to the segment [0; 1]");
            System.out.println("a > 0");
            System.out.println("b > 0");
            System.out.println("------------------------------------");
            Scanner scanner = new Scanner(System.in);
            double argX = scanner.nextDouble();
            double argA = scanner.nextDouble();
            double argB = scanner.nextDouble();
            //Необходимая проверка корректности входных данных
            if (argX < 0 || argX > 1 || argA <= 0 || argB <= 0)
                throw new IllegalArgumentException();
            this.x = argX;
            this.a = argA;
            this.b = argB;
        } catch (IllegalArgumentException e) {
            System.out.println("Incorrect data entered!");
            this.readArguments();
        }
    }
}
