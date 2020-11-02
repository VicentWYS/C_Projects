#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void inputDemo(){
    int n1;
    int n2;

    printf("input the 1st num:\n");
    scanf("%d",&n1);

    printf("input the 2th num:\n");
    scanf("%d", &n2);

    printf("%d + %d = %d\n", n1,n2,n1+n2);
}

void doubleDemo(){
    double n1;
    double n2;

    // %lf 用于接收double型
    printf("input the 1st num:\n");
    scanf("%lf",&n1);

    printf("input the 2th num:\n");
    scanf("%lf", &n2);

    //修改输出格式，使结果只显示小数点后两位
    printf("%.2f * %.2f = %.2f\n", n1,n2,n1*n2);
}

void circle_area(){
    float area;
    int r = 5;

    area = 3.14 * r * r;
    printf("area = %5.2f\n", area);
}

void exchangeValue(){
    int n1;
    int n2;

    printf("input num1:\n");
    scanf("%d", &n1);
    printf("input num2:\n");
    scanf("%d", &n2);
    printf("两数为：n1=%d, n2=%d\n", n1,n2);

    int temp;

    //交换过程
    temp = n1;
    n1 = n2;
    n2 =temp;

    printf("交换后的两数为：n1=%d, n2=%d\n", n1,n2);

}


void leapYear(){
    int year;
    printf("输入年份:\n");
    scanf("%d", &year);

    if((year%4==0 && year%100!=0) || (year%400==0)){
        printf("%d是闰年\n", year);
    }else{
        printf("%d不是闰年\n", year);
    }
}


void findMax(){
    int max;
    int n1 = 10;
    int n2 = 20;

    max = (n1>n2)?n1:n2;

    printf("%d 和 %d 中的最大值是：%d\n", n1,n2,max);
}


//判断成绩等级
void switchDemo(){
    int score;
    printf("输入成绩:\n");
    scanf("%d", &score);

    switch(score/10){
        case 10:
        case 9:
            printf("score %d is A\n", score);
            break;
        case 8:
            printf("score %d is B\n", score);
            break;
        case 7:
            printf("score %d is C\n", score);
            break;
        case 6:
            printf("score %d is D\n", score);
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            printf("score %d is F\n", score);
            break;
        default:
            printf("score %d is error!\n", score);
            break;
    }
}


void whileDemo(){
    int sum=0;
    int n=1;

    while(n<=100){
        sum = sum + n;
        n++;
    }

    printf("1 到 100 的和是：%d\n", sum);
}

//求1到100中所有能被3整除但不能被7整除的数的和
void while_ifDemo(){
    int n = 1;
    int sum = 0;

    while(n<=100){
        if(n%3==0 && n%7!=0){
            sum = sum + n;
        }
        n++;
    }

    printf("求1到100中所有能被3整除但不能被7整除的数的和: %d\n", sum);
}

//求1+3+5+9+...+99
void do_whileDemo(){
    int n = 1;
    int sum = 0;

    do{
        sum = sum + n;
        n = n + 2;
    }while (n<=99);

    printf("1+3+5+9+...+99= %d\n", sum);
}

//判断某数是否为素数
void breakDemo(){
    int i;
    int n=1;
    int m;

    printf("输入带判断的数字m(m大于1):\n");
    scanf("%d", &m);

    //以此判断m能否被2~m-1之间的数整除
    for(i=2; i<=m-1; i++){
        if(m%i == 0){
            break;//此数为非素数
        }
    }

    if(i<=m-1){
        printf("%d 不是素数\n", m);
    }else{
        printf("%d 是素数\n", m);
    }
}


//总和：猜数游戏
void Game_guessNum(){
    int count = 0;
    int madeNum;    //随机产生的待猜的数
    int playerNum;  //玩家某次猜测的数

    printf("猜数游戏\n");

    //产生0~100之间的随机整数
    srand(time(NULL));
    madeNum = rand() % 100;

    count = 0;  //猜测计数清零
    printf("请输入猜测的数（0~100）：\n");
    scanf("%d", &playerNum);
    count = count + 1;

    while( playerNum != madeNum ){
        if(playerNum > madeNum){
            printf("大了，再猜\n");
        }

        if(playerNum < madeNum){
            printf("小了，再猜\n");
        }

        scanf("%d", &playerNum);
        count++;
    }

    //根据猜测次数进行评价
    if(count <= 2){
        printf("高手，猜了%d次就猜了出来\n", count);
    }else if(count <= 5){
        printf("不错，猜了%d次就猜了出来\n", count);
    }else if(count <= 8){
        printf("一般，猜了%d次猜了出来\n", count);
    }else{
        printf("不够好，猜了%d次才猜了出来\n", count);
    }

}


void swap(int a, int b){
    int temp;

    temp = a;
    a = b;
    b = temp;
}


int recursionDemo(int n){
    if(n==1){
        return n;
    }else{
        return n + recursionDemo(n-1);
    }
}


int init(){
    srand(time(NULL));
    return (rand() % 100);
}

int play(int madeNum){
    int playNum;
    int count=0;

    printf("猜数游戏\n");
    printf("请输入你猜的数：\n");
    scanf("%d", &playNum);
    count++;

    while(playNum != madeNum){
        if(playNum > madeNum){
            printf("太大，再猜\n");
        }
        if(playNum < madeNum){
            printf("太小，再猜\n");
        }

        //重新读入猜的数字
        scanf("%d", &playNum);
        count++;
    }

    return count;
}

void getScore(int count){
    //根据猜测次数进行评价
    if(count <= 2){
        printf("高手，猜了%d次就猜了出来\n", count);
    }else if(count <= 5){
        printf("不错，猜了%d次就猜了出来\n", count);
    }else if(count <= 8){
        printf("一般，猜了%d次猜了出来\n", count);
    }else{
        printf("不够好，猜了%d次才猜了出来\n", count);
    }
}


void Game_guessNum2(){
    int madeNum = init();
    int count = play(madeNum);
    getScore(count);
}