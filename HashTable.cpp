/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include<iomanip>
#define SIZE 10
using namespace std;

struct Hash
{
    long mobileNumber;
    string name;
    string company;
    Hash();
};

Hash::Hash()
{
    mobileNumber=0;
    name="-------------";
    company="-------------";
}

class TelephoneDirectory
{
private:
    Hash hashTable[SIZE];
public:
//    TelephoneDirectory();
//    ~TelephoneDirectory();	
    int hashFunction(long);	
    void insert();
    void display();
    void search();
    void deleteData();
};

//TelephoneDirectory::TelephoneDirectory()
//{
//    for(int i=0;i < SIZE;i++)
//    {
//	hashTable[i].mobileNumber=0;
//	hashTable[i].name="-----------";
//	hashTable[i].company="-----------";
//    }
//}
//
//TelephoneDirectory::~TelephoneDirectory()
//{
//    for(int i=0;i < SIZE;i++)
//    {
//	hashTable[i].mobileNumber=0;
//        hashTable[i].name.clear();
//	hashTable[i].company.clear();
//    }
//}

int TelephoneDirectory::hashFunction(long number)
{
    return (number%SIZE);
}

void TelephoneDirectory::insert()
{
    int flag;
    long pNumber;
    string name;
    string companyName;
    cout<<"Enter phone number : ";
    cin>>pNumber;
    cout<<"Enter name : ";
    cin>>name;
    cout<<"Enter company name : ";
    cin>>companyName;

    int i = hashFunction(pNumber);	
    if(hashTable[i].mobileNumber == 0)
    {
	hashTable[i].mobileNumber=pNumber;
	hashTable[i].name=name;
	hashTable[i].company=companyName;
    }
    else
    {
	flag = 0;
        int j;

	for(j=(i+1)%SIZE ;j!=i; j=(j+1)%SIZE )
	{
            if(hashTable[j].mobileNumber == 0)
            {
                hashTable[j].mobileNumber=pNumber;
                hashTable[j].name=name;
                hashTable[j].company=companyName;
                flag=1;
                break;
            }
	}
	if(flag == 0)
        {
            cout<<"Sorry Table is Full\n";
	}
    }
}

void TelephoneDirectory::display()
{
    cout<<"------------------------------------------------------------------------------------\n";
    cout<<setw(12)<<"mobileNumber"<<setw(20)<<"name"<<setw(20)<<"company"<<endl;
    cout<<"------------------------------------------------------------------------------------\n";
    for(int i=0;i < SIZE;i++)
    {
	cout<<setw(12)<<hashTable[i].mobileNumber<<setw(20)<<hashTable[i].name<<setw(20)<<hashTable[i].company<<endl;
    }
    cout<<"------------------------------------------------------------------------------------\n";
}

void TelephoneDirectory::search()
{
    long number;
    int flag=0;	
    cout<<"Enter phone number : ";
    cin>>number;	
    
    int i = number % SIZE;
    //int i = hashFunction(number);
    if(hashTable[i].mobileNumber == number)
	flag=1;
    else
    {
	for(int j=(i+1)%SIZE ;j!=i; j=(j+1)%SIZE )
	{
            if(hashTable[j].mobileNumber == number)
            {
                flag = 1;
                break;
            }
	}
    }
    if(flag == 1)
	cout<<"Number Found\n";
    else
	cout<<"Number not Found\n";		
}

void TelephoneDirectory::deleteData() 
{
    long number;
    int flag=0;	
    int j;
    
    cout<<"Enter phone number : ";
    cin>>number;	
    int i = number % SIZE;
    //int i = hashFunction(number);
    if(hashTable[i].mobileNumber == number)
    {
        j=i;
        flag=1;
    }
    else
    {
	for(j=(i+1)%SIZE ;j!=i; j=(j+1)%SIZE )
	{
            if(hashTable[j].mobileNumber == number)
            {
                flag = 1;
                break;
            }
	}
    }
    
    if(flag == 1)
    {
        hashTable[j].mobileNumber=0;
        hashTable[j].company="-------------";
        hashTable[j].name="-------------";
        cout<<"Data Deleted\n";
    }		
    else
	cout<<"Number not Found\n";
}

int main()
{
    TelephoneDirectory aDirectory;
    char choice;
    char ch;
    int exit=0;
    do
    {
	cout<<"Enter:\n1]Insert\n2]Display\n3]Search\n4]Delete\n5]Exit\nchoice=";
	cin>>choice;
	switch(choice)
	{
            case '1':
                aDirectory.insert();			
                break;
            case '2':
		aDirectory.display();
                break;
            case '3':
		aDirectory.search();
		break;
            case '4':
                aDirectory.deleteData();
		break;
            case '5':
		exit = 1;
		break;
            default :cout<<"Wrong choice entered\n";
	}	
    }while(exit==0);
}