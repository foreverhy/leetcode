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

bool vst[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

class Solution{
  public:

    string Word;

    bool dfs(vector<vector<char> > &board, int idx, int x, int y){
        if(idx == Word.length()){
            return true;
        }
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()){
            return false;
        }
        if(vst[x][y]){
            return false;
        }
        if(idx >= Word.length()){
            return false;
        }
        if(Word[idx] != board[x][y]){
            return false;
        }
        vst[x][y] = true;
        for(int i = 0; i < 4; ++i){
            if(dfs(board, idx + 1, x + dx[i], y + dy[i])){
                return true;
            }
        }
        vst[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word){
        Word = std::move(word);
        //Word = word;
        std::memset(vst, 0, sizeof vst);
        for(int x = 0; x < board.size(); ++x){
            for(int y = 0; y < board[0].size(); ++y){
                if(dfs(board, 0, x, y)){
                    return true;
                }
            }
        }
        return false;

    }

};



int main(){
    Solution slu;
    using std::cin;
    vector<vector<char> > board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    cout << slu.exist(board, "ABCB") << endl;


    return 0;
}


