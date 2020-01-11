/* 
 * File:   SymbolTable.cpp
 * Author: Manish
 *
 * Created on 17 February, 2019, 1:09 PM
 */

#include<iostream>
#include<iomanip>
#define SIZE 10
using namespace std;

struct Symbol
{
    string name;
    string type;
    int intialValue;
    int lineNumber[SIZE];
    int count;
    Symbol * next;
    Symbol();
    ~Symbol();
};

Symbol::Symbol()
{
    name.clear();
    type.clear();
    intialValue=0;
    count=0;
    next = NULL;
}

Symbol::~Symbol()
{
    name.clear();
    type.clear();
    intialValue=0;
    count=0;
    next = NULL;
}

class SymbolTable
{
private:
    Symbol * header;
public:
    SymbolTable();
    ~SymbolTable();
    void create();
    void display();
    void search();
    void modify();
    void deleteSymbol();
};

SymbolTable::SymbolTable()
{
    header = NULL;
}

SymbolTable::~SymbolTable()
{
    header = NULL;
}

void SymbolTable::create()
{
    int i=0;
    char choice1,choice2;	
    Symbol * nn;
    do
    {	
	nn = new Symbol;
	cout << "Enter identifer name : " ;
	cin >> nn->name;
	cout << "Enter Type of identifer : " ;
	cin >> nn->type;
	cout << "Enter intial value of identifier : " ;
	cin >> nn->intialValue;
	i=0;
	do
	{	
            cout << "Enter line number at which identifer is present : " ;
            cin >> nn->lineNumber[i] ;
            i++;
            cout << "Is there any another line at which identifier is present [Y/N] ? : " ;
            cin>>choice1;
	}while(choice1 == 'y' or choice1 == 'Y');
	nn->count = i; 

	if(header == NULL)
            header = nn;
	else
	{
            Symbol * temp = header;
            while(temp -> next != NULL)
		temp = temp -> next;
            temp -> next = nn;
	}
	cout << "Do you want to add another symbol [Y/N] ? : " ;
	cin>>choice2;
    }while(choice2 == 'y' or choice2 == 'Y');
}

void SymbolTable::display()
{
    Symbol * temp=header;
    cout<<"--------------------------------------------------------------------------------------------\n";
    cout<<setw(15)<<"Name"<<setw(15)<<"Type"<<setw(20)<<"Intial value"<<setw(15)<<"count"<<setw(20)<<"line number\n";
    cout<<"--------------------------------------------------------------------------------------------\n";
    while(temp!=NULL)
    {
	cout<<setw(15)<<temp->name<<setw(15)<<temp->type<<setw(20)<<temp->intialValue<<setw(15)<<temp->count<<setw(10);
	for(int i=0;i < temp->count;i++)
            cout<<temp->lineNumber[i]<<" ";
        cout<<endl;
	temp=temp->next;
    }
}

void SymbolTable::search()
{
    int flag=0;	
    Symbol * temp=header;
    string tempIdentiferName;
    if(header == NULL)
    {
        cout<<"SymbolTable is Empty!!!\n";
        return;
    }
            
    cout<<"Enter identifer name to search : ";
    cin>>tempIdentiferName;
    while(temp != NULL)
    {
        if(temp->name == tempIdentiferName)
        {
            flag=1;
            break;
        }
        temp = temp->next;
    }

    if(flag == 1)
        cout<<"Identifer Found !!!\n";
    else
        cout<<"Indentifer not found !!!\n";
    
    return;
}

void SymbolTable::modify()
{
    int flag=0;	
    char choice1;
    Symbol * temp=header;
    string tempIdentiferName;
    if(header == NULL)
    {
        cout<<"SymbolTable is Empty!!!\n";
        return;
    }
            
    cout<<"Enter identifer name to modify : ";
    cin>>tempIdentiferName;
    while(temp != NULL)
    {
        if(temp->name == tempIdentiferName)
        {
            cout << "Enter identifer name : " ;
            cin >> temp->name;
	    cout << "Enter Type of identifer : " ;
	    cin >> temp->type;
	    cout << "Enter intial value of identifier : " ;
	    cin >> temp->intialValue;
	    int i=0;
	    do
	    {	
	        cout << "Enter line number at which identifer is present : " ;
	        cin >> temp->lineNumber[i] ;
	        i++;
	        cout << "Is there any another line at which identifier is present [Y/N] ? : " ;
	        cin>>choice1;
	    }while(choice1 == 'y' or choice1 == 'Y');
	    temp->count = i; 

            flag=1;
            break;
        }
        temp = temp->next;
    }

    if(flag == 1)
        cout<<"Modify Operation Done Successfully !!!\n";
    else
        cout<<"Indentifer not found !!!\n";
    return;
}

void SymbolTable::deleteSymbol()
{
    Symbol * temp=header;
    Symbol * prevNode;
    string tempIdentiferName;
    int flag = 0;
    if(header == NULL)
    {
        cout<<"SymbolTable is Empty!!!\n";
        return;
    }
            
    cout<<"Enter identifer name to delete : ";
    cin>>tempIdentiferName;

    while(temp != NULL)
    {
        if(temp->name == tempIdentiferName)
        {
            flag=1;
            break;
        }
        prevNode = temp;
        temp = temp->next;
    }

    if(flag == 1)        
    {
        if(temp==header)
            header = temp->next;
        else
            prevNode->next = temp->next;
        
        delete temp;
        temp=NULL;
        cout<<"Delete Operation Done Successfully !!!\n";
    }
    else
        cout<<"Indentifer not found !!!\n";
}

int main()
{
    SymbolTable obj;
    char choice;
    int exit=0;		
    do
    {
        cout<<"\nEnter:\n1]To create\n2]To display\n3]To search\n4]To modify\n5]To delete\n6]To exit\nchoice =";
	cin>>choice;
	switch(choice)
	{
            case '1':
		obj.create();
		break;
            case '2':
                obj.display();
		break;
            case '3':
                obj.search();
		break;
            case '4':
                obj.modify();
		break;
            case '5':
                obj.deleteSymbol();
		break;
            case '6':
		exit=1;
		break;
            default :
                cout<<"Wrong choice entered !!!\n";
		break;	
	}
    }while(exit==0);
    return 0;
}

