#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;

    map<int, bool> g[200000];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        g[i].clear();
    }

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v - 1][u - 1] = true;
    }


    for (int i = 0; i < n; i++) {
        for (map<int, bool> :: iterator j = g[i].begin(); j != g[i].end(); j++) {
            g[j->first].erase(i);
        }

        g[i].clear();

        int ans = 0;

        for (int j = i + 1; j < n; j++) {
            ans += g[j].size();
        }
        
        cout << ans << endl;
    }

    return 0;
}