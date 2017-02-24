import java.math.*;
import java.util.Scanner;
public class Main {
	
	/**
	 * ProjectEuler Problem 80: Square Root Digital Expansion
	 * 
	 * Given a pair of positive integers (N, D) (default (100, 100)), returns the sum
	 * of the first D digits of the positive square root of all positive integers less
	 * than or equal to N that do not have a rational square root.
	 * 
	 */
	public static void main(String[] args)
	{
		long start = System.currentTimeMillis();
		int max = (args.length < 1) ? 100 : Integer.parseInt(args[0]);
		int digits = (args.length < 2) ? 100 : Integer.parseInt(args[1]);
		int total = 0;
		for(int i = 1; i <= max; i++) {
			int sum = 0;
			double root = Math.sqrt(i);
			if(root == Math.floor(root)) continue;
			BigInteger R = BigInteger.valueOf((int) root), T = BigInteger.valueOf(i);
			while(R.toString().length() < digits) {
				T = T.multiply(BigInteger.TEN.multiply(BigInteger.TEN));
				R = R.multiply(BigInteger.TEN).add(BigInteger.TEN)
						.subtract(BigInteger.ONE);
				while(R.multiply(R).compareTo(T) > 0) 
					R = R.subtract(BigInteger.ONE);
			}
			String S = R.toString();
			for(int j = 0; j < S.length(); j++)
				sum += Integer.parseInt(S.substring(j, j + 1));
			// System.out.println(i + ": " + sum + " " + S);
			total += sum;
		}
		System.out.println(total);
		System.out.println("Time: " + (System.currentTimeMillis() - start));
	}
	
}