#include "leet.h"




#include <algorithm>
#include <cstring>
#include <map>

class TwoSum {
    std::map<int, int> mp;
  public:
    void add(int number) {
        mp[number]++;
    }

    bool find(int value) {
        for (auto &item : mp) {
            auto left = value - item.first;
            auto iter = mp.find(left);
            if (iter != mp.end()) {
                int diff = 0;
                if (left == item.first) diff = 1;
                if (iter->second > diff) {
                    return true;
                }
            }
        }
        return false;
    }

};



int main(){


    return 0;
}


