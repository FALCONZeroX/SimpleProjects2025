#include <iostream>
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
        :║▒▒▒▒║                     •  ATM Simulator  •                      ║▒▒▒▒║:  
         :║▒▒▒║                     -------------------                      ║▒▒▒║:    
          :║▒▒║           |using| • C++ Basics • Conditions • Loops •        ║▒▒║:     
           :║▒║              © Created BY FALCON • 2025 • Be PRO             ║▒║:      
           :╚╦╝                                                              ╚╦╝:     
            :╚════════════════════════════════════════════════════════════════╝:'      
            '':::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::''  
*/

int main()
{
    int default_password = 12345, attempts = 3, balance = 50000, User_Password, choice, withdraw, deposit, menu;
    bool ran = true;
    cout << "========================================================" << endl;
    cout << "====================== ATM Simulator ===================" << endl;
    cout << "========================================================" << endl;
    cout << "Please Enter Your Password" << endl;
    cout << "=> ";
    cin >> User_Password;
    cin.clear();
    cin.ignore(500, '\n');

    while(User_Password != default_password)
    {
        if(attempts == 1)
        {
            cout << "You are Blocked, [Remaining Attempts] => |" << (attempts - 1) << "|" << endl;
            ran = false;
            break;
        }
        attempts--;
        cout << "Wrong Password, Try again [Remaining Attempts] => |" << attempts << "|" << endl;
        cout << "=> ";
        cin >> User_Password;
        cin.clear();
        cin.ignore(500, '\n');
    }

    if(ran == false)
    {
        return 0;
    }

    system("cls");

   do
   {
        system("cls");
        cout << "========================================================" << endl;
        cout << "====================== ATM Simulator ===================" << endl;
        cout << "========================================================" << endl;
        cout << "Welcome to ATM Simulator, Please Choose an Operation:" << endl;
        cout << "1. Show Balance" << endl;
        cout << "2. Cash Withdrawal" << endl;
        cout << "3. Cash Deposit" << endl;
        cout << "4. Change Password" << endl;
        cout << "5. Exit" << endl;
        cout << "=> ";
        cin >> choice;
        cin.clear();
        cin.ignore(500, '\n');

        system("cls");

        switch(choice)
        {
            case 1:
                cout << "========================================================" << endl;
                cout << "========================= BALANCE ======================" << endl;
                cout << "========================================================" << endl;
                cout << "Your Balance is: [" << balance << "] Rials" << endl; 
                cout << " ______________________________________________________" << endl;
                cout << "|     |1| Exit Program      |Any Number| Main Menu     |" << endl;
                cout << "|______________________________________________________|" << endl;
                cout << "=> ";
                cin >> menu;
                if(menu == 1)
                    ran = false;
                else
                    continue;
                break;

            case 2:
                cout << "=========================================================" << endl;
                cout << "==================== Cash Withdrawal ====================" << endl;
                cout << "=========================================================" << endl;
                cout << "How Much money do you want to withdraw?" << endl;
                cout << "=> ";
                cin >> withdraw;
                if(withdraw <= balance)
                {
                cout << ">==[ Successful Operation ]==<" << endl;
                    cout << "- You Withdraw a [" << withdraw << "] Rials From your account" << endl;
                    balance = balance - withdraw;
                    cout << "- Your balance is [" << balance << "] Rials" << endl;
                }
                else
                {
                    cout << "Wrong Operation!, You don't have enough money" << endl;
                }
                cout << " ______________________________________________________" << endl;
                cout << "|     |1| Exit Program      |Any Number| Main Menu     |" << endl;
                cout << "|______________________________________________________|" << endl;
                cout << "=> ";
                cin >> menu;
                if(menu == 1)
                    ran = false;
                else
                    continue;
                break;
            
            case 3:
                cout << "========================================================" << endl;
                cout << "====================== Cash Deposit ====================" << endl;
                cout << "========================================================" << endl;
                cout << "How much money do you want to deposit?" << endl;
                cout << "=> ";
                cin >> deposit;

                cout << ">==[ Successful Operation ]==<" << endl;
                cout << "- You Deposited [" << deposit << "] Rials to your account" << endl;
                balance = balance + deposit;
                cout << "- Your balance is [" << balance << "] Rials" << endl;
                cout << " ______________________________________________________" << endl;
                cout << "|     |1| Exit Program      |Any Number| Main Menu     |" << endl;
                cout << "|______________________________________________________|" << endl;
                cout << "=> ";
                cin >> menu;
                if(menu == 1)
                {
                    ran = false;
                }
                else
                    continue;
                break;

            case 4:
                cout << "========================================================" << endl;
                cout << "==================== Change Password ===================" << endl;
                cout << "========================================================" << endl;
                int first_password, new_password;
                cout << "Enter your Fisrt Password" << endl;
                cout << "=> ";
                cin >> first_password;
                if(first_password == default_password)
                {
                    cout << "----------------------" << endl;
                    cout << "(^_^) Correct Password" << endl;
                    cout << "----------------------" << endl;
                    cout << "- Now, Enter Your New Password" << endl;
                    cout << "=> ";
                    cin >> new_password;
                    default_password = new_password;
                    cout << "---------------------------" << endl;
                    cout << "Your New Password is |" << default_password << "|" << endl;
                    cout << "---------------------------" << endl;
                }
                else
                {
                    cout << "--------------" << endl;
                    cout << "Wrong Password" << endl;
                    cout << "--------------" << endl;
                }
                cout << " ______________________________________________________" << endl;
                cout << "|     |1| Exit Program      |Any Number| Main Menu     |" << endl;
                cout << "|______________________________________________________|" << endl;
                cout << "=> ";
                cin >> menu;
                if(menu == 1)
                    ran = false;
                else
                    continue;
                break;
            
                case 5:
                    cout << "=======================================================" << endl;
                    cout << "========== Thank you for using our service ============" << endl;
                    cout << "=======================================================" << endl;
                    ran = false;
                break;

                default: 
                    cout << "Invalid Choice" << endl; 
        }
    }while(ran);

    return 0;
}
