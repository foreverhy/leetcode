#include "leet.h"




#include <algorithm>
#include <cstring>


class TrieNode {
  public:
    char ch;
    int cnt;
    int w_cnt;

    TrieNode *lchd, *right;

    TrieNode(char c): ch(c), cnt(0), w_cnt(0), lchd(nullptr), right(nullptr){}

};

class Trie{
  private:
    TrieNode *root;
  public:
    Trie(): root(new TrieNode(0)){}

    void insert(const string &s){
        auto pre = root;
        auto h = root->lchd;
        bool isright = false;
        for (auto it = s.begin(); it != s.end(); ++it){
            auto c = *it;
            for (; h && h->ch != c; isright = true, pre = h, h = h->right);
            if (!h){
                if (isright){
                    h = (pre->right = new TrieNode(c));
                } else {
                    h = (pre->lchd = new TrieNode(c));
                }
            }
            ++h->cnt;
            if (it == s.end() - 1){
                ++h->w_cnt;
            }
            pre = h;
            h = h->lchd;
            isright = false;
        }
    }

    bool search(const string &s){
        auto h = root->lchd;
        for (auto it = s.begin(); it != s.end(); ++it){
            auto c = *it;
            for (; h && h->ch != c;h = h->right);
            if (!h || !h->cnt){
                break;
            }
            if (it == s.end() - 1){
                return h->w_cnt > 0;
            }
            h = h->lchd;
        }
        return false;
    }

    bool startsWith(const string &s){
        auto h = root->lchd;
        for (auto it = s.begin(); it != s.end(); ++it){
            auto c = *it;
            for (; h && h->ch != c;h = h->right);
            if (!h || !h->cnt){
                break;
            }
            if (it == s.end() - 1){
                return true;
            }
            h = h->lchd;
        }
        return false;

    }
    

};



int main(){
    Trie t;


    return 0;
}


