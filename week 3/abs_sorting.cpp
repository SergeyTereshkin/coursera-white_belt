#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


bool comp(int i , int j)
{
    return (abs(i) < abs(j));
}


int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    sort(begin(numbers), end(numbers), comp);
    for (const auto& c : numbers)
    {
        cout << c << " ";
    }
    return 0;
}
