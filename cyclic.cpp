#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj;
    Graph(int V) ;
    void addEdge(int v, int w);
    bool cyclicDFS(int v, bool visited[], bool *rec) ;
    bool isCyclic();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    // ditected Graph
    adj[v].push_back(w); 
}

bool Graph::cyclicDFS(int v, bool visited[], bool *rec)
{
    if(visited[v] == false)
    {
        // mark visit node
        visited[v] = true;
        rec[v] = true;

        // dfs recur each vertices
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && cyclicDFS(*i, visited, rec))
                return true;
            else if (rec[*i])
                return true;
        }
    }
    rec[v] = false;
    return false;
}
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *rec = new bool[V];
    // mark false all index
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        rec[i] = false;
    }
    for(int i = 0; i < V; i++)
        if (cyclicDFS(i, visited, rec))
            return true;
    return false;
}

int main()
{
    int numNode,numEdge,src,des,v,w;
    cin >> numNode;
    cin >> numEdge;
    Graph g(numNode) ;
    for(int i = 0 ; i < numEdge ; i++){
        cin >> v >> w;
        g.addEdge(v,w);
    }
    if(g.isCyclic())
        cout << "Graph contains cycle" ;
    else
        cout << "Graph doesn't contain cycle" ;
    return 0 ;
}