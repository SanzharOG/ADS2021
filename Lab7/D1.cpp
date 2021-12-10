#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if(s[j] == s[i])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    int n, cnt, a;
    cnt = 0;
    cin >> n;
    string s, t;
    for (int k = 0; k < n; k++){
    string x= "";
        cin >> s >> t;
    x =  s + "#" + t;
    cnt = 0;
    vector<int> pi = prefix_function(x);
    for(int i = 0; i < x.size(); i++){
        if(pi[i] == t.size()){
            cnt++;
            cout << i <<" ";
        }
    }
    cout <<"\n";
    if(cnt != 0)
    cout << cnt << "\n";
    else
    cout << "Not Found" << "\n";
    }
    return 0;
}