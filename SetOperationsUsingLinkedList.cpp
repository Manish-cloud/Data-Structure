/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
using namespace std;
struct setElement
{
    int element;
    setElement * nextElement;
    setElement();
    ~setElement();
};

setElement::setElement()
{
    element = 0;
    nextElement = NULL;
}

setElement::~setElement()
{
    element = 0;
    nextElement = NULL;
}

class SetOperations
{
private:
    setElement * firstSet;
    setElement * secondSet;	
public:
    SetOperations();
    ~SetOperations();		
    void create();
    void display();
    bool isElementPresent(setElement *,int);
    void unionOperation();
    void intersectionOperation();
    void differenceOperation();
    void subsetOperation();
};

SetOperations::SetOperations()
{
    firstSet = NULL;
    secondSet = NULL;
}

SetOperations::~SetOperations()
{
    firstSet = NULL;
    secondSet = NULL;
}

void SetOperations::create()
{
    setElement * nn;
    setElement * temp;
    char ch;
    if(firstSet!=NULL)
        firstSet=NULL;
    if(secondSet!=NULL)
        secondSet=NULL;
    do
    {   
        cout<<"Enter elements of first set : ";
        nn = new setElement;
        cin>>nn->element;
        if(firstSet == NULL)
            firstSet=nn;
        else
        {
            temp=firstSet;
            while(temp->nextElement!=NULL)
                temp=temp->nextElement;
            temp->nextElement=nn;
        }
        cout<<"Do you want to add more element to first set [Y/N] : ";
        cin>>ch;
    }while(ch=='Y' or ch=='y');	

    do
    {   
        cout<<"Enter elements of second set : ";
        nn = new setElement;
        cin>>nn->element;
        if(secondSet == NULL)
            secondSet=nn;
        else
        {
            temp=secondSet;
            while(temp->nextElement!=NULL)
                temp=temp->nextElement;
            temp->nextElement=nn;
        }
        cout<<"Do you want to add more element to second set [Y/N] : ";
        cin>>ch;
    }while(ch=='Y' or ch=='y');
}

void SetOperations::display()
{
    setElement * temp;
    
    cout<<"Elements of first set : ";
    temp=firstSet;
    while(temp!=NULL)
    {
        cout<<temp->element<<" ";
        temp=temp->nextElement;
    }
    cout<<"\nElements of second set : ";
    temp=secondSet;
    while(temp!=NULL)
    {
        cout<<temp->element<<" ";
        temp=temp->nextElement;
    }
}

bool SetOperations::isElementPresent(setElement * set , int element)       //if element is present in set it will return true, else it will return false
{
    bool flag = false;
    
    while(set!=NULL)
    {
        if(set->element==element)
        {
            flag=true;
            break;
        }
        set=set->nextElement;
    }
    return flag;
}

void SetOperations::unionOperation()
{
    setElement * set;
    
    create();
    cout<<"Required set elements :";
    set=firstSet;
    while(set!=NULL)
    {
        cout<<set->element<<" ";
        set=set->nextElement;
    }
    set=secondSet;
    while(set!=NULL)
    {
        if(!(isElementPresent(firstSet,set->element)))
            cout<<set->element<<" ";
        set=set->nextElement;
    }
    cout<<endl;
}

void SetOperations::intersectionOperation()
{
    setElement * set;
    
    create();
    cout<<"Required set elements :";
    set = firstSet;
    while(set!=NULL)
    {
        if(isElementPresent(secondSet,set->element))
            cout<<set->element<<" ";
        set=set->nextElement;
    }
    cout<<endl;
}

void SetOperations::differenceOperation()
{
    setElement * set;
    
    create();
    cout<<"Required set elements which are present in first set and not in second set :";
    set = firstSet;
    while(set!=NULL)
    {
        if(!(isElementPresent(secondSet,set->element)))
            cout<<set->element<<" ";
        set=set->nextElement;
    }
    cout<<endl;
	
    cout<<"Required set elements which are present in second set and not in first set :";
    set = secondSet;
    while(set!=NULL)
    {
        if(!(isElementPresent(firstSet,set->element)))
            cout<<set->element<<" ";
        set=set->nextElement;
    }
    cout<<endl;
}

void SetOperations::subsetOperation()
{
    char exitChoice='N';
    setElement * nn,* temp;
    setElement * subSet;
    setElement * set;
    char ch;
    
    do
    {
    	create();
        subSet=NULL;
	do
        {   
            cout<<"Enter elements of subSet : ";
            nn = new setElement;
            cin>>nn->element;
            if(subSet == NULL)
                subSet=nn;
            else
            {
                temp=subSet;
                while(temp->nextElement!=NULL)
                    temp=temp->nextElement;
                temp->nextElement=nn;
            }
            cout<<"Do you want to add more element to subSet [Y/N] : ";
            cin>>ch;
        }while(ch=='Y' or ch=='y');	
        int flag1=1,flag2=1;
	
        set = subSet;
        while(set!=NULL)
        {
            if(!(isElementPresent(firstSet,set->element)))
            {
                flag1=0;
                break;
            }
            set=set->nextElement;
        }
        set = subSet;
        while(set!=NULL)
        {
            if(!(isElementPresent(secondSet,set->element)))
            {
                flag2=0;
                break;
            }
            set=set->nextElement;
        }

	if( flag1 and flag2 )
            cout<<"Given set is subset of both set\n";	
        else if(flag1)
            cout<<"Given set is subset of first set\n";
	else if(flag2)
            cout<<"Given set is subset of second set\n";
        else
            cout<<"Given set is not an subset of any set\n";		

	cout<<"Do you want to continue ? [Y/N] :";
	cin>>exitChoice;
    }while( exitChoice == 'Y' or exitChoice == 'y' );
}

int main()
{
    SetOperations aSet;
    char choice;	
    char exitChoice='N';
    do
    {
	cout<<"Enter:\n1]To perform union operation\n2]To perform intersection operation\n3]To perform difference operation\n4]To perform subset operation\n5]To exit\nchoice = ";
	cin>>choice;
	switch(choice)
	{
            case '1' :
		aSet.unionOperation();
            break;
            case '2':
		aSet.intersectionOperation();
            break;
            case '3':
		aSet.differenceOperation();
            break;
            case '4':
                aSet.subsetOperation();
            break;
            case '5':
		exitChoice = 'Y';
            break;
            default:
		cout<<"Wrong choice entered !!!\n";
            break;		
	}
    }while(exitChoice == 'N');
}