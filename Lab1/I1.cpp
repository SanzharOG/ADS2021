#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, howmany;
    cin >> n;
    stack<int> st2[5]; // for case when we have only 2 stacks
    stack<int> a[n + 1];
    //create array of stacks
    for (int i = 1; i <= n; i++)
    {
        cin >> howmany;
        for (int j = 0; j < howmany; j++)
        {
            int temp;
            cin >> temp;
            a[i].push(temp);
            if (n == 2)
                st2[i].push(temp);
        }
    }
    if (n == 1)
        return 0;
    bool possible = false;
    // if n == 2 it's hard
    if (n == 2)
    {
        // checker for cases when some of stacks is zero
        int checker = 0;
        if (!st2[1].empty() and st2[2].empty())
        {
            bool isTwoTop = false;
            if (st2[1].top() == 2)
                isTwoTop = true;
            int prev = st2[1].top();
            st2[1].pop();
            while (!st2[1].empty())
            {
                if (st2[1].top() != prev)
                {
                    checker++;
                    prev = st2[1].top();
                }
                st2[1].pop();
            }
            if ((checker == 0 and isTwoTop) or (checker == 1 and isTwoTop) or (checker == 0 and !isTwoTop))
            {
                possible = true;
            }
            else
            {
                cout << 0 << endl;
                return 0;
            }
        }
        else if (st2[1].empty() and !st2[2].empty())
        {
            bool isOneTop = false;
            if (st2[2].top() == 1)
                isOneTop = true;
            int prev = st2[2].top();
            st2[2].pop();
            while (!st2[2].empty())
            {
                if (st2[2].top() != prev)
                {
                    checker++;
                    prev = st2[2].top();
                }
                st2[2].pop();
            }
            if ((checker == 0 and isOneTop) or (checker == 1 and isOneTop) or (checker == 0 and !isOneTop))
            {
                possible = true;
            }
            else
            {
                cout << 0 << endl;
                return 0;
            }
        }
        else if (st2[1].empty() and st2[2].empty())
        {
            return 0;
        }
        else if (!st2[1].empty() and !st2[2].empty())
        {
            bool isOneTopOnFirst = false;
            bool isTwoTopOnSecond = false;
            int check1 = 0;
            int check2 = 0;
            if (st2[1].top() == 1)
                isOneTopOnFirst = true;
            if (st2[2].top() == 2)
                isTwoTopOnSecond = true;
            int prev1 = st2[1].top();
            int prev2 = st2[2].top();
            st2[1].pop();
            st2[2].pop();
            while (!st2[1].empty())
            {
                if (st2[1].top() != prev1)
                {
                    check1++;
                    prev1 = st2[1].top();
                }
                st2[1].pop();
            }
            while (!st2[2].empty())
            {
                if (st2[2].top() != prev2)
                {
                    check2++;
                    prev2 = st2[2].top();
                }
                st2[2].pop();
            }
            if ((isOneTopOnFirst and check1 == 0 and isTwoTopOnSecond and check2 == 0) or
                (isOneTopOnFirst and check1 == 0 and !isTwoTopOnSecond and check2 == 1) or
                (isOneTopOnFirst and check1 == 0 and !isTwoTopOnSecond and check2 == 0) or
                (!isOneTopOnFirst and check1 == 1 and isTwoTopOnSecond and check2 == 0) or
                (!isOneTopOnFirst and check1 == 0 and isTwoTopOnSecond and check2 == 0))
            {
                possible = true;
            }
            else
            {
                // cout << "isOneTopOnFirst " << isOneTopOnFirst << "  isTwoTopOnSecond " << isTwoTopOnSecond << endl;
                // cout << "check1 " << check1 << "  check2 " << check2 << endl;
                cout << 0 << endl;
                return 0;
            }
        }
    }
    //transfer everything to the first
    for (int i = 2; i <= n; i++)
    {
        while (!a[i].empty())
        {
            a[1].push(a[i].top());
            a[i].pop();
            cout << i << " " << 1 << endl;
        }
    }
    //transfer everything from 1 to their indexses, and if 1 to 2nd
    while (!a[1].empty())
    {
        int t = a[1].top();
        if (t == 1)
        {
            a[2].push(t);
            cout << 1 << " " << 2 << endl;
            a[1].pop();
        }
        else
        {
            a[t].push(t);
            cout << 1 << " " << t << endl;
            a[1].pop();
        }
    }
    //transfer from 2 to 1 if 1, and if 2 to 3
    while (!a[2].empty())
    {
        int t = a[2].top();
        if (t == 1)
        {
            a[1].push(t);
            cout << 2 << " " << t << endl;
        }
        else
        {
            if (n != 2)
            {
                a[3].push(t);
                cout << 2 << " " << 3 << endl;
            }
        }
        a[2].pop();
    }
    // trarnsfer from 3 to second if not empty and if it's 2
    if (n != 2 and !a[3].empty())
    {
        while (a[3].top() != 3)
        {
            a[3].pop();
            a[2].push(2);
            cout << 3 << " " << 2 << endl;
        }
    }
    // crazy 193 lines
    return 0;
}