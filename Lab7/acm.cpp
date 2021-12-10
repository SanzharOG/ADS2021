#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    long i,sLen, n = 0;
    string str, x, b;
    getline(cin,str);
    sLen = str.length();
    for(i = 0; i < sLen; i++, n++)
        x = str.substr(i,str.length() - i).c_str();
    for(i = 0; i < sLen; i++, n++)
    {   
        str.erase(str.length() - 1);
        b = str.c_str();
    }
    cout<<n<<endl;
    return 0;
}