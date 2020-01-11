#include <iostream>
#include <iomanip>
#define INFINITY 999
using namespace std;

class PrismAlgorithm
{
private:
    int numberOfVertices;
    int ** adjMatrix;
public:    
    PrismAlgorithm();
    ~PrismAlgorithm();
    void createAdjTable();
    void displayAdjTable();
    void prims();
};

PrismAlgorithm::PrismAlgorithm()
{
    numberOfVertices = 0;
    adjMatrix = NULL;
}

PrismAlgorithm::~PrismAlgorithm()
{
    numberOfVertices = 0;
    adjMatrix = NULL;
}

void PrismAlgorithm::createAdjTable()
{
    cout<<"Enter number of vertices in the graph :";
    cin>>numberOfVertices;
   
    adjMatrix = new int * [numberOfVertices];
    for(int i=0;i<numberOfVertices;i++)
	adjMatrix[i]=new int [numberOfVertices];
        
    for(int i=0;i<numberOfVertices;i++)
    {
	for(int j=0;j<numberOfVertices;j++)
            adjMatrix[i][j]=INFINITY;
    }
         
    int v1,v2;
    char ch;
    int weight;
    do
    {
	cout<<"Enter edge : ";
	cin>>v1>>v2;
        cout<<"Enter Weight : ";
        cin>>weight;
	adjMatrix[v1][v2]=adjMatrix[v2][v1]=weight;
	cout<<"Enter Y to add more edges :";
	cin>>ch;
    }while(ch=='y' or ch=='Y');	
}

void PrismAlgorithm::displayAdjTable()
{
    for(int i=0;i<numberOfVertices;i++)
    {
	for(int j=0;j<numberOfVertices;j++)
            cout<<setw(3)<<adjMatrix[i][j]<<" ";
        cout<<endl;
    }
}

void PrismAlgorithm::prims()
{
    int VisitCount = 0;
    int totalWeight = 0;
    int * visited = new int [numberOfVertices];
    int minimumWeight;
    int minVertex[2];
    
    for(int i=0;i<numberOfVertices;i++)
        visited[i]=0;
    
    int vertex;
    cout<<"Enter Source Vertex : ";
    cin>>vertex;
    
    visited[vertex] = 1;
    VisitCount = 1;
    while(VisitCount!=numberOfVertices)
    {
        minimumWeight = INFINITY;
        for(vertex = 0;vertex < numberOfVertices;vertex++)
        {
            if(visited[vertex] == 1)
            {
                for(int i=0;i<numberOfVertices;i++)
                {
                    if(adjMatrix[vertex][i] != INFINITY and visited[i] == 0)
                    {
                        if(adjMatrix[vertex][i] < minimumWeight)
                        {
                            minimumWeight = adjMatrix[vertex][i];
                            minVertex[0] = i;
                            minVertex[1] = adjMatrix[vertex][i];
                        }
                    }    
                }
            }
        }
        totalWeight = totalWeight + minVertex[1];
        visited[minVertex[0]]=1;
        VisitCount++;
    }
    cout<<"Minimum Cost = "<<totalWeight<<endl;
}

int main()
{
    PrismAlgorithm obj;
    obj.createAdjTable();
    obj.displayAdjTable();
    obj.prims();
}