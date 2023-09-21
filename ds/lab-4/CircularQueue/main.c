/* WRITE DISPLAY FUNCTION*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void cenq(int *arr,int *pfront, int *prear, int item){
    if((*prear==MAX-1&&*pfront==0)||(*prear+1==*pfront)){
        printf("Queue is full\n");
        return;
    }
    if (*prear==MAX-1)
        *prear=0;   // giving the circular queue its "circularity" from the rear
    else
        *prear++;
    arr[*prear]=item;   //regular case enqueue

    if(*pfront==-1)
        *pfront=0;  // giving the circular queue its "circularity" from the front
}

int cdeq(int *arr, int *pfront, int *prear){
    int data;
    if (*pfront==-1){
        printf("Queue is full\n");
        return NULL;
    data=arr[*pfront];
    arr[*pfront]=0;
    if (*prear==*pfront){
        *pfront=*prear=-1;
        }
    }
    else{
        if (*pfront == MAX-1)
            *pfront=0;
        else
            *pfront++;
    }
    return data;
    }


void main()
{
    int arr[MAX];
    int i, front, rear,item;
    front =rear=-1;
    for (i=0;i<MAX;i++)
        arr[i]=0;

    int d;
    printf("1 for Enqueue");
    printf("2 for Dequeue");
    printf("-1 to exit");

    cenq(arr,&front,&rear,22);
    cenq(arr,&front,&rear,17);
    i=cdeq(arr,&front,&rear);
    if (i!=NULL){
        printf("Item deleted %d\n",i);
    }
    for(i=front;i<rear;i++)
        printf("%d\t", arr[i]);
}
