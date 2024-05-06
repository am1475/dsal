#include<iostream>
using namespace std;

class tnode
{
    public:
    int data;
    tnode*left;
    tnode*right;

    tnode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class tree
{
    public:
    tnode*root;

    tree()
    {
        root=NULL;
    }
    void insert(tnode*root,tnode*node);
    tnode*create();
    void inorder(tnode*root);
    void search(tnode*root,int key);
    int MIN(int a,int b);
    int MAX(int a,int b);
};
int tree::MAX(int a, int b )
{
    int max;
    if(a>b)
    {
        max=a;
    }
    else
    {
        max=b;
    }
    return max;
}
int tree::MIN(int a, int b )
{
    int min;
    if(a<b)
    {
        min=a;
    }
    else
    {
        min=b;
    }
    return min;
}
void tree::insert(tnode*root,tnode*node)
{
    if(root==NULL)
    {
        return;
    }
    if(node->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left=node;
        }
        else
        {
            insert(root->left,node);
            return;
        }
    }
    else{
        if(root->right==NULL)
        {
            root->right=node;
        }
        else
        {
            insert(root->right,node);
            return;
        }
    }
}
tnode*tree::create()
{
    char ch;
    ch='y';
    do
    {
        cout<<"Enter the data for node"<<endl;
        int newdata;
        cin>>newdata;
        tnode*newnode=new tnode(newdata);

        if(root==NULL)
        {
            root=newnode;
        }
        else{
            insert(root,newnode);
        }
        cout<<"Do you want to continue:"<<endl;
        cin>>ch;
    } while (ch!='n');
    return this->root;
}
void tree::inorder(tnode*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void tree::search(tnode*root,int key)
{
    if(root==NULL)
    {
        cout<<"Key is not present:"<<endl;
        return;
    }
    if(key<root->data)
    {
        search(root->left,key);
    }
    else if(key>root->data)
    {
        search(root->right,key);
    }
    else
    {
        cout<<"Key is present:"<<endl;
        return;
    }
}



int main()
{
    tree t;
    tnode*root;
    int key;
    root=t.create();
    t.inorder(root);
    cout<<"Enter the key to be searched:"<<endl;
    cin>>key;
    t.search(root,key);
    return 0;

}
