#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;

vector<int> a;
     
bool check(ll m) {
    ll Sum = 0;
    int cnt = 1;
    for (int x : a) {
        Sum += x;
        if (Sum > m) {
            Sum = x;
            cnt++;
        }
    }
    if (cnt <= k) return 1;
    else return 0;
}

ll ans;

void binsearch() {
    int mx = *max_element(a.begin(), a.end());
    
    ll l = mx;
    ll r = 1e16;
    while (r >= l) {
        ll mid = l + (r-l)/2ll;   
        if (check(mid) == 1) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
}

void input() {
    cin >> n >> k;
    a.resize(n);
    for (int& x : a) cin >> x;
}

int main() {
    input();
    binsearch();
    cout << ans << "\n";
    return 0;
}