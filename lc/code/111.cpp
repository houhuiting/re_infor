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
    // 后序遍历，将遍历到的最小深度返回给上一层节点
    int ord_getDepth(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int left_depth = ord_getDepth(node->left);
        int right_depth = ord_getDepth(node->right);
        int depth;
        // 注意考虑左右节点为空的情况
        if (left_depth == 0 && right_depth != 0) {
            depth = right_depth + 1;
        }
        else if(left_depth != 0 && right_depth == 0) {
            depth = left_depth + 1;
        }
        // 只有不存在左右节点一个为空，一个不为空的情况，才可以取二者的最小值+1
        else{
            depth = min(left_depth, right_depth) + 1;
        }
        return depth;
    }

    // 前序遍历，使用遍历到的叶子节点的最小深度作为最小深度
    int res = INT32_MAX;
    void pre_getDepth(TreeNode* node, int depth) {
        if (node == nullptr)
            return;
        // 只有当是叶子节点时，才存它的深度
        if (node->left == nullptr && node->right == nullptr) {
            res = min(res, depth);
        }
        pre_getDepth(node->left, depth + 1);
        pre_getDepth(node->right, depth + 1);
        return;
    }
    int minDepth(TreeNode* root) {
        return ord_getDepth(root);
        pre_getDepth(root, 1);
        return res;
    }
};