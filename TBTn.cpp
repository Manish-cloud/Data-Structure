#include <iostream>
using namespace std;

typedef struct  node
{
public:
    int data;
    int lch;
    int rch;
    node *l,*r,*p;
}node;
node * root, *dummy;

class tbt
{
public:
    tbt()
    {
	root=NULL;
	dummy=new node;
	dummy->l=dummy->r=NULL;
	dummy->lch=dummy->rch=0;
    }
    void create();
    void inorder();
    void preorder();
    void postorder();
};

void tbt :: create()
{
    node *nn;
    nn=new node;
    cout<<"enter data";
    cin>>nn->data;
    nn->lch=nn->rch=0;
    nn->l=nn->r=NULL;

    if(root==NULL)
    {
	root=nn;
	root->l=root->r=dummy;
	dummy->l=root;
	return;
    }
    else
    {
	node *t, *p;
	t=root;
	p=NULL;
	while(t!=NULL)
	{
            p=t;
            if(nn->data<t->data)
            {
		if(t->lch==1)
		{
                    t=t->l;
		}
		else
                    t=NULL;
            }
            else
            {
		if(t->rch==1)
		{
                    t=t->r;
		}
                else
                    t=NULL;
            }

	}
	nn->p=p;
	if(nn->data<p->data)
        {
            nn->l=p->l;
            nn->r=p;
            p->lch=1;
            p->l=nn;
        }
	else
	{
            nn->r=p->r;
            nn->l=p;
            p->r=nn;
            p->rch=1;
	}
	return;
    }
 }

 void tbt :: inorder()
 {
    node *t;
    t=root;
    while (1)
    {
	while(t->lch==1)
	{
            t=t->l;
	}
	cout<<t->data<<" ";
	while(t->rch==0)
	{
            if(t->r==dummy)
            {
	 	return;
            }
            else
            {
	 	t=t->r;
	 	cout<<t->data<<" ";
            }

	}
	t=t->r;
    }
 }
void tbt::preorder()
{
    node *t;
    t=root;
    while(1)
    {
	while(t->lch==1)
	{
            cout<<t->data<<" ";
            t=t->l;
	}
	cout<<t->data<<" ";
	while(t->rch==0)
	{
            if(t->r==dummy)
            {
		return;
            }
            else
            {
		t=t->r;
            }
	}
	t=t->r;
    }
}

node *post_succ(node *t)
{
    node *prev,*t1;
    if(t->p->r==t)
        return t->p;
    else
    {
        prev=t->p;
	if(prev->rch==0)
            return prev;
	else
	{
            t=prev->r;
            while(t!=NULL)
            {
		t1=t;
		if(t->lch==1)
		{
                    t=t->l;
		}
		else if(t->rch==1)
                    t=t->r;
		else
                    t=NULL;
            }
            return t1;
	}
    }
}
void tbt::postorder()
{
    node *t,*prev;
    t=root;
    while(t!=NULL)
    {
	prev=t;
	if(t->lch==1)
	{
            t=t->l;
	}
	else
	{
            if(t->rch==1)
                t=t->r;
            else
		t=NULL;
	}
    }
    cout<<" "<<prev->data;
    t=prev;
    while(t!=root)
    {
        t=post_succ(t);
	cout<<" "<<t->data;
    }
}

 int main()
 {
	 tbt t;
	 int ch;

	 do
	 {
	 cout<<"********MENU************\n";
	 cout<<"1.create\n";
	 cout<<"2.inorder\n";
	 cout<<"3.preorder\n";
	 cout<<"4.postorder\n";
	 cout<<"************************\n";
	 cin>>ch;


	 switch(ch)
	 {
	 case 1:
		 	 t.create();
		 	 break;
	 case 2:cout<<"Inorder Data";
		 	 t.inorder();
		 	 break;
	 case 3:cout<<"Preorder Data";
		     t.preorder();
		     break;
	 case 4:cout<<"Postorder Data";
	 	     t.postorder();
	         break;
	 default:
		 cout<<" wrong choice";
		 break;
	 }
cout<<"\n";
	 }while(ch==1 || ch==2|| ch==3||ch==4);
 }

