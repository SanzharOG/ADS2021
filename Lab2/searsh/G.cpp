#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i) 
       cin >> a[i]; 
    for(int i = 0; i < k; ++i) {
        int x, l = 0, r = n; cin >> x;
        bool f = 0;
        while(l < r) {
            int mid = (r + l) / 2;
            if(a[mid] == x) {
                cout << "YES" << endl;
                f = 1;
                break;
            } else {
                if(a[mid] > x ) r = mid;
                else l = mid + 1; 
            }
        }
        if(!f) cout << "NO" << endl;
    }
}