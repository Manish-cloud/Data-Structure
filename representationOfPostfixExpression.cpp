/* 
 * File:   representationOfPostfixExpressionIntoBST.cpp
 * Author: Manish
 *
 * Created on 11 January, 2019, 10:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

/*
 * 
 */
class RepresentationInBST
{
private:
    struct node
    {
        node * l;
        char data;
        node * r;
    };
    node * nn;
    node * root;
public:
    RepresentationInBST()
    {
        nn=NULL;
        root=NULL;
    }
    void create();
    void inOrderRec(node *);
    void display();
};

void RepresentationInBST::create()
{
    char arr[20];                   //Array to store Postfix Expression
    cout<<"Enter Postfix Expression : ";
    cin>>arr;
    stack <node *>s;
    int i=0;
    while(arr[i]!='\0')
    {
        nn=new node;
        nn->data=arr[i];
        nn->l=nn->r=NULL;
        if(nn->data=='+' or nn->data=='-' or nn->data=='*' or nn->data=='/')
        {
            node * temp1=NULL;
            node * temp2=NULL;
            temp1=s.top();
            s.pop();
            temp2=s.top();
            s.pop();
            
            nn->r=temp1;
            nn->l=temp2;
            s.push(nn);
        }
        else
        {
            s.push(nn);
        }
        i++;
    }
    root=nn;
}

void RepresentationInBST::inOrderRec(node * temp)
{
    if(temp!=NULL)
    {
        inOrderRec(temp->l);
        cout<<temp->data<<" ";
        inOrderRec(temp->r);
    }
}
void RepresentationInBST::display()
{
    inOrderRec(root);
    cout<<endl;
}

int main(int argc, char** argv) {
    RepresentationInBST t;
    t.create();
    t.display();
    return 0;
}