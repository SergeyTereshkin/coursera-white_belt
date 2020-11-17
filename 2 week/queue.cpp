#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    vector<string> commands(Q + 1);
    vector<bool> queue;
    for (string&s : commands) {
        getline(cin, s);
    }

    for (int i = 1; i < commands.size(); i++) {
        size_t pos = commands[i].find(" ");
        string command1 = commands[i].substr(0, pos);
        if (command1 != "WORRY_COUNT") {
            int number = stoi(commands[i].substr(pos + 1));
            if (command1 == "WORRY") {
                queue[number] = true;
            } else if (command1 == "QUIET") {
                    queue[number] = false;
            } else if (command1 == "COME") {
                queue.resize(queue.size() + number);
            }
        }
        else if (command1 == "WORRY_COUNT")
        {
            int counter = 0;
            for (auto s : queue)
            {
                if (s)
                {
                    counter++;
                }
            }
            cout << counter << endl;
        }
    }
    return 0;
}
