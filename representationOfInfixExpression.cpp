#include <iostream>
//#include <stack>

#include "Stack.h"
using namespace std;

struct node
{
    node * l;
    char data;
    node * r;
    node();
};

node :: node()
{
    l=NULL;
    data=' ';
    r=NULL;
}

class RepresentationInExp
{
private:
    node * root;
public:
    RepresentationInExp()
    {
        root=NULL;
    }
    void create();
    void inOrderRec(node *);
    void preOrderRec(node *);
    void postOrderRec(node *);
    void inOrderNonRecursive();
    void preOrderNonRecursive();
    void postOrderNonRecursive();
    void display();
};

int getPrecedence(char ch)
{
    if(ch == '+' or ch =='-')
        return 1;
    if(ch == '*' or ch == '/')
	return 2;
}

void RepresentationInExp::create()
{
    node * nn;
    node * temp1;
    char arr[20];                   //Array to store infix Expression
    
    cout<<"Enter infix Expression : ";
    cin>>arr;
    
    Stack <node *> s1;				// stack for operator
    Stack <node *> s2;				// stack for operand
    
    int i=0;
    while(arr[i]!='\0')
    {
        nn=new node;
        nn->data=arr[i];
        if(nn->data=='+' or nn->data=='-' or nn->data=='*' or nn->data=='/')
        {
            if(s1.empty())
                s1.push(nn);			
            else
            {
		temp1 = s1.top();
		if(getPrecedence(temp1->data) < getPrecedence(nn->data))
                    s1.push(nn);
		else
		{
                    s1.pop();
                    s1.push(nn);
                    temp1->r = s2.top();
                    s2.pop();
                    temp1->l = s2.top();
                    s2.pop();
                    s2.push(temp1);
		}
            }
        }
        else
            s2.push(nn);
        i++;
    }

    while(!s1.empty())
    {
	temp1=s1.top();
	s1.pop();
	temp1->r = s2.top();
	s2.pop();
	temp1->l = s2.top();
	s2.pop();
	s2.push(temp1);
    }
    
    root=s2.top();
}

void RepresentationInExp::inOrderRec(node * temp)
{
    if(temp!=NULL)
    {
        inOrderRec(temp->l);
        cout<<temp->data<<" ";
        inOrderRec(temp->r);
    }
}

void RepresentationInExp::preOrderRec(node * temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        preOrderRec(temp->l);
        preOrderRec(temp->r);
    }
}

void RepresentationInExp::postOrderRec(node * temp)
{
    if(temp!=NULL)
    {
        postOrderRec(temp->l);
        postOrderRec(temp->r);
        cout<<temp->data<<" ";
    }
}

void RepresentationInExp::inOrderNonRecursive()
{
    Stack <node *> s1;
    node * temp = root;
    while(temp != NULL)
    {
        s1.push(temp);
        temp = temp->l;
    }
    while(! s1.empty())
    {
        temp = s1.top();
        s1.pop();
        cout<<temp->data<<" ";
        temp=temp->r;
        while(temp != NULL)
        {
            s1.push(temp);
            temp = temp->l;
        }
    }
}

void RepresentationInExp::preOrderNonRecursive()
{
    Stack <node *> s1;
    node * temp = root;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        s1.push(temp);
        temp = temp->l;
    }
    while(! s1.empty())
    {
        temp = s1.top();
        s1.pop();
        temp=temp->r;
        while(temp != NULL)
        {
            s1.push(temp);
            cout<<temp->data<<" ";
            temp = temp->l;
        }
    }
}

void RepresentationInExp::postOrderNonRecursive()
{
    Stack <node *>s1;
    Stack <node *>s2;
    node * temp=root;	
    
    s1.push(temp);
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->l != NULL)
            s1.push(temp->l);
        if(temp->r != NULL)
            s1.push(temp->r);
    }
    while(!s2.empty())
    {
        temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }   
}


void RepresentationInExp::display()
{
    cout<<"------------------------------------------------\n";
    cout<<"Using recursion\n";
    cout<<"------------------------------------------------\n";
    cout<<"Infix expression : ";
    inOrderRec(root);
    cout<<endl;
    cout<<"Prefix expression : ";
    preOrderRec(root);
    cout<<endl;
    cout<<"Postfix expression : ";
    postOrderRec(root);
    cout<<endl;
    cout<<"------------------------------------------------\n";
    cout<<"Using Non recursion\n";
    cout<<"------------------------------------------------\n";
    cout<<"Infix expression : ";
    inOrderNonRecursive();
    cout<<endl;
    cout<<"Prefix expression : ";
    preOrderNonRecursive();
    cout<<endl;
    cout<<"Postfix expression : ";
    postOrderNonRecursive();
    cout<<endl;
}

int main(int argc, char** argv) {
    RepresentationInExp t;
    t.create();
    t.display();
    return 0;
}