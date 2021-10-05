#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++){
       cin >> a[i];
    }
    cin >> x;
    for (int i = 1; i <= n; i++){
        if (a[i] ==x){
            cout << i <<" ";
        }
    }
}