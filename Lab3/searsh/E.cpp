#include <iostream>
using namespace std;
int main(){
    int n;
    long long max1 = -9223372036854775805, max2 = -9223372036854775805;
    cin >> n;
    while(n--) {
        long long x; cin >> x;
        if(x > max1) {
            max2 = max1;
            max1 = x;
        } else if(x > max2 && x != max1) {
            max2 = x;
        }
    }
    cout << max2;
}