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
    // 前序遍历，递归
    void traversal(TreeNode* node, vector<int>& vec) {
        if (node==nullptr)
            return;
        vec.push_back(node->val); // 中
        traversal(node->left, vec); // 左
        traversal(node->right, vec); // 右
    }
    // 前序遍历，迭代法
    void iteration1(TreeNode* node, vector<int>& vec) {
        stack<TreeNode*> st;
        if (node == nullptr)
            return;
        st.push(node);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            // 栈顶输出
            vec.push_back(cur->val);
            st.pop();
            // 把栈顶的右节点放入栈
            if (cur->right)
                st.push(cur->right);
            // 把栈顶的右节点放入栈
            if (cur->left)
                st.push(cur->left);
        }
        return;
    }

    // 前序遍历，中左右，迭代
    void iteration2(TreeNode* node, vector<int>& vec) {
        if (node == nullptr)
            return;
        stack<TreeNode*> st;
        st.push(node);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            // 栈顶不为空时，就取出栈顶，按照右左中（前序的倒序）顺序压入元素
            if (cur != nullptr) {
                st.pop();
                // 右
                if (cur->right)
                    st.push(cur->right);
                // 左
                if (cur->left)
                    st.push(cur->left);
                // 中
                st.push(cur);
                // 对第二次进入栈的节点标记
                st.push(nullptr);
            }
            else {
                st.pop();
                cur = st.top();
                st.pop();
                vec.push_back(cur->val);
            }
        }
        return;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
