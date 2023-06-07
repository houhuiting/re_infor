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
    TreeNode* traversal(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return NULL;
        TreeNode* node = new TreeNode();
        if (t1 == nullptr && t2 != nullptr) {
            // 中
            node->val = t2->val;
            // 左
            node->left = traversal(NULL, t2->left);
            // 右
            node->right = traversal(NULL, t2->right);
        }
        if (t1 != nullptr && t2 == nullptr) {
            // 中
            node->val = t1->val;
            // 左
            node->left = traversal(t1->left, NULL);
            // 右
            node->right = traversal(t1->right, NULL);
        }
        if (t1 != nullptr && t2 != nullptr) {
            // 中
            node->val = t1->val + t2->val;
            // 左
            node->left = traversal(t1->left, t2->left);
            // 右
            node->right = traversal(t1->right, t2->right);
        }
        return node;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return traversal(t1, t2);
    }
};