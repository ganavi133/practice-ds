/*. Write a C function to count the number of nodes' 
in a singly linked list..*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}NODE;
NODE *ins_last(NODE *first,int data)
{
    int count =0;
    NODE *temp, *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->info=data;

    if(first==NULL)
    {
        first = newnode;
        count++;
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
        count++;
    }
    return first;
}
void display(NODE *first)
{
    int count =0;
    if (first==NULL)
    {
        printf("empty list\n");
    }
    else
    {
        while(first!=NULL)
        {
            printf("%d ",first->info);
            count++;
            first=first->next; 
        }
    }
    printf("\nnumber of nodes %d\n",count);
}
int main()
{
    NODE *first=NULL;
    int key;
    int data;
    int choise;
    while(1)
    {
        printf("\n1.last\n2.display\n4.exit\n");
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