#include <bits/stdc++.h>

using namespace std;

enum Side {
    U,
    D,
    F,
    B,
    L,
    R
};

int t, n;
char cube[6][3][3];
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
map<char, int> ston{{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}};
string ntos[6] = {"U", "D", "F", "B", "L", "R"};

void initCube() {
    for (int s = 0; s < 6; s++) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[s][i][j] = color[s];
    }
}

void rotateSide(int s, int d) {
    char tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[i][j] = cube[s][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (d) cube[s][j][2-i] = tmp[i][j];
            else cube[s][2-j][i] = tmp[i][j];
}

void turnCube(string order) {
    int side = ston[order[0]];
    int dir = (order[1] == '+') ? 1 : 0;
    rotateSide(side, dir);

    char tmp;
    switch (side) {
        case U:
            if (dir) {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[F][0][i];
                    cube[F][0][i] = cube[R][0][i];
                    cube[R][0][i] = cube[B][0][i];
                    cube[B][0][i] = cube[L][0][i];
                    cube[L][0][i] = tmp;
                }
            }
            else {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[F][0][i];
                    cube[F][0][i] = cube[L][0][i];
                    cube[L][0][i] = cube[B][0][i];
                    cube[B][0][i] = cube[R][0][i];
                    cube[R][0][i] = tmp;
                }
            }
            break;
        case D:
            if (dir) {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[F][2][i];
                    cube[F][2][i] = cube[L][2][i];
                    cube[L][2][i] = cube[B][2][i];
                    cube[B][2][i] = cube[R][2][i];
                    cube[R][2][i] = tmp;
                }
            }
            else {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[F][2][i];
                    cube[F][2][i] = cube[R][2][i];
                    cube[R][2][i] = cube[B][2][i];
                    cube[B][2][i] = cube[L][2][i];
                    cube[L][2][i] = tmp;
                }
            }
            break;
        case F:
            if (dir) {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[U][2][i];
                    cube[U][2][i] = cube[L][2-i][2];
                    cube[L][2-i][2] = cube[D][0][2-i];
                    cube[D][0][2-i] = cube[R][i][0];
                    cube[R][i][0] = tmp;
                }
            }
            else {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[U][2][i];
                    cube[U][2][i] = cube[R][i][0];
                    cube[R][i][0] = cube[D][0][2-i];
                    cube[D][0][2-i] = cube[L][2-i][2];
                    cube[L][2-i][2] = tmp;
                }
            }
            break;
        case B:
            if (dir) {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[U][0][i];
                    cube[U][0][i] = cube[R][i][2];
                    cube[R][i][2] = cube[D][2][2-i];
                    cube[D][2][2-i] = cube[L][2-i][0];
                    cube[L][2-i][0] = tmp;
                }
            }
            else {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[U][0][i];
                    cube[U][0][i] = cube[L][2-i][0];
                    cube[L][2-i][0] = cube[D][2][2-i];
                    cube[D][2][2-i] = cube[R][i][2];
                    cube[R][i][2] = tmp;
                }
            }
            break;
        case L:
            if (dir) {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[U][i][0];
                    cube[U][i][0] = cube[B][2-i][2];
                    cube[B][2-i][2] = cube[D][i][0];
                    cube[D][i][0] = cube[F][i][0];
                    cube[F][i][0] = tmp;
                }
            }
            else {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[U][i][0];
                    cube[U][i][0] = cube[F][i][0];
                    cube[F][i][0] = cube[D][i][0];
                    cube[D][i][0] = cube[B][2-i][2];
                    cube[B][2-i][2] = tmp;
                }
            }
            break;
        case R:
            if (dir) {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[U][i][2];
                    cube[U][i][2] = cube[F][i][2];
                    cube[F][i][2] = cube[D][i][2];
                    cube[D][i][2] = cube[B][2-i][0];
                    cube[B][2-i][0] = tmp;
                }
            }
            else {
                for (int i = 0; i < 3; i++) {
                    tmp = cube[U][i][2];
                    cube[U][i][2] = cube[B][2-i][0];
                    cube[B][2-i][0] = cube[D][i][2];
                    cube[D][i][2] = cube[F][i][2];
                    cube[F][i][2] = tmp;
                }
            }
            break;
    }
}

void printUp() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << cube[U][i][j];
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        initCube();
        cin >> n;
        while (n--) {
            string input;
            cin >> input;
            turnCube(input);
        }
        printUp();
    }
}