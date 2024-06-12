#include <bits/stdc++.h>

typedef long long LL;
int readLine(char* buf);


struct Expression {
    int X, Coeff[27]; // 'a'~'z' : denoted as -1, -2, ..., -26
} EXP[50], * EXPPtr;

struct Summary {
    int M[27][27]; // index 0: the identity element '1'
    void InitAsIdentity() {
        memset(M, 0, sizeof(M));
        for (int i = 0; i <= 26; i++) M[i][i] = 1;
    }
    void InitFromExpression(struct Expression* E) {
        InitAsIdentity();
        memcpy(M[E->X], E->Coeff, sizeof(E->Coeff));
    }
    void ApplyComposition(struct Summary* Q) { /* apply this->M and than Q->M. (left matrix product) */
        int T[27][27];
        memcpy(T, M, sizeof(M));

        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                LL val = 0;
                for (int k = 0; k <= 26; k++) {
                    val += Q->M[i][k] * (LL)T[k][j];
                }
                M[i][j] = (int)(val % 10000);
            }
        }
    }
    void ApplySquare() {
        int T[27][27];
        memcpy(T, M, sizeof(M));

        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                LL val = 0;
                for (int k = 0; k <= 26; k++) {
                    val += T[i][k] * (LL)T[k][j];
                }
                M[i][j] = (int)(val % 10000);
            }
        }
    }
    void ApplyPowers(int n) {
        Summary S = *this;
        InitAsIdentity();

        for (int k = 0; k <= 17; k++) {
            if (n & (1 << k)) ApplyComposition(&S);
            S.ApplySquare();
        }
    }
    void Act(int* vars) {
        int T[27];
        memcpy(T, vars, sizeof(T));

        for (int i = 0; i <= 26; i++) {
            int val = 0;
            for (int j = 0; j <= 26; j++) {
                val += M[i][j] * T[j];
            }
            vars[i] = val % 10000;
        }
    }
} SMR[100], * SMRPtr;

struct Block {
    int Type; // 0: expression; 1: REPEAT block; 2: PRINT
    int RepeatCount;
    int Count;
    int PrintTarget;
    struct Block* Children[50];
    struct Expression* E;
    struct Summary* S;
    struct Summary* Eval() {
        if (!S) {
            if (Type == 0) {
                S = SMRPtr++;
                S->InitFromExpression(E);
            }
            else if (Type == 1) {
                S = SMRPtr++;
                S->InitAsIdentity();
                for (int i = 0; i < Count; i++) {
                    auto Q = Children[i]->Eval();
                    if (!Q) {
                        /* blocks with PRINT cannot be summarized into a matrix (hence executed step-by-step) */
                        return S = nullptr;
                    }
                    S->ApplyComposition(Q);
                }
                S->ApplyPowers(RepeatCount);
            }
            else {
                /* PRINT expression cannot be summarized into a matrix */
            }
        }
        return S;
    }
    void Execute(int* vars) {
        struct Summary* S = Eval();
        if (S) {
            S->Act(vars);
        }
        else if (Type == 1) {
            for (int r = 0; r < RepeatCount; r++) {
                for (int i = 0; i < Count; i++) {
                    Children[i]->Execute(vars);
                }
            }
        }
        else if (Type == 2) {
            printf("%c = %d\n", (char)(PrintTarget - 1 + 'a'), vars[PrintTarget]);
        }
    }
} BLK[50], * BLKPtr, * Root;


char Lines[50][300];

void GatherInput() {
    EXPPtr = EXP;
    SMRPtr = SMR;
    BLKPtr = BLK;

    int L = 0;
    while (1) {
        readLine(Lines[L]);
        if (!strncmp(Lines[L], "STOP", 4)) {
            L++;
            break;
        }
        L++;
    }

    strcpy(Lines[0], "REPEAT 1");
    std::function<struct Block* (int, int, int)> Parse = [&](int lv, int S, int E) -> struct Block* {
        struct Block* B = BLKPtr++;
        B->S = nullptr;

        char* p = strtok(Lines[S], " ");
        if (!strncmp(p, "REPEAT", 6)) {
            B->Type = 1;
            B->RepeatCount = atoi(strtok(nullptr, " "));
            B->Count = 0;

            for (int i = S + 1; i < E; ) {
                /* find j */
                int j = i;
                if (!strncmp(Lines[i] + (lv + 1LL) * 3, "REPEAT", 6)) {
                    while (strncmp(Lines[j] + (lv + 1LL) * 3, "STOP", 4)) j++;
                }

                /* recurse */
                B->Children[B->Count++] = Parse(lv + 1, i, j);

                /* progress to next */
                i = j + 1;
            }
        }
        else if (!strncmp(p, "PRINT", 5)) {
            B->Type = 2;
            B->PrintTarget = (int)(*strtok(nullptr, " ") - 'a' + 1);
        }
        else {
            B->Type = 0;
            B->E = EXPPtr++;
            B->E->X = (int)(*p - 'a' + 1);
            memset(B->E->Coeff, 0, sizeof(B->E->Coeff));

            while (p = strtok(nullptr, " ")) {
                int sign = (*p == '-') ? -1 : +1;
                p = strtok(nullptr, " ");

                int M = strlen(p);
                int c, coeff;
                if (p[M - 1] <= '9') {
                    c = 0;
                    coeff = atoi(p);
                }
                else {
                    c = p[M - 1] - 'a' + 1;
                    if (M == 1) coeff = 1;
                    else p[M - 1] = 0, coeff = atoi(p);
                }
                coeff *= sign;
                coeff = (coeff + 10000) % 10000;
                B->E->Coeff[c] += coeff;
                B->E->Coeff[c] %= 10000;
            }
        }

        return B;
    };
    Root = Parse(0, 0, L - 1);
}

void Solve() {
    int vars[27];
    memset(vars, 0, sizeof(vars));
    vars[0] = 1;

    Root->Execute(vars);
}


int main() {
    GatherInput();
    Solve();
    return 0;
}

namespace fio {
    const int BSIZE = 1048576;
    char buffer[BSIZE];
    auto p = buffer + BSIZE;
    size_t count = 0;
    inline char readChar() {
        if (p == buffer + BSIZE) {
            count = fread(buffer, 1, BSIZE, stdin);
            p = buffer;
        }
        if (p == buffer + count) {
            return 0;
        }
        char c = *p++;
        return c;
    }
    int readLine(char* buf) {
        char c;
        do {
            c = readChar();
            if (c == 0) {
                *buf++ = 0;
                return 0;
            }
        } while (c < ' ');
        int len = 0;
        do {
            *buf++ = c;
            len++;
            c = readChar();
        } while (c != '\n' && c != 0);
        *buf++ = 0;
        return len;
    }
}

int readLine(char* buf) {
    return fio::readLine(buf);
}