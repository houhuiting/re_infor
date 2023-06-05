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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 && postorder.size() == 0)
            return NULL;
        // 后序遍历的最后一个节点，一定是当前节点的值
        int node_data = postorder[postorder.size() - 1];
        // 在中序遍历里面，找到这个节点的位置
        int index = 0;
        while (index < inorder.size()) {
            if (inorder[index] == node_data)
                break;
            index++;
        }

        // 使用当前节点位置，节点将中序遍历的数组分为左右数组
        // 得到[0,index-1]数组
        vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
        // 得到[index,end-1]数组
        vector<int> right_inorder(inorder.begin() + index + 1, inorder.end());
        
        // 使用中序遍历分成的左右数组大小，将后序遍历也分成对应大小的左右数组
        // 得到[0,size-1]数组
        vector<int> left_postorder(postorder.begin(), postorder.begin() + left_inorder.size());
        // 得到[size,end-2]数组
        vector<int> right_postorder(postorder.begin() + left_inorder.size(), postorder.end() - 1);
        
        // 生成当前节点
        TreeNode* node = new TreeNode(node_data);
        node->left = traversal(left_inorder, left_postorder);
        node->right = traversal(right_inorder, right_postorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, postorder);
    }
};

int main()
{
    vector<int> inorder;
    vector<int> postorder;
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);
    postorder.push_back(9);
    postorder.push_back(15);
    postorder.push_back(7);
    postorder.push_back(20);
    postorder.push_back(3);
    Solution sol;
    sol.buildTree(inorder, postorder);
}