#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int new_year, int new_month, int new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }
    int GetYear() const {
        return year;
    };
    int GetMonth() const {
        return month;
    };
    int GetDay() const {
        return day;
    };
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    }
    if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()) {
        return true;
    }
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() < rhs.GetDay();
};

bool operator==(const Date& lhs, const Date& rhs) {
    return (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}

stringstream& operator>>(stringstream & stream, Date& new_date) {
    stringstream ss1;
    string date;
    stream >> date;
    ss1 << date;
    int day, month, year;
    char c1, c2;
    ss1 >> year >> c1 >> month >> c2 >> day;
    if ((ss1) && ss1.eof() && (c1 == '-') && (c2 == '-') && (1 <= month && month <= 12) && 1 <= day && day <= 31) {
        new_date = Date(year, month, day);
    }
    else if (!ss1 || !ss1.eof() || c1 != '-' || c2 != '-') {
        cout << "Wrong date format: " << date << endl;
        throw exception();
    }
    else if (month >= 1 && month <= 12) {
        cout << "Day value is invalid: " << day << endl;
        throw exception();
    }
    else {
        string error = "Month value is invalid: " + to_string(month);
        cout << "Month value is invalid: " << month << endl;
        throw exception();
    }
    return stream;
}

class Database {
public:
    Database() {
        events[{}] = {""};
    }
    void AddEvent(const Date& date, const string& event) {
        events[date].insert(event);
    };
    bool DeleteEvent(const Date& date, const string& event) {
        set<string> tbdel;
        try {
            tbdel = events.at(date);
        }
        catch (out_of_range& e) {
            return false;
        }
        bool is = tbdel.count(event) > 0;
        events[date].erase(event);
        return is;
    };
    int  DeleteDate(const Date& date) {
        int amount;
        try {
            amount = events[date].size();
        }
        catch (out_of_range& e) {
            return 0;
        }
        events.erase(date);
        return amount;
    };

    set<string> Find(const Date& date) const {
        try {
            events.at(date);
        }
        catch (out_of_range& e) {
            return {};
        }
        return events.at(date);
    };

    void Print() const {
        if (events.empty()) {
            return;
        }
        for (auto& m : events) {
            int cur_year = m.first.GetYear();
            int cur_month = m.first.GetMonth();
            int cur_day = m.first.GetDay();
            set<string> ev;
            ev = m.second;
            set<string> ::iterator itr;
            for (itr = ev.begin(); itr != ev.end(); ++itr) {
                cout << setw(4) << setfill('0') << cur_year << '-'
                     << setw(2) << setfill('0') << cur_month << '-'
                     << setw(2) << setfill('0') << cur_day << " ";
                cout << *itr << endl;
            }
        }
    };
private:
    map<Date, set<string>> events;
};

int main() {
    Database db;
    db.DeleteDate({});
    map<Date, set<string>> events;
    string command;
    string command1;
    while (getline(cin, command)) {
        stringstream ss;
        ss << command;
        ss >> command1;
        if (command.empty()) {
            continue;
        }
        if (command1 == "Add") {
            try {
                string event;
                Date new_date;
                ss >> new_date >> event;
                event.erase(remove_if(event.begin(), event.end(), ::isspace), event.end());
                db.AddEvent(new_date, event);
            }
            catch (exception& e) {
            }
        }
        else if (command1 == "Del") {
            string event;
            Date date;
            try {
                ss >> date;
            }
            catch (exception& e) {
                return 0;
            }
            if (getline(ss, event)) {
                event.erase(remove_if(event.begin(), event.end(), ::isspace), event.end());
                if (db.DeleteEvent(date, event)) {
                    cout << "Deleted successfully" << endl;
                }
                else {
                    cout << "Event not found" << endl;
                }
            }
            else {
                int N = db.DeleteDate(date);
                cout << "Deleted " << N << " events" << endl;
            }
        }
        else if (command1 == "Find") {
            Date date;
            try {
                ss >> date;
            }
            catch (exception& e) {
                return 0;
            }
            set<string> found_events;
            found_events = db.Find(date);
            for (auto& m : found_events) {
                cout << m << endl;
            }
        }
        else if (command1 == "Print") {
            db.Print();
        }
        else {
            cout << "Unknown command: " << command << endl;
        }
    }
    return 0;
}
