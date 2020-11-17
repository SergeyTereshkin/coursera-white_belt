#include <iostream>
#include <exception>
#include <string>
using namespace std;


class TimeServer {
public:
    string GetCurrentTime() {
        try {
            AskTimeServer();
        }
        catch (system_error& e) {
            return last_fetched_time;
        }
        string fetched_time = AskTimeServer();
        last_fetched_time = fetched_time;
        return last_fetched_time;
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    }

private:
    string last_fetched_time = "00:00:00";
};
