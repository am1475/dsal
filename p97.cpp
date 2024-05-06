#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;
    int height;
};
class AVL
{
    private:
    Node*root;

    int height(Node*node)
    {
        if(node==NULL)
        {
            return;
        }
        return node->height;
    }
    int bf(Node*node)
    {
        if(node==nullptr)
        {
            return 0;
        }
        else
        {
            return node->left-node->right;
        }
    }
};
int main()
{
    AVL a;
    Node*root;
    a.height(root);
    a.bf(root);
}