#include <iostream>
#include <climits>
using namespace std;
#define number2 1000
int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;
    for(int k=0;k<number2;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int **graph,int src) // adjacency matrix 
{
    int distance[number2]; // // array to calculate the minimum distance for each node                             
    bool Tset[number2];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<number2; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<number2; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<number2; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<number2; k++)                      
    { 
        char str=65+k; 
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}


int main() 
{
    int number;
    int **arr = new int*[number2];
    srand (time(NULL));
    for (int i = 0 ; i < number2; i++) 
        arr[i] = new int[number2];
    for(int i=0; i<number2; i++){
        for(int y=0; y<number2; y++){
            number = rand() % 10;
            arr[i][y]=number;
            // if(y == number2-1){
            //     cout<<arr[i][y]<<endl;
            //     continue;
            // }
            // cout<<arr[i][y];
        }
    }
    DijkstraAlgo(arr,0);
}