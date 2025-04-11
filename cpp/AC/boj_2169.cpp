// 백준 2169 로봇 조종하기 AC

#include <iostream>

using namespace std;
using pii = pair<int, int>;

constexpr int MX = 1'002;
constexpr int INF = 1'000'000'000;
constexpr pii d[] = {
    {1, 0}, {0, -1}, {0, 1} // 0 하 1 좌 2 우
};

int n, m, dp[3][MX][MX], arr[MX][MX];
bool visit[MX][MX];

inline int max(int a, int b) {
    return a > b ? a : b;
}

int run(int r,  int c, int dir = 0) {
    if(r == n && c == m) return arr[r][c];
    if(dp[dir][r][c] != -INF) return dp[dir][r][c];

    visit[r][c] = true;
    int tret = -INF;
    for(int i = 0; i < 3; ++i) {
        const pii p = d[i];
        int nr = r + p.first, nc = c + p.second;
        if(nr < 1 || nc < 1 || nr > n || nc > m || visit[nr][nc]) continue;
        tret = max(tret, run(nr, nc, i));
    }
    visit[r][c] = false;

    return dp[dir][r][c] = tret + arr[r][c];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m; 
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = -INF;
        }
    }
    
    cout << run(1, 1);
}