#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
class student {
private:
    bool file_exists;
    int grade;
    string first_name;
    string last_name;
    int classyear;
    string p1_grade, p2_grade, p3_grade, p4_grade, p5_grade, p6_grade;
    string p1, p2, p3, p4, p5, p6;
public:

    void set_file() {
        cout << "\n\n\t\t---Add Student---" << endl << endl << endl;
        cout << "\tGrade: "; cin >> grade;
        cin.ignore(1000, '\n');
        cout << "\tFirst name: "; cin >> first_name;
        cout << "\tLast name: "; cin >> last_name;
        cout << "\tClass Year: "; cin >> classyear;
        cout << "\tPeriod 1: "; cin >> p1; cout << "Grade: "; cin >> p1_grade;
        cout << "\tPeriod 2: "; cin >> p2; cout << "Grade: "; cin >> p2_grade;
        cout << "\tPeriod 3: "; cin >> p3; cout << "Grade: "; cin >> p3_grade;
        cout << "\tPeriod 4: "; cin >> p4; cout << "Grade: "; cin >> p4_grade;
        cout << "\tPeriod 5: "; cin >> p5; cout << "Grade: "; cin >> p5_grade;
        cout << "\tPeriod 6: "; cin >> p6; cout << "Grade: "; cin >> p6_grade;

        ofstream file(first_name + "_" + last_name + ".txt");

        file << grade << endl << first_name << endl << last_name << endl << classyear << endl << p1 << endl << p1_grade << endl << p2 << endl << p2_grade << endl << p3 << endl << p3_grade << endl << p4 << endl << p4_grade << endl << p5 << endl << p5_grade << endl << p6 << endl << p6_grade;
        file.close();
        ofstream  data("database.txt", ios::app);
        data << first_name << " " << last_name << endl;
        data.close();
    }
    void get_file(string p_first, string p_last) {
        ifstream file(p_first + "_" + p_last + ".txt");
        if (file.is_open()) {
            file >> grade;
            file >> first_name;
            file >> last_name;
            file >> classyear;
            file >> p1;
            file >> p1_grade;
            file >> p2;
            file >> p2_grade;
            file >> p3;
            file >> p3_grade;
            file >> p4;
            file >> p4_grade;
            file >> p5;
            file >> p5_grade;
            file >> p6;
            file >> p6_grade;
            file_exists = true;
        }
        else {
            cout << "\t Error" << endl;
            file_exists = false;
        }
        file.close();
    }

    void get_name_list() {
        string line;
        int i = 1;
        ifstream file("database.txt");
        cout << "\n\n\t\t---Student Files---" << endl << endl << endl;
        while (getline(file, line)) {
            cout << "\t" << i << ". " << line << endl;
            i++;
        }
        file.close();
        cin.ignore(100, '\n');
        cout << "\tPress enter to continue...";
        cin.get();
    }
    void search_student() {
        cout << "\n\n\t\t---Search Student---" << endl << endl << endl;
        string first, last;
        cout << "\tEnter name: ";
        cin >> first >> last;
        get_file(first, last);
        if (file_exists) {
            cout << "\n\n\t\t---Student Info" << endl << endl << endl;
            cout << "\t Name: " << first_name << " " << last_name << endl;
            cout << "\t Grade: " << grade << endl;
            cout << "\t Class Year: " << classyear << endl;
            cout << "\t " << p1 << ": " << p1_grade << endl;
            cout << "\t " << p2 << ": " << p2_grade << endl;
            cout << "\t " << p3 << ": " << p3_grade << endl;
            cout << "\t " << p4 << ": " << p4_grade << endl;
            cout << "\t " << p5 << ": " << p5_grade << endl;
            cout << "\t " << p6 << ": " << p6_grade << endl << endl;
            cin.ignore(100, '\n');
            cout << "\tPress enter to continue...";
            cin.get();
        }
        else {
            cout << "\t Student does not exist!";
        }

    }
    void remove_student() {
        string first;
        string last;
        string name;
        string filename;
        cout << "\n\n\t\t---Delete Student" << endl << endl << endl;
        cout << "\tEnter Student Name: "; cin >> first >> last;
        filename = first + "_" + last + ".txt";
        name = first + " " + last;
        if (remove(filename.c_str()) != 0) {
            cout << "\tError deleting file" << endl;
        }
        else {
            cout << "\tSuccess" << endl;
        }

        string line;
        ifstream filein("database.txt");
        ofstream fileout("temp.txt");

        while (getline(filein, line)) {
            if (line != name) {
                fileout << line << endl;
            }
        }
        filein.close();
        fileout.close();
        remove("database.txt");
        ofstream write("database.txt");
        ifstream read("temp.txt");
        while (getline(read, line)) {
            write << line << endl;
        }
        read.close();
        remove("temp.txt");
        cin.ignore(100, '\n');
        cout << "\tPress enter to continue...";
        cin.get();

    }
    void change_student_data() {
        string first;
        string last;
        int change;
        string line;
        string filename;
        cout << "\n\n\t\t---Edit Student Details---" << endl << endl << endl;
        cout << "\tEnter Student Name: ";
        cin >> first >> last;
        ifstream read(first + "_" + last + ".txt");
        ofstream write("temp.txt");
        if (read.is_open()) {
            cout << "\t\tSelect Change" << endl;
            int u = 2;
            int i = 1;
            while (i < 15) {
                if (i == 1) {
                    cout << "\t" << i << ". Grade" << endl;
                }
                else if (i == 2) {
                    cout << "\t" << i << ". Class Year" << endl;
                }
                else if (i % 2 != 0 && i > 1) {
                    cout << "\t" << i << ".\tPeriod " << i - u << " class" << endl;
                }
                else {
                    cout << "\t" << i << ".\tPeriod " << i - u - 1 << " Grade" << endl;
                    u++;
                }
                i++;
            }
            i = 0;
            cout << "\n\tEnter your option: "; cin >> change;
            if (change == 4)
                change += 2;
            if (change == 3)
                change += 2;
            change -= 1;
            while (getline(read, line)) {
                if (i != change) {
                    write << line << endl;
                }
                else {
                    string s_change;
                    cout << "\tNote: Any name changes wont change inside All Students directory\n\tWhat do you want to change it to: "; cin >> s_change;
                    write << s_change << endl;
                }
                i++;
            }
            read.close();
            write.close();
            filename = first + "_" + last + ".txt";
            remove(filename.c_str());
            ofstream newfile(first + "_" + last + ".txt");
            ifstream temp("temp.txt");
            while (getline(temp, line)) {
                newfile << line << endl;
            }
            newfile.close();
            temp.close();
            remove("temp.txt");
            

        }
        else {
            cout << "\tError" << endl << endl << endl;
        }

    }
};

int main() {
    student s;
    int choice;
    while (true) {
        cout << "\n\n\t\t----Student Database----" << endl << endl << endl;
        cout << "\t1. Search Student" << endl;
        cout << "\t2. All Students" << endl;
        cout << "\t3. Add Student" << endl;
        cout << "\t4. Remove Student" << endl;
        cout << "\t5. Edit Student Data" << endl;
        cout << "\t6. Quit" << endl;
        cout << "\t=> ";  cin >> choice;

        if (choice == 1) {
            system("cls");
            s.search_student();
            system("cls");
        }
        else if (choice == 2) {
            system("cls");
            s.get_name_list();
            system("cls");
        }
        else if (choice == 3) {
            system("cls");
            s.set_file();
            system("cls");
        }
        else if (choice == 4) {
            system("cls");
            s.remove_student();
            system("cls");
        }
        else if (choice == 5) {
            system("cls");
            s.change_student_data();
            system("cls");
        }
        else if (choice == 6) {
            return 0;
        
        }else {
            cout << "\tInvlaid Option";
        }

    }

}