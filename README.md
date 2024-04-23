# student-record

The Student Record Management System is a C++ program designed to manage student records via a console-based application. This system allows users to perform several operations related to student records, which include adding new records, searching for existing records, updating details, and removing student entries from the system. All these operations use a plain text file (students.txt) as the database to persistently store and manage the student data.
Key Features of the System:

    File-Based Data Storage:
        The system uses a simple text file (students.txt) to store each student's information, including roll number, name, and subject. Each line in the file represents a student record, formatted as "rollNo,name,subject".

    Operations:
        Add Student: Allows the user to add new student records to the system. Each new record is appended to the file.
        Search Student: Facilitates searching for a student by their roll number. The program reads the file and prints the matching student's details.
        Update Student: Enables the modification of an existing student's details. The system rewrites the file with the updated information where needed.
        Delete Student: Removes a student's record from the file by rewriting the file excluding the deleted student's details.

    Serialization and Deserialization:
        The Student class provides methods to serialize (convert to a string suitable for file storage) and deserialize (convert back from the string to a Student object) student data. This functionality facilitates easy reading and writing of student objects to and from the file.

    Menu-Driven Interface:
        The system features a simple text-based menu that guides the user to perform operations. Users select the operation they wish to perform (add, search, update, delete) by entering a corresponding number.
