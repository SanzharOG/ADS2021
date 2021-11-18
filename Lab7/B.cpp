#include <bits/stdc++.h>
using namespace std;

int prefix_function (string s) {
	int n = s.size();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return n - pi[s.size()-1];
}

int main(){
    string s;
    cin >> s;  
    int pi = prefix_function(s);
   if(s.size() % pi == 0){
    cout << s.size() / pi;
}
   else cout << 1;
    return 0;
}