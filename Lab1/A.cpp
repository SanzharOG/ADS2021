#include <bits/stdc++.h>
using namespace std;
int st[1000];
int h = 0;

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "size")
            cout << h << endl;
        else if (s == "push")
        {
            int n;
            cin >> n;
            st[h++] = n;
            cout << "ok" << endl;
        }
        else if (s == "clear"){
            h = 0;
            cout << "ok" << endl;
        }
        else if (s == "exit")
        {
            cout << "bye" << endl;
            return 0;
        }
        else if (s == "back"){
            if (h != 0)
              cout << st[h - 1] << endl;
            else
              cout << "error" << endl;
        }
        else if (s == "pop"){
            if (h != 0)
             cout << st[--h] << endl;
            else
             cout << "error" << endl;
        }
    }

    return 0;
}