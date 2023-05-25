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
private:
    //  使用先序遍历去遍历一遍所有节点
    int count = 0;
    void getNodesNum1(TreeNode* node) {
        if (node == nullptr)
            return;
        // 中
        count++;
        // 左
        getNodesNum1(node->left);
        // 右
        getNodesNum1(node->right);
        return;
    }

    // 利用深度为h的满二叉树节点数量等于2^h - 1的特性，来求完全二叉树的节点数量
    // 一个完全二叉树可以被分为多个满二叉树，使用递归的方式去查找满二叉树，如果找到满二叉树的根节点，就返回这个根节点下面的节点数量
    int getNodesNum2(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int left_dep = 0;
        int right_dep = 0;
        TreeNode* left = node;
        TreeNode* right = node;
        // 查找该节点左边的最大深度
        while (left->left) {
            left_dep++;
            left = left->left;
        }
        // 查找该节点右边的最大深度
        while (right->right) {
            right_dep++;
            right = right->right;
        }
        // 左边深度和右边深度相等，说明是满二叉树
        if (left_dep == right_dep)
            return (2 << left_dep) - 1; // 相当于2的left_dep+1次方减1
        // 如果不是满二叉树，那就递归去找，先递归左子树
        int node1 = getNodesNum2(node->left);
        // 再递归右子树
        int node2 = getNodesNum2(node->right);
        // 最后左右结果相加再加1，就是该节点下面的节点数（包括自己）
        int sum = node1 + node2 + 1;
        return sum;
    }

public:
    int countNodes(TreeNode* root) {
        // getNodesNum1(root);
        // return count;
        return getNodesNum2(root);
    }
};

int main() 
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    Solution solution;
    int count = solution.countNodes(root);
    cout << count << endl;
    return 0;
}