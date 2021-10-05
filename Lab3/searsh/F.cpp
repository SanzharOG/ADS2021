#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[n];
    long long max = -922337203685477580, min = 922337203685477580;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    for(int i = 0; i < n; ++i) {
        if(a[i]==max){
          a[i]=min;
        }
        cout << a[i] <<" ";
    }
}