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
        // 如果是p和q，就将他们的值返回给上一级节点
        if (node == p || node == q )
            return node;
        // 如果是空节点，会向上一级返回空
        if (node == nullptr)
            return NULL;
        TreeNode* left;
        TreeNode* right;
        // 左
        left = traversal(node->left, p, q);
        // 右
        right = traversal(node->right, p, q);
        // 中
        // 如果左右子树都不为空，说明p和q出现在这2个子树上，这就是最近公共祖先，直接将当前节点返回
        if (left != nullptr && right != nullptr)
            return node;
        // 如果左右子树的返回值有一个不为空，则说明p和q出现在这个子树上，直接将这个子树的返回值返回
        else if (left != nullptr && right == nullptr)
            return left;
        else if (left == nullptr && right != nullptr)
            return right;
        // 当这个节点的左右子树都不存在p和q时，就把空节点返回给上级
        else {
            return nullptr;
        } 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};