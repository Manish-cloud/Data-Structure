#include<iostream>
#include<fstream>
using namespace std;

class stud
{
private:
    char name[10],addr[20],div;
    int rno;
public:
    void accept()
    {
        cout<<"\nEnter your name   : ";
	cin>>name;
	cout<<"\nEnter roll number : ";
	cin>>rno;
	cout<<"\nEnter division    : ";
	cin>>div;
	cout<<"\nEnter address     : ";
	cin>>addr;
    }

    void Delete()
    {
	remove("db.txt");
    }

    void display();
    void update(int rno);
    void search(int rno);
    void write();	
};

void stud::display()
{
    stud obj;
    ifstream f;
    f.open("db.txt",ios::in);

    while(f.read((char *)&obj, sizeof(obj)))
    {
	cout<<"\n---------------------------------------------------------------";
	cout<<"\nName           : "<<obj.name;
	cout<<"\nRoll number    : "<<obj.rno;
	cout<<"\nDivision       : "<<obj.div;
	cout<<"\nAddress        : "<<obj.addr;
    }
    f.close();
}

void stud::write()
{
    stud obj;
    obj.accept();
    ofstream f;
    f.open("db.txt",ios::out | ios::app);
    f.write((char *)&obj, sizeof(obj));
    f.close();
}

void stud::search(int r)
{
    stud obj;
    ifstream f;
    f.open("db.txt",ios::in);
    int flag=0;
    while(f.read((char *)&obj, sizeof(obj)))
    {
	if(obj.rno==r)
	{
            flag=1;
            break;
	}
    }
    if(flag)
    {
	cout<<"\n-----------------------!!RECORD FOUND!!-----------------------";
	cout<<"\nname: "<<obj.name;
	cout<<"\nRoll number: "<<obj.rno;
	cout<<"\ndivision: "<<obj.div;
	cout<<"\nAddress: "<<obj.addr;	
    }
    else
	cout<<"\nRecord not found..!!";
    
    f.close();
}

void stud::update(int r)
{
    stud obj;
    fstream f;
    f.open("db.txt",ios::in | ios::out);
    int flag=0;
    while(f.read((char *)&obj, sizeof(obj)))
    {
	if(obj.rno==r)
	{
            flag=1;
            break;
	}
    }	
    if(flag)
    {
	cout<<"\nEnter new data";
	obj.accept();
	f.seekp(-sizeof(obj),ios::cur);
	f.write((char *)&obj, sizeof(obj));
	cout<<"\nRECORD Updated..!!";
    }
    else
	cout<<"\nRecord not found..!!";
}

int main()
{
    stud my;
    int op,r;
    char ch;
    int exit=0;
    do
    {
        cout<<"\n---------------------------------------------------------------";
        cout<<"\nEnter \n1) New data \n2) Display \n3) Search \n4) Update \n5) Delete file\n6] Exit\nchoice = ";
	cin>>op;
	switch(op)
	{
            case 1:
                my.write();
                break;
            case 2:
                my.display();
                break;
            case 3:	
                cout<<"\nEnter roll number to search: ";
		cin>>r;
		my.search(r);
                break;
            case 4:
                cout<<"\nEnter roll number to update: ";
		cin>>r;
		my.update(r);
                break;
            case 5:
                my.Delete();
                break;
            case 6:
                exit=1;
                break;
            default:
                cout<<"\nWrong choice..!!";
	}
    }while(exit==0);
    return 0;
}