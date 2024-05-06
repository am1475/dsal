#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

struct node
{
    char label[100];
    int ch_count;
    node*child[10];
}*root;

class GT
{
    public:
    void create();
    void display(node*r1);
    GT()
    {
        root=NULL;
    }
};
void GT::create()
{
    int tchapters,i,j;
    root=new node;
    cout<<"Enter the book name:"<<endl;
    cin.ignore();
    cin.getline(root->label,sizeof(root->label));
    cout<<"Enter the number of Chapters:"<<endl;
    cin>>tchapters;
    root->ch_count=tchapters;
    for(i=0;i<tchapters;i++)
    {
        root->child[i]=new node;
        cout<<"Enter the Chapter name:"<<endl;
        cin.ignore();
        cin.getline(root->child[i]->label,sizeof(root->child[i]->label));
        cout<<"Enter the number of sections in chapter:"<<endl;
        cin>>root->child[i]->ch_count;
        for(j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"Enter section name:"<<endl;
            cin.ignore();
            cin.getline(root->child[i]->child[j]->label,sizeof(root->child[i]->child[j]->label));
        }

    }
}
void GT::display(node*r1)
{
    int tchapters,i,j;
    if(r1!=NULL)
    {
        cout<<"*******Book Hierarchy*************"<<endl;
        cout<<"Book Title:"<<r1->label<<endl;
        tchapters=r1->ch_count;
        for(i=0;i<tchapters;i++)
        {
            cout<<"Chapter name:"<<r1->child[i]->label<<endl;
            for(j=0;j<r1->child[i]->ch_count;j++)
            {
                cout<<"Section name:"<<r1->child[i]->child[j]->label<<endl;
            }
        }
    }
}
int main()
{
    int ch;
    GT gt;
    while(true)
    {
    cout<<"Book tree:"<<endl;
    cout<<"1.Create:"<<endl;
    cout<<"2.Display:"<<endl;
    cout<<"3.Exit:"<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:gt.create();
               break;
        case 2:gt.display(root);
               break;
        case 3:exit(0);
                break;
    }
    }

    return 0;

}

