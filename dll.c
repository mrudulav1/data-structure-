#include<stdio.h>
#include<stdlib.h>
struct node *L=0,*t;
struct node                   
{
int key;
struct node *prev,*next;
};
void main()
{
struct node * insertdll(struct node *,int);                       //functions are declared
struct node * deletedll(struct node *,struct node *);
struct node * search(struct node *,int);
void display(struct node *);
int opt,key;
do
{
printf("\n 1.Insert\n 2.Delete\n 3.Search\n 4.Display\n 5.Exit\n");
printf("Option :");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Data : ");
scanf("%d",&key);                                         //data to be inserted is stored in 'key'
L=insertdll(L,key);                              //return of function insertdll()is stored in L
break;
case 2:printf("Data : ");
scanf("%d",&key);                           //data to be deleted is stored in 'key'
t=search(L,key);                            //index of 'key' is stored in t
if(t!=(struct node *)0)                     
L=deletedll(L,t);               
else printf("Not Found\n");
break;
case 3:printf("Data : ");
scanf("%d",&key);
t=search(L,key);
if(t==(struct node *)0)
printf("Not Found");
else printf("Found");
break;
case 4:display(L);
break;
case 5:exit(0);
break;
}
}while(1);
}
//function to insert value into the list
struct node * insertdll(struct node *L1,int k)
{
struct node *x;            
x=(struct node *)malloc(sizeof(struct node));      //memory is allocated for variable 'x'
x->key=k;                                          //data is stored in x
x->next=L;                                         //x node pointer next points to L
x->prev=(struct node *)0;                          //x node pointer prev points to NULL
if(L!=(struct node *)0)                            //if L is not equal to NULL then x is assigned to L-prev
L->prev=x;
L=x;                                               //x is assigned as new L
return L;
}
//function to display the list
void display(struct node *L1)
{
while(L1!=(struct node *)0){                       //loop continues untill L1 points to NULL                
printf(" %d ",L1->key);                            //print data of the node L1
L1=L1->next;                                       //L1-next is assigned to  L1
}
}
//function to search an element from the list
struct node * search(struct node *L1,int key1)
{
while(L1!=(struct node *)0 && L1->key!=key1)       //loop continues until L1 points to null or searched value is found
L1=L1->next;                                       //L1-next is assigned to L1
return L1;
}
//function to delete an element from the list
struct node * deletedll(struct node *L1,struct node *x)
{
if(x->prev!=(struct node *)0)                     //if prev of node x is not NULL then 
x->prev->next=x->next;                            //next of prev of node x is assigned as next of node x     
else
L1=L1->next;                                      
if(x->next!=(struct node *)0)
x->next->prev=x->prev;
return L1;
}
