import java.util.Scanner;

public class FibonacciWithStepCount {
        public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of Fibonacci numbers to calculate: ");
        int n = scanner.nextInt();
        
        long[] fibonacciSeries = new long[n];
        long stepCount = 0;
        
        if (n >= 1) {
        fibonacciSeries[0] = 0;
        stepCount++;
        }
        if (n >= 2) {
        fibonacciSeries[1] = 1;
        stepCount++;
        }
        
        for (int i = 2; i< n; i++) {
        fibonacciSeries[i] = fibonacciSeries[i - 1] + fibonacciSeries[i - 2];
        stepCount += 3; // Each iteration includes 3 steps: addition, access previous two values, and assignment.
        }
        
System.out.println("Fibonacci Series:");
for (int i = 0; i < n; i++) {
System.out.print(fibonacciSeries[i] + " ");
}

System.out.println("Total steps taken to calculate the Fibonacci series: " + stepCount);
}
}