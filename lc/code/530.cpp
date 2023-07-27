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
    TreeNode* pre = NULL;
    // 由于是中序遍历，结果应该是有序的，因此，只需要看相邻两个元素的差就行
    void recursion(TreeNode* node) {
        if (node == nullptr)
            return;
        // 左
        recursion(node->left);
        // 中，使用当前节点，和前一个节点做差，看结果是否小于最小值
        if (pre != nullptr && node->val - pre->val < mix){
            mix = node->val - pre->val;
        }
        pre = node;
        // 右
        recursion(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        recursion(root);
        return mix;
    }
};
// 12346
int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Solution sol;
    cout << sol.getMinimumDifference(root) << endl;
}