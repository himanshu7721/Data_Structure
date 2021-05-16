#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertatend();
void display();
void insertatfront();
void randominsert();
void deleteatfirst();
void deleteatend();
void deleterandom();
void search();

struct node *head;
int main() {
   
int n=0;
while(n!=9)
{
scanf("%d",&n);
switch(n)
{
case 1:
insertatend();
break;
case 2:
insertatfront();
break;

case 3:
randominsert();
break;
case 4:
deleteatfirst();
break;
case 5:
deleteatend();
break;
case 6:
deleterandom();
break;
case 7:
search();
break;
case 8:
display();
break;

case 9:
exit(0);
break;
default:
printf("Enter anything\n");
}
}
	return 0;
}
void insertatend()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    if(head==NULL)
    {
        ptr->next=NULL;
        head=ptr;
            printf("Element inserted\n");
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        
        }
        temp->next=ptr;
        ptr->next=NULL;
            printf("Element inserted\n");
    }
    
}
void insertatfront()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    ptr->next=head;
    head=ptr;
}

void randominsert()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    int loc;
    scanf("%d",&loc);
    struct node *temp;
    temp=head;
    int i;
    for(i=0;i<loc;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("can't insert\n");
            break;
        }
    }
    ptr->next=temp->next;
    temp->next=ptr;
    
}

void deleteatfirst()
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        head=ptr->next;
        ptr=NULL;
        free(ptr);
    }
}

void deleteatend()
{
    struct node *ptr;
    if(head==NULL)
    printf("List is empty\n");
    else if(head->next==NULL)
    {
        ptr=head;
        head=head->next;
        free(ptr);
    }
    else
    {
        struct node *ptr1;
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
    }
}

void deleterandom()
{
    int loc;
    scanf("%d",&loc);
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
    struct node *ptr;
    ptr=head;
    struct node *ptr1;
    for(int i=0;i<loc;i++)
    {
        ptr=ptr->next;
        ptr1=ptr->next;
        if(ptr==NULL)
        {
            printf("can't\n");
            break;
        }
    }
    ptr->next=ptr1->next;
    free(ptr1);
    
    }
    
}

void search()
{
    struct node *ptr;
    ptr=head;
    int i=0;
    if(ptr==NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        int item;
        scanf("%d",&item);
        int flag=0;
        while(ptr!=NULL)
        {
            if(ptr->data==item)
            {
                printf("%d is found at %d\n",item,i+1);
                flag=1;
            }
            ptr=ptr->next;
            i++;
        }
        if(flag==0)
        {
            printf("Elemet not found\n");
        }
    }
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
