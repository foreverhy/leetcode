#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


template<typename RAIter>
typename std::iterator_traits<RAIter>::value_type get_pivot(RAIter first, RAIter last){
    auto mid = first + (last - first); 
    RAIter min, max;
    if(*first < *last){
        min = first;
        max = last;
    }else{
        min = last;
        max = first;
    }
    if(*mid < *min){
        return *min;
    }else if (*mid > *max){
        return *max;
    }else{
        return *mid;
    }
}

template<typename RAIter>
std::pair<RAIter, RAIter> partition_3(RAIter first, RAIter end){
    auto left = first, flg = first, right = end - 1;
    auto pivot = get_pivot(left, right); 
    while(left <= right){
        for(; flg < left && *flg < pivot; ++flg);
        for(; right > left && *right > pivot; --right);
        if(*left > pivot){
            std::swap(*left, *right);
            --right;
        }else if(*left < pivot){
            if(left != flg){
                std::swap(*left, *flg);
            }
            ++flg;
            ++left;
        }else{
            ++left;
        }
    }
    return {flg, left};
    //return std::make_pair(flg, left);
}


template<typename RAIter>
void qsort(RAIter first, RAIter end){
    if(first >= end){
        return;
    }
    auto mids = partition_3(first, end);
    qsort(first, mids.first);
    qsort(mids.second, end);
}

#include <random>

int main(){
    std::vector<int> a;
    std::mt19937 mt(0);
    for(int i = 0; i < 10000; ++i){
        a.push_back(mt() % 10000);
    }
    qsort(a.begin(), a.end());
    for(auto p: a){
        std::cout << p << std::endl;
    }
    return 0;
}
