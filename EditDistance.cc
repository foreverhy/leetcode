
#include <algorithm>
#include <cstring>

class Solution {
  public:
    int minDistance(string word1, string word2){
        auto l1 = word1.length();
        auto l2 = word2.length();
        int s[l1+10][l2+10];
        std::memset(s, 0x3f3f3f3f, sizeof s);
        s[0][0] = 0;
        for(int i = 1; i <= static_cast<int>(l1); ++i){
            s[i][0] = i;
        }
        for(int i = 1; i <= static_cast<int>(l2); ++i){
            s[0][i] = i;
        }
        for(decltype(l1) wi = 0; wi < l1; ++wi){
            for(decltype(l2) wj = 0; wj < l2; ++wj){
                auto i = wi + 1;
                auto j = wj + 1;
                if(word1[wi] == word2[wj]){
                    s[i][j] = s[i-1][j-1];
                }else{
                    auto tmp = std::min(s[i-1][j-1], s[i-1][j]);
                    tmp = std::min(tmp, s[i][j-1]);
                    s[i][j] = std::min(tmp+1, s[i][j]);
                }
            }
        }
        //for(auto i = 0u; i <= l1; ++i){
            //for(auto j = 0u; j <= l2; ++j){
                //std::cout<<s[i][j]<<" ";
            //}
            //std::cout<<"\n";
        //}
        return s[l1][l2];
    }
};
