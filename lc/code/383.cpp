#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

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