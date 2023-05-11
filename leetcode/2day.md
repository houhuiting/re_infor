# 第二天 | 977.有序数组的平方、 209.长度最小的子数组、 59.螺旋矩阵II

### 977 有序数组的平方

##### 题目

​		题目链接：[977. 有序数组的平方 - 力扣（LeetCode）](https://leetcode.cn/problems/squares-of-a-sorted-array/)

​		给你一个按 非递减顺序 排序的整数数组 `nums`，返回 每个数字的平方 组成的新数组，要求也按非递减顺序排序。

##### 思路

​		这题最简单的方法还是暴力破解，直接对所有数字都平方，然后再排序，那么这样的时间复杂度为$O(n+nlogn)$，其中平方是n，排序（sort函数）是nlogn。

​		然后观察发现，数组其实是有序的，平方之后的最大值一定在数组的左右两边，而最小值一定在中间。那这样就可以使用双指针法了。让一个指针指向最左边，一个指针指向最右边，比较谁大，大的那一个就放到新数组里。

##### 代码

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1 ;
        vector<int> res(nums.size());
        int len = nums.size() - 1;
        while (len >= 0) {
            int r = nums[right]*nums[right];
            int l = nums[left]*nums[left];
            if (r >= l) {
                res[len] = r;
                right--;
                len--;
            }
            else {
                res[len] = l;
                left++;
                len--;
            }
        }
        return res;
    }
};
```

### 209 长度最小的子数组

##### 题目

​		题目链接：https://leetcode.cn/problems/minimum-size-subarray-sum/

​		给定一个含有 `n` 个正整数的数组和一个正整数 `target` 。

​		找出该数组中满足其和 `≥ target` 的长度最小的 连续子数组 `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度**。**如果不存在符合条件的子数组，返回 `0` 。

##### 思路

​		本题拿到题目最简单的方法就是暴力破解，使用双层循环的方式来解决。一个下标表示起始位置，一个下标表示终止位置。

​		接下来考虑优化。

​		可以采用滑动窗口的方式，来使用一个循环，遍历起始位置和终止位置。注意，这个循环遍历的应该是终止位置，如果是起始位置的话，那就和暴力破解一样了。在遍历终止位置时，每次循环都要找到使得大于目标值的最大起始位置，从而获取在当前终止位置的最小值。

##### 代码

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        int min = INT_MAX;
        while (end < nums.size())
        {
            sum = sum + nums[end];
            while (sum >= target)
            {
                min = min < (end - start + 1) ? min : (end - start + 1);
                sum = sum - nums[start];
                start++;
            }
            end++;
        }
        return min < INT_MAX ? min : 0;
        
    }
};
```

### 59 螺旋矩阵II

##### 题目

​		题目链接：https://leetcode.cn/problems/spiral-matrix-ii/

​		给你一个正整数 `n` ，生成一个包含 `1` 到 `n2` 所有元素，且元素按顺时针顺序螺旋排列的 `n x n` 正方形矩阵 `matrix` 。

##### 思路

​		本题的思路在于如何去定义循环的条件。一共`n x n` 个元素，就想到循环的条件可以为这`n x n` 个元素，然后让元素去填充矩阵。观察填充过程发现，填充方式有4种，从左往右、从上往下、从右往左、从下往上，知道填充数量达到`n x n` 为止。

​		那我就考虑使用switch设置四种循环情况，通过判断是否达到边界（下一个元素是否赋值、是否到达矩阵边界）来判断是否要切换下一种情况。

##### 代码

```cpp
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > arr(n, vector<int>(n, 0));
        int mod = 1;
        int row = 0;
        int col = 0;
        int i = 1;
        while(i <= n*n) {
            switch (mod)
            {
            case 1:
                if (col < n && arr[row][col] == 0) {
                    arr[row][col] = i;
                    col++;
                    i++;
                }
                else {
                    mod = 2;
                    // 将行提前设置在下一种情况的开始位置
                    row ++;
                    // 由于循环条件是看col < n，就会导致最后的col = n，溢出，将col减回去
                    col --;
                }
                break;
            case 2:
                if (row < n && arr[row][col] == 0) {
                    arr[row][col] = i;
                    row++;
                    i++;
                }
                else {
                    mod = 3;
                    col--;
                    row--;
                }
                break;
            case 3:
                if (col > -1 && arr[row][col] == 0) {
                    arr[row][col] = i;
                    col--;
                    i++;
                }
                else {
                    mod = 4;
                    col++;
                    row--;
                }
                break;
            case 4:
                if (row > -1 && arr[row][col] == 0) {
                    arr[row][col] = i;
                    row--;
                    i++;
                }
                else {
                    mod = 1;
                    row++;
                    col++;
                }
                break;
            }
        }
        return arr;
    }
};
```



