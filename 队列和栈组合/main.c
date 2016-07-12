//
//  main.c
//  队列和栈组合
//
//  Created by Monstar on 16/5/13.
//  Copyright © 2016年 Monstar. All rights reserved.
//

#include <stdio.h>
struct queue{
    int data[1000];
    int head;
    int tail;
};
struct stack{
    int data[10];
    int top;
};
int main(int argc, const char * argv[]) {
    struct queue q1,q2;
    struct stack s;
    int i,t;
    int book[10];
    
    q1.head = 1; q1.tail = 1;
    
    q2.head = 1; q2.tail = 1;
   
    s.top   = 0;
    //初始化用来标记的数组，用来标记那些牌已经在桌上
    for (i = 1; i < 9; i ++) {
        book[i] = 0;
    }
    
    for (i=1; i<=6; i++) {
        scanf("%d",&q1.data[q1.tail]);//读入一个数到队尾
        q1.tail ++;//队尾往后挪一位
        
    }
    for (int i =1; i<=6; i++) {
        scanf("%d",&q2.data[q2.tail]);
        q2.tail ++;
    }
    
    while (q1.head<q1.tail && q2.head<q2.tail) {
       t = q1.data[q1.head];//小哼出一张牌
        if (book[t] == 0) {
            q1.head++;
            s.top++
            s.data[s.top] = t;
            book[t]=1;
        }else{
         //小哼此轮可以赢牌
            q1.head ++;//小哼已经打出一张牌
            q1.data[q1.tail] = t;//紧接着把打出的牌放到手中牌的末尾
            q1.tail ++;
            while (s.data[s.top]!=t)//
            {
                book[s.data[s.top]]=0;//取消标记
                q1.data[q1.tail] = s.data[s.top];//依次放入队尾
                q1.tail ++;
                s.top --;
            }
        }
        t=q2.data[q2.head]; //小哈出一张牌
        //判断小哈当前打出的牌是否能赢牌
        if (book[t] == 0) {
            //小哈此轮没有赢牌
            q2.head ++;
            s.top++;
            s.data[s.top] = t;
            book[t]=1;
        }
        else{
            //小哈此轮可以赢牌
            q2.head ++;
            q2.data[q2.tail] = t;
            q2.tail ++;
            while (s.data[s.top]!=t) {
                book[s.data[s.top]]=0;//取消标记
                q2.data[q2.tail] = s.data[s.top];//依次放入队尾
                q2.tail++;
                s.top--;
            }
        }
    }
    if (q2.head == q2.tail) {
        printf("小哼win/n");
        if (s.top>0) {//桌上有牌
        }
        else
            printf("\n桌上已经没有牌了");
    }
    else{
        printf("小哈win");
        printf("小哈当前手中的牌是");
        for (i=q2.head; i<=q2.tail-1; i++) {
            printf("%d",q2.data[i]);
        }
        if(s.top>0){
            for (i=1; i<=s.top; i++) {
                printf("%d",s.data[i]);
            }
        }else{
            printf("桌上没有牌了");
        }
    }
    return 0;
}
