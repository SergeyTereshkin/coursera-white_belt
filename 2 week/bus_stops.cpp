#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    map <string, vector<string>> routes;
    vector<string> sorted_buses;

    for (int i = 0; i < q; ++i) {
        string code;
        cin >> code;

        if (code == "NEW_BUS") {
            string bus;
            cin >> bus;
            sorted_buses.push_back(bus);
            int bus_count;
            cin >> bus_count;
            for (int j = 0; j < bus_count; j++)
            {
                string stop;
                cin >> stop;
                routes[bus].push_back(stop);
            }

        } else {
            if (code == "BUSES_FOR_STOP") {
                int stop_counter = 0;
                string bus_stop;
                cin >> bus_stop;
                vector<string> true_buses;
                map<int, string> true_order;
                for (auto& m : routes) {
                    for (auto &c : m.second) {
                        if (c == bus_stop) {
                            true_buses.push_back(m.first);
                            stop_counter++;
                        }
                    }
                }
                    for (auto& c : true_buses)
                    {
                        for (int k = 0; k < sorted_buses.size(); k++)
                        {
                            if (c == sorted_buses[k])
                            {
                                true_order[k] = c;
                            }

                        }
                    }
                    for (auto& m : true_order)
                    {
                        cout << m.second << " ";
                    }
                    true_order.clear();
                    true_buses.clear();
                if (stop_counter == 0)
                {
                    cout << "No stop";
                }
                cout << endl;
            }

            else if (code == "STOPS_FOR_BUS") {
                string bus_name;
                int stop_counter = 0;
                cin >> bus_name;
                int bus_counter = routes.count(bus_name);
                if (bus_counter == 0)
                {
                    cout << "No bus" << endl;
                } else
                {
                    map<string, string> buses;
                    vector<string> stops = routes[bus_name];
                    for (auto& stop : stops)
                    {
                        cout << "Stop " << stop << ": ";
                        vector<string> true_buses;
                        map<int, string> true_order;
                        for (auto& m : routes)
                        {
                            if (m.first == bus_name)
                            {
                                continue;
                            }
                            for (auto& c : m.second)
                            {
                                if (c == stop)
                                {
                                    true_buses.push_back(m.first);
                                    stop_counter++;
                                }
                            }

                        }
                        for (auto& c : true_buses)
                        {
                            for (int k = 0; k < sorted_buses.size(); k++)
                            {
                                if (c == sorted_buses[k])
                                {
                                    true_order[k] = c;
                                    break;
                                }

                            }
                        }
                        for (auto& m : true_order)
                        {
                            cout << m.second << " ";
                        }
                        true_order.clear();
                        true_buses.clear();



                        if (stop_counter == 0)
                        {
                            cout << "no interchange";
                        }
                        cout << endl;
                        stop_counter = 0;
                    }
                }

            }
            else if (code == "ALL_BUSES")
            {
                int bus_count = 0;
                for (auto& m : routes)
                {
                    cout << "Bus " << m.first << ": ";
                    bus_count++;
                    for (auto& st : m.second)
                    {
                        cout << st << " ";
                    }
                    cout << endl;
                }
                if (bus_count == 0)
                {
                    cout << "No buses" << endl;
                }
            }
        }
    }

    return 0;
}
