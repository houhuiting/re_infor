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
    TreeNode* traversal(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        
        // 找到最大值
        int max = nums[0];
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        // 中
        // 设最大值为当前节点
        TreeNode* node = new TreeNode(max);
        
        // 构造左右区间
        vector<int> left_num(nums.begin(), nums.begin() + index);
        vector<int> right_num(nums.begin() + index + 1, nums.end());
        
        // 左
        node->left = traversal(left_num);

        // 右
        node->right = traversal(right_num);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        return traversal(nums);
    }
};