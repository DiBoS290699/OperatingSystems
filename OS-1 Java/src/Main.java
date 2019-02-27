public class Main {
    public static void main(String[] args) {
        while (true) {
            try {
                BetaFunction beta = new BetaFunction();
                beta.readArguments();
                System.out.printf("B[%f](%f, %f) = %f\n", beta.getX(), beta.getA(), beta.getB(),
                        beta.integrate(0.01));
                break;
            }
            catch (Throwable e) {
                System.out.print("Incorrect data entered!\n");
            }
        }
    }
}
