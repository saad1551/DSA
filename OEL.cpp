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
    // operator overloading to check compare the two results based on their marks
    bool operator>(const Result& other) const {
        return marks > other.marks;
    }
};

// Partition function for QuickSort
int partition(Result arr[], int low, int high) {
    // take the last element as the pivot
    Result pivot = arr[high];
    // iterator to move from the left of the array
    int i = low - 1;

    // loop through all the elements of the array
    for (int j = low; j < high; j++) {
        // if the current element is greater than the pivot, increment the iterator and swap the current element with the element at the iterator
        if (arr[j] > pivot) { 
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // move the pivot to its place
    swap(arr[i + 1], arr[high]);
    // return the position of the pivot after partitioning
    return i + 1;
}

// QuickSort function
void quickSort(Result arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

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

// Merge function to merge five sorted arrays
void merge(Result mergedArray[], Result arr1[], int size1, Result arr2[], int size2,
           Result arr3[], int size3, Result arr4[], int size4, Result arr5[], int size5) {
    int i = 0, j = 0, k = 0, l = 0, m = 0;

    while (i < size1 && j < size2 && k < size3 && l < size4 && m < size5) {
        if (arr1[i] > arr2[j] && arr1[i] > arr3[k] && arr1[i] > arr4[l] && arr1[i] > arr5[m]) {
            mergedArray[i + j + k + l + m] = arr1[i++];
        } else if (arr2[j] > arr1[i] && arr2[j] > arr3[k] && arr2[j] > arr4[l] && arr2[j] > arr5[m]) {
            mergedArray[i + j + k + l + m] = arr2[j++];
        } else if (arr3[k] > arr1[i] && arr3[k] > arr2[j] && arr3[k] > arr4[l] && arr3[k] > arr5[m]) {
            mergedArray[i + j + k + l + m] = arr3[k++];
        } else if (arr4[l] > arr1[i] && arr4[l] > arr2[j] && arr4[l] > arr3[k] && arr4[l] > arr5[m]) {
            mergedArray[i + j + k + l + m] = arr4[l++];
        } else {
            mergedArray[i + j + k + l + m] = arr5[m++];
        }
    }

    while (i < size1) {
        mergedArray[i + j + k + l + m] = arr1[i++];
    }

    while (j < size2) {
        mergedArray[i + j + k + l + m] = arr2[j++];
    }

    while (k < size3) {
        mergedArray[i + j + k + l + m] = arr3[k++];
    }

    while (l < size4) {
        mergedArray[i + j + k + l + m] = arr4[l++];
    }

    while (m < size5) {
        mergedArray[i + j + k + l + m] = arr5[m++];
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


    // sort all the arrays based on marks using the quick sort algorithm
    quickSort(CommSkills, 0, 39);
    quickSort(OOP, 0, 39);
    quickSort(DSA, 0, 39);
    quickSort(IslamicStudies, 0, 39);
    quickSort(DatabaseSystems, 0, 39);

    // Merge the arrays while maintaining descending order based on marks
    Result mergedArray[200];  // Assuming the total size of all arrays is 200 (40 students * 5 courses)
    merge(mergedArray, CommSkills, 40, OOP, 40, DSA, 40, IslamicStudies, 40, DatabaseSystems, 40);


    quickSort(mergedArray, 0, 199);


    for (int i = 0; i < 200; i++) {
        mergedArray[i].displayResult();
    }

    return 0;
}

/* References */
/* https://www.mygreatlearning.com/blog/file-handling-in-cpp/ */
/* https://www.geeksforgeeks.org/csv-file-management-using-c/ */
/* https://www.simplilearn.com/tutorials/cpp-tutorial/string-stream-in-cpp#:~:text=Using%20the%20header%20file,to%20a%20StringStream%20object%20easily. */