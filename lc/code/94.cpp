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
    // 中序遍历，递归
    void traversal(TreeNode* node, vector<int>& vec) {
        if (node==nullptr)
            return;
        traversal(node->left, vec); // 左
        vec.push_back(node->val); // 中
        traversal(node->right, vec); // 右
    }
    // 中序遍历，迭代
    // 顺序为左中右
    // 当左为空的时候，就输出当前值(栈顶)
    // 当右为空的时候，左中右的顺序已经循环过一遍了，就要返回上一层节点(栈顶)
    void iteration1(TreeNode* node, vector<int>& vec) {
        stack<TreeNode*> st;
        TreeNode* cur = node;
        while (!st.empty() && cur != nullptr) {
            if (cur) {
                st.push(cur);
                cur = cur->left;// 左
            }
            else {
                cur = st.top();
                st.pop();
                vec.push_back(cur->val);// 中
                cur = cur->right;// 右
            }
        }
        return;
    }

    void iteration2(TreeNode* node, vector<int>& vec) {
        stack<TreeNode*> st;
        if (node == nullptr)
            return;
        st.push(node);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            if (cur != nullptr) {
                // 弹出cur
                st.pop();
                // 因为栈是倒序输出，所以先把右节点放进去
                if (cur->right)
                    st.push(cur->right);
                // 对第二次进入栈的节点标记
                st.push(cur);
                st.push(nullptr);
                // 因为栈是倒序输出，所以先把右节点放进去，再放左节点
                if (cur->left)
                    st.push(cur->left);
            }
            // 如果识别到了栈顶是null，说明找到了第二次入栈的节点
            else {
                st.pop();
                cur = st.top();
                // 第二次入栈的节点弹出，并放入结果集
                vec.push_back(cur->val);
                st.pop();
            }
        }
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // 递归法
        traversal(root, res);
        // 迭代法
        iteration1(root, res);
        // 迭代法
        iteration2(root, res);
        return res;
    }
};