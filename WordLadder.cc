#include "leet.h"

#include <unordered_set>
using std::unordered_set;




#include <algorithm>
#include <cstring>
#include <memory>

#include <queue>


class Word {
  public:

    string str;
    int cnt;

    Word (string rhs, int c = 0): str(rhs.data()), cnt(c){}
    Word (const Word &rhs): str(rhs.str), cnt(rhs.cnt){}
    Word (Word &&rhs): str(std::move(rhs.str)), cnt(rhs.cnt){}

};

int dist(const Word &w1, const Word &w2){
    int len = w1.str.length();
    int diff = 0;
    const char *p1 = w1.str.data();
    const char *p2 = w2.str.data();
    for (int i = 0; i < len; ++i){
        if (*p1 != *p2){
            ++diff;
        }
        if (diff > 1){
            return -1;
        }
        ++p1, ++p2;
    }
    return diff;
}

#include <set>
#include <list>

const string table = "abcdefghijklmnopqrstuvwxyz";

// 双向BFS更快
class Solution{
  public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &dict){
        std::queue<Word> q;
        Word begin(beginWord, 1);
        Word end(endWord, 0);
        auto it = dict.find(beginWord);
        if (it != dict.end()){
            dict.erase(it);
        }

        q.push(begin);

        int len;
        int tlen = table.length();

        while (!q.empty()){
            auto now = q.front();
            if (dist(now, end) >= 0){
                return now.cnt + 1;
            }
            len = now.str.length();
            for (int i = 0; i < len; ++i){
                for (int j = 0; j < tlen; ++j) if (table[j] != now.str[i]){
                    auto tmpstr = now.str[i];
                    auto tmpcnt = now.cnt;
                    now.str[i] = table[j];
                    auto it = dict.find(now.str);
                    if (it != dict.end()){
                        now.cnt++;
                        q.push(now);
                        dict.erase(it);
                    }
                    now.cnt = tmpcnt;
                    now.str[i] = tmpstr;
                }
            }
            
            q.pop();
        }

        return 0;
    }

};


#include <fstream>
#include <iostream>


int main(int argc, char *argv[]){
    if (2 != argc){
        cout << "INPUTDATA" << endl;
        return -1;
    }
    std::ifstream in(argv[1]);
    Solution slu;
    string start;
    string end;
    in >> start;
    in >> end;
    string x;
    std::unordered_set<string> dc;
    while (in >> x){
        dc.insert(x);
    }
    cout << dc.size() << endl;


    cout << slu.ladderLength(start, end, dc) << endl;


    return 0;
}


