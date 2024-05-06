#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class AVL {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* llRotation(Node* node) {
        Node* p = node;
        Node* tp = p->left;

        p->left = tp->right;
        tp->right = p;

        p->height = max(height(p->left), height(p->right)) + 1;
        tp->height = max(height(tp->left), height(tp->right)) + 1;

        return tp;
    }

    Node* rrRotation(Node* node) {
        Node* p = node;
        Node* tp = p->right;

        p->right = tp->left;
        tp->left = p;

        p->height = max(height(p->left), height(p->right)) + 1;
        tp->height = max(height(tp->left), height(tp->right)) + 1;

        return tp;
    }

    Node* insertRec(Node* node, int data) {
        if (node == nullptr) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->left = newNode->right = nullptr;
            newNode->height = 1;
            return newNode;
        }

        if (data < node->data)
            node->left = insertRec(node->left, data);
        else
            node->right = insertRec(node->right, data);

        node->height = max(height(node->left), height(node->right)) + 1;

        int bf = balanceFactor(node);

        if (bf > 1 && data < node->left->data)
            return llRotation(node);
        if (bf < -1 && data > node->right->data)
            return rrRotation(node);
        if (bf > 1 && data > node->left->data) {
            node->left = rrRotation(node->left);
            return llRotation(node);
        }
        if (bf < -1 && data < node->right->data) {
            node->right = llRotation(node->right);
            return rrRotation(node);
        }

        return node;
    }

public:
    AVL() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
    }

    void levelOrder() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            cout << endl;
        }
    }
};

int main() {
    AVL tree;
    int choice, data;

    do {
        cout << "\n1. Insert\n2. Display Level Order\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Level Order Traversal:" << endl;
                tree.levelOrder();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
