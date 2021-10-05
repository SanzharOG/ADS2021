#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct heap {
    int h[N];
    int hs;

    heap(){
        hs = 0;
    }

    void add(int x) {
        int i = hs++;
        h[i] = x;
        int p = (i - 1) / 2;
        while(i && h[i] > h[p]) {
            swap(h[i], h[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }

    void increase(int num, int x) {
        int i = --num;
        h[num] += x;
        int p = (i - 1) / 2;
        while(i && h[i] > h[p]) {
            swap(h[i], h[p]);
            i = p;
            p = (i - 1) / 2;
        }
        cout << i + 1 << endl;
    }

    void print() {
        int i = 0;
        while(i < hs) {
            cout << h[i] << " ";
            i++;
        }
    }
};

int main(){
    int n, m;
    heap he;
    cin >> n;
    while(n--) {
        int x; cin >> x;
        he.add(x);
    }
    cin >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        he.increase(x, y);
    }
    he.print();
}