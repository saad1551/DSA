#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Result {
private:
    string student_id;
    string student_name;
    string course_name;
    string marks;
public:
    Result() {

    }
    void SetResult(string student_id, string student_name, string course_name, string marks) {
        this->student_id = student_id;
        this->student_name = student_name;
        this->course_name = course_name;
        this->marks = marks;
    }
    string getStudentID() {
        return student_id;
    }
    string getStudentName() {
        return student_name;
    }
    string getCourseName() {
        return course_name;
    }
    string getMarks() {
        return marks;
    }
    void displayResult() {
        cout << this->student_name << " " << "has scored " << this->marks << " in " << course_name << endl;
    }
};


void ReadResult(fstream& file_pointer, Result array[], string course, int marks_column) {
    string line, word;
    vector<string> row;
    stringstream s;
    getline(file_pointer, line);
    for (int i = 0; i < 40; i++) {
        getline(file_pointer, line);
        s.str(line);
        while(getline(s, word, ',')) {
            row.push_back(word);
        }
        array[i].SetResult(row[0], row[1], course, row[marks_column]);
        row.clear();
        s.clear();
    }
}

int main() {
    fstream CSVFile;
    CSVFile.open("OEL.csv", ios::in);
    if (!CSVFile) {
        cout << "Couldn't open the file. Aborting...";
    }

    Result CommSkills[40];
    Result OOP[40];
    Result DSA[40];
    Result IslamicStudies[40];
    Result DatabaseSystems[40];

    ReadResult(CSVFile, CommSkills, "Communication Skills", 2);
    ReadResult(CSVFile, OOP, "Object Oriented Programming", 3);
    ReadResult(CSVFile, DSA, "Data Structures and Algorithms", 4);
    ReadResult(CSVFile, IslamicStudies, "Islamic Studies", 5);
    ReadResult(CSVFile, DatabaseSystems, "Database Systems", 6);

    for (int i = 0; i < 40; i++) {
        CommSkills[i].displayResult();
    }
}

/* References */
/* https://www.mygreatlearning.com/blog/file-handling-in-cpp/ */
/* https://www.geeksforgeeks.org/csv-file-management-using-c/ */
/* https://www.simplilearn.com/tutorials/cpp-tutorial/string-stream-in-cpp#:~:text=Using%20the%20header%20file,to%20a%20StringStream%20object%20easily. */