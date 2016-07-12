//
//  main.c
//  深度搜索
//
//  Created by Monstar on 16/5/17.
//  Copyright © 2016年 Monstar. All rights reserved.
//
#include <stdio.h>
int a[10],book[10],n;
//c语言的全局变量在没有赋值以前默认为0 因此这里的book数组无需全部再次赋初始值
void dfs(int step)//step表示现在在第几个盒子面前
{
    int i;
    if (step == n+1)
    {
        //输出一种排列
        for (i = 1; i<=n; i++) {
            printf("%d",a[i]);
            printf("\n");
        }
        return;
    }
    //站在第steo个盒子面前 应该放哪张牌？ 按照1 2 3的顺序一一尝试
    for (i = 1; i<=n; i++) {
        //判断扑克牌i是否还在手上
        if (book[i] == 0){
            //开始尝试使用扑克牌i
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return;
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    dfs(1);//首先站在1号小盒子面前
    getchar();getchar();
    printf("Hello, World!\n");
    return 0;
}
