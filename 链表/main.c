//
//  main.c
//  链表
//
//  Created by Monstar on 16/5/13.
//  Copyright © 2016年 Monstar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

int main(int argc, const char * argv[]) {
    struct node *head,*p,*q,*t;
    int i,n,a;
    scanf("%d",&n);
    head = NULL;//头指针初始为空
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        //动态申请一个空间 用来存放一个结点 并用临时指针p指向这个结点
        p = (struct node *)malloc(sizeof(struct node));
        p->data=a;//p指针存储a的值
        
        p->next=NULL;
        
        if (head == NULL) {
            head = p;
        }else{
            q->next = p;
        }
        q=p;
    }
    //插入一个比指定数字大的数字
    t = head;//从头部开始遍历
    while (t!=NULL) {
        if (t->next->data > a)//如果当前结点下一个结点的值大于待插入数
        {
            p=(struct node *)malloc(sizeof(struct node));//动态申请一个空间,用来存放新增的结点
            p->data = a;
            p->next = t->next;  //给新增结点赋值，新增结点的后继指针指向当前结点的后继指针
            t->next = p;        //当前结点后继指针指向新增结点
            break;
        }
        t = t->next;//继续查找下一个结点
        printf("%d",t->data);
        t= t->next;//继续下一个结点
    }
    //输出链表所有的数字
    t = head;
    while (t!=NULL) {
        printf("%d",t->data);
        t= t->next;
    }
    getchar();getchar();
    return 0;
}
