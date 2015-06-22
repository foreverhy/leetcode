#include "leet.h"


int read4(char *buf);



#include <algorithm>
#include <cstring>

class Solution{
  public:
    int read(char *buf, int n) {
        int tot = 0;
        int nread = 0;
        char tmpbuffer[5];
        while ( (nread = read4(tmpbuffer)) > 0) {
            tot += nread;
            if (tot >= n) {
                std::memcpy(buf, tmpbuffer, nread - (tot - n));
                break;
            } else {
                std::memcpy(buf, tmpbuffer, nread);
            }
            buf += nread;
        }
        return tot >= n ? n: tot;
    }
};



int main(){
    Solution slu;


    return 0;
}


