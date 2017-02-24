package Level3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class PE096{
	public static void run() throws IOException{
		ArrayList<int[][]> sudoku= getSudoku();
		int[][] sd = sudoku.get(0);
		int result = 0;
		for(int index=0;index<sudoku.size();index++){
			sd = sudoku.get(index);
			solvesudoku(sd,0);
			result += sd[0][0]*100+sd[0][1]*10+sd[0][2];	
		}
		System.out.println(result);
	}
//	24702
//	running time=0s515ms
	public static boolean solvesudoku(int[][] sd,int index){
		if(index >= 81)
			return true;
		int x = index/9;
		int y = index%9;
		if(sd[x][y]==0){
			for(int n=1;n<=9;n++){
				sd[x][y] = n;
				if(CheckrowAndcol(sd,x,y,n) && CheckGrid(sd,x,y,n))
					if(solvesudoku(sd,index+1))
						return true;
				sd[x][y] = 0;
			}
		}else
			return solvesudoku(sd,index+1);
		return false;
		
	}
	// 判断 n 所在的行列是否包含 n
	public static boolean CheckrowAndcol(int[][] sd,int x ,int y,int n){
		// x 行
		for(int j=0;j<9;j++){
			if(j!=y && sd[x][j] ==n  )
				return false;
		}
		// y列
		for(int i=0;i<9;i++){
			if(i!=x && sd[i][y]==n )
				return false;
		}
		return true;
	}
	// 判断所在的方格是否包含 n
	public static boolean CheckGrid(int[][] sd,int x,int y,int n){
		// 根据x y的坐标求其所在方格的左上坐标和右下坐标表示不好想。
		for(int i = (x/3)*3;i<(x/3+1)*3;i++){
			for(int j=(y/3)*3;j<(y/3+1)*3;j++){
				if(i!=x && j!=y && sd[i][j]==n)
					return false;
			}
		}
		return true;
	}
	public static ArrayList<int[][]> getSudoku() throws IOException{
		ArrayList<int[][]> sudoku= new ArrayList<int[][]>();
		int[][] sd = new int[9][9];
		
		String filename = "src/Level3/p096_sudoku.txt";
		BufferedReader data = new BufferedReader(new FileReader(filename));
		String tmp = null;
		// 第几个数独
		int index = 0;
		// 读取到数独的某行
		int row = 0;
		while((tmp=data.readLine())!=null){
			String grid=tmp.substring(0,4);
			if(grid.equals("Grid")){
				if(index!=0){
					sudoku.add(sd);
				}
				index++;
				row =0;
				sd = new int[9][9];
			}else{
				String[] arrayStr = tmp.trim().split("");
				for(int i=0;i<9;i++){
					sd[row][i] = Integer.parseInt(arrayStr[i+1]);
				}
				row++;
			}
		}
		//最后一个数独
		sudoku.add(sd);
		return sudoku;
		
	}
	public static void main(String[] args) throws IOException {
		long t0 = System.currentTimeMillis();
		run();
		long t1 = System.currentTimeMillis();
		long t = t1 - t0;
		System.out.println("running time="+t/1000+"s"+t%1000+"ms");

	}
}