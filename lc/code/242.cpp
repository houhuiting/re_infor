#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> words;
        for (int i = 0; i < s.size(); i++) {
            words[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            words[t[i]]--;
            if (words[t[i]] < 0)
                return false;
        }
        return true;
    }
};