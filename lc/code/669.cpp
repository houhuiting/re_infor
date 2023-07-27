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
    TreeNode* traversal(TreeNode* node, int low, int high){
        if (node == nullptr)
            return node;
        // 中
        // 如果当前节点小于区间，当前节点的右子树可能还存在一些节点是在区间范围内的，因此，递归右子树
        // 将递归右子树的结果存下来，这是当前节点的新右子树的根节点，将其返回给上一层，相当于对本层节点做了一个删除操作
        if (node->val < low){
            // 递归右子树，把所有符合区间的新右子树的根节点找出
            TreeNode* right = traversal(node->right, low, high);
            // 返回给上一层
            return right;
        }
        // 如果当前节点大于区间，当前节点的左子树可能还存在一些节点是在区间范围内的，因此，递归左子树
        // 将递归左子树的结果存下来，这是当前节点的新左子树的根节点，将其返回给上一层，相当于对本层节点做了一个删除操作
        if (node->val > high){
            // 递归左子树，把所有符合区间的新左子树的根节点找出
            TreeNode* left = traversal(node->left, low, high);
            // 返回给上一层
            return left;
        }
        // 左
        // 使用node->left去承接下一层返回的结果
        node->left = traversal(node->left, low, high);
        // 右
        // 使用node->right去承接下一层返回的结果
        node->right = traversal(node->right, low, high);
        return node;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high){
        return traversal(root, low, high);
    }
};