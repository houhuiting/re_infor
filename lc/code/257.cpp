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
    //  前序遍历，res存放最终结果，path存放当前路径
    void traversal(TreeNode* node, vector<string>& res, vector<int>& path) {
        // 中
        path.push_back(node->val);
        // 如果是叶子节点，就把路径存到结果集里面
        if (node->left==nullptr && node->right==nullptr) {
            string spath;
            for (int i = 0; i < path.size() - 1; i++) {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            res.push_back(spath);
            return;
        }
        if (node->left) {
            traversal(node->left, res, path);
            // 由于进入递归之后，path会压入node->left节点
            // path不能只增加，不减少，下一跳路径不应该包括node->left
            // 回溯
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, res, path);
            path.pop_back();
        }
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res; 
        vector<int> path;
        if (root) {
            traversal(root, res, path);
        }
        return res;
    }
};