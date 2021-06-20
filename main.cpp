#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include "Queue.h"

using namespace std;

struct node *root=NULL;

void Tcreate()
{
    struct node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);

    cout<<"Enter root value :\t";
    cin>>x;
    root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->left=root->right=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        cout<<"enter left child of "<<p->data<<": \t";
        cin>>x;
        if(x!=-1){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->left=t->right=NULL;
            p->left=t;
            enqueue(&q,t);
        }
        cout<<"enter right child of "<<p->data<<": \t";
        cin>>x;
        if(x!=-1){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->left=t->right=NULL;
            p->right=t;
            enqueue(&q,t);
        }
    }
}

void preOrder(struct node *p){
if(p)
   {
       cout<<p->data<<"\t";
       preOrder(p->left);
       preOrder(p->right);
   }
}

void inOrder(struct node *p){
if(p)
   {
       preOrder(p->left);
       cout<<p->data<<"\t";
       preOrder(p->right);
   }
}

void postOrder(struct node *p){
if(p)
   {
       preOrder(p->left);
       preOrder(p->right);
       cout<<p->data<<"\t";
   }
}

int count(struct node *p)
{
    if(p)
    {
        return count(p->left)+count(p->right)+1;
    }
    return 0;
}

int height(struct node *p)
{
    int x=0, y=0;
    if(p==0)
        return 0;
    x=height(p->left);
    y=height(p->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    Tcreate();

    cout<<"\n\nHEIGHT of the tree: "<<height(root);

    cout<<"\n\nCOUNT of nodes in tree: "<<count(root);

    cout<<"\n\nPREORDER is of the form: \t";
    preOrder(root);

    cout<<"\n\nINORDER is of the form: \t";
    inOrder(root);

    cout<<"\n\nPOSTORDER is of the form: \t";
    postOrder(root);

    cout<<"\n\n";

    return 0;
}
