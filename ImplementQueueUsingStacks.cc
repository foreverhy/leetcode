#include "leet.h"




#include <algorithm>
#include <cstring>
#include <stack>

class Queue {
    std::stack<int> stack1, stack2;
  public:

    void push(int x) {
        stack1.push(x);
    }

    void pop() {
        peek();
        stack2.pop();
    }

    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};



int main(){


    return 0;
}


