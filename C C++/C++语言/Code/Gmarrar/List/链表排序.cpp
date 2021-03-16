/*输入四位同学的学号和成绩，可以按学号的顺序排序*/
#include <stdio.h>
#include <stdlib.h>
#define SNUM 4
struct student
{
    long num;
    int score;
    struct student *next;
};

/*接受一堆数据，进行排序，最后串成一个链表*/ 
struct student *sort(struct student *head)
{
    int i,j,score[SNUM],ts;
    long num[SNUM],y;
    struct student *p1;
    p1=head;
    /*输入数据*/ 
    for(i=0;i<SNUM;i++){
        scanf("%ld %d",&num[i],&score[i]);     
    }
    
    /*对输入的数据进行排序*/ 
    for(i=0;i<SNUM-1;i++){                     
        for(j=1;j<SNUM-i;j++){
            if(num[j-1]>num[j]){               
                t=num[j-1];
                num[j-1]=num[j];
                num[j]=t;
                ts=score[j-1];
                score[j-1]=score[j];
                score[j]=ts;
            }
        }
    }
    
    /*建立链表*/
    for(i=0;i<SNUM;i++){
        p1->num=num[i];                        //p1指向第一个num and score
        p1->score=score[i];
        p1->next=(struct student*)malloc(sizeof(struct student));      
        p1=p1->next;                           //使p1指向下一个成员数据
    }
    p1->next=NULL;
    return head;
}

int main()
{
    struct student *head=(struct student*)malloc(sizeof(struct student)),*p1;
    p1=sort(head);
    printf("\n");
    while(p1->next!=NULL){
        printf("学号为:%ld    成绩为:%d\n",p1->num,p1->score);
        p1=p1->next;
    }
    return 0;
}
