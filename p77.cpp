#include<iostream>
#include<climits>
using namespace std;

int sum(int freq[],int i , int j);
int optcost(int freq[],int i,int j)
{
    int cost;
    if(j<i)
    {
        return 0;
    }
    if(j==i)
    {
        return freq[i];
    }
    int fsum=sum(freq,i,j);
    int mincost=INT_MAX;
    for(int r=i;r<=j;r++)
    {
        cost=optcost(freq,i,r-1)+optcost(freq,r+1,j);
    if(cost<mincost)
    {
        mincost=cost;
    }
    }
    return mincost+fsum;
}
int optimalbst(int keys[],int freq[],int n)
{
    return(optcost(freq,0,n-1));
}
int sum(int freq[],int i,int j)
{
    int s=0;
    for(int k=i;k<=j;k++)
    {
        s=s+freq[k];
    }
    return s;
}
int main()
{
    int nk;
    cout<<"Enter the number of keys:"<<endl;
    cin>>nk;
    int keys[nk];
    int freq[nk];
    for(int i=0;i<nk;i++)
    {
        cout<<"Enter the key and frequency:"<<endl;
        cin>>keys[i]>>freq[i];
    }
    int n=sizeof(keys)/sizeof(keys[0]);
    cout<<"Cost of Optimal BST:"<<optimalbst(keys,freq,n)<<endl;
    return 0;
}