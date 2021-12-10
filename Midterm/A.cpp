#include <iostream>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    long** rows = new long* [n];

    for (int i = 0; i < n; i++) {
        rows[i] = new long[m];
    }

    long* sums = new long[n], * rows_ind = new long[n];

    for (int i = 0; i < n; i++) {
        sums[i] = 0;
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
            sums[i] += rows[i][j];
            rows_ind[i] = i;
        }
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (sums[j] > sums[i]) {
                long tmp = sums[j];
                sums[j] = sums[i];
                sums[i] = tmp;

                tmp = rows_ind[j];
                rows_ind[j] = rows_ind[i];
                rows_ind[i] = tmp;
            }

    int i = 0;
    while (i < n) {
        long long sum = sums[i];
        int j = i, l = i, r;
        while (j < n && sums[j] == sum) {
            j++;

        r = j - 1;
        i = j;

        for (int d = 0; d < m; d++) {
            for (int j = l; j < r; j++)
                for (int k = j + 1; k <= r; k++)
                    if (rows[rows_ind[k]][d] > rows[rows_ind[j]][d]) {
                        long long tmp = rows_ind[j];
                        rows_ind[j] = rows_ind[k];
                        rows_ind[k] = tmp;
                    }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << rows[rows_ind[i]][j] << " ";
        cout << endl;
    }

    return 0;
}