/* 
 * File:   Graph.cpp
 * Author: Manish
 *
 * Created on 23 January, 2019, 8:17 PM
 */

#include<iostream>
//#include<stack>
//#include<queue>
#include "Stack.h"
#include "queue.h"
using namespace std;

struct node 
{
    int vertexNumber;
    node * next;
    node();
    ~node();
};

node::node()
{
    vertexNumber=0;
    next=NULL;
}

node::~node()
{
    vertexNumber=0;
    if(next!=NULL)
    {
        delete next;
        next=NULL;
    }       
}

class Graph
{
private:
    int numberOfVertices;
    int ** adjMatrics;
    node ** adjList;
    int * visited;
public :
    Graph();
    ~Graph();
    void createMatrics();
    void displayMatrics();
    void createList();
    void displayList();
    void dfsRec(int);
    void dfsNonRec(int);
    void bfs(int);
};

Graph::Graph()
{   
    numberOfVertices=0;	
    adjMatrics=NULL;
    adjList=NULL;
    visited=NULL;
}
Graph::~Graph()
{
    numberOfVertices=0;	
    adjMatrics=NULL;
    adjList=NULL;
}

void Graph::createMatrics()
{
    if(adjMatrics!=NULL)                                //memory management
    {
        for(int i = 0; i < numberOfVertices; i++)
            delete [] adjMatrics[i];
	delete [] adjMatrics;
    }
	
    if(visited!=NULL)                                   //memory management
	delete [] visited;
    //
    
    cout<<"Enter number of vertices in the graph :";
    cin>>numberOfVertices;
   
    adjMatrics = new int * [numberOfVertices];
    for(int i=0;i<numberOfVertices;i++)
	adjMatrics[i]=new int [numberOfVertices];
        
    for(int i=0;i<numberOfVertices;i++)
    {
	for(int j=0;j<numberOfVertices;j++)
            adjMatrics[i][j]=0;
    }
        
    visited = new int [numberOfVertices];
    for(int i=0;i<numberOfVertices;i++)
        visited[i]=0;
        
    int v1,v2;
    char ch;
    do
    {
	cout<<"Enter edge : ";
	cin>>v1>>v2;
	adjMatrics[v1][v2]=adjMatrics[v2][v1]=1;
	cout<<"Enter Y to add more edges :";
	cin>>ch;
    }while(ch=='y' or ch=='Y');		
}

void Graph::displayMatrics()
{
    for(int i=0;i<numberOfVertices;i++)
    {
	for(int j=0;j<numberOfVertices;j++)
            cout<<adjMatrics[i][j]<<" ";
        cout<<endl;
    }
}

void Graph::createList()
{
    if(adjList!=NULL)
    {
	for(int i=0;i<numberOfVertices;i++)
           delete adjList[i];
        delete adjList;
    }
    
    cout<<"Enter number of vertices in the graph :";
    cin>>numberOfVertices;
    
    adjList = new node * [numberOfVertices];
    for(int i=0;i < numberOfVertices;i++)
        adjList[i]=NULL;
    char ch;
    int v1,v2;
    node * nn;
    node * temp;
    do
    {
        cout<<"Enter edge : ";
        cin>>v1>>v2;

        nn=new node;
        nn->vertexNumber=v2;
        if(adjList[v1]==NULL)
            adjList[v1]=nn;
        else
        {
            temp=adjList[v1];
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=nn;
        }
                    // for undirected graph
	nn=new node;                    
	nn->vertexNumber=v1;
	if(adjList[v2]==NULL)
	    adjList[v2]=nn;
	else
	{
            temp=adjList[v2];
	    while(temp->next!=NULL)
	    	temp=temp->next;
	    temp->next=nn;
	}
        cout<<"Enter Y to add more edges :";
	cin>>ch;
    }while(ch=='y'||ch=='Y');
}

void Graph::displayList()
{
    node * temp;
    for(int i=0;i<numberOfVertices;i++)
    {
	cout<<i<<" : ";
        temp=adjList[i];
        if(temp)
        {
            while(temp!=NULL)
            {
                cout<<temp->vertexNumber<<" ";
                temp=temp->next;
            }
        }
	cout<<endl;
    }
}

void Graph::dfsRec(int v1)
{
    cout<<v1<<" ";
    visited[v1]=1;
    for(int v2=0;v2 < numberOfVertices;v2++)
    {
	if(adjMatrics[v1][v2]==1 and visited[v2]==0)
            dfsRec(v2);
    }
}

void Graph::dfsNonRec(int v)
{
    Stack <int> s;
    s.push(v);
    int * visited = new int [numberOfVertices];
    for(int i=0;i<numberOfVertices;i++){
        visited[i]=0;
    }
    visited[v]=1;
    int v1,v2;
    while(!s.empty())
    {
	v1=s.top();
	s.pop();
	cout<<v1<<" ";
	for(v2=0;v2 < numberOfVertices;v2++)
	{
            if(adjMatrics[v1][v2]==1 and visited[v2]==0)
            {
		s.push(v2);
		visited[v2]=1;
            }
	}
    }
}

void Graph::bfs(int v)
{
    queue <int> q;
    q.push(v);
    int * visited = new int [numberOfVertices];
    for(int i=0;i<numberOfVertices;i++){
        visited[i]=0;
    }
    visited[v]=1;
    int v1,v2;
    while(!q.empty())
    {
	v1=q.front();
	q.pop();
	cout<<v1<<" ";
	for(v2=0;v2 < numberOfVertices;v2++)
	{
            if(adjMatrics[v1][v2]==1 and visited[v2]==0)
            {
		q.push(v2);
		visited[v2]=1;
            }
	}
    }
}

int main()
{
    int exit=0;
	int v;
    char choice;
    Graph g;
    do
    {
	cout<<"\nEnter\n1]To create Adjacency Matrics\n2]To display Adjacency Matrics\n3]To create Adjacency list\n4]To display Adjacency list\n5]DFS\n6]BFS\n7]To exit\nchoice=";
	cin>>choice;
	switch(choice)
	{
            case '1':
            g.createMatrics();
            break;
            case '2':
            g.displayMatrics();
            break;
            case '3':
            g.createList();
            break;
            case '4':
            g.displayList();
            break;
            case '5':
            cout<<"Enter source vertex for DFS :";
            cin>>v;
            g.dfsNonRec(v);
            cout<<endl;
            break;
            case '6':
            cout<<"Enter source vertex for BFS :";
            cin>>v;
            g.bfs(v);
            break;
            case '7':
            exit=1;
            break;
            default:
            cout<<"Wrong choice entered !!!\n";
	}
    }while(exit==0);
	return 0;
}