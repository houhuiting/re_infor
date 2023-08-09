#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    int tree_height = 0;
    int cur_height = 0;
    //判断最新加入的这个数字是否合法
    bool is_valid(vector<vector<char>>& board, int row, int col) {
        // 看同行是否有重复
        unordered_set<char> set1;
        for (int j = 0; j < board[0].size(); j++) {
            if (board[row][j] == '.')
                continue;
            if (!set1.count(board[row][j]))
                set1.insert(board[row][j]);
            else {
                return false;
            }
        }
        // 看同列是否有重复
        unordered_set<char> set2;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == '.')
                continue;
            if (!set2.count(board[i][col]))
                set2.insert(board[i][col]);
            else {
                return false;
            }
        }
        // 看附近九宫格是否有重复
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;
        unordered_set<char> set3;
        for (int i = startrow; i < startrow + 3; i++) {
            for (int j = startcol; j < startcol + 3; j++) {
                if (board[i][j] == '.')
                    continue;
                if (!set3.count(board[i][j]))
                    set3.insert(board[i][j]);
                else {
                    return false;
                }
            }
        }
        return true;
    }
    // row和col用来传递上一个加入数字的位置
    // 那么检索下一个.位置只需从这个地址开始检索就行
    // bool类型用于当找到正确的情况，直接全部返回
    bool backtracking(vector<vector<char>>& board, int row, int col) {
        if (!is_valid(board, row, col))
            return false;
        // cout << endl;
        // for (int i =0;i<board.size();i++) {
        //     for (int j=0;j<board[i].size();j++) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // 如果到了最后一层节点的位置，且合法，就说明这是一个正确的结果
        if (cur_height == tree_height)
            return true;
        int next_row = 0;
        int next_col = 0;
        // 找到下一个.的位置
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    next_row = i;
                    next_col = j;
                    break;
                }
            }
            if (board[next_row][next_col] == '.') {
                break;
            }
        }
        cout << next_row << next_col << endl;
        // 循环1-9出现
        for (int i = 1; i < 10; i++) {
            board[next_row][next_col] = '0' + i;
            cur_height++;
            if (backtracking(board, next_row, next_col))
                return true;
            // 回溯
            board[next_row][next_col] = '.';
            cur_height--;
        }
        return false;
    }    
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.')
                    tree_height++;
            }
        }
        cout << tree_height << endl;
        backtracking(board, 0, 0);
    }
};

int main()
{
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    Solution sol;
    sol.solveSudoku(board);
    cout << endl;
    for (int i =0;i<board.size();i++){
        for (int j=0;j<board[i].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}