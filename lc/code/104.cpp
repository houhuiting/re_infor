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
    // 后序遍历，左右中
    // 将左节点的高度和右节点的高度给中节点，层层往上返回，直到到达root节点
    int ord_getDepth(TreeNode* node) {
        if (node == nullptr)
            return 0;
        // 左
        int left_depth = ord_getDepth(node->left);
        // 右
        int right_depth = ord_getDepth(node->right);
        // 中
        int node_depth = max(left_depth, right_depth) + 1;
        return node_depth;
    }
    // 前序遍历，使用遍历到的最大深度作为深度
    int res = 1;
    void pre_getDepth(TreeNode* node, int depth) {
        if (node == nullptr)
            return;
        // 中
        res = max(res, depth);
        // 左
        pre_getDepth(node->left, depth + 1);
        // 右
        pre_getDepth(node->right, depth + 1);
        return;
    }
    int maxDepth(TreeNode* root) {
       return ord_getDepth(root);
       pre_getDepth(root, 1);
       return res;
    }
};