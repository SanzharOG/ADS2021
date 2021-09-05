#include <bits/stdc++.h>
using namespace std;
int dq[100000];
int start = 50000, tail = 50001;
bool q_empty()
{
    return (start + 1) == tail;
}
void dq_push_front(int x)
{
    dq[start--] = x;
    cout << "ok" << endl;
}
void dq_push_back(int x)
{
    dq[tail++] = x;
    cout << "ok" << endl;
}
void dq_pop_front()
{
    if (q_empty())
        cout << "error" << endl;
    else
        cout << dq[++start] << endl;
}
void dq_pop_back()
{
    if (q_empty())
        cout << "error" << endl;
    else
        cout << dq[--tail] << endl;
}
void dq_front()
{
    if (q_empty())
        cout << "error" << endl;
    else
        cout << dq[start + 1] << endl;
}
void dq_back()
{
    if (q_empty())
        cout << "error" << endl;
    else
        cout << dq[tail - 1] << endl;
}
int dq_size()
{
    return tail - (start + 1);
}
void dq_clear()
{
    start = 50000;
    tail = 50001;
    cout << "ok" << endl;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "size")
            cout << dq_size() << endl;
        else if (s == "push_front")
        {
            int n;
            cin >> n;
            dq_push_front(n);
        }
        else if (s == "push_back")
        {
            int n;
            cin >> n;
            dq_push_back(n);
        }
        else if (s == "front")
            dq_front();
        else if (s == "back")
            dq_back();
        else if (s == "pop_front")
            dq_pop_front();
        else if (s == "pop_back")
            dq_pop_back();
        else if (s == "clear")
            dq_clear();
        else if (s == "exit")
        {
            cout << "bye" << endl;
            return 0;
        }
    }

    return 0;
}