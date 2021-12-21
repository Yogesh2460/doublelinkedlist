#include<iostream>
using namespace std;

class kim
{
 struct node
 {
 int data;
 node *next;
 node *prev;
 };
 
public: 
node *p,*r,*temp;
kim()
{
 p=NULL;
}
void create(int num)
{
 
  if (p==NULL){
  temp=new node;
  temp->data=num;
  temp->prev=NULL;
  temp->next=NULL;
  p=temp;
}
else
{
  r=new node;
  r->data=num;
  r->next=NULL;
  r->prev=temp;
  temp->next=r;
  temp=temp->next;
}
}
void display()
{ 
 temp = p ;
   while(temp!=NULL)
   {
   cout<<temp->data<<endl;
   temp=temp->next;
  
 }
 }
 void addbeg(int num)
  {
  temp=new node;
  temp->data=num;
  temp->next=p;
  temp->prev=NULL;
  p=temp;
  p->prev=temp;
  p=temp;
  }
  
void addint(int num,int loc)
  {
    temp=p;
    r=new node;
    r->data=num;
    for(int i=0;i<loc;i++)
    {
    temp=temp->next;
    }
    r->prev=temp;
    r->next=temp->next;
    temp->next->prev=r;
    temp->next=r;
    }
    
void addend(int num)
{
    temp=p;
    r=new node;
    r->data=num;
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    r->next=NULL;
    r->prev=temp;
    temp->next=r;
    }

void del(int num)
{
  temp=p;
  r=temp->next;
   if(p->data==num)
  {
  p=p->next;
  p->prev=NULL;
  delete(temp);
  }
  
else
{
    while(r->data!=num)
    {
    temp=temp->next;
    r=r->next;
    }
    if(r->next==NULL)
    {
    temp->next=NULL;
    delete(r);
    }
    else
    {
    temp->next=r->next;
    r->next->prev=temp;
    delete(r);
    }}
    }    

    
 };
int main()
{
kim ob;
ob.create(10);
ob.create(20);
ob.create(30);
ob.addbeg(5);
ob.addint(15,1);
ob.addend(25);
ob.del(25);
ob.display();
return 0;
}
