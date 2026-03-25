#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
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
        :║▒▒▒▒║                   •  BANK Simple System  •                   ║▒▒▒▒║:  
         :║▒▒▒║                     -------------------                      ║▒▒▒║:    
          :║▒▒║      |using| • C++ Basics • Conditions • Vector • Functions  ║▒▒║:     
           :║▒║                 © Created BY FALCON • 2026 •                 ║▒║:      
           :╚╦╝                                                              ╚╦╝:     
            :╚════════════════════════════════════════════════════════════════╝:'      
            '':::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::''  
*/

const string Seperator = string(67, '-');
const string Clients_File_Name = "Clients.txt";
const string Users_File_Name = "Users.txt";

struct stClientData
{
    string Account_NO;
    string Pin_Code;
    string Name;
    string Phone_Number;
    double Balance;
    bool Delete_Client = false;
};
struct stUsers
{
    string UserName;
    string PassWord;
    //Permissions
    bool All;
    bool Show_Clients_Permission;
    bool Add_Clients_Permission;
    bool Delete_Clients_Permission;
    bool Update_Clients_Permission;
    bool Find_Clients_Permission;
    bool Tranactions_Permission;
    bool User_Manager_Permission;
    bool Delete_User = false;
};
enum ReadMode
{
    Add,
    Update
};
enum back_To
{
    Main_Menu_Screen,
    Transactions_Screen, 
    User_Manager_Screen
};

stUsers *Current_User = nullptr;

/*Basic Functions*/
void Main_Menu(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Show_All_Clients(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Add_New_Client(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Delete_Client(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Update_Clients(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Find_Client(vector <stClientData> &vClients, vector <stUsers> &vUsers);
/*Extension 1 (Transactions)*/
void Transactions_Menu_Screen(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Deposit_And_Withdraw(vector <stClientData> &vClients, vector <stUsers> &vUsers, string Operation);
void Total_Balances(vector <stClientData> &vClients, vector <stUsers> &vUsers);
/*Extension 2 (Login Screen)*/
void Login_Screen(vector <stUsers> &vUsers, vector <stClientData> &vClients);
/*Extension 3 (User Manager)*/
void User_Manager(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Users_List(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Add_New_User(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Delete_User(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Update_User(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Find_User(vector <stClientData> &vClients, vector <stUsers> &vUsers);
/*Reading From User Functions*/
int Read_Integer_Number(string message);
double Read_Double_Number(string message);
string Read_String_Line(string message);
char Read_Charachter();
stClientData Read_Client_Record(vector <stClientData> &vClients, ReadMode read, const string Acc_NO);
stUsers Read_Users_Record(vector <stUsers> &vUsers);
/*Export & Import Functions*/
void Export_Clients_Data_To_TXT(vector <stClientData> &vClients,  string filename);
void Export_Users_Data_To_TXT(vector <stUsers> &vUsers,  string filename);
vector <stClientData> Import_Data_TXT_To_Clients(string filename, char delimiter);
vector <stUsers> Import_Data_TXT_To_Users(string filename, char delimiter);
/*Other Helpful Functions*/
string Convert_Clients_Vector_To_String_Line(stClientData Data, char delimiter);
void Print_Client_Info(stClientData client);
void Print_User_Info(stUsers user);
void Show_Access_Denied_Message(vector <stClientData> &vClients, vector <stUsers> &vUsers);
void Clear_Buffer();
/*Header & Messages Functions*/
void Header_Message(int Line_Size, char Symbol, int left_size, int right_size, string text);
void Message(vector <stClientData> &vClients, vector <stUsers> &vUsers, string txt, back_To back);

int main()
{
    vector <stClientData> vClients = Import_Data_TXT_To_Clients(Clients_File_Name, '-');
    vector <stUsers> vUsers = Import_Data_TXT_To_Users(Users_File_Name, '-');

    Login_Screen(vUsers, vClients);
}

/*Basic Functions*/
void Main_Menu(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("color 0F");
    system("cls");
    Header_Message(67, '=', 27, 27, " BANK SYSTEM ");
    cout << "\t\t\tCURRENT USER [" << Current_User->UserName << "] " << endl;
    cout << Seperator << endl;
    cout << "(1) Show All Clients" << endl;
    cout << "(2) Add New Client" << endl;
    cout << "(3) Delete Client" << endl;
    cout << "(4) Update Client Info" << endl;
    cout << "(5) Find Client" << endl;
    cout << "(6) Transactions" << endl;
    cout << "(7) User Manager" << endl;
    cout << "(8) Logout" << endl;
    cout << "(9) Exit" << endl;
    cout << string(45, '-') << endl;
    int choice = Read_Integer_Number("Please Enter Your Choice");

    switch(choice)
    {
        case 1:
            if(Current_User->Show_Clients_Permission)
                Show_All_Clients(vClients, vUsers);
            else
                Show_Access_Denied_Message(vClients, vUsers);
            break;
        case 2:
            if(Current_User->Add_Clients_Permission)
                Add_New_Client(vClients, vUsers);
            else
                Show_Access_Denied_Message(vClients, vUsers);
            break;
        case 3:
            if(Current_User->Delete_Clients_Permission)
                Delete_Client(vClients, vUsers);
            else
                Show_Access_Denied_Message(vClients, vUsers);
            break;
        case 4:
            if(Current_User->Update_Clients_Permission)
                Update_Clients(vClients, vUsers);
            else
                Show_Access_Denied_Message(vClients, vUsers);
            break;
        case 5:
            if(Current_User->Find_Clients_Permission)
                Find_Client(vClients, vUsers);
            else
                Show_Access_Denied_Message(vClients, vUsers);
            break;
        case 6:
            if(Current_User->Tranactions_Permission)
                Transactions_Menu_Screen(vClients, vUsers);
            else
                Show_Access_Denied_Message(vClients, vUsers);
            break;
        case 7:
            if(Current_User->User_Manager_Permission)
                User_Manager(vClients, vUsers);
            else
                Show_Access_Denied_Message(vClients, vUsers);
            break;
        case 8:
            Clear_Buffer();
            Login_Screen(vUsers, vClients);
            break;
        case 9:
            exit(0);
            break;
        default:
            Main_Menu(vClients, vUsers);
            break;
    }
}
void Show_All_Clients(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    if(vClients.empty())
    {
        system("color 40");
        system("cls");
        Header_Message(67, '=', 25, 24, " Show All Clients ");  
        Message(vClients, vUsers, "No Enought Data To Display", back_To::Main_Menu_Screen);     
    }
    else
    {
        system("color 60");
        system("cls");
        Header_Message(67, '=', 25, 24, " Show All Clients ");
        cout << "\t\t     Client List (" << vClients.size() << ") Clients(s)" << endl;
        cout << Seperator << endl;
        cout << left << setw(13) << "Account NO" << setw(10) << "Pin Code" << setw(21) << "Client Name" << setw(13) << "Phone" << setw(12) << "Balance" << endl;
        cout << Seperator << endl;
        float Total = 0;
        for(stClientData &client : vClients)
        {
            if(client.Delete_Client == false)
            {
                cout << left << setw(13) << client.Account_NO << setw(10) << client.Pin_Code << setw(21) << client.Name << setw(13) << client.Phone_Number << setw(12) << client.Balance << endl;
                Total += client.Balance;
            }
        }
        cout << Seperator << endl;
        cout << left << setw(57) << "Total Amount" << setw(12) << Total << endl;
        Message(vClients, vUsers, "End of Report", back_To::Main_Menu_Screen);
    }
}
void Add_New_Client(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    while(true)
    {
        system("cls");
        Header_Message(67, '=', 26, 25, " Add New Client ");
        vClients.push_back(Read_Client_Record(vClients, ReadMode::Add, ""));
        Export_Clients_Data_To_TXT(vClients, Clients_File_Name);

        cout << Seperator << endl;
        cout << "Do U Want To add More Clients?" << endl;
        cout << Seperator << endl;
        cout << "|Y| Yes" << endl;
        cout << "|Any Key| No - Return To Main Menu" << endl;
        cout << Seperator << endl;

        char choice = Read_Charachter();
        switch(choice)
        {
            case 'y':
            case 'Y':
                continue;
                break;
            default:
                system("color 20");
                Message(vClients, vUsers, "Client Added Successfully", back_To::Main_Menu_Screen);
                break;
        }
    }
}
void Delete_Client(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("cls");
    Header_Message(67, '=', 26, 26, " Delete Client ");
    Clear_Buffer();
    string tmp_NO = Read_String_Line("Please Enter Account NO To Delete");
    bool found = false;
    for(stClientData &client : vClients)
    {
        if(tmp_NO == client.Account_NO)
        {
            system("color 20");
            Print_Client_Info(client);
            cout << endl;
            cout << Seperator << endl;
            cout << "Are You Sure You Want To Delete This Client?" << endl;
            cout << Seperator << endl;
            cout << "|Y| Yes" << endl;
            cout << "|Any Key| No - Return To Main Menu" << endl;
            cout << Seperator << endl;

            char choice = Read_Charachter();
            switch(choice)
            {
                case 'y':
                case 'Y':
                    client.Delete_Client = true;
                    Export_Clients_Data_To_TXT(vClients, Clients_File_Name);
                    break;
                default:
                    Main_Menu(vClients, vUsers);
                    break;
            }
            found = true;
            break;
        }
    }

    if(!found)
    {
        system("color 40");
    }
    
    Message(vClients, vUsers, found ? "Client Deleted Successfully" : "Client Not Found", back_To::Main_Menu_Screen);
}
void Update_Clients(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("cls");
    Header_Message(67, '=', 26, 26, " Update Client ");
    Clear_Buffer();
    string tmp_NO = Read_String_Line("Please Enter Account NO To Update");
    bool found = false;

    for(stClientData &client : vClients)
    {
        if(tmp_NO == client.Account_NO)
        {
            system("color 20");
            Print_Client_Info(client);
            cout << endl;
            cout << Seperator << endl;
            cout << "Are You Sure You Want To Update This Client?" << endl;
            cout << Seperator << endl;
            cout << "|Y| Yes" << endl;
            cout << "|Any Key| No - Return To Main Menu" << endl;
            cout << Seperator << endl;

            char choice = Read_Charachter();
            switch(choice)
            {
                case 'y':
                case 'Y':
                    client = Read_Client_Record(vClients, ReadMode::Update, client.Account_NO);
                    Export_Clients_Data_To_TXT(vClients, Clients_File_Name);
                    system("color 20");
                    break;
                default:
                    Main_Menu(vClients, vUsers);
                    break;
            }
            found = true;
            break;
        }
    }

    if(!found)
    {
        system("color 40");
    }
    
    Message(vClients, vUsers, found ? "Client Updated Successfully" : "Client Not Found", back_To::Main_Menu_Screen);
}
void Find_Client(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("cls");
    Header_Message(67, '=', 26, 26, " Update Client ");
    Clear_Buffer();
    string tmp_NO = Read_String_Line("Please Enter Account NO or Name To Seaerh");
    bool found = false;
    for(stClientData &client : vClients)
    {
        if(tmp_NO == client.Account_NO || tmp_NO == client.Name)
        {
            system("color 20");
            Print_Client_Info(client);
            found = true;
        }
    }

    if(!found)
    {
        system("color 40");
    }
    
    Message(vClients, vUsers, found ? "Search Done Successfully" : "Client Not Found", back_To::Main_Menu_Screen);
}
/*Extension 1 (Transactions)*/
void Transactions_Menu_Screen(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("color 0F");
    system("cls");
    Header_Message(67, '=', 20, 21, " Transactions Menu Screen ");
    cout << "(1) Deposit" << endl;
    cout << "(2) Withdraw" << endl;
    cout << "(3) Total Balance" << endl;
    cout << "(4) Return To Main Menu" << endl;
    cout << string(45, '-') << endl;   
    int choice = Read_Integer_Number("Please Enter Your Choice");

    switch(choice)
    {
        case 1:
            Deposit_And_Withdraw(vClients, vUsers, "Deposit");
            break;
        case 2:
            Deposit_And_Withdraw(vClients, vUsers, "Withdraw");
            break;
        case 3:
            Total_Balances(vClients, vUsers);
            break;
        case 4:
            Main_Menu(vClients, vUsers);
            break;
        default:
            Transactions_Menu_Screen(vClients, vUsers);
            break;
    }
}
void Deposit_And_Withdraw(vector <stClientData> &vClients, vector <stUsers> &vUsers,  string Operation)
{
    system("cls");
    Header_Message(67, '=', 29, 29, " " + Operation + " ");
    Clear_Buffer();
    string tmp_NO = Read_String_Line("Enter Account NO To " + Operation);
    bool found = false;

    for(stClientData &client : vClients)
    {
        if(tmp_NO == client.Account_NO)
        {
            Print_Client_Info(client);
            cout << endl;
            double Amount = Read_Double_Number("Please Enter " + Operation + " Amount");

            if(Operation == "Deposit")
                client.Balance += Amount;
            else
            {
                if(client.Balance < Amount)
                {
                    system("color 40");
                    Message(vClients, vUsers, "Not Enough Credit", back_To::Transactions_Screen);
                }
                client.Balance -= Amount;
            }

            cout << Seperator << endl;
            cout << "\t\t\t New Balance is: [" << client.Balance << "]" << endl;
            Export_Clients_Data_To_TXT(vClients, Clients_File_Name);
            system("color 20");
            found = true;
            break;
        }
    }

    if(!found)
    {
        system("color 40");
    }
    
    Message(vClients, vUsers, found ? Operation + " Done Successfully" : "Client Not Found", back_To::Transactions_Screen);
}
void Total_Balances(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    if(vClients.empty())
    {
        system("color 40");
        system("cls");
        Header_Message(67, '=', 22, 22, " Total Balances ");
        Message(vClients, vUsers, "No Enought Data To Display", back_To::Transactions_Screen);     
    }
    else
    {
        system("color 60");
        system("cls");
        Header_Message(67, '=', 25, 26, " Total Balances ");
        cout << "\t\t     Balance List (" << vClients.size() << ") Clients(s)" << endl;
        cout << Seperator << endl;
        cout << left << setw(18) << "Account NO" << setw(29) << "Client Name" << setw(12) << "Balance" << endl;
        cout << Seperator << endl;
        float Total = 0;
        for(stClientData &client : vClients)
        {
            if(client.Delete_Client == false)
            {
                cout << left << setw(18) << client.Account_NO << setw(29) << client.Name << setw(12) << client.Balance << endl;
                Total += client.Balance;
            }
        }
        cout << Seperator << endl;
        cout << "\t\t\t Total Amount = " << Total << endl;
        Message(vClients, vUsers, "End of Report", back_To::Transactions_Screen);
    }
}
/*Extension 2 (Login Screen)*/
void Login_Screen(vector <stUsers> &vUsers, vector <stClientData> &vClients)
{
    system("cls");
    Header_Message(67, '=', 21, 20, " BANK SYSTEM LOGIN SCREEN ");    
    int attempts = 3;
    do
    {
        string username = Read_String_Line("Enter Username");
        string Password = Read_String_Line("Enter Password");
        for(stUsers &user : vUsers)
        {
            if(username == user.UserName && Password == user.PassWord)
            {
                Current_User = &user;
                Main_Menu(vClients, vUsers);
            }
        }
        system("color 60");
        attempts--;
        cout << Seperator << endl;
        cout << "Invalid Username/Password, Remaining Attempts [" << attempts << "]" << endl; 
        cout << Seperator << endl;
    } while (attempts > 0);

    system("cls");
    system("color 40");
    Header_Message(67, '=', 26, 27, " LOGIN SCREEN ");  
    cout << Seperator << endl;
    cout << "\t\t\t You're Blocked" << endl; 
    cout << Seperator << endl;
}
/*Extension 3 (User Manager)*/
void User_Manager(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("color 0F");
    system("cls");
    Header_Message(67, '=', 26, 27, " USER MANAGER ");
    cout << "(1) Users List" << endl;
    cout << "(2) Add New User" << endl;
    cout << "(3) Delete User" << endl;
    cout << "(4) Update User" << endl;
    cout << "(5) Find User" << endl;
    cout << "(6) Return To Main Menu" << endl;
    cout << string(45, '-') << endl;   
    int choice = Read_Integer_Number("Please Enter Your Choice");

    switch(choice)
    {
        case 1:
            Users_List(vClients, vUsers);
            break;
        case 2:
            Add_New_User(vClients, vUsers);
            break;
        case 3:
            Delete_User(vClients, vUsers);
            break;
        case 4:
            Update_User(vClients, vUsers);
            break;
        case 5:
            Find_User(vClients, vUsers);
            break;
        case 6:
            Main_Menu(vClients, vUsers);
        default:
            User_Manager(vClients, vUsers);
            break;
    }
}
void Users_List(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    if(vUsers.empty())
    {
        system("color 40");
        system("cls");
        Header_Message(67, '=', 26, 25, " Show All Users ");  
        Message(vClients, vUsers, "No Enought Data To Display", back_To::User_Manager_Screen);     
    }
    else
    {
        system("color 60");
        system("cls");
        Header_Message(67, '=', 26, 25, " Show All Users ");
        cout << "\t\t     Users List (" << vUsers.size() << ") User(s)" << endl;
        cout << Seperator << endl;
        cout << "  " << left << setw(37) << " " << setw(25) << "Permissions" << endl;
        cout << "  " << left << setw(11) << "UserName" << setw(11) << "PassWord" << setw(5) << string(43, '-') << endl;
        cout << "  " << left << setw(22) << " " << setw(7) << "SC" << setw(6) << "AC" << setw(6) << "DC" << setw(6) << "UC" << setw(6) << "FC" << setw(6) << "TRAN" << setw(6) << "UM" << endl;
        cout << left << setw(49) << Seperator << endl;
        for(stUsers &user : vUsers)
        {
            if(user.Delete_User == false)
            {
                cout << "  " << left << setw(11) << user.UserName << setw(11) << user.PassWord << setw(7) << user.Show_Clients_Permission << setw(6) << user.Add_Clients_Permission << setw(6) << user.Delete_Clients_Permission << setw(6) << user.Update_Clients_Permission << setw(6) << user.Find_Clients_Permission << setw(6) << user.Tranactions_Permission << setw(6) << user.User_Manager_Permission << endl;
            }
        }
        cout << Seperator << endl;
        cout << endl;
        cout << Seperator << endl;
        cout << "Permissions Keys Map:" << endl;
        cout << Seperator << endl;
        cout << "SC = Show Clients" << endl;
        cout << "AC = Add Clients" << endl;
        cout << "DC = Delete Clients" << endl;
        cout << "UC = Update Clients" << endl;
        cout << "FC = Find Clients" << endl;
        cout << "TRAN = Transactions" << endl;
        cout << "UM = User Manager" << endl;
        Message(vClients, vUsers, "End of Users List", back_To::User_Manager_Screen);
    }
}
void Add_New_User(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    while(true)
    {
        system("cls");
        Header_Message(67, '=', 27, 26, " Add New User ");
        vUsers.push_back(Read_Users_Record(vUsers));
        Export_Users_Data_To_TXT(vUsers, Users_File_Name);

        cout << Seperator << endl;
        cout << "Do U Want To add More Users?" << endl;
        cout << Seperator << endl;
        cout << "|Y| Yes" << endl;
        cout << "|Any Key| No" << endl;
        cout << Seperator << endl;

        char choice = Read_Charachter();
        switch(choice)
        {
            case 'y':
            case 'Y':
                continue;
                break;
            default:
                system("color 20");
                Message(vClients, vUsers, "User Added Successfully", back_To::User_Manager_Screen);
                break;
        }
    }
}
void Delete_User(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("cls");
    Header_Message(67, '=', 27, 27, " Delete User ");
    Clear_Buffer();
    string tmp_user = Read_String_Line("Please Enter Username To Delete");
    bool found = false;
    for(stUsers &user : vUsers)
    {
        if(tmp_user == "Admin")
        {
            system("cls");
            system("color 40");
            Header_Message(67, '=', 27, 27, " Delete User ");
            Message(vClients, vUsers, "You Can't Delete This User Because This is The Admin User", back_To::User_Manager_Screen);
        }

        if(tmp_user == Current_User->UserName)
        {
            system("cls");
            system("color 40");
            Header_Message(67, '=', 27, 27, " Delete User ");
            Message(vClients, vUsers, "You Can't Delete This User Because it is Currently Used", back_To::User_Manager_Screen);
        }

        if(tmp_user == user.UserName)
        {
            system("color 20");
            Print_User_Info(user);
            cout << endl;
            cout << Seperator << endl;
            cout << "Are You Sure You Want To Delete This User?" << endl;
            cout << Seperator << endl;
            cout << "|Y| Yes" << endl;
            cout << "|Any Key| No - Return To User Manager" << endl;
            cout << Seperator << endl;

            char choice = Read_Charachter();
            switch(choice)
            {
                case 'y':
                case 'Y':
                    user.Delete_User = true;
                    Export_Users_Data_To_TXT(vUsers, Users_File_Name);
                    break;
                default:
                    User_Manager(vClients, vUsers);
                    break;
            }
            found = true;
            break;
        }
    }

    if(!found)
    {
        system("color 40");
    }
    
    Message(vClients, vUsers, found ? "User Deleted Successfully" : "User Not Found", back_To::User_Manager_Screen);
}
void Update_User(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("cls");
    Header_Message(67, '=', 27, 27, " Update User ");
    Clear_Buffer();
    string tmp_user = Read_String_Line("Please Enter Username To Update");
    bool found = false;

    for(stUsers &user : vUsers)
    {
        if(tmp_user == "Admin")
        {
            system("cls");
            system("color 40");
            Header_Message(67, '=', 27, 27, " Update User ");
            Message(vClients, vUsers, "You Can't Update This User Because This is The Admin User", back_To::User_Manager_Screen);
        }

        if(tmp_user == Current_User->UserName)
        {
            system("cls");
            system("color 40");
            Header_Message(67, '=', 27, 27, " Update User ");
            Message(vClients, vUsers, "You Can't Update This User Because it is Currently Used", back_To::User_Manager_Screen);
        }

        if(tmp_user == user.UserName)
        {
            system("color 20");
            Print_User_Info(user);
            cout << endl;
            cout << Seperator << endl;
            cout << "Are You Sure You Want To Update This User?" << endl;
            cout << Seperator << endl;
            cout << "|Y| Yes" << endl;
            cout << "|Any Key| No - Return To User Manager" << endl;
            cout << Seperator << endl;

            char choice = Read_Charachter();
            switch(choice)
            {
                case 'y':
                case 'Y':
                    user = Read_Users_Record(vUsers);
                    Export_Users_Data_To_TXT(vUsers, Users_File_Name);
                    system("color 20");
                    break;
                default:
                    User_Manager(vClients, vUsers);
                    break;
            }
            found = true;
            break;
        }
    }

    if(!found)
    {
        system("color 40");
    }
    
    Message(vClients, vUsers, found ? "User Updated Successfully" : "User Not Found", back_To::User_Manager_Screen);
}
void Find_User(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("cls");
    Clear_Buffer();
    Header_Message(67, '=', 28, 28, " Find User ");
    string tmp_user = Read_String_Line("Please Enter Username To Search");
    bool found = false;
    for(stUsers &user : vUsers)
    {
        if(tmp_user == user.UserName)
        {
            system("color 20");
            Print_User_Info(user);
            found = true;
        }
    }

    if(!found)
    {
        system("color 40");
    }
    
    Message(vClients, vUsers, found ? "Search Done Successfully" : "User Not Found", back_To::User_Manager_Screen);
}
/*Reading From User Functions*/
int Read_Integer_Number(string message)
{
    int num;
    cout << message << endl;
    cout << ">> ";
    cin >> num;
    while(cin.fail() || num < 0)
    {
        if(cin.fail())
        {
            system("color 40");
            Clear_Buffer();
            cout << "Invalid Charachter, Please Re-Enter A Valid Value" << endl;
            cout << ">> ";
            cin >> num;
        }
        else
        {
            system("color 40");
            Clear_Buffer();
            cout << "Invalid Value, Value Must be > 0" << endl;
            cout << ">> ";
            cin >> num;
        }
    }

    system("color 0F");
    return num;
}
double Read_Double_Number(string message)
{
    double num;
    cout << message << endl;
    cout << ">> ";
    cin >> num;
    while(cin.fail() || num < 0)
    {
        if(cin.fail())
        {
            system("color 40");
            Clear_Buffer();
            cout << "Invalid Charachter, Please Re-Enter A Valid Value" << endl;
            cout << ">> ";
            cin >> num;
        }
        else
        {
            system("color 40");
            Clear_Buffer();
            cout << "Invalid Value, Value Must be > 0" << endl;
            cout << ">> ";
            cin >> num;
        }
    }
    system("color 0F");
    return num;
}
string Read_String_Line(string message)
{
    string txt;
    cout << message << endl;
    cout << ">> ";
    getline(cin, txt);
    return txt;
}
char Read_Charachter()
{
    char ch;
    cout << ">> ";
    cin >> ch;
    return ch;
}
bool Read_Boolean(string message)
{
    char choice;
    cout << message << endl;
    cout << ">> ";
    cin >> choice;
    switch(choice)
    {
        case 'y':
        case 'Y':
            return true;
            break;
        default:
            return false;
            break;
    }
}
stClientData Read_Client_Record(vector <stClientData> &vClients, ReadMode read, const string Acc_NO)
{
    stClientData data;

    switch(read)
    {
        case ReadMode::Add:
            Clear_Buffer();
            data.Account_NO = Read_String_Line("Please Enter Account Number");
            for(int i = 0; i < vClients.size(); i++)
            {
                for(stClientData &client : vClients)
                {
                    while(data.Account_NO == client.Account_NO)
                    {
                        i == 0;
                        data.Account_NO = Read_String_Line("Client (" + data.Account_NO + ") Already Exist, Please ReEnter Another No");
                    }
                }   
            }
            break;
        case ReadMode::Update:
            data.Account_NO = Acc_NO;
            break;
        }
    data.Pin_Code = Read_String_Line("Please Enter Pin Code");  
    data.Name = Read_String_Line("Please Enter Client Name");
    data.Phone_Number = Read_String_Line("Please Enter Phone Number");
    data.Balance = Read_Double_Number("Please Enter Client Balance");

    return data;
}
stUsers Read_Users_Record(vector <stUsers> &vUsers)
{
    stUsers data;

    Clear_Buffer();
    data.UserName = Read_String_Line("Please Enter UserName");

    for(int i = 0; i <= vUsers.size(); i++)
    {
        for(stUsers &user : vUsers)
        {
            if(data.UserName == user.UserName)
            {
                i = 0;
                data.UserName = Read_String_Line("User (" + data.UserName + ") Already Exist, Please ReEnter Another One");
            }
        }
    }

    
    data.PassWord = Read_String_Line("Please Enter Password");
    data.All = Read_Boolean("Do You Want To Give All Permission Y/N?");
    if(data.All == 1)
    {
        data.Add_Clients_Permission = 1;
        data.Delete_Clients_Permission = 1;
        data.Find_Clients_Permission = 1;
        data.Show_Clients_Permission = 1;
        data.Tranactions_Permission = 1;
        data.Update_Clients_Permission = 1;
        data.User_Manager_Permission = 1;
    }
    else
    {
        data.Show_Clients_Permission = Read_Boolean("Show Clients Permission Y/N?");
        data.Add_Clients_Permission = Read_Boolean("Add Clients Permission Y/N?");
        data.Delete_Clients_Permission = Read_Boolean("Delete Clients Permission Y/N?");
        data.Update_Clients_Permission = Read_Boolean("Update Clients Permission Y/N?");
        data.Find_Clients_Permission = Read_Boolean("Find Clients Permission Y/N?");
        data.Tranactions_Permission = Read_Boolean("Transactions Permission Y/N?");
        data.User_Manager_Permission = Read_Boolean("User Manager Permission Y/N?");
    }
    return data;
}
/*Other Helpful Functions*/
void Print_Client_Info(stClientData client)
{
    cout << Seperator << endl;
    cout << left << setw(13) << "Account NO" << setw(10) << "Pin Code" << setw(21) << "Client Name" << setw(13) << "Phone" << setw(12) << "Balance" << endl;
    cout << Seperator << endl;
    cout << left << setw(13) << client.Account_NO << setw(10) << client.Pin_Code << setw(21) << client.Name << setw(13) << client.Phone_Number << setw(12) << client.Balance << endl;
}
void Print_User_Info(stUsers user)
{
    cout << left << setw(49) << Seperator << endl;
    cout << "  " << left << setw(37) << " " << setw(25) << "Permissions" << endl;
    cout << "  " << left << setw(11) << "UserName" << setw(11) << "PassWord" << setw(5) << string(43, '-') << endl;
    cout << "  " << left << setw(22) << " " << setw(7) << "SC" << setw(6) << "AC" << setw(6) << "DC" << setw(6) << "UC" << setw(6) << "FC" << setw(6) << "TRAN" << setw(6) << "UM" << endl;
    cout << left << setw(49) << Seperator << endl;
    cout << "  " << left << setw(11) << user.UserName << setw(11) << user.PassWord << setw(7) << user.Show_Clients_Permission << setw(6) << user.Add_Clients_Permission << setw(6) << user.Delete_Clients_Permission << setw(6) << user.Update_Clients_Permission << setw(6) << user.Find_Clients_Permission << setw(6) << user.Tranactions_Permission << setw(6) << user.User_Manager_Permission << endl;
}
string Convert_Clients_Vector_To_String_Line(stClientData Data, char delimiter)
{
    string Record;

    Record += Data.Account_NO + delimiter;
    Record += Data.Pin_Code + delimiter;
    Record += Data.Name + delimiter;
    Record += Data.Phone_Number + delimiter;
    Record += to_string(Data.Balance);

    return Record;
}
string Convert_Users_Vector_To_String_Line(stUsers Data, char delimiter)
{
    string Record;

    Record += Data.UserName + delimiter;
    Record += Data.PassWord + delimiter;
    Record += to_string(Data.Show_Clients_Permission) + delimiter;
    Record += to_string(Data.Add_Clients_Permission) + delimiter;
    Record += to_string(Data.Delete_Clients_Permission) + delimiter;
    Record += to_string(Data.Update_Clients_Permission) + delimiter;
    Record += to_string(Data.Find_Clients_Permission) + delimiter;
    Record += to_string(Data.Tranactions_Permission) + delimiter;
    Record += to_string(Data.User_Manager_Permission) + delimiter;
    Record += to_string(Data.Delete_User);

    return Record;
}
void Clear_Buffer()
{
    cin.clear();
    cin.ignore(100, '\n');
}
void Show_Access_Denied_Message(vector <stClientData> &vClients, vector <stUsers> &vUsers)
{
    system("cls");
    Header_Message(67, '=', 27, 27, " BANK SYSTEM ");
    system("color 40");
    Message(vClients, vUsers, "Access Denied", back_To::Main_Menu_Screen);
}
/*Export & Import Functions*/
void Export_Clients_Data_To_TXT(vector <stClientData> &vClients,  string filename)
{
    ofstream MyFile(filename);

    if(MyFile.is_open())
    {
        for(stClientData &client : vClients)
        {
            if(client.Delete_Client == false)
            {
                MyFile << Convert_Clients_Vector_To_String_Line(client, '-') << endl;
            }
        }
    }
    MyFile.close();
}
void Export_Users_Data_To_TXT(vector <stUsers> &vUsers,  string filename)
{
    ofstream MyFile(filename);

    if(MyFile.is_open())
    {
        for(stUsers &user : vUsers)
        {
            if(user.Delete_User == false)
            {
                MyFile << Convert_Users_Vector_To_String_Line(user, '-') << endl;
            }
        }
    }
    MyFile.close();
}
vector <stUsers> Import_Data_TXT_To_Users(string filename, char delimiter)
{
    ifstream MyFile(filename, ios::in);

    vector <stUsers> vUsers;
    stUsers data;
    string line;
    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            stringstream ss(line);
            string show, add, del, update, find, trans, userm, del_user;
            getline(ss, data.UserName, delimiter);
            getline(ss, data.PassWord, delimiter);
            getline(ss, show, delimiter);
            data.Show_Clients_Permission = stoi(show);
            getline(ss, add, delimiter);
            data.Add_Clients_Permission = stoi(add);
            getline(ss, del, delimiter);
            data.Delete_Clients_Permission = stoi(del);
            getline(ss, update, delimiter);
            data.Update_Clients_Permission = stoi(update);
            getline(ss, find, delimiter);
            data.Find_Clients_Permission = stoi(find);
            getline(ss, trans, delimiter);
            data.Tranactions_Permission = stoi(trans);
            getline(ss, userm, delimiter);
            data.User_Manager_Permission = stoi(userm);
            getline(ss, del_user, delimiter);
            data.Delete_User = stoi(del_user);
            vUsers.push_back(data);
        }
    }
    MyFile.close();
    return vUsers;
}
vector <stClientData> Import_Data_TXT_To_Clients(string filename, char delimiter)
{
    ifstream MyFile(filename, ios::in);

    vector <stClientData> vClients;
    stClientData data;
    string line;
    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            stringstream ss(line);
            string Balance;
            getline(ss, data.Account_NO, delimiter);
            getline(ss, data.Pin_Code, delimiter);
            getline(ss, data.Name, delimiter);
            getline(ss, data.Phone_Number, delimiter);
            getline(ss, Balance, delimiter);
            data.Balance = stod(Balance);
            vClients.push_back(data);
        }
    }
    MyFile.close();
    return vClients;
}
/*Header & Messages Functions*/
void Message(vector <stClientData> &vClients, vector <stUsers> &vUsers, string txt, back_To back)
{
    cout << Seperator << endl;
    cout << txt << endl;
    cout << Seperator << endl;
    cout << "(E) Exit Program" << endl;
    switch(back)
    {
        case back_To::Main_Menu_Screen:
            cout << "(Any Key) Return To Main Menu" << endl;
            break;
        case back_To::Transactions_Screen:
            cout << "(Any Key) Return To Transaction" << endl;
            break;
        case back_To::User_Manager_Screen:
            cout << "(Any Key) Return To User Manager" << endl;
            break;
    }
    char choice = Read_Charachter();

    switch(choice)
    {
        case 'e':
        case 'E':
            exit(0);
            break;
        default:
            switch(back)
            {
                case back_To::Main_Menu_Screen:
                    Main_Menu(vClients, vUsers);
                    break;
                case back_To::Transactions_Screen:
                    Transactions_Menu_Screen(vClients, vUsers);
                    break;       
                case back_To::User_Manager_Screen:
                    User_Manager(vClients, vUsers);
                    break;
            }
            break;
    }
}
void Header_Message(int Line_Size, char Symbol, int left_size, int right_size, string text)
{
    cout << string(Line_Size, Symbol) << endl;
    cout << string(left_size, Symbol) << text << string(right_size, Symbol) << endl;
    cout << string(Line_Size, Symbol) << endl;
}