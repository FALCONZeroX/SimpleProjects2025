#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
            ..:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::..          
           .:╔════════════════════════════════════════════════════════════════╗:.       
           :╔╩╗                                                              ╔╩╗:       
           :║▒║     ▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓▓ ▓▓      ▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓▓▓ ▓▓     ▓▓▓    ║▒║:      
          :║▒▒║     ▓▓      ▓▓    ▓▓ ▓▓      ▓▓      ▓▓     ▓▓ ▓▓   ▓▓ ▓▓    ║▒▒║:    
         :║▒▒▒║     ▓▓▓▓▓   ▓▓▓▓▓▓▓▓ ▓▓      ▓▓      ▓▓     ▓▓ ▓▓  ▓▓  ▓▓    ║▒▒▒║:    
        :║▒▒▒▒║     ▓▓      ▓▓    ▓▓ ▓▓      ▓▓      ▓▓     ▓▓ ▓▓ ▓▓   ▓▓    ║▒▒▒▒║:   
       :║▒▒▒▒▒║     ▓▓      ▓▓    ▓▓ ▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓▓▓ ▓▓▓▓    ▓▓    ║▒▒▒▒▒║:  
       :║▒▒▒▒▒║                                                              ║▒▒▒▒▒║:  
        :║▒▒▒▒║                   •  Student Managment  •                      ║▒▒▒▒║:  
         :║▒▒▒║                     -------------------                      ║▒▒▒║:    
          :║▒▒║           |using| • C++ Basics • Conditions • Loops          ║▒▒║:     
           :║▒║              © Created BY FALCON • 2025 • Be PRO             ║▒║:      
           :╚╦╝                                                              ╚╦╝:     
            :╚════════════════════════════════════════════════════════════════╝:'      
            '':::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::''  
*/

int main() 
{
vector <int> student_ages;
vector <int> student_grades;
vector <string> student_name;
string name;
int ages, grades;
int student_num = 3, student_count = 0, choice, list;

bool run_program = true;

while(run_program) 
{
    system("cls");   
    cout << "\t\t -----------------------------------------------------------------------" << endl;  
    cout << "\t\t |                         Student Manager                             |" << endl;  
    cout << "\t\t -----------------------------------------------------------------------" << endl;  
    cout << "\t\t Welcome to Student Management Program, Please choose an option:" << endl;  
    cout << "\t\t |1| Add Student" << endl;  
    cout << "\t\t |2| Show All Students" << endl;  
    cout << "\t\t |3| Search Student" << endl;  
    cout << "\t\t |4| Delete Student" << endl;  
    cout << "\t\t |5| Exit" << endl;  
    cout << "\t\t  => ";  
    
    cin >> choice;  
    cin.clear();  
    cin.ignore(100, '\n');   
    
    
    system("cls");  
    switch(choice)
    {  
        case 1:  
            if(student_count < student_num)  
            {  
                cout << "\t\t -----------------------------------------------------------------------" << endl;  
                cout << "\t\t |                         Add A Student                               |" << endl;  
                cout << "\t\t -----------------------------------------------------------------------" << endl;  
                              
                cout << "\t\t Enter student name: ";  
                getline(cin , name); 
                student_name.push_back(name); 
                  
                cout << "\t\t Enter student age: "; 
                cin >> ages; 
                student_ages.push_back(ages);  
                cin.clear();  
                cin.ignore(100, '\n');   
                  
                cout << "\t\t Enter student grade: ";  
                cin >> grades;
                student_grades.push_back(grades);  
                cin.clear();  
                cin.ignore(100, '\n');   
                  


                student_count++;  
                cout << "\t\t [ Student added successfully ]" << endl;    
                  
                  
            }   
            else  
            {  
                cout << "\t\t -----------------------------------------------------------------------" << endl;  
                cout << "\t\t |                         Add A Student                               |" << endl;  
                cout << "\t\t -----------------------------------------------------------------------" << endl;  
                cout << "\t\t\t\t !!ERROR!! Max Student Numbers" << endl;  
            }  

            cout << endl;  
            cout << "\t\t ------------------------------------------------------------------------" << endl;  
            cout << "\t\t |          |1| Exit Program          |Any Number| Main Page            |" << endl;  
            cout << "\t\t ------------------------------------------------------------------------" << endl;  
            cout << "\t\t => ";  
            cin >> list;  
            cin.clear();  
            cin.ignore(100, '\n');  
            if(list == 1)  
            {  
                run_program = false;  
            }  
            else  
            {  
                continue; 
            }  

            break;  

              
        case 2:  
            cout << "\t\t -----------------------------------------------------------------------" << endl;  
            cout << "\t\t |                         Show All Student                             |" << endl;  
            cout << "\t\t -----------------------------------------------------------------------" << endl;  
              
            if(student_count == 0)
            {  
                cout << "\t\t No students!!!!!!!!!!" << endl;  
            } 
            else 
            {  
                cout << "\t\t -----------------------" << endl;  
                cout << "\t\t | Total Students: [" << student_count << "] |" << endl;  
                cout << "\t\t -----------------------" << endl;  

                cout << endl;  
                for(int i = 0; i < student_count; i++)  
                {  
                    cout << "\t\t ---------------------------" << endl;  
                    cout << "\t\t Student No. [" << (i + 1) << "]:" << endl;  
                    cout << "\t\t ---------------------------" << endl;  
                    cout << "\t\t Name => [" << student_name.at(i) << "]" << endl;  
                    cout << "\t\t Age => [" << student_ages.at(i) << "] years" << endl;  
                    cout << "\t\t Grade => [" << student_grades.at(i) << "]" << endl;  
                    cout << "\t\t ---------------------------" << endl;  
                    cout << endl;  
                }  
            }  
            cout << endl;  
            cout << "\t\t ------------------------------------------------------------------------" << endl;  
            cout << "\t\t |          |1| Exit Program          |Any Number| Main Page            |" << endl;  
            cout << "\t\t ------------------------------------------------------------------------" << endl;  
            cout << "\t\t => ";  
            cin >> list;  
            cin.clear();  
            cin.ignore(100, '\n');  
            if(list == 1)  
            {  
                run_program = false;  
            }  
            else  
            {  
                continue;  
            }  
            break;  
              
        case 3:  
            cout << "\t\t -----------------------------------------------------------------------" << endl;  
            cout << "\t\t |                         Search Student                               |" << endl;  
            cout << "\t\t -----------------------------------------------------------------------" << endl;  
              
            if(student_count == 0)  
            {  
                cout << "\t\t ---------------------------" << endl;   
                cout << "\t\t No students to search!" << endl;  
                cout << "\t\t ---------------------------" << endl;   
            }   
            else  
            {  
                string searchName;  
                cout << "\t\t Enter student name to search: ";  
                getline(cin, searchName);

                cout << endl;
                bool found = false;  
                for(int i = 0; i < student_count; i++)  
                {  
                    if(student_name.at(i) == searchName)  
                    {  
                        cout << "\t\t ---------------------------" << endl;  
                        cout << "\t\t >==[ Student Found ]==<" << endl;  
                        cout << "\t\t ---------------------------" << endl;  
                        cout << "\t\t Name: " << student_name.at(i) << endl;  
                        cout << "\t\t Age: " << student_ages.at(i) << " years" << endl;  
                        cout << "\t\t Grade: " << student_grades.at(i) << endl;  
                        cout << "\t\t ---------------------------" << endl;  
                        found = true;  
                        break;  
                    }  
                }  
                if(!found) 
                { 
                    cout << "\t\t ----------------------" << endl;   
                    cout << "\t\t Student not found!" << endl;  
                    cout << "\t\t ----------------------" << endl;   
                }  
            }  
            cout << endl;  
            cout << "\t\t ------------------------------------------------------------------------" << endl;  
            cout << "\t\t |          |1| Exit Program          |Any Number| Main Page            |" << endl;  
            cout << "\t\t ------------------------------------------------------------------------" << endl;  
            cout << "\t\t => ";  
            cin >> list;  
            cin.clear();  
            cin.ignore(100, '\n');  
            if(list == 1)  
            {  
                run_program = false;  
            }  
            else  
            {  
                continue;  
            }  
            break;  
              
        case 4:  
            cout << "\t\t -----------------------------------------------------------------------" << endl;  
            cout << "\t\t |                         Delete Student                               |" << endl;  
            cout << "\t\t -----------------------------------------------------------------------" << endl;  
              
            if(student_count == 0) 
            {  
                cout << "\t\t No students to delete!" << endl;  
            } 
            else 
            {  
                string deleteName;  
                cout << "\t\t Enter student name to delete: ";  
                getline(cin, deleteName);  
                  
                bool found = false;  
                for(int i = 0; i < student_count; i++)  
                {  
                    if(student_name.at(i) == deleteName)  
                    {  
                        for(int j = i; j < student_count - 1; j++)  
                        {  
                            student_name.at(j) = student_name.at(j + 1);  
                            student_ages.at(j) = student_ages.at(j + 1);  
                            student_grades.at(j) = student_grades.at(j + 1);  
                        }  
                        student_count--;  
                        cout << "\t\t [ Student deleted successfully! ]" << endl;  
                        found = true;  
                        break;  
                    }  
                }  
                  
                if(!found)  
                {  
                    cout << "\t\t ----------------------" << endl;   
                    cout << "\t\t Student not found!" << endl;  
                    cout << "\t\t ----------------------" << endl;   
                }  
            }  
            cout << endl;  
            cout << "\t\t ------------------------------------------------------------------------" << endl;  
            cout << "\t\t |          |1| Exit Program          |Any Number| Main Page            |" << endl;  
            cout << "\t\t ------------------------------------------------------------------------" << endl;  
            cout << "\t\t => ";  
            cin >> list;  
            cin.clear();  
            cin.ignore(100, '\n');  
            if(list == 1)  
            {  
                run_program = false;  
            }  
            else  
            {  
                continue;  
            } 
            break;  
              
        case 5:  
            cout << "\t\t -----------------------------------------------------------------------" << endl;  
            cout << "\t\t |                             GOOD BYE                                 |" << endl;  
            cout << "\t\t -----------------------------------------------------------------------" << endl;  
            run_program = false;  
            break;  
              
        default:  
            cout << "\t\t Invalid choice! Please try again." << endl;  
    }  
}  

return 0;
}

