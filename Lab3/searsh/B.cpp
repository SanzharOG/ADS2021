#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, max, t;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++){
       cin >> a[i];
    }
    max = a[1];
    for (int i = 1; i <= n; i++){
        if (a[i] >= max){
            t = a[i];
            max = t;
        }
    }
    cout << max;
}