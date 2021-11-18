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
    string s;
    cin >> s;
    vector<int> pi = prefix_function(s);
    for(int i = 0; i < s.size(); i++){
        cout << pi[i] << " ";
    }
    return 0;
}