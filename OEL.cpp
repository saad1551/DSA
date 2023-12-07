#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Result {
private:
    int student_id;
    string student_name;
    string course_name;
    float marks;
public:
    // default constructor 
    Result() {

    }
    // function to set the credentials of a particular student
    void SetResult(int student_id, string student_name, string course_name, float marks) {
        this->student_id = student_id;
        this->student_name = student_name;
        this->course_name = course_name;
        this->marks = marks;
    }
    // getter function for ID
    int getStudentID() {
        return student_id;
    }
    // getter function for student name
    string getStudentName() {
        return student_name;
    }
    // getter function for course name
    string getCourseName() {
        return course_name;
    }
    // getter function for marks
    float getMarks() {
        return marks;
    }
    // function to display the result of a particular student in a particular course
    void displayResult() {
        cout << this->student_name << " " << "has scored " << this->marks << " in " << course_name << endl;
    }
};

// function to read the result all the students in an array for a particular subject
void ReadResult(fstream& file_pointer, Result array[], string course, int marks_column) {
    // string variables to store the current line of the CSV file, and the comma separated words in the line
    string line, word;
    // a vector to store all the words of the current row
    vector<string> row;
    // an object to store the current line as a string stream
    stringstream s;
    // go to the beginning of the file
    file_pointer.seekg(0, std::ios::beg);
    // ignore the first line of the file as it contains headers
    getline(file_pointer, line);
    // loop through the 40 rows of the file
    for (int i = 0; i < 40; i++) {
        // read the current line
        getline(file_pointer, line);
        // store the line in the string stream object
        s.str(line);
        // read the words from the line separated by comma and push them one by one into the vector, until the end of the line is reached
        while(getline(s, word, ',')) {
            row.push_back(word);
        }
        // set the result of the particular student in the particular course 
        array[i].SetResult(stoi(row[0]), row[1], course, stof(row[marks_column]));
        // clear the row vector to make it usable for the next iteration
        row.clear();
        // clear the string stream object to store the next line object
        s.clear();
    }
}

int main() {
    // create a file pointer
    fstream CSVFile;
    // open the CSV file and store it in the file pointer
    CSVFile.open("OEL.csv", ios::in);
    // check if opening the file resulted in a failure, in which case abort the program
    if (!CSVFile) {
        cout << "Couldn't open the file. Aborting...";
    }

    // arrays of size 40 for each course to store the marks of 40 students in that course
    Result CommSkills[40];
    Result OOP[40];
    Result DSA[40];
    Result IslamicStudies[40];
    Result DatabaseSystems[40];

    // read the result of each course 
    ReadResult(CSVFile, CommSkills, "Communication Skills", 2);
    ReadResult(CSVFile, OOP, "Object Oriented Programming", 3);
    ReadResult(CSVFile, DSA, "Data Structures and Algorithms", 4);
    ReadResult(CSVFile, IslamicStudies, "Islamic Studies", 5);
    ReadResult(CSVFile, DatabaseSystems, "Database Systems", 6);
}

/* References */
/* https://www.mygreatlearning.com/blog/file-handling-in-cpp/ */
/* https://www.geeksforgeeks.org/csv-file-management-using-c/ */
/* https://www.simplilearn.com/tutorials/cpp-tutorial/string-stream-in-cpp#:~:text=Using%20the%20header%20file,to%20a%20StringStream%20object%20easily. */