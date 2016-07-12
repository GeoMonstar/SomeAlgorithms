//
//  main.c
//  桶排序
//
//  Created by Monstar on 16/5/13.
//  Copyright © 2016年 Monstar. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int book[1001],i,j,t,n;
    for (i = 0; i <=1000; i++) {
        book[i] = 0;
    }
    scanf("%d",&n);
    for (i =1; i<=1000; i++) {
        scanf("%d".&t);
        book[t]++;//将编号为t的位置计数
    }
    //判断1000-0的数组 将出现的编号打印出来
    for (i = 1000; i>=0; i--) {
        for (j = 1; j<=book[i]; j ++) {
            printf("%d",i);
        }
    }
    getchar(),getchar();

    return 0;
}
