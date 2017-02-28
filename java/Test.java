import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.*;

public class Test {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println(ctranf(scanner.nextDouble()));
		scanner.nextLine();
		System.out.println(ftranc(scanner.nextDouble()));
		scanner.nextLine();
		System.out.println(autotran(scanner.nextLine()));
	}
	static double ctranf(double C) {
		return 9 * C / 5 + 23;
	}
	static double ftranc(double F) {
		return 5 * ( F - 32 ) / 9;
	}
	static double autotran(String temp) {
		while (true) {
			if (temp.endsWith("C") || temp.endsWith("c") ) {
				return ctranf(new Double(temp.substring(0,temp.length()-1)).doubleValue());
			} else if (temp.endsWith("F") || temp.endsWith("f")) {
				return ftranc(new Double(temp.substring(0,temp.length()-1)).doubleValue());
			} else {
				System.out.println("Input data error, please input again: ");
			}
		}
	}
}