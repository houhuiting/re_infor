# 第一天 | 704. 二分查找、27. 移除元素

### 704 二分查找

##### 题目

​		题目链接：[704. 二分查找 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-search/)

​		给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

##### 思路

​		本题最简单的方法就是暴力破解遍历一遍，然后看每一个元素是否是目标值。这样做的话，时间复杂度为O(n)。但是题目又强调是有序数组，考虑使用二分法来替代遍历的方式，时间复杂度为O($log n$)。

​		二分法有两种，左闭右开区间和左闭右闭区间，但是思路都是一样的，都是使用中间值和目标值的大小比较，来逐渐缩小区间范围。

​		我比较习惯使用左闭右闭区间，这样就以左闭右闭[left, right]区间为例，注意两点：

​		1、while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=

​		2、if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1

##### 代码

```c++
// 使用左闭右闭区间规则
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // 设区间为[left, rigih]
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
            if (nums[mid] == target) {
                return mid;
            }
        }
        return -1;
    }
};


//使用左闭右开区间规则
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size();
        // 设区间为[left, rigih)
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
            if (nums[mid] == target) {
                return mid;
            }
        }
        return -1;
    }
};
```

### 27 移除元素

##### 题目

​		题目链接：[27. 移除元素 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-element/)

​		给你一个数组 `nums` 和一个值 `val`，你需要 原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。不要使用额外的数组空间，你必须仅使用 `O(1)` 额外空间并 原地 修改输入数。元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

##### 思路

​		看到这题最快想到的就是遍历数组，查找val的元素，如果找到了，就用后一个元素覆盖前一个元素，需要使用到双重循环。

​		但是这样的话，时间复杂度就是$O(N^2)$。

​		对于一次循环，有一个变量i，两次循环，有两个变量i、j。我们会发现，其实i和j是有关系的，就是j一定比i大，且i和j都是顺序递增的。那么能不能利用这个关系，在一层循环里面，定义两个变量，解决两层循环要做的事情？

​		可以考虑使用双指针法来替代两次for循环。

​		快指针：用来搜索数组元素，用来寻找非目标值的数组元素。（类比于第二层循环）

​		慢指针：把快指针找到的元素赋值到新数组上覆盖到当前位置上。（类比于第一层循环）

​		如果快指针找到目标值，则跳过；如果快指针没找到目标值，说明快指针指向的数据就是我们需要的，那就赋值给慢指针。最终，慢指针应该停留在最后一个赋值的元素的下一个位置，下标为新数组长度。

##### 代码

​		暴力破解

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0;
        while(i < len) {
            if (nums[i] == val) {
                for (int j = i; j < len - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                len = len - 1;
                i--;
            }
            i++;
        }
        return len;
    }
};
```

​		双指针

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] == val) {
                fast++;
            }
            else {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};
```

