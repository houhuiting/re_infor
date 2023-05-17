#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// class Solution {
// public:
//     string replaceSpace(string s) {
//         string t;
//         int j = 0;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] != ' ') {
//                 t[j] = s[i];
//                 j++;
//             }
//             else {
//                 t[j] = '%';
//                 t[j+1] = '2';
//                 t[j+2] = '0';
//                 j = j + 3;
//             }
//         }
//         return t;
//     }
// };

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                count++;
        }
        int fast = s.size() - 1;
        int slow = fast + count*2;
        // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        s.resize(s.size() + count * 2);
        s[slow + 1] = '\0';
        while (fast != slow) {
            if (s[fast] != ' ') {
                s[slow] = s[fast];
                slow--;
                fast--;
            }
            else {
                s[slow] = '0';
                s[slow - 1] = '2';
                s[slow - 2] = '%';
                slow = slow -3;
                fast--;
            }
        }
        return s;
    }
};