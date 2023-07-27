#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum = 0;
    TreeNode* traversal(TreeNode* node){
        if (node == nullptr)
            return node;
        // 右
        node->right = traversal(node->right);
        // 中
        sum = sum + node->val;
        node->val = sum;
        // 左
        node->left = traversal(node->left);
        return node;
    }
    TreeNode* convertBST(TreeNode* root){
        return traversal(root);
    }
};