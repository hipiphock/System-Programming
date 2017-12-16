#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string s1;
    string s2 = "kill -USR1 ";
    getline(cin, s1);
    s1.erase(s1.begin(), s1.begin() + 2);
    s2 = s2 + s1;
    cout << s2;
    system(s2.c_str());
    return 0;
}
