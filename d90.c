/*Write a C function which will perform an insertion to the immediate left of the K
th node in the singly linked list.*/
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
void inst_left(NODE *first,int key,int data)
{
    NODE *newnode,*temp,*prev,*var;
    var=first;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->info=data;
    temp=first;
    int count=1;
    
        while(temp!=NULL && count < key )
        {
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(temp==NULL)
        {
            printf("key is grater\n");
            
        }
        if (prev==NULL)
        {
            newnode->next=first;
            first=newnode;
        }
        else{
            prev->next=newnode;
            newnode->next=temp;
        }

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
    int key;
    int data;
    int choise;
    while(1)
    {
        printf("\n1.last\n2.key isert\n3.display\n4.exit\n");
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
                 scanf("%d",&data);
                 printf("enter the key element\n");
                 scanf("%d",&key);
                inst_left(first,key, data);
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
