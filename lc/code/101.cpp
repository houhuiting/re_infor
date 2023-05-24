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
    // 比较左边节点和右边节点是否相等
    bool is_same(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left != nullptr && right != nullptr && right !=left)
            return false;
        else if (left == nullptr && right == nullptr)
            return true;
        // 后序遍历。因为要先判断两个子树的左右节点是否相同，才能判断两个子树是否对称
        // 比较左节点的左节点和右节点的右节点是否相等
        bool outside = is_same(left->left, right->right);
        // 比较左节点的右节点和右节点的左节点是否相等
        bool inside = is_same(left->right, right->left);
        // 由于经过上面的判断，left和right肯定相等
        // 如果outside和inside也相等的话，那left子树和right子树对称
        bool result = outside && inside;
        return result;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return false;
        return is_same(root->left, root->right);
    }
};