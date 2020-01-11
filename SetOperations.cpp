#include<iostream>
using namespace std;

class SetOperations
{
private:
    int * firstSet;
    int * secondSet;	
    int numberOfElementsInFirstSet;
    int numberOfElementsInSecondSet;
public:
    SetOperations();
    ~SetOperations();		
    int getnumberOfElementsInFirstSet();
    int getnumberOfElementsInSecondSet();
    void create();
    void display();
    void search();
    bool isElementPresent(int *,int);
    void unionOperation();
    void intersectionOperation();
    void differenceOperation();
    void subsetOperation();
};

SetOperations::SetOperations()
{
    firstSet = NULL;
    secondSet = NULL;
    numberOfElementsInFirstSet=0;
    numberOfElementsInSecondSet=0;
}

SetOperations::~SetOperations()
{
    firstSet = NULL;
    secondSet = NULL;
    numberOfElementsInFirstSet=0;
    numberOfElementsInSecondSet=0;
}

int SetOperations::getnumberOfElementsInFirstSet()
{
    return numberOfElementsInFirstSet;
}

int SetOperations::getnumberOfElementsInSecondSet()
{
    return numberOfElementsInSecondSet;
}

void SetOperations::create()
{
    cout<<"Enter number of elements in first set : ";
    cin>>numberOfElementsInFirstSet;
    firstSet = new int[numberOfElementsInFirstSet];
    cout<<"Enter elements of first set [ by providing space between two numbers ] : ";
    for(int i=0;i<numberOfElementsInFirstSet;i++)
    {
	cin>>firstSet[i];
    }	

    cout<<"Enter number of elements in second set : ";
    cin>>numberOfElementsInSecondSet;	
    secondSet = new int[numberOfElementsInSecondSet];
    cout<<"Enter elements of second set [ by providing space between two numbers ] : ";
    for(int i=0;i<numberOfElementsInSecondSet;i++)
    {
	cin>>secondSet[i];
    }
}

void SetOperations::display()
{
    cout<<"Elements of first set : ";
    for(int i=0;i<numberOfElementsInFirstSet;i++)
    {
	cout<<firstSet[i]<<" ";
    }

    cout<<"\nElements of second set : ";
    for(int i=0;i<numberOfElementsInSecondSet;i++)
    {
	cout<<secondSet[i]<<" ";
    }
}

bool SetOperations::isElementPresent(int * set , int element)       //if element is present in set it will return true, else it will return false
{
    bool flag = false;
    int numberofElementsInSet;
	
    if(set == firstSet)
	numberofElementsInSet = getnumberOfElementsInFirstSet();
    else
	numberofElementsInSet = getnumberOfElementsInSecondSet();		
	
    for(int i=0;i < numberofElementsInSet;i++)
    {
	if(element == set[i])
	{
            flag=true;
            break;
	}
    }
    return flag;
}

void SetOperations::search()
{
    char choice;
    int exit = 0;
    int element;
    do
    {
	cout<<"Enter :\n1]To perform search operation in first set\n2]To perform search operation in second set\n3]To close search operation\nchoice = ";
	cin>>choice;
	switch(choice)
	{
            case '1' :
		cout<<"Enter Element to search : ";
		cin>>element;
		if(isElementPresent(firstSet,element))
                    cout<<"Element found !!!\n";
		else
                    cout<<"Element not found !!!\n";		
            break;		
				
            case '2' :
		cout<<"Enter Element to search : ";
		cin>>element;
		if(isElementPresent(secondSet,element))
                    cout<<"Element found !!!\n";
		else
                    cout<<"Element not found !!!\n";		
            break;		
				
            case '3' :
                exit=1;
            break;
		
            default :
		cout<<"Wrong Choice Entered !!!\n";
	}	
    }while(exit == 0);
}

void SetOperations::unionOperation()
{
    create();
    cout<<"Required set elements :";
    for(int i=0;i < getnumberOfElementsInFirstSet();i++)
    {
	cout<<firstSet[i]<<" ";
    }
    for(int i=0;i < getnumberOfElementsInSecondSet();i++)
    {
	if(! (isElementPresent(firstSet,secondSet[i])) )
            cout<<secondSet[i]<<" ";		
    }
    cout<<endl;
}

void SetOperations::intersectionOperation()
{
    create();
    cout<<"Required set elements :";
    for(int i=0;i < getnumberOfElementsInFirstSet();i++)
    {
	if( isElementPresent(secondSet,firstSet[i]) )
            cout<<firstSet[i]<<" ";		
    }
    cout<<endl;
}

void SetOperations::differenceOperation()
{
    create();
    cout<<"Required set elements which are present in first set and not in second set :";
    for(int i=0;i < getnumberOfElementsInFirstSet();i++)
    {
	if( ! ( isElementPresent(secondSet,firstSet[i]) ) )
            cout<<firstSet[i]<<" ";		
    }
    cout<<endl;
	
    cout<<"Required set elements which are present in second set and not in first set :";
    for(int i=0;i < getnumberOfElementsInSecondSet();i++)
    {
	if( ! ( isElementPresent(firstSet,secondSet[i]) ) )
            cout<<secondSet[i]<<" ";		
    }
    cout<<endl;
}

void SetOperations::subsetOperation()
{
    char exitChoice='N';
    int numberOfElements;
    do
    {
	create();
	cout<<"Enter number of elements present in subset :";
	cin>>numberOfElements;
	int * subSet = new int [numberOfElements];
	cout<<"Enter elements of subset [ by providing space between two numbers ] : ";
	for(int i=0;i<numberOfElements;i++)
	{
            cin>>subSet[i];
        }
	
	int flag1=1,flag2=1;
	
	for(int i=0;i<numberOfElements;i++)
	{
            if( ! ( isElementPresent(firstSet,subSet[i]) ) )
            {
		flag1=0;
		break;
            }
	}
	
        for(int i=0;i<numberOfElements;i++)
	{
            if( ! ( isElementPresent(secondSet,subSet[i]) ) )
            {
		flag2=0;
		break;
            }
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