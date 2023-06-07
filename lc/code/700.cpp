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
    TreeNode* traversal(TreeNode* node, int val) {
        if (node == nullptr)
            return NULL;
        // 中
        if (node->val == val)
            return node;
        TreeNode* res;
        //左
        if (node->val > val)
            res = traversal(node->left, val);
        //右
        if (node->val < val)
            res = traversal(node->right, val);
        return res;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return traversal(root, val);
    }
};