import java.util.*;
import java.lang.*;

public class Test {
	public static void main(String[] args) {
		System.out.println("abc");
	}

	static void prime_in(int begin, int end) {
		System.out.printf("Between %d and %d: ", begin, end);
		for (int n=begin; n<end; n++) {
			if (is_prime(n)) {
				System.out.printf("%d ", n);
			}
		}
		System.out.println();
	}

	static boolean is_prime(int n) {
		for(int i=2; i<Math.sqrt(n); i++) {
			if ( n%i == 0 ) {
				return false;
			}
		}
		return true;
	}

	static boolean is_daffodil(int n) {
		int i = n / 100;
		int j = n / 10 % 10;
		int k = n % 10;
		if (Math.pow(i,3) + Math.pow(j,3) + Math.pow(k,3) == n) {
			return true;
		} else {
			return false;
		}
	}

	static void daffodil_in(int begin, int end) {
		System.out.printf("Between %d and %d is: ", begin, end);
		for (int n=begin; n < end; n++) {
			if (is_daffodil(n)) {
				System.out.printf("%d ", n);
			}
		}
		System.out.println();
	}

	static void fibonacci(int n) {
		if ( n<2 ) {
			System.out.println("Error");
		} else {
			int i=1, j=1, z;
			for (int count=0; count<=n; count++) {
				z = i + j;
				i = j;
				j = z;
				System.out.printf("%d ", z);
			}
			System.out.println();
		}
	}

	static int area(int width, int high) {
		return width * high;
	}

	static double area(double a, double b, double c) {
		double s = (a+b+c) /2;
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}

	static double area(double r) {
		return Math.PI * r * r;
	}
}