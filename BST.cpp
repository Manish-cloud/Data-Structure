/* 
 * File:   BST.cpp
 * Author: Manish
 *
 * Created on 21 January, 2019, 9:02 PM
 */

#include<iostream>
using namespace std;

struct node
{
    node * left;
    string word;
    string meaning;
    node * right;
    node();
    ~node();
};

node::node()
{
    left=NULL;
    word.clear();
    meaning.clear();
    right=NULL;
}

node::~node()
{
    left=NULL;
    word.clear();
    meaning.clear();
    right=NULL;
}

class Dictionary
{
private:
    node * root;
public:
    Dictionary();
    ~Dictionary();
    void create();
    void inOrderRec(node *);
    void preOrderRec(node *);
    void postOrderRec(node *);
    void display();
    node * search();
    void modifyDictionary();
    void deleteWord();
    void findMaxInLeftSubtreeAndDeleteNode(node *);         
};

Dictionary::Dictionary()
{
    root=NULL;
}

Dictionary::~Dictionary()
{
    root=NULL;
}

void Dictionary::create()
{
    node * nn=NULL;
    nn=new node;
    cout<<"Enter word : ";
    cin>>nn->word;
    cin.ignore(100,'\n');
    cout<<"Enter meaning : ";
    getline(std::cin,nn->meaning);
    if(root==NULL)
    {
        root=nn;
    }
    else
    {
        node * temp=NULL,* parent=NULL;
	temp=root;
	while(temp!=NULL)
	{
            parent=temp;		
            if(nn->word > temp->word)
                temp=temp->right;
            else if(nn->word < temp->word)
                temp=temp->left;
            else
            {
                cout<<"Duplicate enters not allowed !!!\n";
                delete nn;
                nn=NULL;
                return;
            }
                
	}
	if(nn->word > parent->word)
            parent->right=nn;
	else
            parent->left=nn;
    }
}

void Dictionary::display()
{
    cout<<"Displaying data in InOrder traversal\n";
    inOrderRec(root);
    cout<<endl;
    cout<<"Displaying data in PreOrder traversal\n";
    preOrderRec(root);
    cout<<endl;
    cout<<"Displaying data in PostOrder traversal\n";
    postOrderRec(root);
    cout<<endl;
}

void Dictionary::inOrderRec(node * temp)
{
    if(temp!=NULL)
    {
        inOrderRec(temp->left);
	cout<<temp->word<<" : "<<temp->meaning<<endl;
	inOrderRec(temp->right);
    }
}

void Dictionary::preOrderRec(node * temp)
{
    if(temp!=NULL)
    {
	cout<<temp->word<<" : "<<temp->meaning<<endl;
	preOrderRec(temp->left);
	preOrderRec(temp->right);
    }
}

void Dictionary::postOrderRec(node * temp)
{
    if(temp!=NULL)
    {
	postOrderRec(temp->left);
	postOrderRec(temp->right);
	cout<<temp->word<<" : "<<temp->meaning<<endl;
    }
}

node * Dictionary::search()
{
    node * temp=root;
    string tempData;
    cout<<"Enter word : ";
    cin>>tempData;
    int flag=0;
    while(temp!=NULL)
    {
	if(tempData==temp->word)
        {
            flag=1;break;
        }
	else
	{
            if(tempData > temp->word)
                temp=temp->right;
            else 
                temp=temp->left;
	}            
    }
//    if(flag==1)
//        return temp;
//    else
//    {
//        temp=NULL;
//        return temp;
//    }
    return temp;
}

void Dictionary::modifyDictionary()
{
    node * x=NULL;
    x=search();
    if(x!=NULL)
    {
        cin.ignore(100,'\n');
        cout<<"Enter meaning : ";
        getline(std::cin,x->meaning);
        cout<<"Meaning updated\n";	
    }
    else
        cout<<"Word not Found!!!\n";
}

void Dictionary::findMaxInLeftSubtreeAndDeleteNode(node * temp)
{
    node * t;
    node *p;
    t=p=temp;
    t=t->left;
    while(t->right)
    {
        p=t;
        t=t->right;
    }
    if(p==temp)
    {
        temp->word=t->word;
        temp->meaning=t->meaning;
        temp->left=t->left;
        delete t;
        t=NULL;
    }
    else
    {
        temp->word=t->word;
        temp->meaning=t->meaning;  
        p->right=t->left;
        delete t;
        t=NULL;
    }
}

void Dictionary::deleteWord()
{
    node * temp=root;
    node * parent=NULL;
    string tempData;
    cout<<"Enter word : ";
    cin>>tempData;
    int flag=0;
    parent=temp;
    while(temp!=NULL)
    {	
	if(tempData==temp->word)
	{
            flag=1;
            break;
	}
	else
	{
            parent=temp;
            if(tempData > temp->word)
                temp=temp->right;
            else 
                temp=temp->left;	
        }	
    }
    if(flag==1)
    {      
        if(temp->left==NULL and temp->right==NULL)		//leaf node deletion
        {
            if(temp==root)
            {
		delete root;
		root=NULL;            
            }
            else
            {
                if(temp->word > parent->word)
                    parent->right=NULL;
		else
                    parent->left=NULL;
	    	delete temp;
            	temp=NULL;
            }
	}
	else if(temp->left==NULL and temp->right!=NULL)
	{
            if(temp==root)
		root=temp->right;
            else
            {
		if(temp->word > parent->word)
		    parent->right=temp->right;
		else
		    parent->left=temp->right;
            }
            delete temp;
            temp=NULL;
	}
        else if(temp->left!=NULL and temp->right==NULL)
	{
            if(temp==root)
                root=temp->left;
            else
            {
                if(temp->word > parent->word)
                    parent->right=temp->left;
		else
                    parent->left=temp->left;
            }
            delete temp;
            temp=NULL;
	}
	else if(temp->left!=NULL and temp->right!=NULL)       
            findMaxInLeftSubtreeAndDeleteNode(temp);
    }
    else
	cout<<"Word not found!!!\n";
}

int main()
{
    Dictionary aDictionary;
    int exit=0;
    node * x=NULL;
    char choice;
    do
    {
    	cout<<"Enter: \n1]To add word to Dictionary\n2]To display\n3]To Search\n4]To modify\n5]To delete Word\n6]To exit\nchoice=";
	cin>>choice;
	switch(choice)
	{	
            case '1':
            aDictionary.create();
            break;
            case '2':
            aDictionary.display();
            break;
            case '3':
            x=NULL;                    
            x=aDictionary.search();
            if(x!=NULL)
		cout<<"Word Found\n";
            else
		cout<<"Word not Found\n";                    
            break;
            case '4':
            aDictionary.modifyDictionary();
            break;
            case '5':
            aDictionary.deleteWord();
            break;
            case '6':
            exit=1;
            break;
            default:
            cout<<"Wrong choice Entered!!!\n"; 
	}
    }while(exit==0);
}