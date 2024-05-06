#include<iostream>
using namespace std;
class heap1
{
    public:
    void maxheapify(int a[],int i,int n)
    {
        int l,r,largest,loc;
        l=2*i;
        r=2*i+1;
        if((l<=n)&&(a[l]>a[i]))
        {
            largest=l;
        }
        else
        {
            largest=i;
        }
        if((r<=n)&&(a[r]>a[largest]))
        {
            largest=r;
        }
        if(largest!=i)
        {
            loc=a[i];
            a[i]=a[largest];
            a[largest]=loc;
        }
    }
    void buildheap(int a[],int n)
    {
        for(int k=n/2;k>=1;k--)
        {
            maxheapify(a,k,n);
        }
    }
    void heapsort(int a[],int n)
    {
        buildheap(a,n);
        int i;
        for(i=n;i>=2;i--)
        {
            swap(a[i],a[1]);
            maxheapify(a,1,i-1);
        }
    }
    void accept()
    {
        int n,i;
        int a[n];
        cout<<"Enter the number of students:"<<endl;
        cin>>n;
        cout<<"Enter the marks:"<<endl;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        heapsort(a,n);
        display(a,n);
    }
    void display(int a[],int n)
    {
        cout<<"Sorted marks:"<<endl;
        for(int i=i;i<=n;i++)
        {
            cout<<a[i]<<endl;
        }
        cout<<"Minimum marks:"<<a[1]<<endl;
        cout<<"Maximum marks:"<<a[n]<<endl;
    }
};
int main()
{
    heap1 h;
    h.accept();
    return 0;
}