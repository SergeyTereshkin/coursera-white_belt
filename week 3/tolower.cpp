#include <iostream>
#include <vector>
#include <cmath>
#include <locale>
#include <algorithm>

using namespace std;


bool comp(int i , int j)
{
    return (abs(i) < abs(j));
}


int main() {
    int n;
    cin >> n;
    vector<string> lines(n);
    for (auto& line : lines)
    {
        cin >> line;
    }
    sort(begin(lines), end(lines), [](const string& s1, const string& s2) {
        string str1;
        string str2;
        for (const auto& c : s1)
        {
            str1 += tolower(c);
        }
        for (const auto& h : s2)
        {
            str2 += tolower(h);
        }
        return (str1 < str2);
    });
    for (const auto& c : lines)
    {
        cout << c << " ";
    }
    return 0;
}
