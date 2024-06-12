#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<int, int>;
using ti3 = tuple<int, int, int>;

vector<string> cmd;
int line;
int rs[55];
int var[30];

void repeat(int, int);
int exec(int);

deque<string> split(string line) {
    deque<string> result;
    stringstream ss(line);
    string tmp;
    while (getline(ss, tmp, ' ')) result.push_back(tmp);
    return result;
}

void print(char v) { cout << v << " = " << var[v - 'a'] << '\n'; }
string trim(const string& s) { return s.substr(s.find_first_not_of(' ')); }

int toNumber(string s) {
    int firstAlpha = find_if(s.begin(), s.end(), ::isalpha) - s.begin();
    if (firstAlpha == s.size()) return stoi(s);
    else if (firstAlpha == 0) return var[s[0] - 'a'];
    else {
        int c = stoi(s.substr(0, firstAlpha));
        char v = s[firstAlpha];
        return var[v - 'a'] * c;
    }
}

void assign(deque<string> expr) {
    int vIdx = expr.front()[0] - 'a';
    expr.pop_front();
    expr.pop_front();
    deque<int> num;
    deque<char> op;
    while (!expr.empty()) {
        string first = expr.front(); expr.pop_front();
        if (first == "+" || first == "-") op.push_back(first[0]);
        else num.push_back(toNumber(first));
    }
    while (!op.empty()) {
        int n1 = num.front(); num.pop_front();
        int n2 = num.front(); num.pop_front();
        char o = op.front(); op.pop_front();
        int result = (o == '+') ? n1 + n2 : n1 - n2;
        num.push_front(result);
    }
    var[vIdx] = num.front() % 10000;
}

void repeat(int line, int rep) {
    int s = line + 1;
    int e = rs[line];
    while (rep--) {
        line = s;
        while (line < e) line += exec(line);
    }
}

int exec(int line) {
    deque<string> sl = split(cmd[line]);
    if (sl[0] == "REPEAT") {
        repeat(line, stoi(sl[1]));
        return rs[line] - line;
    }
    else if (sl[0] == "PRINT") print(sl[1][0]);
    else if (sl[0].size() == 1) assign(sl);
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    stack<int> r;
    r.push(0);
    while (getline(cin, input)) {
        input = trim(input);
        cmd.push_back(input);
        if (input[0] == 'R') r.push(line);
        if (input[0] == 'S') rs[r.top()] = line, r.pop();
        line++;
    }
    line = 0;
    repeat(line, 1);
}