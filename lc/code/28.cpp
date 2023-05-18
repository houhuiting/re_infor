#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        // 初始化前缀末尾为0，pre用来寻找前缀的最后一个位置
        int pre = 0;
        // 初始化后缀末尾为-1，suf用来寻找后缀的最后一个位置
        int suf = 1;
        next[0] = 0;
        while(suf < s.size()) {
            // 当前缀末尾和后缀末尾不相等，就去寻找和后缀末尾相等的前缀末尾
            // 如果pre到了第一个元素的位置，就不能往前走了，说明不存在和后缀末尾相等的前缀末尾
            // 如果前缀末尾和后缀末尾不相等，就不断往前寻找
            while (pre > 0 && s[pre] != s[suf]) {
                // 首先，已知s[pre]和s[suf]不相等，但是二者都是前缀末尾和后缀末尾，由于pre > 0，所以前面部分的前缀和前面部分的后缀应该是相等的。如果不相等，那前面部分的前缀和前面部分的后缀不同，最大相等前后缀为0，而pre是定位前缀末尾的，pre应该在0的位置。
                // 已知前面部分的前缀和前面部分的后缀相等，那suf-1和pre-1的元素是相等的，再来看[0, pre-1]字符串，这个字符串的最大相等前后缀是next[pre-1]，说明next[pre-1]和pre-1的元素相等
                // 因此，suf-1、pre-1和next[pre-1]的元素都相等，已知suf和pre位置元素不相等，所以应该回到next[pre-1]的位置，再让next[pre-1]+1和suf这两个位置元素前进行比较
                // 而如果前面部分的前缀和前面部分的后缀不相等，那next[pre-1]为0
                pre = next[pre - 1];
            }
            // 如果寻找到相等的前缀末尾和后缀末尾，或者当前的前缀末尾和后缀末尾相等，那么最大相等前后缀就是pre的下一个元素下标(注意，下标从0开始)
            if (s[pre] == s[suf]) {
                pre++;
            }
            // 对于寻找到相等的前缀末尾和后缀末尾，和pre=0的情况（没有找到相等的前缀末尾和后缀末尾），next[suf]都应该等于pre。
            next[suf] = pre;
            suf++;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        int next[needle.size()];
        getNext(next, needle);
        for (int i = 0; i < needle.size(); i++) {
            cout << next[i] << " ";
        }
        cout << endl;
        int p1 = 0;
        int p2 = 0;
        while (p1 < haystack.size()) {
            // 寻找匹配的位置，如果p2 = 0，说明在needle里不存在匹配的位置
            while (p2 > 0 && haystack[p1] != needle[p2]) {
                p2 = next[p2 - 1];
            }
            // 如果匹配上了
            if (haystack[p1] == needle[p2]) {
                p2++;
            }
            // 不管有没有匹配上，p1都要后移
            p1++;
            // 如果needle全部匹配上了，返回结果
            if (p2 == needle.size())
                return p1 - needle.size();
        }
        return -1;
    }
};
int main()
{
    Solution sol;
    string haystack = "aaaaaabcabcabcabcabc";
    string needle = "abcabcabcabc";
    cout << sol.strStr(haystack, needle) << endl;;
    return 0;
}