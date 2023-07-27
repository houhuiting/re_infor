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
    // 定义区间为[left, right]
    TreeNode* traversal(vector<int>& nums){
        if (nums.size() == 0)
            return nullptr;
        // 中
        TreeNode* node = new TreeNode();
        int mid = (0 + nums.size()) / 2;
        node->val = nums[mid];
        // 把左子树对于的左数组抽离出来，[0, mid-1]
        vector<int> left_num(nums.begin(), nums.begin() + mid);
        // 把左子树对于的左数组抽离出来，[mid+1, end-1]
        vector<int> right_num(nums.begin() + mid + 1, nums.end());
        // 左
        node->left = traversal(left_num);
        // 右
        node->right = traversal(right_num);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return traversal(nums);
    }
};