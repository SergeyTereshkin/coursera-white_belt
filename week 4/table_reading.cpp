#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    ifstream input("input.txt");
    string line1, line2, line;
    if (input) {
        getline(input, line1, ' ');
        getline(input, line2);
        int rows = stoi(line1);
        int columns = stoi(line2);
        for (int i = 0; i < rows - 1; i++)
        {
            for (int j = 0; j < columns - 1; j++)
            {
                getline(input, line, ',');
                cout << setw(10) << line << " ";
            }
            getline(input, line);
            cout << setw(10) << line;
            cout << endl;
        }
        for (int j = 0; j < columns - 1; j++)
        {
            getline(input, line, ',');
            cout << setw(10) << line << " ";
        }
        getline(input, line);
        cout << setw(10) << line;
    }
    return 0;
}

