#include <iostream>
#include <map>

using namespace std;

const int Inf = 2 << 29;

int Dijkstra(bool **GR, int V, int st, int fn, bool inv)
{
    int count, index, i, u;
    int *distance = new int[V];
    bool *visited = new bool[V];

    for (i = 0; i < V; i++) {
        distance[i] = Inf; visited[i] = false;
    }

    distance[st] = 0;

    for (count = 0; count < V - 1; count++) {
        int min = Inf;
        for (i = 0; i < V; i++)
            if (!visited[i] && distance[i] <= min) {
                min = distance[i]; index = i;
            }
        u = index;
        visited[u] = true;
        for (i = 0; i < V; i++)
            if (!visited[i] && (GR[u][i] xor inv) && distance[u] != Inf &&
                distance[u] + 1 < distance[i])
                distance[i] = distance[u] + 1;
    }

    return (distance[fn] == Inf ? -1 : distance[fn]);
}

int main() {

    int n, m;

    cin >> n >> m;

    bool** g = new bool*[n];

    for (int i = 0; i < n; i++) {
        g[i] = new bool[n];

        for (int j = 0; j < n; j++)
            g[i][j] = false;
    }

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v][u] = true;
        g[u][v] = true;
    }

    int road = Dijkstra(g, n, 0, n - 1, false);
    int air = Dijkstra(g, n, 0, n - 1, true);

    if (!(road == -1 || air == -1)) {
        int max = road;
        if (max < air)
            max = air;
        cout << max;
    }
    else
        cout << "-1";


    return 0;
}