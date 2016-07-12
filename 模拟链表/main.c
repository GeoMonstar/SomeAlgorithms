//
//  main.c
//  模拟链表
//
//  Created by Monstar on 16/5/17.
//  Copyright © 2016年 Monstar. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int data[101],int right[101];
    int i,n,t,len;
    //读入已有的数
    scanf("%d",&n);
    for (i = 1; i<=n; i++) {
        scanf("%d",&data[i]);
    }
    len = n;
    for (i = 1; i <n; i++) {
        if (i!=n) {
            right[i] = i + 1;
        }
        else
            right[i] = 0;
    }
    len ++;
    scanf("%d",&data[len]);
    t = 1;
    while (t!= 0) {
        if (data[right[t]]>data[len]) {//如果当前结点下一个结点的值大于待出入数
            right[len] = right[t];
            right[t]   = len;
            break;
        }
        t = right[t];
    }
    //输出链表中所以得数
    t= 1;
    while (t!= 0) {
        printf("%d",data[t]);
        t = right[t];
    }
    getchar();getchar();
    printf("Hello, World!\n");
    return 0;
}
