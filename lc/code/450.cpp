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
    TreeNode* traversal(TreeNode* node, int val){
        if (node == nullptr)
            return node;
        // 中
        if (node->val == val){
            // 如果是叶子结点，直接删除，把null返回给上一层节点
            if (node->left == nullptr && node->right == nullptr)
                return nullptr;
            // 如果左节点为空，右节点不为空
            else if (node->left == nullptr && node->right != nullptr)
                return node->right;
            // 如果右节点为空，左节点不为空
            else if (node->left != nullptr && node->right == nullptr)
                return node->left;
            // 如果左右节点均不为空
            else {
                // 寻找当前节点右子树最左边的节点
                TreeNode* p = node->right;
                while (p->left) {
                    p = p->left;
                }
                // 把当前节点左子树给放到当前节点右子树最左边的节点的左边
                p->left = node->left;
                return node->right;
            }
        }
        // 左
        if (node->val > val){
            // 使用node->left去承接下一层返回的新节点
            node->left = traversal(node->left, val);
            // 由于搜索数有序，不需要把所有路径遍历，只需要遍历一条路径
            // 因此在选择这个路径，并处理好之后，可以直接返回
            return node;
        }
        // 右
        if (node->val < val){
            node->right = traversal(node->right, val);
            return node;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key){
        return traversal(root, key);
    }
};