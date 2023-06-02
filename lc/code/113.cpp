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
    int path = 0;
    // 前序遍历
    void traversal(TreeNode* node, int sum, vector<int>& vec_path, vector<vector<int> >& res) {
        // 中
        path += node->val;
        vec_path.push_back(node->val);
        cout << path << endl;
        for (int i = 0; i<vec_path.size(); i++) {
            cout << vec_path[i] << " ";
        }
        cout << endl;
        // 如果找到了，就把结果放到结果集里面
        if (node->left == nullptr && node->right == nullptr && path == sum) {
            res.push_back(vec_path);
            cout << "yes!" << endl;
            cout << path << endl;
        }
        // 如果到了叶子节点，发现并不是这个路径，直接返回
        if (node->left == nullptr && node->right == nullptr && path != sum) 
            return;
        // 左
        if (node->left)
        {
            traversal(node->left, sum, vec_path, res);
            // 回溯
            path -= node->left->val;
            vec_path.pop_back();
            cout << path << endl;
            for (int i = 0; i<vec_path.size(); i++) {
                cout << vec_path[i] << " ";
            }
            cout << endl;
        }
        // 右
        if (node->right)
        {
            traversal(node->right, sum, vec_path, res);
            // 回溯
            path -= node->right->val;
            vec_path.pop_back();
            cout << path << endl;
            for (int i = 0; i<vec_path.size(); i++) {
                cout << vec_path[i] << " ";
            }
            cout << endl;
        }
        // 如果该节点递归完了它所有的左右节点，那就直接返回
        return;
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> vec_path;
        if (root){
            traversal(root, sum, vec_path, res);
        }
        return res;
    }
};

int main() 
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    Solution solution;
    vector<vector<int> > res = solution.pathSum(root, 22);
    return 0;
}