//
//  main.c
//  快速排序
//
//  Created by Monstar on 16/5/13.
//  Copyright © 2016年 Monstar. All rights reserved.
//

#include <stdio.h>
int a[101] n;
void quicksort(int left,int right){
    int i,j,t,temp;
    if (left>right) {
        return;
    }
    temp = a[left];
    i = left;
    j = right;
    
    while (i != j) {
        //先从右向左找
        while (a[j]>temp && i<j) {
            j --;
        }
        while (a[i]<temp && i<j) {
            i ++;
        }
        //交换两个数组中的位置
        if (i < j) {
            t    = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //将基准数交换 开始新的循环
    a[left] = a[i];
    a[i]    = temp;
    quicksort(left, i -1);
    quicksort(i +1, right);

}
int main(int argc, const char * argv[]) {
    
    int i,j,t;
    scanf("%d",&n);
    for (i = 0; i < n; i ++) {
        scanf("%d",&a[i]);
    }
    quicksort(0, n);
    for (i = 0; i < n; i ++) {
        printf("%d",a[i]);
        
    }
    getchar();getchar();
    
    return 0;
}
