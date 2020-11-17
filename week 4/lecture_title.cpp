#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Specialization {
    string value;
    explicit Specialization(const string& new_specialization) {
        value = new_specialization;
    }
};
struct Course {
    string value;
    explicit Course(const string& new_course) {
        value = new_course;
    }
};
struct Week {
    string value;
    explicit Week(const string& new_week) {
        value = new_week;
    }
};
struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization new_specialization, Course new_course, Week new_week)
    {
        course = new_course.value;
        week = new_week.value;
        specialization = new_specialization.value;
    }
};
