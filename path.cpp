#include <iostream>
#include <list>
#include <queue>
using namespace std;

#define NMAX 500

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    bool hasPath(int u, int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::hasPath (int u, int v) { // BFS
    if (u == v)
        return true;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
 
    visited[u] = true; //visited 
    queue.push_back(u); //add u to queue

    
    list<int>::iterator i;
    while (!queue.empty()) 
    {

        u = queue.front(); 
        queue.pop_front(); 
 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) //check
        {
            if (*i == v) 
                return true;
 
            if (!visited[*i]) // visit and add to queue
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false; 
}

int main() {
    int n,e,start,end;
    cin >> n;
    Graph g(n);
    cin >> e;
    for (int i = 0; i < e; i++) {
        int from,to;
        cin >> from >> to;
        g.addEdge(from,to);
    }
    cin >> start >> end;
    if (g.hasPath(start,end)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}