#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};

int main()
{
    vector<char> s;
    s.push_back('H');
    s.push_back('a');
    s.push_back('n');
    s.push_back('n');
    s.push_back('a');
    s.push_back('h');
    Solution sol;
    sol.reverseString(s);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}