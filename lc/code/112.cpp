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

class solution {
public:
    // 前序遍历 中左右
    // 使用path来传递当前路径的总和
    int path = 0;
    bool traversal (TreeNode* node, int sum) {
        // 中
        path += node->val;
        if (node->left == nullptr && node->right == nullptr && path == sum) 
            return true;
        if (node->left == nullptr && node->right == nullptr && path != sum) 
            return false;
        if (node->left)
        {
            bool res = traversal(node->left, sum);
            // 如果已经找到了这条路径，就直接return，没必要递归下去了
            if (res)
                return true;
            // 只有当没找到这条路径，才递归下去
            path = path - node->left->val;
        }
        if (node->right)
        {
            bool res = traversal(node->right, sum);
            // 如果已经找到了这条路径，就直接return，没必要递归下去了
            if (res)
                return true;
            // 只有当没找到这条路径，才递归下去
            path = path - node->right->val;
        }
        // 如果该节点递归完了它所有的左右节点，都没有找到一个这样的路径，就返回false
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root)
            return traversal(root, sum);
        return false;
    }
};