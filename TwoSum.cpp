#include <algorithm>
#include <cstring>
#include <map>

class Solution{

  public:
    vector<int> twoSum(vector<int> &numbers, int target){
            std::map<int, int> mp;
            for(vector<int>::size_type i = 0; i < numbers.size(); ++i){
                        mp[numbers[i]] = i + 1;
                    }
            for(vector<int>::size_type i = 0; i < numbers.size(); ++i){
                        auto rv = target - numbers[i];
                        auto fit = mp.find(rv);
                        if(fit != mp.end()){
                                        int lidx = i + 1;
                                        if(fit->second == lidx)continue;
                                        return {lidx, fit->second};
                                    }
                    }
            return {};
        }
};
