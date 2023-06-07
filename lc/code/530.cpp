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
    int mix = INT32_MAX;
    // 由于是中序遍历，结果应该是有序的，因此，只需要看相邻两个元素的差就行
    void recursion(TreeNode* node, TreeNode* pre) {
        if (node == nullptr)
            return;
        // 左
        recursion(node->left, node);
        // 中，使用当前节点，和前一个节点做差，看结果是否小于最小值
        if (node->val - pre->val < mix)
            mix = node->val - pre->val;
        // 右
        recursion(node->right, node);
    }
    int getMinimumDifference(TreeNode* root) {
        
        return recursion(root, NULL);
    }
};