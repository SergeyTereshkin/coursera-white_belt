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
    string GetFullNameWithHistory(int year)
    {
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
                    cout << itr->second;
                    if (itr != surname.begin())
                    {
                        map<int, string>::iterator  itt;
                        itt = surname.begin();
                        if (itr != ++surname.begin() || itr->second != itt->second)
                        {
                            vector<string> surnames;
                            while (itr != surname.begin())
                            {
                                map<int, string>::iterator  old_itr;
                                old_itr = itr;
                                --itr;
                                if (itr->second != old_itr->second)
                                {
                                    surnames.push_back(itr->second);
                                }
                            }
                            if (!surnames.empty())
                            {
                                vector<string>::iterator  n_itr;
                                n_itr = surnames.end();
                                n_itr--;
                                cout << " (";
                                for (int i = 0; i < surnames.size() - 1; i++)
                                {
                                    cout << surnames[i] << ", ";
                                }
                                cout << *n_itr << ")";
                            }
                        }
                    }
                }
            }
            else {
                itr = surname.lower_bound(year);
                cout << itr->second;
                if (itr != surname.begin())
                {
                    map<int, string>::iterator  itt;
                    itt = surname.begin();
                    if (itr != ++surname.begin() || itr->second != itt->second)
                    {
                        vector<string> surnames;
                        while (itr != surname.begin())
                        {
                            map<int, string>::iterator  old_itr;
                            old_itr = itr;
                            --itr;
                            if (itr->second != old_itr->second)
                            {
                                surnames.push_back(itr->second);
                            }
                        }
                        if (!surnames.empty())
                        {
                            vector<string>::iterator  n_itr;
                            n_itr = surnames.end();
                            n_itr--;
                            cout << " (";
                            for (int i = 0; i < surnames.size() - 1; i++)
                            {
                                cout << surnames[i] << ", ";
                            }
                            cout << *n_itr << ")";
                        }
                    }
                }
            }
            return " with unknown first name";
        }
        else if (year < surname.begin()->first || surname.size() == 0)
        {
            map<int, string>::iterator itr;
            if (name.count(year) == 0) {
                itr = name.lower_bound(year);
                if (itr != name.begin()) {
                    itr--;
                    cout << itr->second;
                    if (itr != name.begin())
                    {
                        map<int, string>::iterator  itt;
                        itt = name.begin();
                        if (itr != ++name.begin() || itr->second != itt->second)
                        {
                            vector<string> names;
                            while (itr != name.begin())
                            {
                                map<int, string>::iterator  old_itr;
                                old_itr = itr;
                                --itr;
                                if (itr->second != old_itr->second)
                                {
                                    names.push_back(itr->second);
                                }
                            }
                            if (!names.empty())
                            {
                                vector<string>::iterator  n_itr;
                                n_itr = names.end();
                                n_itr--;
                                cout << " (";
                                for (int i = 0; i < names.size() - 1; i++)
                                {
                                    cout << names[i] << ", ";
                                }
                                cout << *n_itr << ")";
                            }
                        }
                    }
                }
            }
            else {
                itr = name.lower_bound(year);
                cout << itr->second;
                if (itr != name.begin())
                {
                    map<int, string>::iterator  itt;
                    itt = name.begin();
                    if (itr != ++name.begin() || itr->second != itt->second)
                    {
                        vector<string> names;
                        while (itr != name.begin())
                        {
                            map<int, string>::iterator  old_itr;
                            old_itr = itr;
                            --itr;
                            if (itr->second != old_itr->second)
                            {
                                names.push_back(itr->second);
                            }
                        }
                        if (!names.empty())
                        {
                            vector<string>::iterator  n_itr;
                            n_itr = names.end();
                            n_itr--;
                            cout << " (";
                            for (int i = 0; i < names.size() - 1; i++)
                            {
                                cout << names[i] << ", ";
                            }
                            cout << *n_itr << ")";
                        }
                    }
                }
            }
            return " with unknown last name";
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
        cout << itr1->second + " ";
        if (itr1 != name.begin())
        {
            map<int, string>::iterator  itt;
            itt = name.begin();
            if (itr2 != ++name.begin() || itr1->second != itt->second)
            {
                vector<string> names;
                while (itr1 != name.begin())
                {
                    map<int, string>::iterator  old_itr;
                    old_itr = itr1;
                    --itr1;
                    if (itr1->second != old_itr->second)
                    {
                        names.push_back(itr1->second);
                    }
                }
                if (!names.empty())
                {
                    vector<string>::iterator  n_itr;
                    n_itr = names.end();
                    n_itr--;
                    cout << "(";
                    for (int i = 0; i < names.size() - 1; i++)
                    {
                        cout << names[i] << ", ";
                    }
                    cout << *n_itr << ") ";
                }
            }
        }

        cout << itr2->second;
        if (itr2 != surname.begin())
        {
            map<int, string>::iterator  itt;
            itt = surname.begin();
            if (itr2 != ++surname.begin() || itr2->second != itt->second)
            {
                vector<string> surnames;
                while (itr2 != surname.begin())
                {
                    map<int, string>::iterator  old_itr;
                    old_itr = itr2;
                    --itr2;
                    if (itr2->second != old_itr->second)
                    {
                        surnames.push_back(itr2->second);
                    }
                }
                if (!surnames.empty())
                {
                    vector<string>::iterator  n_itr;
                    n_itr = surnames.end();
                    n_itr--;
                    cout << " (";
                    for (int i = 0; i < surnames.size() - 1; i++)
                    {
                        cout << surnames[i] << ", ";
                    }
                    cout << *n_itr << ")";
                }
            }
        }
        return "";
        }


private:
    map<int, string> name;
    map<int, string> surname;
};







