#include <bits/stdc++.h>
using namespace std;
int q[100000];
int start, tail;

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "size")
            cout << tail - start << endl;
        else if (s == "push")
        {
            int n;
            cin >> n;
            q[tail++] = n;
            cout << "ok" << endl;
        }
        else if (s == "clear"){
            tail = 0;
            start = 0;
            cout << "ok" << endl;
        }
        else if (s == "front"){
            if (start == tail)
              cout << "error" << endl;
            else
              cout << q[start] << endl;
        }
        else if (s == "exit")
        {
            cout << "bye" << endl;
            return 0;
        }
        else if (s == "pop"){
            if (start == tail)
             cout << "error" << endl;
            else
             cout << q[start++] << endl;
        }
    }

    return 0;
}