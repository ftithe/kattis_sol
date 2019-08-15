#include<iostream>
#include<string>
#include<vector>

using namespace std;

class student {
private:
    string name;
    vector <int> test_scores;
    int adjusted_total_score;
    int adjusted_total_score_percentage;
    char adjusted_grade;
public:
    student () : adjusted_grade('A') {
    }
    void get_name (string student_name) {
        name = student_name;
    }
    void get_test_scores (int student_score) {
        test_scores.push_back(student_score);
    }
    int total_score ();
    void total_score_percentage (int max_score);
    void grade ();
    void display ();
};

int student::total_score () {
    int lowest_score = 5;
    for (int k = 0; k < test_scores.size() - 1; k++)
        if (lowest_score > test_scores[k])
            lowest_score = test_scores[k];
    int total_score = 0;
    for (int k = 0; k < test_scores.size(); k++)
        total_score += test_scores[k];
    adjusted_total_score = total_score - lowest_score;
    return adjusted_total_score;
}

void student::total_score_percentage (int max_score) {
    if (max_score != 0) {
        double percentage;
        percentage = (adjusted_total_score/static_cast<double>(max_score)) * 100;
        adjusted_total_score_percentage = static_cast<int>(percentage);
        if (percentage - adjusted_total_score_percentage != 0)
            adjusted_total_score_percentage++;
    }
    else
        adjusted_total_score_percentage = 100;
}

void student::grade () {
    if (adjusted_total_score_percentage >= 90)
        adjusted_grade = 'A';
    else if (adjusted_total_score_percentage >= 80 && adjusted_total_score_percentage < 90)
        adjusted_grade = 'B';
    else if (adjusted_total_score_percentage >= 70 && adjusted_total_score_percentage < 80)
        adjusted_grade = 'C';
    else if (adjusted_total_score_percentage >= 60 && adjusted_total_score_percentage < 70)
        adjusted_grade = 'D';
    else
        adjusted_grade = 'F';
}

void student::display () {
    cout<<name<<" "<<adjusted_total_score<<" "<<adjusted_total_score_percentage<<" "<<adjusted_grade<<endl;
}

int main () {
    
    int i, j;
    string stud_name;
    int n_students, n_tests, stud_score;
    vector <student> students;
    
    cin >> n_students >> n_tests;
    
    i = 0;
    while (i < n_students) {
        student student_x;
        cin >> stud_name;
        student_x.get_name(stud_name);
        for (j = 0; j < n_tests + 1; j++) {
            cin >> stud_score;
            student_x.get_test_scores(stud_score);
        }
        students.push_back(student_x);
        i = i + 1;
    }
    
    int max_score = 0;
    for (i = 0; i < students.size(); i++)
        if (max_score < students[i].total_score())
            max_score = students[i].total_score();
    
    for (i = 0; i < students.size(); i++) {
        students[i].total_score_percentage(max_score);
        students[i].grade();
        students[i].display();
    }
    
    return 0;
}
