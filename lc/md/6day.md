# 第六天 ｜ 454、四数相加II 383、赎金信 15、三数之和 

## 454 四数相加II

#### 题目

题目链接：https://leetcode.cn/problems/4sum-ii/

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

例如:

输入:

A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:

2

解释:

两个元组如下:

(0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
(1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

#### 思路

看到这题，其实想到我们之前做的一个两数之和，判断两个数字相加是不是为target（0）。其实这题也是一样，区别就在于，是判断4个数字相加是不是0。

最简单的方法就是暴力破解，循环四次，时间复杂度为O(n^4)。

其实可以将这题的a+b看作是一个数，c+d看作是一个数，那这题就和两数之和一样了，可以使用map来存一个数（a+b），循环另外一个数（c+d），通过map来快速判断-c-d是否在map中，这样时间复杂度就变成了O(n^2)。

这里使用map的原因是，题目要求输出有几种可能，所以需要将a+b产生的次数也存下来。

#### 代码

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mapab;
        int count = 0;
        // 先把a+b的所有可能存到map中，因为题目要求返回次数，所以要把次数作为value存下来。
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                int add = A[i] + B[j];
                mapab[add]++;
            }
        }
        // 遍历所有可能的c+d，判断-c-d在不在map里面
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                int add = C[i] + D[j];
                int sub = 0 - add;
                if (mapab.count(sub)) {
                    count = count + mapab[sub];
                }
            }
        }
        return count;
    }
};
```

## 383 赎金信

#### 题目

题目链接：https://leetcode.cn/problems/ransom-note/

给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

#### 思路

这题和之前做过的一个字母异位词思路一样，可以采用一个map来存放magazine的字符和字符出现次数，然后遍历ransom字符，每使用一个ransom字符，就在map中对应的字符的value减去1。如果map中出现value为-1的情况，说明这个字符在magazine中出现次数小于ransom中出现次数，返回false。

#### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        // 记录magazine的字符和字符出现次数
        for (int i = 0; i < magazine.size(); i++) {
            map[magazine[i]]++;
        }
        // 每使用一个ransom字符，就在map中对应的字符的value减去1
        for (int i = 0; i < ransomNote.size(); i++) {
            map[ransomNote[i]]--;
            // 说明这个字符在magazine中出现次数小于ransom中出现次数，返回false
            if (map[ransomNote[i]] == -1)
                return false;
        }
        return true;
    }
};
```

## 15 三数之和

#### 题目

题目链接：https://leetcode.cn/problems/3sum/

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]

#### 思路

这题的思路和前面的四数相加类似，使用哈希法解决。可以先将nums放到set中，然后双层循环计算a+b，然后去map中去找有没有-a-b。注意a b c的下标必须不同，因此考虑使用map来存放c的下标。且三元组不能重复，最后的结果还需要去重。

本题如果采用哈希法的话，做起来难度较大，考虑使用排序+双指针的方法。将三重循环，使用双指针来替换掉其中的两层循环。

#### 代码
