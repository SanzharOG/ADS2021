#include <iostream>

using namespace std;

struct point {
    int x;
    int y;
};

int main() {

    int k;

    cin >> k;

    int* f = new int[k], *inds = new int[k];

    for (int i = 0; i < k; i++) {
        cin >> f[i];
        inds[i] = i;
    }

    for (int i = 0; i < k - 1; i++)
        for (int j = i + 1; j < k; j++)
            if (f[j] > f[i]) {
                int tmp = f[j];
                f[j] = f[i];
                f[i] = tmp;

                tmp = inds[i];
                inds[i] = inds[j];
                inds[j] = tmp;
            }

    int n, m;

    cin >> n >> m;

    int** snake = new int* [n];

    for (int i = 0; i < n; i++)
        snake[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> snake[i][j];

    int c = 0;

    

    point* ans = new point[k];

    for (int i = 0; i < k; i++) {
        ans[i].x = -1;
        ans[i].y = -1;
    }

    int i = 0;
    int j = 0;

    while (i != n && c < k) {
        
        while (snake[i][j] < f[c] && c < k) {
            c++;
        }

        if (snake[i][j] == f[c] && c < k) {
            ans[inds[c]].x = i;
            ans[inds[c]].y = j;
            c++;
        }


        if (i % 2 == 0) {
            j++;

            if (j == m) {
                i++;
                j = m - 1;
            }
        }
        else {
            j--;

            if (j == -1) {
                i++;
                j = 0;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        if (ans[i].x == -1)
            cout << -1 << endl;
        else 
            cout << ans[i].x << " " << ans[i].y << endl;
    }

    return 0;
}