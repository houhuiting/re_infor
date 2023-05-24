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
    // 后序遍历，递归
    void traversal(TreeNode* node, vector<int>& vec) {
        if (node==nullptr)
            return;
        traversal(node->left, vec); // 左
        traversal(node->right, vec); // 右
        vec.push_back(node->val); // 中
    }
    // 后序遍历，迭代
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
            // 把栈顶的左节点放入栈
            if (cur->left)
                st.push(cur->left);
            // 把栈顶的右节点放入栈
            if (cur->right)
                st.push(cur->right);
        }
        // 将中右左翻转一下，就是左右中了
        reverse(vec.begin(), vec.end());
    }
    // 后序遍历，左右中，迭代
    void iteration2(TreeNode* node, vector<int>& vec) {
        if (node == nullptr)
            return;
        stack<TreeNode*> st;
        st.push(node);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            // 栈顶不为空时，就取出栈顶，按照中右左（后序的倒序）顺序压入元素
            if (cur != nullptr) {
                st.pop();
                // 中
                st.push(cur);
                // 对第二次进入栈的节点标记
                st.push(nullptr);
                // 右
                if (cur->right)
                    st.push(cur->right);
                // 左
                if (cur->left)
                    st.push(cur->left);
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

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        iteration1(root, res);
        return res;
    }
};