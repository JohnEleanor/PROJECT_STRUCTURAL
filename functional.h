#include <iostream>
#include <fstream>
using namespace std;

/*
    [🧠] หน้าเมนูหลัก 
    [📂] ใช้สำหรับ : เเสดงผลเท่านั้น
*/
void main_menu()
{
    // system("CLS");
    cout << "===== Welcome =====" << endl;
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
    system("CLS");
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
    cout << "===== User management =====\n";
    cout << "[1] Add User \n";
    cout << "[2] Edit User \n";
    cout << "[3] Delete User \n";
    cout << "[9] Exit Menu \n";
    cout << "[0] Exit Program \n";
    cout << "===================\n";
    cout << "[+] Plase Enter Your Choice : ";
}

/*
    [🧠] เพิ่มผู้ใชงาน
    [📂] ใช้สำหรับ : เพิ่มผู้ใช้งาน
*/
void InsertData(ofstream &OutFile)
{
    string Id, Name, SurName;
    cout << endl;
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