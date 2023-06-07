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
    // 使用num来存储中序遍历的结果
    // 如果是二叉搜索树的中序遍历，那结果应该是有序的，且是递增的
    bool recursion(TreeNode* node, vector<int>& num) {
        // 如果找到了空节点，此时不做任何判断，认为没有发生错误，直接返回true
        if (node == nullptr)
            return true;
        bool res;
        // 左
        res = recursion(node->left, num);
        // 如果递归时已经出现了错误，后面不管是否再次出现错误，都是错的，后面判断不用进行了，直接返回false
        if (!res)
            return false;
        // 中
        // 如果遍历数组为空，就差入第一个元素
        // 如果不为空，就拿最后一个元素和节点值相比
        if (num.size() == 0)
            num.push_back(node->val);
        else {
            if (num[num.size() - 1] >= node->val)
                return false;
            else {
                num.push_back(node->val);
            }
        }
        // 右
        res = recursion(node->right, num);
        if (!res)
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> num;
        return recursion(root, num);
    }
};
int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    Solution sol;
    cout << sol.isValidBST(root) << endl;
}