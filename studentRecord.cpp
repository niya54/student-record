#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
class Student {
public:
    int rollNo;
    std::string name;
    std::string subject;

    Student() {}

    Student(int rollNo, std::string name, std::string subject) :
        rollNo(rollNo), name(name), subject(subject) {}

    // Serialize the student data for file storage
    std::string serialize() const {
        std::ostringstream oss;
        oss << rollNo << "," << name << "," << subject << "\n";
        return oss.str();
    }

    // Deserialize the student data from file storage
    static Student deserialize(const std::string& data) {
        std::istringstream iss(data);
        std::string token;
        std::getline(iss, token, ',');
        int roll = std::stoi(token);
        std::getline(iss, token, ',');
        std::string name = token;
        std::getline(iss, token, ',');
        std::string subject = token;
        return Student(roll, name, subject);
    }
};
const std::string fileName = "students.txt";

void addStudent(const Student& student) {
    std::ofstream outFile;
    outFile.open(fileName, std::ios::app);
    outFile << student.serialize();
    outFile.close();
}

std::vector<Student> loadStudents() {
    std::vector<Student> students;
    std::ifstream inFile;
    inFile.open(fileName);
    std::string line;
    while (std::getline(inFile, line)) {
        students.push_back(Student::deserialize(line));
    }
    inFile.close();
    return students;
}

void searchStudent(int rollNo) {
    bool found = false;
    std::vector<Student> students = loadStudents();
    for (const auto& student : students) {
        if (student.rollNo == rollNo) {
            std::cout << "Student Found: " << student.name << " - " << student.subject << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student not found.\n";
    }
}

void changeStudent(int rollNo, const Student& newDetails) {
    std::vector<Student> students = loadStudents();
    std::ofstream outFile;
    outFile.open(fileName);
    bool found = false;
    for (auto& student : students) {
        if (student.rollNo == rollNo) {
            student = newDetails;
            found = true;
        }
        outFile << student.serialize();
    }
    outFile.close();
    if (!found) {
        std::cout << "Student not found to update.\n";
    }
}

void removeStudent(int rollNo) {
    std::vector<Student> students = loadStudents();
    std::ofstream outFile;
    outFile.open(fileName);
    bool found = false;
    for (const auto& student : students) {
        if (student.rollNo != rollNo) {
            outFile << student.serialize();
        } else {
            found = true;
        }
    }
    outFile.close();
    if (!found) {
        std::cout << "Student not found to delete.\n";
    }
}
void showMenu() {
    std::cout << "Student Record Management System\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Search Student\n";
    std::cout << "3. Update Student\n";
    std::cout << "4. Delete Student\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice, rollNo;
    std::string name, subject;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter roll number: ";
                std::cin >> rollNo;
                std::cin.ignore();
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter subject: ";
                std::getline(std::cin, subject);
                addStudent(Student(rollNo, name, subject));
                break;
            case 2:
                std::cout << "Enter roll number to search: ";
                std::cin >> rollNo;
                searchStudent(rollNo);
                break;
            case 3:
                std::cout << "Enter roll number to update: ";
                std::cin >> rollNo;
                std::cin.ignore();
                std::cout << "Enter new name: ";
                std::getline(std::cin, name);
                std::cout << "Enter new subject: ";
                std::getline(std::cin, subject);
                changeStudent(rollNo, Student(rollNo, name, subject));
                break;
            case 4:
                std::cout << "Enter roll number to delete: ";
                std::cin >> rollNo;
                removeStudent(rollNo);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
