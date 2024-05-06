#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n,i,j,k,mincost=0,min,row,col;
    char ch;

    cout<<"Enter the number of cities:"<<endl;
    cin>>n;
    int cost[n][n];
    int visit[n];

    for(i=0;i<n;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cost[i][j]=-1;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            cout<<"Do you want to have a connection between city"<<i+1<<"and city"<<j+1<<endl;
            cin>>ch;
            if(ch=='Y'||ch=='y')
            {
                cout<<"Enter the weight:"<<endl;
                cin>>cost[i][j];
                cost[j][i]=cost[i][j];
            }
            
        }
    }
    visit[0]=1;

    for(k=0;k<n-1;k++)
    {
        min=INT_MAX;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(visit[i]==1 && visit[j]==0)
                {
                    if(cost[i][j]!=-1 && min>cost[i][j])
                    {
                        min=cost[i][j];
                        row=i;
                        col=j;
                    }
                }
            }

        }
        mincost+=min;
        visit[col]=1;
        cost[row][col]=cost[col][row]-1;
        cout<<row+1<<"->"<<col+1<<endl;
    }
    cout<<"Minimum cost="<<mincost<<endl;
    return 0;
}