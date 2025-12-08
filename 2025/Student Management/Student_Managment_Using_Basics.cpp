#include <iostream>
#include <string>
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
          :║▒▒║     |using| • C++ Basics • Conditions • Loops • arrays       ║▒▒║:     
           :║▒║              © Created BY FALCON • 2025 • Be PRO             ║▒║:      
           :╚╦╝                                                              ╚╦╝:     
            :╚════════════════════════════════════════════════════════════════╝:'      
            '':::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::''  
*/

int main() 
{
int student_num = 3, ages[student_num], grades[student_num], student_count = 0, choice, list;
string students[student_num];
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
                getline(cin, students[student_count]);  
                  
                cout << "\t\t Enter student age: ";  
                cin >> ages[student_count];  
                cin.clear();  
                cin.ignore(100, '\n');   
                  
                cout << "\t\t Enter student grade: ";  
                cin >> grades[student_count];  
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
                    cout << "\t\t Name => [" << students[i] << "]" << endl;  
                    cout << "\t\t Age => [" << ages[i] << "] years" << endl;  
                    cout << "\t\t Grade => [" << grades[i] << "]" << endl;  
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
                    if(students[i] == searchName)  
                    {  
                        cout << "\t\t ---------------------------" << endl;  
                        cout << "\t\t >==[ Student Found ]==<" << endl;  
                        cout << "\t\t ---------------------------" << endl;  
                        cout << "\t\t Name: " << students[i] << endl;  
                        cout << "\t\t Age: " << ages[i] << " years" << endl;  
                        cout << "\t\t Grade: " << grades[i] << endl;  
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
                    if(students[i] == deleteName)  
                    {  
                        for(int j = i; j < student_count - 1; j++)  
                        {  
                            students[j] = students[j + 1];  
                            ages[j] = ages[j + 1];  
                            grades[j] = grades[j + 1];  
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

