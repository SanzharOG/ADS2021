#include <iostream>

using namespace std;
int zero (int a, int b) {
    
}
int main () {
    int n, k, count = 0, i = 1, j = 1;
    cin >> n >> k;
    while(i != n + 1 && j != k + 1) {
        if( i == n && j != k ) { i = 0; }
        if( i != n && j == k) { j = 0; }
      
        i++;
        j++;
        count++;
    }   
    cout << count;
}