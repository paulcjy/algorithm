#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define MOD 10000

enum CmdType { BEGIN, ASSIGN, REPEAT, STOP, PRINT };
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
    vvi root = powMatrix(a, n/2);
    vvi square = mulMatrix(root, root);
    if (n & 1) return mulMatrix(a, square);
    else return square;
}

/////////////////////////////////////////////////
void printMatrix(vvi m) {
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++) cout << m[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

TermType checkTerm(string s) {
    if (isalpha(s.back())) {
        if (s.size() == 1) return V;
        else return NV;
    }
    else return N;
}

void getInput(int i, string line, stack<int>& rs) {
    istringstream iss(line);
    string cmd;
    iss >> cmd;
    if (cmd == "BEGIN") {
        prog[i] = REPEAT;
        args[i] = 1;
        rs.push(i);
    }
    else if (cmd == "REPEAT") {
        prog[i] = REPEAT;
        iss >> args[i];
        rs.push(i);
    }
    else if (cmd == "PRINT") {
        prog[i] = PRINT;
        char v;
        iss >> v;
        args[i] = v - 'a';
    }
    else if (cmd == "STOP") {
        prog[i] = STOP;
        stop[rs.top()] = i;
        rs.pop();
    }
    else { // ASSIGN
        prog[i] = ASSIGN;
        args[i] = cmd[0] - 'a';
        vector<int>& e = expr[i];
        int co[26] = {0};
        int c = 0;
        for (string op, v; iss >> op >> v; ) {
            TermType tt = checkTerm(v);
            int sign = (op == "-") ? -1 : 1;
            if (tt == N) c += stoi(v);
            else if (tt == V) co[v.back() - 'a'] += 1 * sign;
            else if (tt == NV) co[v.back() - 'a'] += stoi(v) * sign;
        }
        e.push_back(c % MOD);
        for (int j = 0; j < 26; j++) {
            if (co[j] != 0) {
                e.push_back(j);
                e.push_back(co[j] % MOD);
            }
        }
    }
}

void getUsedVar() {
    int used[27] = {};
    used[26] = 1;
    for (int i = 1; i < stop[0]; i++)
        if (prog[i] == ASSIGN) used[args[i]]++;
    for (int i = 0; i < 27; i++)
        if (used[i] > 0) usedVar.push_back(i);
}

bool findPrint(int s, int e) {
    for (int i = s; i < e; i++)
        if (prog[i] == PRINT) return true;
    return false;
}

void getRepeatResult(int line) {
    int s = line + 1;
    int e = stop[line];
    int r = args[line];
    vvi result = newIMatrix();
    bool hasPrint = findPrint(s, e);
    for (int i = s; i < e; i++) {
        CmdType cmd = prog[i];
        if (cmd == REPEAT) {
            getRepeatResult(i);
            if (!repeatResult[i].empty())
                result = mulMatrix(repeatResult[i], result);
            i = stop[i];
        }
        else if (!hasPrint && cmd == ASSIGN) {
            vi& v = expr[i];
            int tv = args[i];
            vvi cur = newIMatrix();
            cur[tv][tv] = 0;
            cur[tv][26] = v[0];
            if (v.size() > 1)
                for (int i = 1; i < v.size(); i += 2)
                    cur[tv][v[i]] = v[i + 1];
            result = mulMatrix(cur, result);
        }
    }
    if (!hasPrint) repeatResult[line] = powMatrix(result, r);
}

void updateVar(int i) {
    vvi& matrix = repeatResult[i];
    vi result;
    for (auto i : usedVar) {
        int sum = 0;
        for (auto j : usedVar){
            sum += (matrix[i][j] * var[j]);
            sum %= MOD;
        }
        result.push_back(sum % MOD);
    }
    for (int i = 0; i < result.size(); i++)
        var[usedVar[i]] = result[i];
}

void repeat(int i) {
    int s = i + 1;
    int e = stop[i];
    int r = args[i];
    for (i = s; r--; i = s) {
        while (i < e) {
            CmdType cmd = prog[i];
            if (cmd == REPEAT) {
                if (!repeatResult[i].empty()) updateVar(i);
                else repeat(i);
                i = stop[i] + 1;
            }
            else if (cmd == PRINT) {
                cout << char(args[i] + 'a') << " = " << var[args[i]] << '\n';
                i++;
            }
            else if (cmd == ASSIGN) {
                vi& v = expr[i];
                int sum = v[0];
                if (v.size() > 1) {
                    for (int j = 1; j < v.size(); j += 2) {
                        sum += var[v[j]] * v[j+1];
                        sum %= MOD;
                    }
                }
                var[args[i]] = sum % MOD;
                i++;
            }
            else i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (
        auto [i, line, rs] = tuple{0, string(), stack<int>()};
        getline(cin, line);
        getInput(i++, line, rs)
    );
    var[26] = 1;
    getUsedVar();
    getRepeatResult(0);
    repeat(0);
}