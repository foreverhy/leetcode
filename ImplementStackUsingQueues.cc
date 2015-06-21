#include "leet.h"




#include <algorithm>
#include <cstring>
#include <queue>
#include <memory>



class Stack {
    std::queue<int> q1;
    std::queue<int> q2;
  public:
    Stack() {
    }

    void push(int x) {
        q2.push(x);
    }

    void pop(void) {
        while (1 != q2.size()) {
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
        std::swap(q1, q2);
    }

    int top(void) {
        return q2.back();
    }

    bool empty(void) {
        return q2.empty();
    }

};



int main(){


    return 0;
}


