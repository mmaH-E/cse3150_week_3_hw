#include <iostream>
#include <cstring>   // for strlen, strcpy


// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);
// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
    if (size >= capacity){
        throw "List full";
    }
    names[size] = new char[strlen(name) + 1];
    std::strcpy(names[size], name);
    gpas[size] = gpa;
    size ++;
}
// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){

    *gpaPtr = newGpa;

}
// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){
    std::cout << name << std::endl;
    std::cout << gpa << std::endl;
}
// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
    if (size == 0){
        throw "No students";
    }
    double avg = 0;
    for (int i = 0; i<size; i++){
        avg += gpas[i];
    }

    return avg/size;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic

                char buff[100];
                double gpa;
                std::cout << "Enter the student's name: " << std::endl;
                std::cin >> buff;
                std::cout << "Enter the student's gpa: " << std::endl;
                std::cin >> gpa;
                try {
                    addStudent(buff, gpa, names, gpas, size, capacity);
                    
                } catch (const char* msg) {
                    std::cout << msg << std::endl << std::endl;
                }

                break;
            }
            case 2: {
                // TODO: implement menu logic
                int idx;
                double newgpa;
                std::cout << "enter the index of the student and their new gpa: " << std::endl;
                std::cin >> idx >> newgpa;
                if(idx >= size || idx < 0){
                    std::cout << "Invalid index";
                    break;
                }
                updateGPA(&gpas[idx], newgpa);


                break;
            }
            case 3: {
                // TODO: implement menu logic
                for (int i = 0; i < size; i++){
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try {
                    double avg = averageGPA(gpas, size);

                    std::cout << "Average GPA" << std::endl;
                    std::cout << avg << std::endl;
                    
                } 
                catch (const char* msg) {
                    std::cout << msg << std::endl;
                }

                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i = 0; i < size; i++) delete[] names[i];

    return 0;
}
