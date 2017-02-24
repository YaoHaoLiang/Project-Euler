
import java.math.*;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args)
	{
		int n=2000000; int area=0;
		int min=2000000;
		int len=(int)Math.sqrt(n)+100;
		for(int i=1;i<=len;i++)
		{
			for(int j=i;j<len;j++)
			{
				int sumx=i*(i+1)/2;
				int sumy=j*(j+1)/2;
				
				int sum=sumx*sumy;
				if(Math.abs(sum-n)< min){
					min=Math.abs(sum-n);
					area=i*j;
				}
			}
		}
		System.out.println(area);
		
	}
}
