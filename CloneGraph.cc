#include "leet.h"


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x): label(x){}
};



#include <algorithm>
#include <cstring>
#include <queue>
#include <map>


class Solution{
  public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
        if (!node){
            return nullptr;
        }
        std::queue<UndirectedGraphNode*> q;
        std::map<int, UndirectedGraphNode*> mp;
        int start = node->label;
        q.push(node);
        mp[start] = new UndirectedGraphNode(start);

        while (!q.empty()){
            auto now = q.front();
            auto nn = mp[now->label];
            for (auto &p : now->neighbors){
                auto nb = now;
                auto iter = mp.find(p->label);
                if (iter  == mp.end()){
                    q.push(p);
                    nb = new UndirectedGraphNode(p->label);
                    mp[nb->label] = nb;
                } else {
                    nb = iter->second;
                }
                nn->neighbors.push_back(nb);
            }
            q.pop();
        }

        return mp[start];
    }
};



int main(){
    Solution slu;


    return 0;
}


