#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node*left;
    node*right;
    int height;
};
class avl
{
    private:
    node*root;

    int height(node*node1)
    {
        if(node1==nullptr)
        {
            return 0;
        }
        else
        {
            return node1->height;
        }
    }
    int bf(node*node1)
    {
        if(node1==nullptr)
        {
            return 0;
        }
        else
        {
            return node1->left-node1->right;
        }
    }
    node*ll(node*node1)
    {
        node*p=node1;
        node*tp=p->left;

        p->left=tp->right;
        tp->right=p;

        p->height=max((height(p->left)),height(p->right))+1;
        tp->height=max(height(tp->left),height(tp->right))+1;

        return tp;
    }    
    node*rr(node*node1)
    {
        node*p=node1;
        node*tp=p->right;

        p->right=tp->left;
        tp->left=p;

        p->height=max((height(p->left)),(height(p->right)))+1;
        tp->height=max((height(tp->left)),height(tp->right))+1;

        return tp;
    }
    node*insert(node*node1,int data)
    {

        if(node1==nullptr)
        {
            node*newnode=new node;
            newnode->data=data;
            newnode->left=NULL;
            newnode->right=NULL;
            newnode->height=1;
            return newnode;
        }
        else
        {
            if(data<node1->data)
            {
                node1->left=insert(node1->left,data);
            }
            else
            {
                node1->right= insert(node1->right,data);
            }
            node1->height=max((height(node1->left)),height(node1->right))+1;

            int b=bf(node1);

            if(b>1 && data<node1->left->data)
            {
                return(ll(node1));
            }
            if(b<-1 && data>node1->right->data)
            {
                return(rr(node1));
            }
            if(b>1 && data>node1->left->data)
            {
                node1->left=rr(node1);
                return ll(node1);
            }
            if(b<-1 && data<node1->right->data)
            {
                node1->right=ll(node1);
                return rr(node1);
            }
        }
        return node1;
    }
    public:
    avl()
    {
        root=nullptr;
    }
    void insert(int data)
    {
        root=insert(root,data);

    }
    void level()
    {
        if(root==nullptr)
        {
            cout<<"Tree is empty:"<<endl;
            return;
        }
        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                node*temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            cout<<endl;

            }
        }


    };
int main()
{
    avl a;
    int i=0,data;
    char ch;
    do{
        cout<<"Enter the data:"<<endl;
        cin>>data;
        a.insert(data);
        cout<<"Do you want to continue:"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    a.level();
    return 0;
}

