#include<iostream>
#define MAX 10
#define TRUE 1
#define FALSE 0

using namespace std;

class graph
{
private:
    int cost[MAX][MAX];

    struct node
    {
        int vertex;
        node* next;
    };
    node* adjlist[MAX];
    int visited[MAX];

public:
    graph()
    {
        for(int i=0;i<MAX;i++)
        {
            visited[i]=FALSE;
            adjlist[i]=NULL;
            for(int j=0;j<MAX;j++)
            {
                cost[i][j]=0;
            }
        }
    }

    void adjmatrix()
    {
        int e,v,i,j;
        cout<<"Enter the number of vertices:"<<endl;
        cin>>v;
        cout<<"Enter the number of edges:"<<endl;
        cin>>e;

        for(int k=0;k<e;k++)
        {
            cin>>i>>j;
            cost[i][j]=1;
            cost[j][i]=1;
        }
        displayadjmatrix(v);
    }

    void displayadjmatrix(int v)
    {
        cout<<"The adjacency matrix is:"<<endl;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<" "<<cost[i][j];
            }
            cout<<endl;
        }
    }

    void dfs(int v, int n) {
        cout << "DFS of the graph is:" << endl;
        int visited[MAX] = {0}; // Properly initialize visited array within the dfs function
        dfsUtil(v, n, visited);
    }

    void dfsUtil(int v, int n, int visited[]) { // Pass visited array by reference
        cout << v << " ";
        visited[v] = 1;
        for (int j = 0; j < n; j++) {
            if (cost[v][j] != 0 && visited[j] != 1) {
                dfsUtil(j, n, visited);
            }
        }
    }

    int accept()
    {
        int v;
        adjmatrix();
        cout<<"Enter the initial vertex:"<<endl;
        cin>>v;
        if(v>=MAX)
        {
            cout<<"Invalid vertex:"<<endl;
            return -1; // Return -1 for error
        }
        else
        {
            for(int i=0;i<MAX;i++)
            {
                visited[i]=FALSE;
            }
            dfs(v,MAX);
        }
        return 0; // Return 0 for success
    }
};

int main()
{
    graph g;
    g.accept();
    return 0;
}
