#include "leet.h"


int read4(char *buf);



#include <algorithm>
#include <cstring>

class Solution{
    char tmpbuffer[5];
    int offset;
    int len;
  public:
    Solution() : offset(0), len(0) {}
    int read(char *buf, int n) {
        int nleft = n;
        int nread = 0;

        if (offset != len) {
            int ncopy = len - offset;
            if (ncopy > n) {
                ncopy = n;
            }
            std::memcpy(buf, tmpbuffer + offset, ncopy);
            nleft -= ncopy;
            nread += ncopy;
            offset += ncopy;
            buf += ncopy;
        }
        while (nleft > 0) {
            int reads;
            if ((reads = read4(tmpbuffer)) <= 0) {
                break;
            }
            len = reads;
            offset = len;
            nread += reads;
            if (nread > n) {
                offset = nleft;
                nread = n;
            }
            nleft -= reads;
            std::memcpy(buf, tmpbuffer, reads);
            buf += reads;
        }
        return nread;
    }
};



int main(){
    Solution slu;


    return 0;
}


