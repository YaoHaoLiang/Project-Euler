
public class Main
{
	
	public static void main(String[] args) 
	{
		int sums[]=new int[1000001];
		int check[]=new int[sums.length];
		
		for(int i=1;i<=sums.length;i++)
		{
			for(int t=i*2; t<sums.length;t+=i){
				sums[t]+=i;
			}
		}
		for(int best=0,i=1; i<sums.length; i++){
			for(int n=0, t=i;(t=sums[t]) < sums.length && check[t]!=i; n++,check[t]=i)
			{
				if(t==i && n> best)
					System.out.println("Chain length: " + (best = n) + " Smalles member: " + i);
			}
		}
	}
		
}