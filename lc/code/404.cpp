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
    // 后序遍历，让左右节点，把他们的左叶子的值返回给中节点
    int traversal(TreeNode* node, int is_left){
        // 如果是空，直接返回0，没有右节点
        if (node == nullptr)
            return 0;
        // 如果是左节点，就返回当前值
        if (node->left == nullptr && node->right == nullptr && is_left == 1)
            return node->val;
        int left_num = traversal(node->left, 1);
        int right_num = traversal(node->right, 0);
        int sum = left_num + right_num;
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return traversal(root, 1);
    }
};