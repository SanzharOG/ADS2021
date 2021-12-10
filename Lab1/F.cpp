#include <iostream>
#include <stack>
using namespace std;
int main(){
    char c;
    stack <char> q;
    while(cin >> c) {
        if(c == '[' || c == '(' || c == '{') q.push(c);
        else {
            if(q.size() == 0) {
                cout << "no";
                return 0;
            }
            if(c == ']') {
                if(q.top() == '[') q.pop();
                else {
                    cout << "no";
                    return 0;
                }
            } else if(c == ')') {
                if(q.top() == '(') q.pop();
                else {
                    cout << "no";
                    return 0;
                }
            } else {
                if(q.top() == '{') q.pop();
                else {
                    cout << "no";
                    return 0;
                }
            }
        }
    }
    if(q.size() == 0) cout << "yes";
    else cout << "no";
}