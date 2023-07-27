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
    int max_count = 0;
    int count = 0;
    TreeNode* pre = NULL;
    vector<int> res;
    void recursion(TreeNode* cur) {
        if (cur == nullptr)
            return;
        // 左
        recursion(cur->left);
        // 中
        if (pre == NULL) {
            count = 1;
        }
        else if (pre->val == cur->val) {
            count++;
        }
        else {
            count = 1;
        }
        if (count == max_count)
            res.push_back(cur->val);
        else if (count > max_count) {
            max_count = count;
            // 之前存的数不是最大频率数，因此要清空
            res.clear();
            res.push_back(cur->val);
        }
        pre = cur;
        // 右
        recursion(cur->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        recursion(root);
        return res;
    }
};