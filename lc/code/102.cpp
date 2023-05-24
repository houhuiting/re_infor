#include <iostream>
#include <vector>
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
    // 迭代
    void iteration(TreeNode* node, vector<vector<int> >& res) {
        if (node == nullptr)
            return;
        queue<TreeNode*> que;
        que.push(node);
        while (!que.empty()) {
            TreeNode* front;
            int size = que.size();
            vector<int> ele;
            // 由于题目要求输出的结果是vector<vector<int> >，如[[1],[2,3],[4,5,6,7]]
            // 所以，对于每一层都要单独循环一遍，将这一层的所有节点使用while一次性处理了，再处理下一层
            // 每次处理的节点数量应该是que的大小，也就是第n层节点数量
            while (size--) {
                front = que.front();
                // 将队首放到结果集中，并删掉队首（第n层的节点）
                ele.push_back(front->val);
                que.pop();
                // 把对首节点的下一层的左右节点（第n+1层的节点）放到队尾
                if (front->left)
                    que.push(front->left);
                if (front->right)
                    que.push(front->right);
            }
            res.push_back(ele);
        }
    }

    // 递归
    // 利用先序遍历（中左右），将先序遍历的节点根据层次，放入不同层的res中，由于先序遍历也是从左到右的，因此虽然是先序遍历，但是最后的结果和层次遍历相同。
    void traversal(TreeNode* node, vector<vector<int> >& res, int depth) {
        if (node == nullptr)
            return;
        // 如果是这一层的第一个节点，就给这一层新建一个vector
        if (res.size() == depth)
            res.push_back(vector<int>());
        // 将节点放到第depth层的vector中
        res[depth].push_back(node->val);
        traversal(node->left, res, depth + 1);
        traversal(node->right, res, depth + 1);
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        iteration(root, res);
        traversal(root, res, 0);
        return res;
    }
};