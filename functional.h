#include <iostream>
#include <fstream>
using namespace std;

/*
    [🧠] หน้าเมนูหลัก
    [📂] ใช้สำหรับ : เเสดงผลเท่านั้น
*/
void main_menu()
{
    system("CLS");

    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(25);
    cout << "Welcome" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "[1] Room management \n";
    cout << "[2] User management \n";
    cout << "[0] EXIT Program \n";
    cout << "===================\n";
    cout << "[+] Plase Enter Your Choice : ";
}

/*
    [🧠] หน้าเมนูจัดการห้อง
    [📂] ใช้สำหรับ : เเสดงผลเท่านั้น
*/
void room_menu()
{
    // system("CLS");
    cout << "===== Room management =====\n";
    cout << "[1] Create Room \n";
    cout << "[2] Edit Room \n";
    cout << "[3] Delete Room \n";
    cout << "[9] Exit Menu \n";
    cout << "[0] Exit Program \n";
    cout << "===================\n";
    cout << "[+] Plase Enter Your Choice : ";
}

/*
    [🧠] หน้าเมนูจัดการผู้ใช้
    [📂] ใช้สำหรับ : เเสดงผลเท่านั้น
*/
void user_menu()
{
    // system("CLS");
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "User management" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "[1] Add User \n";
    cout << "[2] Edit User \n";
    cout << "[3] Delete User \n";
    cout << "[9] Exit Menu \n";
    cout << "[0] Exit Program \n";
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "[+] Plase Enter Your Choice : ";
}

/*
    [🧠] เช็อการ Login
    [📂] ใช้สำหรับ : เช็คผู้ใชงานสำหรับ Login
*/
bool CheckUser(ifstream &InFile, string param_username, string param_password)
{

    string username, pass;

    while (InFile >> username >> pass)
    {
        if (param_username == username && param_password == pass)
        {
            cout << "Login Successfully" << endl;
            return true;
        }
    }

    return false;
}

bool CheckAlReadyUser_insert(ifstream &InFile, string Check_user, string Check_password)
{

    bool dataExists = false;
    string line;
    string input_user_password;

    input_user_password = Check_user + " " + Check_password;

    while (getline(InFile, line))
    {
        if (line == input_user_password)
        {
            dataExists = true;
            break;
        }
    }


    return dataExists;
}

/*
    [🧠] เพิ่มผู้ใชงาน
    [📂] ใช้สำหรับ : เพิ่มผู้ใช้งาน

    ofstream &OutFile
*/
bool Insert_User(ifstream &InFile)
{
    
    // system("CLS");
    string Filename = "user.txt";
    fstream fileInOut(Filename.c_str(), ios::in | ios::out);
    string Name, Password;
    bool CheckAlready_user;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "User Add Function" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;

    cout << "[+] Plase Enter Your (New username) : ";
    cin >> Name;
    cout << "[+] Plase Enter Your (New Password) : ";
    cin >> Password;

    CheckAlready_user = CheckAlReadyUser_insert(InFile, Name, Password);

    if (CheckAlready_user == false)
    {
        ofstream fileOut(Filename.c_str(), ios_base::app);
        fileOut << endl
                << Name << " " << Password;
        fileOut.close();

        return (true);
    }

    return (false);
}

bool Edit_User(ifstream &InFile)
{
    // system("CLS");

    string username, old_username, password;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "User Edit Function" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "[+] Enter Your old user name : ";
    cin >> old_username;
    cout << "[+] Plase Enter Your New Username : ";
    cin >> username;
    cout << "[+] Plase Enter Your New Password : ";
    cin >> password;

    return true;
}

bool Delete_User(ifstream &InFile, string Filename)
{
    system("CLS");
    fstream fileInOut(Filename.c_str(), ios::in | ios::out);
    // ofstream fileOut(Filename, ios::out);
    // ifstream fileIn(Filename.c_str(), ios::in);
    // ofstream fileOut(Filename, ios::out);
    string username, password;
    string read_username, read_password;
    bool check_status;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "User Delete Function" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "Plase Enter Your Name You Want to Delete : ";
    cin >> username;
    cout << "Confirm Your password : ";
    cin >> password;

    check_status = CheckAlReadyUser_insert(InFile, username, password);

    if (check_status)
    {
        string confirm;

        do
        {
            cout << "Are you sure you want to delete (Y/n) : ";
            cin >> confirm;
            string new_username;
            string input_user_password;
            bool dataExists = false;

            if (confirm == "Y" || "y"){
                input_user_password = username + " " + password;
                while (getline(InFile, input_user_password))
                {
                    if (new_username == input_user_password)
                    {
                        cout << "DELETE :" << endl;
                        dataExists = true;
                        break;
                    }
                }
            }
        
        } while (confirm != "Y" and confirm != "n");
    }
    else
    {
        cout << "[+] Can not find your username ;( " << endl;
    }

    return false;
}
