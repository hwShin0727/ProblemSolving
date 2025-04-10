// 백준 25953 템포럴 그래프 AC

#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;
using vii = vector<pii>;

constexpr int INF = 2'100'000'000;
int dp[2][10000];
vector<pii> t_graph[1000][10000];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int n, t, m, s, e;
    cin >> n >> t >> m >> s >> e;
    for(int i = 0; i != n; ++i) dp[0][i] = dp[1][i] = INF;

    for(int i = 0; i < t; ++i) {
        for(int j = 0; j != m; ++j) {
            int a, b, w;
            cin >> a >> b >> w;
            t_graph[i][a].push_back({b, w});
            t_graph[i][b].push_back({a, w});
        }
    }

    dp[0][s] = dp[1][s] = 0;
    for(int i = 0; i != t; ++i) {
        int dp_cur = i % 2, dp_nxt = (i + 1) % 2;
        for(int j = 0; j != n; ++j) {
            for(pii p : t_graph[i][j]) {
                int nxt = p.first, weight = p.second;
                if(dp[dp_cur][nxt] > weight + dp[dp_cur][j])
                    dp[dp_nxt][nxt] = weight + dp[dp_cur][j];
            }
        }
        for(int j = 0; j != n; ++j) dp[dp_cur][j] = dp[dp_nxt][j];
    }
    
    int ans = dp[0][e] < dp[1][e] ? dp[0][e] : dp[1][e];
    cout << (ans >= INF ? -1 : ans);
}