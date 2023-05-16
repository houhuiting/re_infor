#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

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
