#include<bits/stdc++.h>
using namespace std;
//牌的定义
typedef struct tagCard
{
    char name;  //牌字符：2，3，, A
    char value; //牌字符在字符串中的索引
    char suit;  //花色
} Card;

typedef Card Item;

//两副牌，每幅各有5张牌
Card cardsBlack[5];
Card cardsWhite[5];
//用于在两副牌达到相同level时的辅助比较数组
int orderBlack[5];
int orderWhite[5];

char line[32];


//所有牌的值，其中10用T表示
char CardValues[]="23456789TJQKA";

//判断t1-t2的差值，即两副牌差值
int lessthan(Item t1, Item t2)
{
    return (t1.value<t2.value)? 1:0;    
}

// return t1-t2
int diffence(Item t1, Item t2)
{
    return (t1.value - t2.value);
}

//交换a[]的i，j项
void exchange(Item a[], int i, int j)
{
    char n1=a[i].name;
    char v1=a[i].value;
    char s1=a[i].suit;
    
    a[i].name=a[j].name;
    a[i].value=a[j].value;
    a[i].suit=a[j].suit;
    
    a[j].name=n1;
    a[j].value=v1;
    a[j].suit=s1;
}
 
//排序 
void SelectionSort(Item a[], int left, int right)
{
    int i,j,min;
    for(i=left; i<right; i++)
    {
        min=i;
        for(j=i+1; j<=right; j++)
            if(lessthan(a[j],a[min])) min=j;
        exchange(a, i, min);
    }
}


//把读取的这一行输入给两副牌数组Black , White 
//2H 3D 5S 9C KD 2C 3H 4S 8C AH
void InitCards()
{
    int i;
    for(i=0;i<5;i++)
    {
        cardsBlack[i].name=line[3*i];
        cardsBlack[i].suit=line[3*i+1];
        cardsBlack[i].value=strchr(CardValues, cardsBlack[i].name)-CardValues;
        
        cardsWhite[i].name=line[3*i+15];
        cardsWhite[i].suit=line[3*i+16];
        cardsWhite[i].value=strchr(CardValues, cardsWhite[i].name)-CardValues;
    }
}

//把两副牌按照从小到大的顺序排好序
void SortCards()
{
    SelectionSort(cardsBlack, 0, 4);
    SelectionSort(cardsWhite, 0, 4);
}

//判断从index起始的，向后数4张牌是否构成一副炸弹，即牌值相同！
int IsBomb(Item a[], int i)
{
    if(a[i+1].value==a[i].value&& a[i+2].value==a[i].value&& a[i+3].value==a[i].value)
         return 1;
    return 0;
}

//是否三张相同
int IsThree(Item a[], int i)
{
    if(a[i+1].value==a[i].value&& a[i+2].value==a[i].value)
        return 1;
    return 0;
}

//是否两张相同的对
int IsPair(Item a[], int i)
{
    if(a[i+1].value==a[i].value)
        return 1;
    return 0;
}

//是否5张牌的牌值连续
int IsStraight(Item a[])
{
    if((a[1].value-a[0].value)==1&& (a[2].value-a[1].value)==1&& (a[3].value-a[2].value)==1&& (a[4].value-a[3].value)==1 )
        return 1;
    return 0;
}

//是否5张牌都是同花色
int IsFlush(Item a[])
{
    if(a[1].suit==a[0].suit&& a[2].suit==a[0].suit&& a[3].suit==a[0].suit&& a[4].suit==a[0].suit)
        return 1;
    return 0;
}

//得到某副已经排好序的牌等级（同花顺最高！，杂牌最低）
//order是等级相同时的辅助比较值
int GetLevel(Item a[], int order[])
{
    int level,i,t1,t2,t3;
    order[0]=order[1]=order[2]=order[3]=order[4]=0;
    
    //level 9 - Straight flush. 同花顺，花色相同，并且牌连续
    level=9;
    if(IsStraight(a) && IsFlush(a))
    {
        order[0]=a[4].value;
        return level;
    }
    
    //level 8 - Four of a kind. 有4相同值的牌，即一副炸弹 
    level--;
    if(IsBomb(a, 0) || IsBomb(a, 1))
    {
        //注意如果有4张相同的牌，则a[1]一定位于这4帐牌之中
        order[0]=a[1].value;
        return level;
    }
    
    //level 7 - Full House. 有3张牌是相同值，另外2张牌也是相同值，OOOXX, XXOOO
    level--;
    if( (IsThree(a,0) && IsPair(a,3)) || (IsThree(a, 2) && IsPair(a, 0)) )
    {
        //XXXOO* Ranked by the value of the 3 cards. 
        order[0]=a[2].value;
        return level;
    }
    
    //level 6 - Flush. 5张牌同花色
    level--;
    if(IsFlush(a))
    {
        //If the highest cards have the same value, the hands are ranked by the next highest
        //order中是从大到小排列的牌值，用于判别大小
        for(i=0;i<5;i++) order[i]=a[4-i].value;
        return level;
    }
    
    //level 5 - Straight. 一条龙，即5张牌的值连续.
    level--;
    if(IsStraight(a))
    {
        order[0]=a[4].value;//ranked by their highest card. 
        return level;
    }
    
    //level 4 - Three of a Kind. 有三张相同值。OOOXY,XOOOY,XYOOO
    level--;
    if(IsThree(a,0) || IsThree(a,1) || IsThree(a,2))
    {
        order[0]=a[2].value;//ranked by the value of the 3 cards. 
        return level;
    }
    
    //level 3 - Two Pairs. 两副对，另一个杂牌的索引用i来记录.
    level--;
    if(  (i=0, IsPair(a,1) && IsPair(a,3))         /*-OOII*/
        || (i=2, IsPair(a,0) && IsPair(a,3))        /*OO-II*/
        || (i=4, IsPair(a,0) && IsPair(a,2)) )    /*OOII-*/
    {
        order[0]=a[3].value;/*I: max pair's value;*/
        order[1]=a[1].value;/*O: min pair's value;*/
        order[2]=a[i].value;/*-: remaining card;  */
        return level;
    }
    
    //level 2 - Pair. 一副对；OOxyz, xOOyz, xyOOz, xyzOO
    /*i存储Pair的位置，t1，t2，t3存储其他值的位置 */
    level--;
    if(  (i=0, t1=4, t2=3, t3=2, IsPair(a,0))        /*OOxyz*/
        || (i=1, t1=4, t2=3, t3=0, IsPair(a,1))        /*xOOyz*/
        || (i=2, t1=4, t2=1, t3=0, IsPair(a,2))        /*xyOOz*/
        || (i=3, t1=2, t2=1, t3=0, IsPair(a,3)) )    /*xyzOO*/
    {
        /*ranked by the value of the cards forming the pair. 
          If these values are the same, the hands are ranked 
          by the values of the cards not forming the pair, 
          in decreasing order. */
        order[0]=a[i].value;
        order[1]=a[t1].value;
        order[2]=a[t2].value;
        order[3]=a[t3].value;
        return level;
    }
    
    //level 1 - High Card. 完全的杂牌。不构成上诉任何情况，从大到小比
    level--;
    for(i=0;i<5;i++) order[i]=a[4-i].value;
    return level;
}

int main()
{
    int levelBlack, levelWhite, i;
    int ans=0;
    //freopen("poker.txt","r",stdin);
    while(gets(line)!=NULL && strlen(line)>2)
    {
        InitCards();    //把读入的字符串设置到数组中
        SortCards();   //把两副牌都排好序
        levelBlack=GetLevel(cardsBlack, orderBlack);
        levelWhite=GetLevel(cardsWhite, orderWhite);
        
        //比较两副牌
        if(levelBlack > levelWhite){
        	printf("Black wins.\n");
			//ans++;
		}
            
        else if(levelBlack < levelWhite)
            printf("White wins.\n");
        
        //等级相同 
        else
        {
            //级别相同，需要比较order数组
            for(i=0;i<5;i++)
            {
                if(orderBlack[i]>orderWhite[i])
                {
                    printf("Black wins.\n");
                    //ans++;
                    break;//已经比较出结果！
                }
                else if(orderBlack[i]<orderWhite[i])
                {
                    printf("White wins.\n");
                    break;
                }
            }
            //依然未分出胜负，则平局！
            if(i==5) printf("Tie.\n");
        }
    }
    //printf("%d",ans);
    return 0;
}