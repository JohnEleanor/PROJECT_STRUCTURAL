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
    system("CLS");
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

bool CheckAlReadyUser(ifstream &InFile, string Check_user, string Check_password)
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

    InFile.close();

    return dataExists;
}

/*
    [🧠] เพิ่มผู้ใชงาน
    [📂] ใช้สำหรับ : เพิ่มผู้ใช้งาน

    ofstream &OutFile
*/
bool Insert_User(ifstream &InFile)
{
    system("CLS");
    string Filename = "user.txt";
    fstream fileInOut(Filename.c_str(), ios::in | ios::out);
    string Name, Password;
    bool CheckAlready_user;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "User Add Function" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;

    cout << "[+] Plase Enter Your Name : ";
    cin >> Name;
    cout << "[+] Plase Enter Your Password : ";
    cin >> Password;

    CheckAlready_user = CheckAlReadyUser(InFile, Name, Password);
   

    if (CheckAlready_user == false)
    {
        ofstream fileOut(Filename.c_str(), ios_base::app);
        fileOut << endl << Name << " " << Password;
        fileOut.close();
        
        return (true);
        
    }

    return (false);

}

bool Edit_User(ifstream &InFile)
{
    system("CLS");

    string Name, Password;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "User Edit Function" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;

    cout << "[+] Plase Enter Your Name : ";
    cin >> Name;
    cout << "[+] Plase Enter Your Password : ";
    cin >> Password;

    return true;
}

bool Delete_User(ifstream &InFile)
{
    system("CLS");

    string Name, Password;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "User Edit Function" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;

    cout << "Plase Enter Your Name You Want to Delete : ";
    cin >> Name;

    return true;
}
