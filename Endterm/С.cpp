#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std ;

int n, m, x, y, X, used[5001];
vector<int> g[5001], c;
bool isOk = false, CycleEnded;

void dfs(int v) {
    used[v] = 2;
    for( int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if( used[to] == -1) {
            dfs(to);
            if( isOk == true)
            {
                if(CycleEnded == true)
                    return;
                else
                {
                    c.pb(v);
                    if( v == X)
                        CycleEnded = true;
                    return;
                }
            }
        }
        else if (used[to] == 2) {
            isOk = true;
            CycleEnded = false;
            c.pb(v);
            X = to;
            return;
        }
    }
    used[v] = 1;
}
void dfs2(int v) {
    used[v] = 2;
    for( int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if( v == y && to == x)
            continue;
        if( used[to] == -1) {
            dfs2(to);
            if( isOk == true)
            {
                return;
            }
        }
        else if (used[to] == 2) {
            isOk = true;
            return;
        }
    }
    used[v] = 1;
}
int main()
{
    int cnt = 0;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        if(u == v) {
            ++cnt;
            c.pb(x);
            isOk = true;
        }
    }
    if( isOk == true) {
        if( cnt > 1) {
            cout << "NO";
            return 0;
        }
        x = c[0], y = c[0];
        isOk = false;
        for( int j = 1; j <= n; ++j) {
            if(used[j] == 1) {
                dfs2(j);
            }
        }
        if( isOk == true)
            cout << "NO";
        else
            cout << "YES";
        return 0;
    }
    for( int i = 1; i <= n; ++i)
        used[i] = -1;
    for( int i = 1; i <= n; ++i) {
        if( used[i] == -1) {
            dfs(i);
            if( isOk == true)
                break;
        }
    }
    /*for( int i = 0; i < c.size(); ++i)
        cout << c[i] << " ";*/
    if( isOk == false) {
        cout << "YES";
    }
    else {
        for( int i = 1; i <= n; ++i)
            used[i] = -1;
        for( int i = 1; i < c.size(); ++i) {
            x = c[i - 1], y = c[i];
            isOk = false;
            for( int j = 1; j <= n; ++j) {
                if(used[j] == -1) {
                    dfs2(j);
                }
            }
            if( isOk == false) {
                //cout << x << " " << y;
                cout << "YES";
                return 0;
            }
            for( int i = 1; i <= n; ++i)
                used[i] = -1;
        }
        x = c[c.size() - 1], y = c[0];
        for( int i = 1; i <= n; ++i)
            if(used[i] == -1)
                dfs2(i);
        if(isOk == true)
            cout << "NO";
        else
            cout << "YES";
    }
}