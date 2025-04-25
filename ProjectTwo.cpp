/* Jose L
4/14/2025
CS-300*/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Course structure
struct Course {
    string courseId;
    string courseName;
    vector<string> prerequisites;
};

// Hash table class
class HashTable {

// Public access
public:
    void loadStructure(string file);
    void printCourses();
    void searchCourse(unordered_map<string, Course> courses, string courseNum);
    void menu();
    // Converts to upper case
    string toUpper(const string word) {
        string upperCase = word;
        for (auto& ch : upperCase) {
            ch = toupper(ch);
        }

        return upperCase;
    }

// Private access
private:
    ifstream inFS;
    unordered_map<string, Course> table;
};

// Load data into structure
void HashTable::loadStructure(string file) {
    // Open csv file
    inFS.open(file + ".csv");

    // If csv file didn't open throw error and return
    if (!inFS.is_open()) {
        cout << "Error could not open file " << file << "." << endl << endl;
        return;
    }

    string line;
    // Reads the line from inFS and stores line into string
    while (getline(inFS, line)) {
        // Vector to hold parts after split
        vector<string> parts;
        // Temp string to hold parts of line
        string temp = "";
        // Loop through each char in line
        for (char letter : line) {
            // If char equals comma
            if (letter == ',') {
                // Add part of line into vector
                parts.push_back(temp);
                temp = "";
            }
            else {
                // Add the char to the current word
                temp += letter;
            }
        }
        // Add the last word to the vector
        parts.push_back(temp);

        // If vector size is less than 2 throw error and return
        if (parts.size() < 2) {
            cout << "Invalid line format." << line << endl;
            return;
        }

        // Course object
        Course course;
        // First part courseId added to hash
        course.courseId = parts[0];
        // Second part courseName added to hash
        course.courseName = parts[1];

        // Loop through parts starting at third item 
        for (int i = 2; i < parts.size(); ++i) {
            // Make sure the prereq isn't blank
            if (!parts[i].empty()) {  
                // Add the prereq
                course.prerequisites.push_back(parts[i]);
            }
        }

        //Store inside hash table
        table[course.courseId] = course;
    }
    //Close file
    inFS.close();

    // Check if each course prereqs exist in the course list
    for (auto const& pair : table) {
        // Get course
        const Course course = pair.second;

        // Go through each prereq of the current course
        for (auto const& prereq : course.prerequisites) {
            // If prereq isn't in  table throw error
            if (table.count(prereq) == 0) {
                cout << "Prerequisite " << prereq << " for course " << course.courseId << " not found in course list." << endl;
            }
        }
    
    }

    cout << "Data Structure Loaded." << endl << endl;
}

// Print courses in alphanumeric order
void HashTable::printCourses() {
    // Temp vectr to hold strings
    vector<string> temp;

    // For every course in has table
    for (auto const& courses : table) {
        // Get course
        const Course course = courses.second;
        // Combine Id and Name into one
        string fullList = course.courseId + ", " + course.courseName;
        // Add combinded string to temp list
        temp.push_back(fullList);

    }

    // Sort temp list alphanumerically
    sort(temp.begin(), temp.end());
    
    // Print each course
    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i] << endl;

        
    }
    
    cout << endl;
}

// Search by course 
void HashTable::searchCourse(unordered_map<string, Course> table, string courseNum) {
    // If course exist in hash
    if (table.count(courseNum) > 0) {
        // Get course using courseNum
        Course course = table[courseNum];
        // Print the course Id and name
        cout << course.courseId << ", " << course.courseName << endl;

        // If the course has one or more prereqs
        if (course.prerequisites.size() > 0) {
            cout << "Prerequisites: ";
            // Loop through each prereq and print
            for (int i = 0; i < course.prerequisites.size(); i++) {
                cout << course.prerequisites[i];

                // If not last prereq add comma
                if (i < course.prerequisites.size() - 1) {
                    cout << ", ";
                }
            }

            cout << endl;
        }

        cout << endl;
    }

    else {
        // Else course not found throw error
        cout << courseNum << " not found." << endl << endl;
    }
}

// Print menu
void HashTable::menu() {
    int choice = 0;
    cout << "Welcome to the course planner!" << endl << endl;
    // While user choice doesn't equal 9
    while (choice != 9) {
        // Print menu screen
        cout << "Menu:" << endl;
        cout << "  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "What would you like to do? ";
        // Read user input and store
        cin >> choice;

        // If user choice doesn't equal then break
        if (choice == 1 || choice == 2 || choice == 3 || choice == 9) {
            switch (choice) {

            // If choice is 1
            case 1: {
                // Call to add data into structure
                string fileName;
                cout << "Please input file name (without .csv)" << endl;
                cin.ignore();
                getline(cin, fileName);
                loadStructure(fileName);
                break;
            }

            // If choice is 2
            case 2:
                // Call to print out full course list
                cout << endl;
                printCourses();
                break;

            // If choice is 3
            case 3: {
                // Get user input for course
                string course;
                cout << "What course do you want to know about?";
                cin >> course;
                // Call to search for course and print
                searchCourse(table, toUpper(course));
                break;
            }
            }
        }

        else {
            // Else choise invalid throw error
            cout << choice << " is not a valid option." << endl << endl;
        }
    }

    cout << "Thank you for using the course planner!" << endl;
}

int main() {
    // hashTable object
    HashTable newHash;
    // Use object to call menu
    newHash.menu();

    return 0;
}