import java.math.*;
public class Main {
	
	public static BigDecimal TWO = new BigDecimal("2");
	public static BigDecimal temp;
	
	public static BigDecimal sqrtPrecise(int n, BigDecimal x0) {
		BigDecimal a = x0.multiply(x0);
		a = a.add(new BigDecimal(n + ""));

		a = a.divide(x0.multiply(TWO), 101, BigDecimal.ROUND_HALF_EVEN);
		
		if (a.equals(temp)) {
			return a;
		}
		temp = a;
		a = sqrtPrecise(n, a);
		return a;
	}
	
	public static int decimalSum(BigDecimal a) {
		
		String s = a.toString();
		int sum = 0;
		int d = s.indexOf(".");
		sum =sum + Integer.parseInt(s.substring(0,d));
		for (int i=1; i<=99; i++) {
				sum = sum + Integer.parseInt(s.substring(d+i,d+i+1));
		}
		return sum;
	}
	
	public static void main(String args[]) {
		int sum = 0;
		for (int i=1; i <= 100; i++) {	
			double a = Math.sqrt(i);  
			if (Math.floor(a) == a) {
				continue;
			}

			BigDecimal x0 = new BigDecimal(a + "");
			sum += decimalSum(sqrtPrecise(i,x0));
		}
		
		System.out.println("Total sum: " + sum);
	}
	
}
