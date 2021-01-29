#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
struct node * next;          
};
struct node *sp=NULL;
void main()
{
void push(int);       //function prototype
void pop();
int search(int);
int opt,x,ans;
void display();
do
{
printf("\n1.Insert\n 2.Delete\n 3.Search\n 4.Display\n 5.Exit\n");
printf("Option :");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter the value:");     
scanf("%d",&x);                      //value to be insert is stored in 'x'
push(x);                             //'x' is passed as argument in function push()
break; 
case 2:pop();
break;
case 3:printf("Enter a value to be searched:");
scanf("%d",&x);                     //value to be search is stored in 'x'
ans=search(x);                      //return value of the function search() is stored in 'ans'
if(!ans) printf("Not Found");       //if ans=0 then print not found
else printf("Found");               //if ans=1 then print found
break;
case 4:display();
break;
case 5:exit(0);                     //exit the program
break;
}
}while(1);                          //infinit loop
}
void display()                 //function to display the elements in the list
{
struct node *sp1=sp;           
if(sp1==NULL)                 //if stack points to null then print stack is empty
printf("Stack is empty.");
else
while(sp1!=NULL)               //loop works untill the stack points to null
{
printf(" %d ",sp1->key);      // print the value in the stack
sp1=sp1->next;                //pointer point to the next node
}
}
void push(int x)                //function to insert elements into the stack
{
struct node *t;
t=(struct node*)malloc(sizeof(struct node));    //memory is allocated for variable t
t->key=x;                                       //value to be inserted is entered in t
t->next=sp;                                     //t points to sp          
sp=t;                                           //forms new sp
}
void pop()                       //fuction to delete elements from the stack
{
int t;
struct node *p;
if(sp!=(struct node *)0)        //if the stack pointer is not null 
{
p=sp;                           //stack pointer is assigned to 'p'
sp=sp->next;                    //stack pointer is incremented
printf("%d is deleted",p->key);
free(p);                        //'p' is deleted                   
}
else printf("Stack is empty");
}
int search(int x)         //function to search an element from the stack
{
struct node *sp1=sp;
while(sp1!=NULL && sp1->key!=x)   //the loop works until stack pointer points to null or stack pointer points to the 'x'
sp1=sp1->next;                    //stack pointer is incremented
if(sp1==(struct node *)0)         //if stack pointer points to null then return 0
return 0;  //Not Found
else                              //else return 1
return 1;  //Found
}
