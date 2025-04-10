// 백준 2637 장난감 조립, AC

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using vii = vector<pii>;

vii graph[101];
int dp[101], cnt[101];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    while(m--) {
        int x, y, k;
        cin >> x >> y >> k;
        graph[x].push_back({y, k});
        ++cnt[y];
    }

    queue<int> q;
    q.push(n);
    dp[n] = 1;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        int node = top, mult = dp[node];

        for(pii edge : graph[node]) {
            int next = edge.first, next_mult = edge.second * mult;
            --cnt[next];
            dp[next] += next_mult;
            if(cnt[next] == 0) q.push(next);
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(graph[i].empty()) cout << i << " " << dp[i] << "\n";
    }
}