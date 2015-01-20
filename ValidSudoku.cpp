#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;


#include <cstdlib>
using std::atoi;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};




#include <algorithm>
#include <cstring>

unsigned row;
unsigned col[10];
unsigned sub[10];

class Solution{
  public:
    int c2i(char ch){
        return ch - '0';
    }
    // which sub box
    int w_sub(int r, int c){
        return (r/3) * 3 + c/3;
    }

    bool isValidSudoku(vector<vector<char> > &board){
        row = 0;
        std::memset(col, 0u, sizeof col); 
        std::memset(sub, 0u, sizeof sub); 
        int R = board.size();
        int C = board[0].size();
        for(int r = 0; r < R; ++r){
            row = 0;
            for(int c = 0; c < C; ++c){
                auto ch = board[r][c];
                if('.' != ch){
                    auto num = c2i(ch);
                    auto f = 1u << num;
                    if(row & f || col[c] & f || sub[w_sub(r, c)] & f){
                        return false;
                    }
                    row |= f;
                    col[c] |= f;
                    sub[w_sub(r, c)] |= f;
                }
            }
        }
        return true;
    }


};



int main(){
    Solution slu;
    using std::cin;
    vector<vector<char> > bd ;


    bd.push_back({'.','8','7','6','5','4','3','2','1'});
    bd.push_back({'2','.','.','.','.','.','.','.','.'});
    bd.push_back({'3','.','.','.','.','.','.','.','.'});
    bd.push_back({'4','.','.','.','.','.','.','.','.'});
    bd.push_back({'5','.','.','.','.','.','.','.','.'});
    bd.push_back({'6','.','.','.','.','.','.','.','.'});
    bd.push_back({'7','.','.','.','.','.','.','.','.'});
    bd.push_back({'8','.','.','.','.','.','.','.','.'});
    bd.push_back({'9','.','.','.','.','.','.','.','.'});

    cout << slu.isValidSudoku(bd) << endl;


    return 0;
}


