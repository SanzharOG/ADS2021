#include<bits/stdc++.h>
#define ll long long

using namespace std;

int t, n, k;

string s;

vector<int> p;

void prefix_function() {
    p.resize(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = p[i-1];          
        while (j > 0 && s[i] != s[j]) 
            j = p[j-1];          
        p[i] = j;
        if (s[i] == s[j])
            p[i]++;
    }                            
}

void solve() {
    cin >> s;
    cin >> k;
    n = (int)s.size();
    prefix_function();
    ll length = (ll)(n-p[n-1])*(k-1)+n;
    cout << length << "\n";
}

int main() {
    cin >> t;
    while (t--) 
        solve();
}