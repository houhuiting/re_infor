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
    TreeNode* traversal(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr)
            return NULL;
        // 中
        // 如果当前节点在这个区间里面，说明该节点就是我们要找的节点
        if (node->val >= p->val && node->val <= q->val) {
            return node;
        }
        // 左
        // 如果当前节点大于这个区间，就走左边的路径
        if (node->val > q->val) {
            TreeNode* res = traversal(node->left, p, q);
            return res;
        }
        // 右
        // 如果当前节点小于这个区间，就走右边的路径
        if ( node->val < p->val) {
            TreeNode* res = traversal(node->right, p, q);
            return res;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val)
            return traversal(root, p, q);
        else {
            return traversal(root, q, p);
        }
    }
};