#include <string>
#include <iostream>
#include<map>
#include <vector>
using namespace std;
class Person {
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name)
    {
        surname[year] = last_name;
    }
    string GetFullName(int year) {
        /*for (auto & m : initials)
        {
            cout << m.first << " : " << m.second.first_name << " " << m.second.last_name << endl;
        }*/
        if (name.size() == 0 && surname.size() == 0)
        {
            return "Incognito";
        }
        if (year < name.begin()->first && surname.size() == 0 || name.size() == 0 && year < surname.begin()->first || year < name.begin()->first && year < surname.begin()->first) {
            return "Incognito";
        } else if (year < name.begin()->first || name.size() == 0) {
            map<int, string>::iterator itr;
            if (surname.count(year) == 0) {
                itr = surname.lower_bound(year);
                if (itr != surname.begin()) {
                    itr--;
                    return itr->second + " with unknown first name";
                }
            }
            else {
                itr = surname.lower_bound(year);
                return itr->second + " with unknown first name";
            }
        }
        else if (year < surname.begin()->first || surname.size() == 0)
        {
            map<int, string>::iterator itr;
            if (name.count(year) == 0)
            {
                itr = name.lower_bound(year);
                if (itr != name.begin()) {
                    itr--;
                    return itr->second + " with unknown last name";
                }
            }
            else {
                itr = name.lower_bound(year);
                return itr->second + " with unknown last name";
            }
        }
        map<int, string>::iterator  itr1;
        map<int, string>::iterator  itr2;
        switch (name.count(year)) {
            case 0:
                itr1 = name.lower_bound(year);
                itr1--;
                break;
            default:
                itr1 = name.lower_bound(year);
                break;
        }
        switch (surname.count(year)) {
            case 0:
                itr2 = surname.lower_bound(year);
                itr2--;
                break;
            default:
                itr2 = surname.lower_bound(year);
                break;
        }
        return itr1->second + " " + itr2->second;
    }

private:
    map<int, string> name;
    map<int, string> surname;
};
