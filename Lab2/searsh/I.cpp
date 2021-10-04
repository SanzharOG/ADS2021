#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i) 
    cin >> a[i];
    for(int i = 0; i < k; ++i) {
        int x, l = 0, r = n, l1, r1; 
        cin >> x;
        bool f = 0;
        while(l < r) {
            int mid = (r + l) / 2;
            if(a[mid] == x) {
                l = mid + 1;
                r1 = mid;
                f = 1;
            } else {
                if(a[mid] > x) 
                r = mid;
                else l = mid + 1;
            }
        }   
        if(!f) {
            cout << 0 << endl;
            continue;
        }
        l = 0, r = n;
        while(l < r) {
            int mid = (r + l) / 2;
            if(a[mid] == x) {
                r = mid;
                l1 = mid;
            } else {
                if(a[mid] > x) 
                r = mid;
                else l = mid + 1;
            }
        }  
        cout << l1 + 1 << " " << r1 + 1 << endl;
    }
}