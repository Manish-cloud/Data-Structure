/* 
 * File:   TBT.cpp
 * Author: Manish
 *
 * Created on 21 January, 2019, 9:08 PM
 */

#include <iostream>
using namespace std;

struct node
{
    int lth;
    node * left;
    int data;
    node * right;
    int rth;
    node();
    ~node();
};

node::node()
{
    data=lth=rth=0;
    left=right=NULL;
}

node::~node()
{
    data=lth=rth=0;
    left=right=NULL;
}

class TBT
{
private:
    node * root;
    node * dummy;
public:
    TBT();
    ~TBT();
    void create();
    void inOrder();
    void preOrder();
    void postOrder();
    void display();
};

TBT::TBT()
{
    root=NULL;
    dummy=NULL;
}

TBT::~TBT()
{
    root=NULL;
    dummy=NULL;
}

void TBT::create()
{
    node * nn=NULL;
    nn=new node;
    cout<<"Enter data :";
    cin>>nn->data;
    if(root==NULL)
    {
        root=nn;
        dummy=new node;
        dummy->left=root;
        dummy->lth=1;
        root->left=root->right=dummy;
    }
    else
    {
        node * temp=root;
        node * parent=root;
        while(temp!=NULL)
        {
            parent=temp;
            if(nn->data > temp->data)
            {
                if(temp->rth)
                    temp=temp->right;
                else
                    temp=NULL;
            }
            else
            {
                if(temp->lth)
                    temp=temp->left;
                else
                    temp=NULL;
            }
        }
        if(nn->data > parent->data)
        {
            nn->right=parent->right;
            nn->left=parent;
            parent->right=nn;
            parent->rth=1;
        }
        else
        {
            nn->left=parent->left;
            nn->right=parent;
            parent->left=nn;
            parent->lth=1;
        }
    }
}

void TBT::inOrder()
{
    node * temp=NULL;
    temp=root;
    if(temp==NULL);
    else
    while(1)
    {
        while(temp->lth==1)
            temp=temp->left;        //L
        cout<<temp->data<<" ";      //V
        while(temp->rth==0)
        {
            if(temp->right==dummy)
                return ;
            else
                temp=temp->right;
            cout<<temp->data<<" ";  //V
        }
        temp=temp->right;           //R
    }
}

void TBT::preOrder()
{
    node * temp=NULL;
    temp=root;
    if(temp==NULL);
    else
    while(1)
    {
        while(temp->lth==1)
        {
            cout<<temp->data<<" ";      //V
            temp=temp->left;            //L
        }
        cout<<temp->data<<" ";
        while(temp->rth==0)
        {
            if(temp->right==dummy)
                return ;
            else
                temp=temp->right;       
        }
        temp=temp->right;               //R
    }
}

void TBT::postOrder() {
    node* tptr;
    int arr[100]; 
    int i = 0;
    tptr = root;
    while(1){
        while (tptr->rth == 1) 
        {
            arr[ i++ ] = tptr->data;
            tptr = tptr->right;
        }
        arr[ i++ ] = tptr->data;
        
        while (tptr->lth == 0) 
        {
            if(tptr->left == dummy)
            {
                do 
                {
                    i--;
                    cout << " " << arr[i];
                } while (i > 0);
                return;
            }
            tptr = tptr->left;
        }
        tptr = tptr->left;
    }
    return;
}

void TBT::display()
{
    inOrder();
    cout<<endl;
    preOrder();
    cout<<endl;
    postOrder();
    cout<<endl;
}

int main()
{
    TBT tree;
    int exit=0;
    char choice;
    do
    {
	cout<<"Enter: \n1]To add data\n2]To display\n3]To exit\nchoice=";
	cin>>choice;
        switch(choice)
        {
            case '1':
            tree.create();
            break;
            case '2':
            tree.display();
            break;
            case '3':
            exit=1;
            break;
            default :
            cout<<"Wrong Choice Entered !!!\n";
        }
    }while(exit==0);
    return 0;
}