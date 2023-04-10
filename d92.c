/*Write a C function to change the info field of the K
th node to the value given by X*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}NODE;
NODE *ins_last(NODE *first,int data)
{
    NODE *temp, *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->info=data;

    if(first==NULL)
    {
        first = newnode;
    }
    else
    {
        temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    return first;
}
NODE *change(NODE *first,int k,int x)
{
    NODE *temp,*newnode;
    temp=first;
    int count =1;
    while(temp!=NULL && count<k)
    {
        temp=temp->next;
        count++;
    }
    if(temp==NULL)
    {
        printf("k is greater\n");
    }
    if(temp!=NULL && count==k)
    {
       temp->info=x; 
    }
    return first;
    
}
void display(NODE *first)
{
    if (first==NULL)
    {
        printf("empty list\n");
    }
    else
    {
        while(first!=NULL)
        {
            printf("%d ",first->info);
            first=first->next;
        }
    }
}
int main()
{
    NODE *first=NULL;
    int data;
    int k;
    int x;
    int choise;
    while(1)
    {
        printf("\n1.last\n2.change\n3.display\n4.exit\n");
        printf("enter the choise\n");
        scanf("%d",&choise);
        switch(choise)
        {
            case 1: {printf("enter the data to be inserted\n");
                     scanf("%d",&data);
            first=ins_last(first,data);
            printf("%d is inserted \n",data);
            }
            break;
             case 2: 
            {
                 printf("enter the data to be inserted\n");
                 scanf("%d",&x);
                 printf("enter the key element\n");
                 scanf("%d",&k);
                first=change(first,k,x);
            }
            break;
            case 3:
            {printf("displaying the elements\n");
            display(first);
            }
            break;
            case 4:exit(0);
           // default : pritnf("the entered choise is wrong\n");
        }
    }
    return 0;
}