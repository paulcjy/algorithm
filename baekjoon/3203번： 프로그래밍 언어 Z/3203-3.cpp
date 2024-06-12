#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define MOD 10000

enum CmdType { REPEAT, STOP, PRINT, ASSIGN };
enum TermType { N, NV, V };

CmdType prog[55];
int args[55]; // ASSIGN var, REPEAT n, PRINT var
vi expr[55];
vvi repeatResult[55];
int stop[55];
int var[30];
vi usedVar;

vvi newMatrix() { return vvi(27, vi(27, 0)); }

vvi newIMatrix() {
    vvi v = newMatrix();
    for (int i = 0; i < v.size(); i++) v[i][i] = 1;
    return v;
}

vvi mulMatrix(vvi a, vvi b) {
    vvi ret = newMatrix();
    for (auto i : usedVar) {
        for (auto j : usedVar) {
            for (auto k : usedVar) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vvi powMatrix(vvi a, int n) {
    if (n == 1) return a;
    vvi x = powMatrix(a, n/2);
    vvi sq = mulMatrix(x, x);
    if (n & 1) return mulMatrix(a, sq);
    else return sq;
}

TermType checkTerm(string s) {
    if (isalpha(s.back())) {
        if (s.size() == 1) return V;
        else return NV;
    }
    else return N;
}

void getInput() {
    int used[27] = {};
    used[26] = 1;
    stack<int> st;
    for (auto [i, s] = pair{0, string()}; getline(cin, s); i++) {
        istringstream iss(s);
        string cmd;
        iss >> cmd;
        if (cmd == "REPEAT" || cmd == "BEGIN") {
            prog[i] = REPEAT;
            args[i] = 1;
            if (cmd == "REPEAT") iss >> args[i];
            st.push(i);
        }
        else if (cmd == "STOP") {
            prog[i] = STOP;
            stop[st.top()] = i;
            st.pop();
        }
        else if (cmd == "PRINT") {
            prog[i] = PRINT;
            char v; iss >> v;
            args[i] = v - 'a';
        }
        else {
            prog[i] = ASSIGN;
            args[i] = cmd[0] - 'a';
            used[args[i]]++;
            vi& e = expr[i];
            int co[27] = {};
            for (string op, v; iss >> op >> v; ) {
                TermType tt = checkTerm(v);
                int sign = (op == "-") ? -1 : 1;
                if (tt == N) co[26] += stoi(v);
                else if (tt == V) co[v.back() - 'a'] += sign * 1;
                else if (tt == NV) co[v.back() - 'a'] += sign * stoi(v);
            }
            e.push_back(co[26] % MOD);
            for (int j = 0; j < 26; j++) {
                if (co[j]) {
                    e.push_back(co[j] % MOD);
                    e.push_back(j);
                }
            }
        }
    }
    for (int i = 0; i < 27; i++) 
        if (used[i]) usedVar.push_back(i);
}

void getRepeatResult(int line) {
    int s = line + 1;
    int e = stop[line];
    int r = args[line];
    vvi result = newIMatrix();
    bool hasPrint = false;
    for (int i = s; i < e; i++) if (prog[i] == PRINT) hasPrint = true;
    for (int i = s; i < e; i++) {
        if (prog[i] == REPEAT) {
            getRepeatResult(i);
            if (!repeatResult[i].empty()) result = mulMatrix(repeatResult[i], result);
            i = stop[i];
        }
        else if (!hasPrint && prog[i] == ASSIGN) {
            vi& v = expr[i];
            int tv = args[i];
            vvi cur = newIMatrix();
            cur[tv][tv] = 0;
            cur[tv][26] = v[0];
            if (v.size() > 1)
                for (int j = 1; j < v.size(); j += 2) 
                    cur[tv][v[j+1]] = v[j];
            result = mulMatrix(cur, result);
        }
    }
    if (!hasPrint) repeatResult[line] = powMatrix(result, r);
}

void updateVar(int line) {
    vvi& m = repeatResult[line];
    vi result;
    for (auto i : usedVar) {
        int sum = 0;
        for (auto j : usedVar) {
            sum += m[i][j] * var[j];
            sum %= MOD;
        }
        result.push_back(sum);
    }
    for (int i = 0; i < result.size(); i++) var[usedVar[i]] = result[i];
}

void repeat(int line) {
    int s = line + 1;
    int e = stop[line];
    int r = args[line];
    for (int i = s; r--; i = s) {
        while (i < e) {
            if (prog[i] == REPEAT) {
                if (repeatResult[i].size() != 0) updateVar(i);
                else repeat(i);
                i = stop[i];
            }
            else if (prog[i] == PRINT) {
                cout << char(args[i] + 'a') << " = " << var[args[i]] << '\n';
            }
            else if (prog[i] == ASSIGN) {
                vi& v = expr[i];
                int sum = v[0];
                if (v.size() > 1) {
                    for (int j = 1; j < v.size(); j += 2) {
                        sum += v[j] * var[v[j+1]];
                        sum %= MOD;
                    }
                }
                var[args[i]] = sum;
            }
            i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    var[26] = 1;
    getInput();
    getRepeatResult(0);
    repeat(0);
}