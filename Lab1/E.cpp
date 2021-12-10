#include <iostream>
#include <deque>
using namespace std;
int main(){
    int cnt = 0; deque <int> d, d1;
    for(cnt = 0; cnt < 5; ++cnt) {
        int x; cin >> x;
        d.push_back(x);
    }
    for(cnt = 0; cnt < 5; ++cnt) {
        int x; cin >> x;
        d1.push_back(x);
    }
    for(cnt = 1; cnt <= 1e6; ++cnt) {
        if(d.front() > d1.front()) {
            if(d.front() == 9 && d1.front() == 0) {
                d1.push_back(d.front());
                d.pop_front();
                d1.push_back(d1.front());
                d1.pop_front();
            } else {
                d.push_back(d.front());
                d.pop_front();
                d.push_back(d1.front());
                d1.pop_front();
            }
        }
        else {
            if(d1.front() == 9 && d.front() == 0) {
                d.push_back(d.front());
                d.pop_front();
                d.push_back(d1.front());
                d1.pop_front();
            } else {
                d1.push_back(d.front());
                d.pop_front();
                d1.push_back(d1.front());
                d1.pop_front();
            }
        }
        if(d.size() == 0) {
            cout << "second " << cnt;
            return 0; 
        }
        if(d1.size() == 0) {
            cout << "first " << cnt;
            return 0;
        }
        
    } 
    cout << "botva";    
}