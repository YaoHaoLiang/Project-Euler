import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;


public class Main {
    
	 private static boolean check (int [] arr) 
	    {
	        Arrays.sort (arr);
	        int front = arr [0], back = 0;
	        for (int i = 1; i < (int)Math.ceil (arr.length / 2.); i++)
	        {
	            front += arr [i];
	            back += arr [arr.length - i];
	            if (front <= back) return false;
	        }
	        boolean [][] seen = new boolean [arr.length / 2 + 1][front + back];
	        
	        outer : for (int i = 1; i < (1 << arr.length); i++) 
	        {
	            int sum = 0, count = 0;
	            for (int j = 0; j < arr.length; j++) 
	            {
	                if ((i & (1 << j)) > 0) 
	                {
	                    sum += arr [j];
	                    count++;
	                    if (count > arr.length / 2) continue outer;
	                }
	            }
	            if (seen [count][sum]) return false;
	            seen [count][sum] = true;
	        }
	        return true;
	    }
	 
	 public static void main (String [] args) throws IOException {
		 
        long time = System.currentTimeMillis ();
        BufferedReader in = new BufferedReader (new FileReader (new File ("E:\\Walker_ACM代码库\\Project Euler\\101-150\\105_sets.txt")));
        String line = in.readLine ();
        int sum = 0;
        while (line != null) {
            String [] a = line.split (",");
            int [] arr = new int [a.length];
            int s = 0;
            for (int i = 0; i < a.length; i++) {
                arr [i] = Integer.parseInt (a [i]);
                s += arr [i];
            }
            if (check (arr)) sum += s;
            line = in.readLine ();
        }
        System.out.println (sum);
        System.out.println ("Time: " + (System.currentTimeMillis () - time) / 1000. + "s");
    }
 
}
