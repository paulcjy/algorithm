#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;
#define VV 20000
#define MOD 10000
#define X first
#define Y second

enum CMD { BEGIN, ASSIGN, REPEAT, STOP, PRINT, PASS };
enum TermType { N, NV, V, OP };

pair<CMD, int> cmd[55];
int args[55] = {1};
vector<int> expr[55];
int rs[55];
int var[30];

int exec(int);

TermType checkTerm(string s) {
    if (s == "+" || s == "-") return OP;
    else if (isalpha(s.back())) {
        if (s.size() == 1) return V;
        else return NV;
    }
    else return N;
}

pair<vector<string>, int> split(string s) {
    vector<string> v;
    int firstAlpha = s.find_first_not_of(' ');
    int indent = firstAlpha / 3;
    stringstream ss(s.substr(firstAlpha));
    string t;
    while (getline(ss, t, ' ')) v.push_back(t);
    return {v, indent};
}

void parse(vector<string> e, int i) {
    vector<int>& v = expr[i]; // 수식을 정리해서 저장할 벡터
    int co[26] = {0}; // 각 변수의 계수를 저장할 배열
    int c = 0; // 상수
    int tvar = args[i]; // 수식 결과를 저장할 변수

    for (int i = 0; i < e.size(); i++) {
        TermType tt = checkTerm(e[i]);
        if (tt == OP) {
            string ins = e[i];
            if (checkTerm(e[i+1]) == V) ins += "1";
            e[i+1].insert(0, ins);
        }
        else if (tt == N) c += stoi(e[i]);
        else if (tt == V) co[e[i].back() - 'a'] += 1;
        else if (tt == NV) co[e[i].back() - 'a'] += stoi(e[i]);
    }

    if (co[tvar] != 0) {
        v.push_back(tvar + VV);
        v.push_back(co[tvar] % MOD);
    }
    for (int i = 0; i < 26; i++) {
        if (i != tvar && co[i] != 0) {
            v.push_back(i + VV);
            v.push_back(co[i] % MOD);
        }
    }
    if (c > 0) v.push_back(c % MOD);
}

void print(int i) {
    char v = args[i] + 'a';
    cout << v << " = " << var[args[i]] << '\n';
}

void assign(int i) {
    int sum = 0;
    vector<int>& v = expr[i];
    for (int i = 0; i < v.size(); ) {
        if (v[i] >= VV) {
            sum += var[v[i] - VV] * v[i+1];
            i += 2;
        }
        else sum += v[i++];
    }
    var[args[i]] = sum % 10000;
}

void repeat(int i) {
    int s = i + 1;
    int e = rs[i];
    int r = args[i];
    while (r--) {
        i = s;
        while (i < e) i += exec(i);
    }
}

int exec(int i) {
    if (cmd[i].X == REPEAT) {
        repeat(i);
        return rs[i] - i;
    }
    else if (cmd[i].X == ASSIGN) assign(i);
    else if (cmd[i].X == PRINT) print(i);
    return 1;
}

bool unroll(int i) { // 내부에 PRINT가 있으면 true, 없으면 false
    int s = i + 1;
    int e = rs[i];
    int r = args[i];
    int indent = cmd[s].Y;
    cmd[i].X = cmd[e].X = PASS;
    
    bool hasPrint = false;
    vector<int> unrolling;

    i = s;
    while (i < e) {
        auto [c, ind] = cmd[i];
        if (ind == indent) {
            if (c == REPEAT) hasPrint = unroll(i);
            else if (c == PRINT) hasPrint = true;
            else if (c == ASSIGN) unrolling.push_back(i);
        }
        i++;
    }
    if (hasPrint) return true;
    else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int i = 0;
    string input;
    stack<int> rstack;
    rstack.push(0);
    while (getline(cin, input)) {
        auto [line, indent] = split(input);
        char first = line[0][0];
        if ('a' <= first && first <= 'z') {
            cmd[i] = {ASSIGN, indent};
            args[i] = first - 'a';
            parse(vector<string>(line.begin() + 2, line.end()), i);
        }
        else if (first == 'R') {
            cmd[i] = {REPEAT, indent};
            args[i] = stoi(line.back());
            rstack.push(i);
        }
        else if (first == 'S') {
            cmd[i] = {STOP, indent};
            rs[rstack.top()] = i;
            rstack.pop();
        }
        else if (first == 'P') {
            cmd[i] = {PRINT, indent};
            args[i] = line.back()[0] - 'a';
        }
        i++;
    }
    unroll(0);
    // repeat(0);
}