#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;
    map <string, set<string>> synonims;
    for (int i = 0; i < q; i++)
    {
        string command;
        cin >> command;
        if (command == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;
            synonims[word1].insert(word2);
            synonims[word2].insert(word1);
        }
        else if (command == "COUNT")
        {
            string word;
            cin >> word;
            cout << synonims[word].size() << endl;
        }
        else if (command == "CHECK")
        {
            string word1, word2;
            cin >> word1 >> word2;
            if (synonims[word1].count(word2) > 0)
            {
                cout << "YES" << endl;
            } else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
