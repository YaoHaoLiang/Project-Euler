import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
public class Main
{
	public static int[][] sudoku = new int[9][9];
	public static int sum = 0;
	public static ArrayList<int[]> zero;//=new ArrayList<int[]>;

	public static void solve()
	{
		int i = 0; boolean b = false;

		while (i != zero.size())
		{
			if (b) 
				if (sudoku[zero.get(i)[0]][zero.get(i)[1]] == 9)
				{
					sudoku[zero.get(i)[0]][zero.get(i)[1]] = 0;
					i--;
					continue;
				}
				else sudoku[zero.get(i)[0]][zero.get(i)[1]]++;

			b = false;

			while (!b && !check(zero.get(i)[0], zero.get(i)[1]))
			{
				if (sudoku[zero.get(i)[0]][zero.get(i)[1]] < 9)
					sudoku[zero.get(i)[0]][zero.get(i)[1]]++;
				else {
					sudoku[zero.get(i)[0]][zero.get(i)[1]] = 0;
					b = true;
					i -= 2;
				}
			}			
			i++;
		}
	}

	public static boolean check(int i, int j)
	{
		if (sudoku[i][j] == 0)
			return false;
		for (int k=0; k<9; k++)
			if ((sudoku[i][k] == sudoku[i][j] && k != j) || (sudoku[k][j] == sudoku[i][j] && k != i)) 
				return false;

		int d = i/3 * 3; int e = j/3 * 3;
		for (int k=d; k<d+3; k++)
			for (int l=e; l<e+3; l++)
				if (sudoku[k][l] == sudoku[i][j] && k != i && l != j)
					return false;
		return true;

	}

	public static void main(String[] args)
	{
		BufferedReader br = null;
		try
		{
			String s;
			br = new BufferedReader(new FileReader("C:\\Users\\Administrator\\workspace1\\Main\\096_sudoku.txt"));

			for (int i=1; i<=50; i++)
			{
				zero = new ArrayList<int[]>();
				br.readLine();
				for (int j=0; j<9; j++)
				{
					s = br.readLine();
					for (int k=0; k<9; k++)
					{
						sudoku[j][k] = Character.getNumericValue(s.charAt(k));
						if (Character.getNumericValue(s.charAt(k)) == 0)
							zero.add(new int[]{j,k});
					}
				}		
				solve();	
				sum += sudoku[0][0]*100 + sudoku[0][1]*10 + sudoku[0][2];
			}
			
			System.out.println(sum);
//			br.close();
		} catch (IOException e){
			e.printStackTrace();
		}
   }
}