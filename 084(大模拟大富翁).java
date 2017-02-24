import java.math.*;
import java.util.*;

public class Main {
    
    int[] board = new int[40];
    int currentSquare = 0; 
    int totalRolls = 0;
    int CHcard = 0;
    int CCcard = 0;
    Random generator = new Random();
    
    //特殊的位置
    int cc1 = 2;
    int cc2 = 17;
    int cc3 = 33;
    int jail = 10;
    int go2jail = 30;
    int ch1 = 7;
    int ch2 = 22;
    int ch3 = 36;
    int go = 0;
    
    //记录当前和前2次的投骰子的情况
    int[] prevPrevRoll = new int[2];
    int[] prevRoll = new int[2];
    int[] currRoll = new int[2];
    int numberOfTriples = 0;
    
    Main()
    {
        System.out.println("开始模拟大富翁:");
        for(int i = 0; i < board.length; i++){
            board[i] = 0;
        }
        prevRoll[1] = 30;//保证你不能立刻进监狱，G2J:30
    }
    
    public int Roll(){
        //两个骰子，4个面
        int die1 = generator.nextInt(4) + 1;
        int die2 = generator.nextInt(4) + 1; 

        //记录当前和前2次的投骰子的情况
        prevPrevRoll[0] = prevRoll[0]; 
        prevPrevRoll[1] = prevRoll[1];
        prevRoll[0] = currRoll[0];
        prevRoll[1] = currRoll[1];
        currRoll[0] = die1; 
        currRoll[1] = die2;
        int total = die1 + die2;
        totalRolls++;
        
        int possibleMove = (currentSquare + total)%40;
        
        if(tooManyDoubles(currRoll, prevRoll, prevPrevRoll))
        {
            //投到相同的就重新设置上一次投的情况
            currRoll[1] = -1;
            numberOfTriples++;
            currentSquare = jail;
            board[currentSquare]++;
            return currentSquare;
        }
        //机会卡
        else if(possibleMove == 7 || possibleMove == 22 || possibleMove == 36 ){ 
            
            currentSquare = Chance(possibleMove);
            board[currentSquare]++;
            return currentSquare;
        }
        //宝箱卡
        else if(possibleMove == cc1 || possibleMove == cc2 || possibleMove == cc3){
            
            currentSquare = ComChest(possibleMove);
            board[currentSquare]++;
            return currentSquare;
        }
        //进监狱
        else if(possibleMove == go2jail){
            
            currentSquare = jail;
            board[currentSquare]++;
            return currentSquare;
        }
         //什么都没有发生，继续移动
        else
        {
            currentSquare = (currentSquare + total)%40; 
            board[currentSquare]++;
            return currentSquare;
        }
    }
    
    //连续三次投骰子都投到3次
    public boolean tooManyDoubles(int[] a, int[] b, int[] c){       
        if(a[0] == a[1]){
            if(b[0] == b[1]){
                if(c[0] == c[1]){            
                	return true;
                }
            }
        }
        return false;
    }
    /*
     * 宝箱卡 (2/16 张卡):
	回到起点“GO”
	进入监狱“JAIL”
     */
    //抽宝箱里的卡
    public int ComChest(int currentCell){
        int card = generator.nextInt(16); //一共16张
        switch(card)
        {
            case 1:currentCell = go; break; 
            case 2:currentCell = jail; break; 
            default : break;//题目说其他卡片无视效果
        }
        return currentCell;
    }
     /*
      * 机会卡 (10/16 张卡):
		回到起点“GO”
		进入监狱“JAIL”
		移动到“C1”
		移动到“E3”
		移动到“H2”
		移动到“R1”
		移动到下一个“R”（铁路公司）
		移动到下一个“R”
		移动到下一个“U”（公共服务公司）
		后退三步
      */
     //抽机会卡
    public int Chance(int currentCell){
        int card = generator.nextInt(16);
        switch(card){
            case 1: currentCell = go; break; //go
            case 2: currentCell = jail; break; //jail
            case 3: currentCell = 11; break; //c1
            case 4: currentCell = 24; break; //e3
            case 5: currentCell = 39;break; //h2
            case 6: currentCell = 5; break; //r1
            case 7: currentCell = nextRR(currentCell); break; //next railway
            case 8: currentCell = nextRR(currentCell); break; //next railway
            case 9: currentCell = nextUtil(currentCell); break; //next utility
            case 10: currentCell = back3Squares(currentCell); break; //back 3 squares
            default:break; //其他无效果，不变
        }  
        return currentCell;
    }
    //移动到下一个“U”（公共服务公司）
    public int nextUtil(int currentCell)
    {
        if(currentCell >= 12 && currentCell < 28)
        {
            return 28;
        }
        else
        {
            return 12;
        }
    }
    //移动到下一个“R”
    public int nextRR(int currentCell){
        if(currentCell >= 35 || currentCell < 5)
        {
            return 5;
        }
        else if(currentCell >= 5 && currentCell < 15)
        {
            return 15;
        }
        else if(currentCell >= 15 && currentCell < 25)
        {
            return 25;
        }
        else
        {
            return 35;
        }
        
    }
    //后退三步
    //注意:特殊情况
    public int back3Squares(int currentCell){
        if(currentCell == 2){
            return 39;
        }
         //特殊情况
        else if(currentCell == ch3){
            return ComChest(currentCell);
        }
        else
        {
            return currentCell - 3;
        }
    }

    public static void main(String[] args) {
        Main m = new Main();
        //模拟一千万步
        int itterations = 10000000; 
        for(int i = 0; i < itterations; i++){
            m.Roll();
        }
        
        //打印百分比在3%以上的情况
        for(int i = 0; i < m.board.length; i++)
        {
            float percent = (float)m.board[i]/(float)itterations;
            percent *= 100;
            if(percent > 3)
            {
                System.out.println("位置:" + i + "占百分比: " + percent);
            }
        }
        //注意：每一次模拟都不一样，因为随机模拟
        System.out.println("连续3次投出两个骰子相同次数:"+m.numberOfTriples);
    }
}