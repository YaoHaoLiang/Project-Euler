
public class Main
{
	/*
	 *there are [a/2]-(b-a)+1 solutions (if this expression is positive)
	 * and if b≤M, there are [a/2] extra solutions.
	 */
	public static void addCuboids(int tria, int trib, int [] counts)
	{
		int num = ( tria/2 + 1 ) - ( tria-trib > 0 ? tria - trib : 1);
		counts[trib] += num > 0 ? num : 0;
	}
	
	public static int gcd(int a,int b)
	{ 
		return b==0?a:gcd(b,a%b);
	}
	
	public static int [] countTriplets(int M)
	{
		//所有长、宽、高均不超过M应改为至多只有两个为M，不能3个同时为M
		//如果三个边相等且都为M，那么最短路径显然为M*√5，其不可能为整数
		//d=x^2+y^2, b=max(x^2-y^2,2xy), a=min(x^2-y^2,2xy)
		//我们不用考虑d,d就是最短路径
		//要保证初始状态(x+y) is odd and gcd(x,y)=1,并且不能超过M
		//对于每个勾股数，(a,b,c), a≤M 和 b≤M
		//there are [a/2]-(b-a)+1 solutions (if this expression is positive), and if b≤M, there are [a/2] extra solutions.
		int [] counts = new int[M+1];
		for(int q=1; q < M; q++)
			for(int p=q+1;p<M; p++)
			{
				if(( (p^q) &1 )== 0) continue;
				
				int a = 2*p*q;
				int b = p*p-q*q;
				if((a > M && b > M) || gcd(p,q) != 1) continue;
				int mult = 1;
				while(true)
				{
					int am = a * mult;
					int bm = b * mult;
					if(am > M && bm > M) break;
					if(bm <= M) addCuboids(am, bm, counts);
					if(am <= M) addCuboids(bm, am, counts);
					mult++;
				}
			}
		return counts;
	}
	
	public static void main(String[] args) 
	{
		int[] counts= countTriplets(2000); //预处理2000内所有勾股数
		int sum=0,i; 
		for(i=0; i < counts.length && sum <= 1000000;i++)
			sum+=counts[i];
		System.out.println(i-1);
	}
	
	
}