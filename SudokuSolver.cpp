#include <vector>
#include <iostream>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
#include <cstdlib>
#include <cstdio>

#include <algorithm>
#include <cstring>

const int ROWS = 9 * 9 * 9;
const int MAXR = ROWS + 10;
const int COLS = (9 + 9 + 9) * 9 + 81;
const int MAXC = COLS + 10;
const int MAX = MAXR * MAXC;

const int cr_s = 81;
const int cc_s = cr_s + 9 * 9;
const int cx_s = cc_s + 9 * 9;

int L[MAX], R[MAX], U[MAX], D[MAX], C[MAX], S[MAX], N[MAX];
int rows_, cols_, matched_, h_, k;
int ans[MAXR];

int REM[10][10][10];

void insert(int, int, int);

void init(){
    memset(L, -1, sizeof L);
    memset(R, -1, sizeof R);
    memset(U, -1, sizeof U);
    memset(D, -1, sizeof D);
    memset(C, -1, sizeof C);
    memset(S, -1, sizeof S);
    memset(N, -1, sizeof N);
    memset(REM, -1, sizeof REM);

    matched_ = false;
    h_ = MAX - 1;
    L[h_] = R[h_] = h_;
    k = 0;
    int left = h_;
    for(int c = 0; c < COLS; ++c){
        L[k] = left;
        R[left] = k;
        U[k] = D[k] = C[k] = k;
        S[k] = 0;
        left = k++;
    }
    L[h_] = left;
    R[left] = h_;

    for(int r = 0; r < 9; ++r){
        for(int c = 0; c < 9; ++c){
            for(int n = 0; n < 9; ++n){
                REM[r][c][n] = k ;
                insert(r, c, n);
            }
        }
    }

}


void cover(int c){
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for(int i = D[c]; i != c; i = D[i]){
        for(int j = R[i]; j != i; j = R[j]){
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            --S[C[j]];
        }
    }
}

void cover_row(int x, int y, int num){
    int t = REM[x][y][num - 1];
    int c[4];
    for(int i = 0; i < 4; ++i, t = R[t]){
        c[i] = C[t];
    }
    for(int i = 0; i < 4; ++i){
        cover(c[i]);
    }
}

void uncover(int c){
    for(int i = U[c]; i != c; i = U[i]){
        for(int j = L[i]; j != i; j = L[j]){
            ++S[C[j]];
            U[D[j]] = D[U[j]] = j;
        }
    }

    L[R[c]] = R[L[c]] = c;
}

inline void connect(int k, int c){
    D[k] = c;
    U[k] = U[c];
    D[U[k]] = k;
    U[c] = k;
    C[k] = c;
    N[k] = k;
    S[c]++;
}

// n = 0 ~ 8
void insert(int x, int y, int n){
    int c = x * 9 + y;
    int start = -1, left = -1;
    connect(k, c);
    c = C[k];
    start = left = k++;

    int cr = cr_s + x * 9 + n;
    connect(k, cr);
    cr = C[k];
    R[left] = k;
    L[k] = left;
    left = k++;

    int cc = cc_s + y * 9 + n;
    connect(k, cc);
    cc = C[k];
    R[left] = k;
    L[k] = left;
    left = k++;

    int cx = cx_s + ((x / 3) * 3 + y / 3) * 9 + n;
    connect(k, cx);
    cx = C[k];
    R[left] = k;
    L[k] = left;
    left = k++;

    R[left] = start;
    L[start] = left;

}
int search(int k){
    if(R[h_] == h_){
        return k;
    }
    int c = 0;
    int s = 0x3f3f3f3f;
    for(int j = R[h_]; j != h_; j = R[j]){
        if(S[j] < s){
            s = S[j];
            c = j;
        }
    }

    cover(c);
    for(int r = D[c]; r != c; r = D[r]){
        ans[k] = r;
        for(int j = R[r]; j != r; j = R[j]){
            cover(C[j]);
        }
        int step;
        if((step = search(k + 1)) >= 0){
            return step;
        };
        r = ans[k];
        c = C[r];
        for(int j = L[r]; j != r; j = L[j]){
            uncover(C[j]);
        }
    }
    uncover(c);
    return -1;
}

int match(vector<vector<char> > &board){
    int step;
    if((step = search(0)) < 0){
        return 0;
    };
    int i = 0;
    for(i = 0; i < step && -1 != ans[i]; ++i){
        int r = -1, c = -1, n = -1;
        for(int t = ans[i], i = 0; i < 4; ++i, t = R[t]) {
            int col = C[t];
            if(col < cr_s){
                r = col / 9;
                c = col % 9;
            }else if(col < cc_s){
                col -= cr_s;
                n = col % 9 + 1;
            }
            if(r >=0 && c >= 0 && n >= 0){
                break;
            }
        }
        board[r][c] = '0' + n;
    }
    return i;
}


class Solution{
  public:
    void solveSudoku(vector<vector<char> > &board){
        rows_ = cols_ = 9;
        init();
        for(int i = 0; i < rows_; ++i){
            for(int j = 0; j < cols_; ++j){
                auto ch = board[i][j];
                if('.' != ch){
                    int num = ch - '0';
                    cover_row(i, j, num); 
                }
            }
        }
        match(board);
    }
};



int main(){

    Solution slu;
    vector<vector<char> > board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    slu.solveSudoku(board);
    for(auto &r: board){
        for(auto &c: r){
            cout << c;
        }
        cout << endl;
    }


    return 0;
}


