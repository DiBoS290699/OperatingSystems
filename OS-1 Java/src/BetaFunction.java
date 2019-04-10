import java.util.Scanner;
import static java.lang.Math.pow;

/* You must implement an incomplete beta feature. */

/** Class of incomplete Beta - integral function on the interval [0; x]
 * with two parameters: 'a' and 'b'
 *
 * @author Borisov Dmitriy
 */
public class BetaFunction {
    /** The right border of the integration area and two parameters respectively */
    private double x, a, b;

    /** Default constructor*/
    public BetaFunction() {
        this.x = 1;
        this.a = 1;
        this.b = 1;
    }

    /** Initialization constructor */
    public BetaFunction(double x1, double a1, double b1) {
        if (x1 < 0 || x1 > 1 || a1 <= 0 || b1 <= 0)
            throw new IllegalArgumentException();
        this.x = x1;
        this.a = a1;
        this.b = b1;
    }

    /** getting a field а */
    public double getA() {
        return a;
    }

    /** getting field b */
    public double getB() {
        return b;
    }

    /** getting field x */
    public double getX() {
        return x;
    }

    /** The function paginegialle expression */
    public double getFunctionValue (double t, double a, double b) {
        return pow(t, a-1)*pow((1-t),b-1);
    }

    /** Function that calculates the integral by trapezoid method */
    public double integrate (double discreteStep) throws IllegalArgumentException {
        //It is necessary to check the validity of input data
        if (discreteStep <= 0 || discreteStep >= 1)
            throw new IllegalArgumentException();
        double integralSum = 0, temp = 0;


        while(temp + discreteStep < x) {
            integralSum += getFunctionValue(temp, a, b) * discreteStep +
                    (getFunctionValue(temp + discreteStep, a, b) -  getFunctionValue(temp, a, b))* discreteStep / 2;
            temp += discreteStep;
        }
        //On the integration region there is a segment smaller than the discrete step (discreteStep)
        double end = x - temp;
        integralSum += getFunctionValue(temp, a, b) * end +
                (getFunctionValue(temp + end, a, b) -  getFunctionValue(temp, a, b))* end / 2;
        return  integralSum;
    }

    /** Function to read arguments 'x', 'a', 'b' from console*/
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
            //Necessary to check the validity of input data
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
