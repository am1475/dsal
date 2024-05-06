#include <iostream>
#include <vector>
#include <numeric> // For accumulate
#include <limits>

using namespace std;

// Node structure for BST
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Recursive function to construct BST
TreeNode* constructTree(const vector<int>& keys, const vector<vector<int>>& root, int i, int j);

// Function to construct optimal BST
pair<TreeNode*, double> constructOptimalBST(const vector<int>& keys, const vector<double>& probs) {
    int n = keys.size();
    vector<vector<double>> cost(n + 1, vector<double>(n + 1, 0.0));
    vector<vector<int>> root(n + 1, vector<int>(n + 1, 0));

    // Initialize cost matrix with leaf probabilities
    for (int i = 0; i < n; ++i) {
        cost[i][i] = probs[i];
        root[i][i] = i;
    }

    // Calculate optimal cost and root
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            cost[i][j] = numeric_limits<double>::infinity();
            for (int k = i; k <= j; ++k) {
                double subtreeProbSum = accumulate(probs.begin() + i, probs.begin() + j + 1, 0.0);
                double c = ((k > i) ? cost[i][k - 1] : 0) +
                           ((k < j) ? cost[k + 1][j] : 0) +
                           subtreeProbSum;
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = k;
                }
            }
        }
    }

    // Construct tree recursively
    TreeNode* rootPtr = constructTree(keys, root, 0, n - 1);
    return {rootPtr, cost[0][n - 1]};
}

// Recursive function to construct BST
TreeNode* constructTree(const vector<int>& keys, const vector<vector<int>>& root, int i, int j) {
    if (i > j) return nullptr;
    int k = root[i][j];
    TreeNode* node = new TreeNode(keys[k]);
    node->left = constructTree(keys, root, i, k - 1);
    node->right = constructTree(keys, root, k + 1, j);
    return node;
}

// Utility function to print BST inorder
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    vector<int> keys = {1, 2, 3, 4, 5};
    vector<double> probs = {0.1, 0.2, 0.3, 0.1, 0.3};
    
    auto result = constructOptimalBST(keys, probs);
    TreeNode* root = result.first;
    double minCost = result.second;
    
    cout << "Inorder traversal of optimal BST: ";
    inorder(root);
    cout << endl;
    
    cout << "Minimum cost of optimal BST: " << minCost << endl;

    return 0;
}
