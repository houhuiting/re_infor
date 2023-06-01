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
private:
    // 后序遍历，让左右节点把高度告诉中节点，如果相差不小于1，则返回-1（说明错误）
    int gethight(TreeNode* node) {
        // 如果是叶子节点，高度是1
        if (node->left==nullptr && node->right==nullptr)
            return 1;
        int lefthight = 0;
        int righthight = 0;
        // 因为不处理空节点，所以递归不能递归空节点
        if (node->left) {
            lefthight = gethight(node->left);
        }
        if (node->right) {
            righthight = gethight(node->left);
        }
        // 如果左右节点有-1，就说明已经不是平衡二叉树了，直接返回
        if (lefthight == -1 || righthight == -1)
            return -1;
        // 如果左右节点高度差大于1，就说明已经不是平衡二叉树了，直接返回
        if (abs(lefthight - righthight) > 1)
            return -1;
        // 如果左右节点高度差小于1，就说明可能还是平衡二叉树了，返回中间节点高度
        else {
            return max(lefthight, righthight) + 1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root) {
            return gethight(root) == -1 ? false:true;
        }
        return true;
    }
};