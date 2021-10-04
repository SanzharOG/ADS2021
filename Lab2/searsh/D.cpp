#include <iostream>
using namespace std;
int main(){
    int n, m, max, min, ans = 0;
    cin >> n >> m;
    int a[n][m], b[n], c[m];
    for(int i = 0; i < n; ++i) {
        min = 1001;
        for(int j = 0; j < m; ++j) { 
            cin >> a[i][j];
            if(a[i][j] < min) min = a[i][j];
        }
        b[i] = min;
    }
    for(int i = 0; i < m; ++i) {
        max = -1001;
        for(int j = 0; j < n; ++j) {
            if(a[j][i] > max) max = a[j][i];
        }
        c[i] = max;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == b[i] && a[i][j] == c[j]) ans++;
        }
    }
    cout << ans;
}