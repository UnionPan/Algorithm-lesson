// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices  
// reachable from s. 
#include<iostream> 
#include <list> 
#include <vector> 
#include <limits>
  
using namespace std;

static int Int_Infinity = std::numeric_limits<int>::max();
  
// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency 
    // lists 
    list<int> *adj; 

    void DFSvisit(int v, int visited[], int dis[], int fis[], int time, int pred[]);

    list<int> *adj_reverse;

public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w);  
  
    // prints BFS traversal from a given source s 
    void BFS(int s);   

    void DFS();

    vector<int> Kosaraju();

    vector<int> Tarjan();
}; 

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    adj_reverse = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj_reverse[w].push_back(v);
}


void Graph::BFS(int s){
    bool *visited = new bool[V]; 

    for(int i = 0; i<V; i++){
        visited[i] = 0;
    }
    
    int *dis = new int[V];

    for(int i = 0; i<V; i++){
        dis[i] = Int_Infinity;
    }

    list<int> queue;

    visited[s] = true;
    dis[s] = 0;

    queue.push_back(s);

    list<int>::iterator i;    

    while(!queue.empty()){
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 

        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true;     
                dis[*i] = dis[s] + 1;
                queue.push_back(*i); 
            } 
        } 
    }
    
    cout << "\n" << "print out the distance from source to current vertex " << "\n";
    for(int i = 0; i < V; i++){
        cout << "node" << i << " " << dis[i] << " " ;
    }
    
}

void Graph::DFSvisit(int s, int visited[], int dis[], int fis[], int time, int pred[]){
    visited[s] = 1;
    dis[s] = ++time;
    cout<< "\n" << s << " whose ancestor is " << pred[s] << "  \n";
    cout << "current distance " << dis[s] << " \n";
    
    list<int>::iterator i;  
    for(i = adj[s].begin(); i != adj[s].end(); ++i){
        if (visited[*i] == 0){
            pred[*i] = s;
            DFSvisit(*i, visited, dis, fis, time, pred);
        }
    }
    visited[s] = 2;
    fis[s] = ++time;
}

void Graph::DFS(){
    int *visited = new int[V];
    int *pred = new int[V];
    for(int i = 0; i<V; i++){
        visited[i] = 0;
        pred[i] = 0;
    }

    int time = 0;
    
    int *dis = new int[V];
    int *fis = new int[V];
    
    for(int i = 0; i<V; i++){
        if(visited[i] == 0){
            DFSvisit(i, visited, dis, fis, time, pred);
        } 
    }
    

    for(int i = 0; i < V; i++){
        cout << "  \n " << "distance "<< dis[i] << "  " << fis[i] << "\n";
        cout << " predecessor " << pred[i];
    }
     
}

vector<int> Graph::Kosaraju(){
     // Run DFS(G) from the source 
     int *visited = new int[V];
     int *pred = new int[V];
     

}



// Driver program to test methods of graph class 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 

    g.BFS(2); 

    g.DFS();
  
    return 0; 
} 