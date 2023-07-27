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
        // 中
        // 如果找到了空节点，就返回新节点
        if (node == nullptr) {
            TreeNode* new_node = new TreeNode(val);
            return new_node;
        }
        // 左
        // 如果当前节点大于待插入节点的值，
        if (node->val > val) {
            node->left = traversal(node->left, val);
            return node;
        }
        // 右
        // 如果当前节点小于待插入节点的值，不可能出现等于的情况
        else {
            node->right = traversal(node->right, val);
            return node;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return traversal(root, val);
    }
};