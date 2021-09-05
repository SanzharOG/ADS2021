#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    for (int i = 2; i <= sqrt(k); i++){
        if (k % i == 0){
            cout <<"composite";
            return 0;
        }
    }
    cout <<"prime";
}