using namespace std;

/**
 * @brief Part of J Code
 *? @function main_menu() เเสดงผลหน้าหลัก
 *? @function room_menu() เเสดงผลหน้าห้อง
 *? @function user_menu() เเสดงผลหน้าผู้ใช้งาน
 *? @function CheckUser() เช็ค Login
 *? @function CheckUser_Haved() เช็คผู้ใช้ในบรรทัด return true
 *? @function Insert_User() เพิ่มผู้ใช้งาน
 *? @function Edit_User() เเก้ไขผู้ใช้งาน
 *? @function Delete_User() ลบผู้ใช้งาน
 */

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
            cout << "yay Correct Let gooooo.. " << endl;
            return true;
        }
    }

    return false;
}

/*
    [🧠] เช็คบรรทัด
    [📂] ใช้สำหรับ : เช็คการมีอยู่ของ input ที่กรอกเข้ามา
    [🎃] ถ้ามีอยู่ return (ture)
*/
bool CheckUser_Haved(ifstream &InFile, string Check_user, string Check_password)
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

    cout << "[+] Plase Enter Your (New username) : ";
    cin >> Name;
    cout << "[+] Plase Enter Your (New Password) : ";
    cin >> Password;

    CheckAlready_user = CheckUser_Haved(InFile, Name, Password);

    if (CheckAlready_user == false)
    {
        ofstream fileOut(Filename.c_str(), ios_base::app);
        fileOut << Name << " " << Password << endl;
        fileOut.close();

        return (true);
    }

    return (false);
}

/*
    [🧠] เเก้ไขผู้ใช้งาน
    [📂] ใช้สำหรับ : เเก้ไขผู้ใช้งาน
*/
bool Edit_User(ifstream &InFile, const string Filename)
{
    system("CLS");
    string old_username, old_password, username, password;
    bool Check_status;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "User Edit Function" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "[+] Enter Your old user name : ";
    cin >> old_username;
    cout << "[+] Enter Your old password name : ";
    cin >> old_password;

    Check_status = CheckUser_Haved(InFile, old_username, old_password);
    InFile.close(); // ต้องปิดตัวนี้ก่อน ถึงจะใช้ fstream fileInOut(Filename.c_str(), ios::in | ios::out); ได้นะจ๊ะ
    if (Check_status == true) // ถ้า input มีอยู่จริง จึงจะเเก้ไขได้
    {

        // Do this
        string Confirm;
        do
        {
            cout << "Are you sure you want to Edit (Y/n) : ";
            cin >> Confirm;

            if (Confirm == "Y" || Confirm == "y")
            {
      
                system("CLS");
                cout << setfill('=') << setw(55) << "=" << endl;
                cout << setfill(' ') << setw(35);
                cout << "Edit Mode ;)" << endl;
                cout << setfill('=') << setw(55) << "=" << endl;
                cout << "[+] Plase Enter Your New Username : ";
                cin >> username;
                cout << "[+] Plase Enter Your New Password : ";
                cin >> password;

                fstream fileInOut(Filename.c_str(), ios::in | ios::out);
                ofstream tempFile("temp.txt");
                string userToEdit = old_username + " " + old_password;
                string newUsertoEdit = username + " " + password;
                string line;

        /**
            * @param line คือข้อมูลที่อ่านได้มาในไฟล์ .txt
            * @param fileInOut คือตัวอ่านไฟล์
        */

                 while (getline(fileInOut, line))
                {
                    if (line != userToEdit)
                    {
                        tempFile << line << endl;
                    }
                    
                }

                tempFile << newUsertoEdit << endl;

                fileInOut.close();
                tempFile.close();

                remove(Filename.c_str());

                rename("temp.txt", Filename.c_str());
                return true;
            }
            else
            {

                system("CLS");
                cout << setfill('=') << setw(55) << "=" << endl;
                cout << setfill(' ') << setw(35);
                cout << "[!] Action was canceled." << endl;
                cout << setfill('=') << setw(55) << "=" << endl;
                cout << "Press Any key to Exit... ";
                getch();
                return false;
            }
        } while (Confirm == "Y" || Confirm == "y");
    }
    else
    {
        cout << endl << "Can not find your input ;( .. ";
    }
    getch();
    return false;
}

/*
    [🧠] ใช้เพื่อลบผู้ใช้งาน
    [📂] ใช้สำหรับ : ใช้เพื่อลบผู้ใช้งาน
*/
bool Delete_User(ifstream &InFile, const string Filename)
{
    system("CLS");
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

    check_status = CheckUser_Haved(InFile, username, password);
    InFile.close(); // ต้องปิดตัวนี้ก่อน ถึงจะใช้ fstream fileInOut(Filename.c_str(), ios::in | ios::out); ได้นะจ๊ะ

    if (check_status)
    {
        string confirm;

        do
        {
            cout << "Are you sure you want to delete (Y/n) : ";
            cin >> confirm;

            if (confirm == "Y" || "y")
            {
                string line;
                string userToDelete = username + " " + password;
                fstream fileInOut(Filename.c_str(), ios::in | ios::out);
                // สร้างไฟล์สำรองขึ้นมาก่อนเเล้ว copy ข้อมูลเเล้วลบบรรทัด
                ofstream tempFile("temp.txt");

                while (getline(fileInOut, line))
                {
                    if (line != userToDelete)
                    {
                        tempFile << line << endl;
                    }
                }

                fileInOut.close();
                tempFile.close();

                // ลบไฟล์เก่า
                remove("user.txt");
                //! ตรงนี้ [Debug]
                // cout << "Delete Old file.. " << endl;
                // getch();

                // เปลี่ยนชื่อไฟล์ temp.txt เป็น user.txt อิอิ 😴
                rename("temp.txt", Filename.c_str());

                // system("CLS");
                // cout << setfill('=') << setw(55) << "=" << endl;
                // cout << setfill(' ') << setw(35);
                // cout << "[+] User deleted successfully." << endl;
                // cout << setfill('=') << setw(55) << "=" << endl;
                // cout << "Press Any key to Exit... " << endl ;
                getch();
                return true;
            } else
            {

                system("CLS");
                cout << setfill('=') << setw(55) << "=" << endl;
                cout << setfill(' ') << setw(35);
                cout << "[+] Deletion canceled." << endl;
                cout << setfill('=') << setw(55) << "=" << endl;
                cout << "Press Any key to Exit... " << endl;
                getch();
            }
         

        } while (confirm == "Y");
    }
    else
    {
        system("CLS");
        cout << setfill('=') << setw(55) << "=" << endl;
        cout << setfill(' ') << setw(35);
        cout << "[+] Can not find your username ;( " << endl;
        cout << setfill('=') << setw(55) << "=" << endl;
        cout << "Press Any key to Exit... " << endl;
        getch();
    }

    return false;
}
