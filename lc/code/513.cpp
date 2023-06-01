#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
    // 使用层次遍历
    int iteration(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        // 用于记录每一行的最后一个元素
        int res = 0;
        while (!que.empty()) {
            res = que.front()->val;
            int size = que.size();
            while (size--) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
        }
        return res;
    }
    int findBottomLeftValue(TreeNode* root) {
        return iteration(root);
    }
};