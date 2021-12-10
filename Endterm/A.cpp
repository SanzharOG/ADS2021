#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

const int INF = 2 << 29;

int Dijkstra(map<int, int>* g, int n, int st, int fn)
{
    vector<int> d(n, INF), p(n);
    d[st] = 0;
    set < pair<int, int> > q;
    q.insert(make_pair(d[st], st));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (map<int, int> :: iterator j = g[v].begin(); j != g[v].end(); j++) {
            int to = j->first,
                len = j->second;
            if (d[v] + len < d[to]) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(make_pair(d[to], to));
            }
        }
    }

    return (d[fn] == INF ? -1 : d[fn]);

}

int main() {

    int n, m;

    cin >> n >> m;

    map<int, int>* g = new map<int, int>[n];

    for (int i = 0; i < n; i++) {
        g[i].clear();
    }

    for (int i = 0; i < m; i++) { 
        int v, u, c;
        cin >> v >> u >> c;
        v--; u--;
        g[v][u] = c;
        g[u][v] = c;
    }

    int first, second, third, fourth;

    cin >> first >> second >> third >> fourth;

    first--; second--; third--; fourth--;

    int fs = Dijkstra(g, n, first, second);
    int ft = Dijkstra(g, n, first, third);

    int st = Dijkstra(g, n, second, third);
    int sf = Dijkstra(g, n, second, fourth);

    int ts = Dijkstra(g, n, third, second);
    int tf = Dijkstra(g, n, third, fourth);

    int ans = 0;

    if (!(fs == -1 || st == -1 || tf == -1)) {
        ans = fs + st + tf;
    }

    if (!(ft == -1 || ts == -1 || sf == -1)) {
        int v = ft + ts + sf;
        if (ans > v) ans = v;
    }

    if (ans == 0)
        cout << "-1";
    else
        cout << ans;


    return 0;
}