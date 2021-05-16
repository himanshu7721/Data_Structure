//DOUBLY LINKED LIST
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    struct node *temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    if(head==NULL)
    {
        ptr->next=NULL;
        ptr->prev=NULL;
        head=ptr;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;
        ptr->next=NULL;
    }
}
void insertatfront()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    if(head==NULL)
    {
        ptr->next=NULL;
        ptr->prev=NULL;
        head=ptr;
    }
    else
    {
        head->prev=ptr;
        ptr->prev=NULL;
        ptr->next=head;
        head=ptr;
    }
}

void randominsert()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int loc;
    scanf("%d",&loc);
    
    scanf("%d",&ptr->data);
    struct node *temp;
    int i;
    temp=head;
    for(i=0;i<loc;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Can't insert\n");
            break;
        }
    }
    ptr->prev=temp;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    temp->next=ptr;
    
    
}

void deleteatfirst()
{
   struct node *temp;
   temp=head;
   if(head==NULL)
   {
       printf("nothing to delete\n");
   }
   else if(head->next==NULL)
   {
       head=NULL;
       free(temp);
   }
   else
   {
       head=temp->next;
       head->prev=NULL;
       temp->next=NULL;
       free(temp);
   }
}

void deleteatend()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("nothing to print\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        temp->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
     
}

void deleterandom()
{
    int item;
    scanf("%d",&item);
    struct node *temp,*ptr;
    temp=head;
    if(head==NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
      
       while(temp->data!=item)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("can't\n");
            break;
        }
    }
    if(temp->next==NULL)
    {
        printf("Nothing to delete\n");
        
    }
    else if(temp->next->next==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        ptr=temp->next;
        temp->next=ptr->next;
        
        ptr->next->prev=temp;
        free(ptr);
    }
    
    
    
    }
}

void search()
{
       struct node *temp;
       temp=head;
       int item;
       scanf("%d",&item);
       if(temp==NULL)
       {
           printf("Nothing to search\n");
       }
       else
       {
           int flag=0;
           int i=0;
          while(temp!=NULL)
          {
              
              if(temp->data==item)
              {
                  printf("element found at %d",i+1);
             flag=1;
              }
              i++;
              temp=temp->next;
          }
          if(flag==0)
          {
              printf("Can't find\n");
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
    printf("\n");
}
