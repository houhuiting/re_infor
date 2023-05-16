#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int gethappy(int n) {
        int sum = 0;
        int remain = 0;
        while (n) {
            remain = n % 10;
            n = n / 10;
            sum = sum + remain*remain;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1) {
            n = gethappy(n);
            // 如果等于1，那就是快乐数
            if (n == 1) 
                return true;
            // 发现这个数字之前出现过，数字开始循环，说明肯定无限循环，但始终变不到1
            if (set.count(n))
                return false;
            else {
                set.insert(n);
            }
        }
    }
};

int main()
{
    Solution s;
    bool is = s.isHappy(19);
    cout << is << endl;
    return 0;
}