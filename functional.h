using namespace std;

/**
 * @brief Part of J Code
 *? @function main_menu() เเสดงผลหน้าหลัก
 *? @function room_menu() เเสดงผลหน้าห้อง
 *? @function Check_Room() เช็คห้อง
 *? @function Room_Insert() เพิ่มการจอง
 *? @function Room_Edit() เเก้ไขการจอง
 *? @function Room_Delete() ลบการจอง
 *? @function user_menu() เเสดงผลหน้าผู้ใช้งาน
 *? @function Check_User() เช็คผู้ใช้ในบรรทัด return true
 *? @function Insert_User() เพิ่มผู้ใช้งาน
 *? @function Edit_User() เเก้ไขผู้ใช้งาน
 *? @function Delete_User() ลบผู้ใช้งาน
 */

void alert(string text)
{
    system("CLS");
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << text << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "Press Any key to Continue... ";
    getch();
}

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
    system("CLS");
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(30);
    cout << "Room management" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
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
    [🧠] เช็คบรรทัด
    [📂] ใช้สำหรับ : เช็คการมีอยู่ของ input ที่กรอกเข้ามา
    [🎃] ถ้ามีอยู่ return (ture)
*/
bool Check_User(ifstream &InFile, string Check_user, string Check_password)
{

    bool dataExists = false;
    string line;
    string input_user_password;

    input_user_password = Check_user + " " + Check_password;

    if (InFile.is_open())
    {
        while (getline(InFile, line))
        {
            if (line == input_user_password)
            {
                dataExists = true;
                break;
            }
        }
    }
    else
    {
        system("CLS");
        cout << "[+] File Is can not opened! user.txt\n";
        getch();
    }

    return dataExists;
}

/*
    [🧠] เช็คบรรทัด
    [📂] ใช้สำหรับ : เช็คการมีอยู่ของ input ที่กรอกเข้ามา
    [🎃] ถ้ามีอยู่ return (ture)
*/
bool Check_Room(ifstream &InFile, string RoomNo)
{
    bool dataExists = false;
    string line;
    string File_RoomNo, File_roomBooking_Day, Room_pricePer_Day, Room_CustomerName, Room_CustomerPhone;

    if (InFile.is_open())
    {

        while (InFile >> File_RoomNo >> File_roomBooking_Day >> Room_pricePer_Day >> Room_CustomerName >> Room_CustomerPhone)
        {
            if (File_RoomNo == RoomNo)
            {
                dataExists = true;
                break;
            }
        }

    }else {
        system("CLS");
        cout << "[+] File Is can not opened! room.txt\n";
        getch();
    }
    return dataExists;
}

/*
    [🧠] เพิ่มผู้ใชงาน
    [📂] ใช้สำหรับ : เพิ่มผู้ใช้งาน
*/
bool User_insert(ifstream &InFile, const string Filename)
{

    system("CLS");
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

    CheckAlready_user = Check_User(InFile, Name, Password);

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
bool User_Edit(ifstream &InFile, const string Filename)
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

    Check_status = Check_User(InFile, old_username, old_password);
    InFile.close(); // ต้องปิดตัวนี้ก่อน ถึงจะใช้ fstream fileInOut(Filename.c_str(), ios::in | ios::out); มั่วทรง

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
                alert("[!] Action was canceled.");
                return false;
            }
        } while (Confirm == "Y" || Confirm == "y");
    }
    else
    {
        cout << endl
             << "Can not find your input ;( .. ";
    }
    return false;
}

/*
    [🧠] ใช้เพื่อลบผู้ใช้งาน
    [📂] ใช้สำหรับ : ใช้เพื่อลบผู้ใช้งาน
*/
bool User_Delete(ifstream &InFile, const string Filename)
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

    check_status = Check_User(InFile, username, password);
    InFile.close(); // ต้องปิดตัวนี้ก่อน ถึงจะใช้ fstream fileInOut(Filename.c_str(), ios::in | ios::out); มั่วทรง

    if (check_status == true)
    {
        string confirm;

        do
        {
            cout << "Are you sure you want to delete (Y/n) : ";
            cin >> confirm;

            if (confirm == "Y" || confirm == "y")
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

                return true;
            }
            else
            {
                alert("[+] Deletion canceled.");
                return false;
            }

        } while (confirm == "Y");
    }
    else
    {
        alert("[+] Can not find your username ");
    }

    return false;
}

/*
    [🧠] ใช้เพื่อเพิ่มห้อง
    [📂] ใช้สำหรับ : ใช้เพิ่มห้อง
*/
bool Room_Insert(ifstream &InFile, const string Filename)
{
    system("CLS");
    string roomNo, CustomerName, CustomerPhone;
    double roomBooking_Day, pricePer_Day;
    bool CheckRoomStatus;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "Room Create" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "[+] Enter Your Room Number : ";
    cin >> roomNo;
    cout << "[+] Enter Your Room Booking Day : ";
    cin >> roomBooking_Day;
    cout << "[+] Enter Your Price/Day : ";
    cin >> pricePer_Day;
    cout << "[+] Enter Your Customer Name : ";
    cin >> CustomerName;
    cout << "[+] Enter Your Customer Phone Number : ";
    cin >> CustomerPhone;

    InFile.open(Filename.c_str()); //! เปิดไฟล์เเละเช็ค
    CheckRoomStatus = Check_Room(InFile, roomNo);

    if (CheckRoomStatus == false)
    {
        ofstream fileOut(Filename.c_str(), ios_base::app);
        fileOut << roomNo << " " << roomBooking_Day << " " << pricePer_Day << " " << CustomerName << " " << CustomerPhone << endl;
        fileOut.close();
        system("CLS");
        cout << setfill('=') << setw(55) << "=" << endl;
        cout << setfill(' ') << setw(35);
        cout << "[*] Zone Customer " << endl;
        cout << setfill('=') << setw(55) << "=" << endl;
        cout << "This is your Booking Day : " << roomBooking_Day << endl;
        cout << "This is your Price/Day : " << pricePer_Day << endl;
        cout << "For Customer name  : " << CustomerName << endl;
        cout << "This is total : " << roomBooking_Day * pricePer_Day << " BATH" << endl;
        cout << "Press Enter Any Key To Continue...";
        getch();
        return (true);
    }
    else
    {
        cout << "[ERROR] Can not Write File ." << endl;
        return (false);
    }
}

/*
    [🧠] ใช้เพื่อเเก้ไขห้อง
    [📂] ใช้สำหรับ : ใช้เพื่อเเก้ไขห้อง
*/
bool Room_Edit(ifstream &InFile, const string Filename)
{
    system("CLS");
    string roomNo, CustomerName, CustomerPhone, roomBooking_Day;

    bool CheckRoomStatus;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "Edit Room" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "[+] Enter Your Room Number ( You want to edit ) : ";
    cin >> roomNo;

    InFile.open(Filename.c_str()); //! เปิดไฟล์เเละเช็ค
    CheckRoomStatus = Check_Room(InFile, roomNo);
    InFile.close();

    if (CheckRoomStatus == true)
    {
        system("CLS");
        string new_room_no, new_roomBooking_Day, new_pricePer_Day, new_CustomerName, new_CustomerPhone;
        cout << setfill('=') << setw(55) << "=" << endl;
        cout << setfill(' ') << setw(35);
        cout << "[!] Edit Mode" << endl;
        cout << setfill('=') << setw(55) << "=" << endl;
        cout << "[+] Enter Your New Room Number : ";
        cin >> new_room_no;
        cout << "[+] Enter Your New Room Booking Day : ";
        cin >> new_roomBooking_Day;
        cout << "[+] Enter Your New Room Price/Day : ";
        cin >> new_pricePer_Day;
        cout << "[+] Enter Your New Room Customer Name : ";
        cin >> new_CustomerName;
        cout << "[+] Enter Your New Room Phone Number : ";
        cin >> new_CustomerPhone;
        string new_Edit_concate = new_room_no + " " + new_roomBooking_Day + " " + new_pricePer_Day + " " + new_CustomerName + " " + new_CustomerPhone;

        string File_RoomNo, File_roomBooking_Day, Room_pricePer_Day, Room_CustomerName, Room_CustomerPhone;
        string line;
        fstream fileInOut(Filename.c_str(), ios::in | ios::out);

        // สร้างไฟล์สำรองขึ้นมาก่อนเเล้ว copy ข้อมูลเเล้วลบบรรทัด
        ofstream tempFile("temp.txt");

        while (fileInOut >> File_RoomNo >> File_roomBooking_Day >> Room_pricePer_Day >> Room_CustomerName >> Room_CustomerPhone)
        {
            string concatenate_room = File_RoomNo + " " + File_roomBooking_Day + " " + Room_pricePer_Day + " " + Room_CustomerName + " " + Room_CustomerPhone;

            if (File_RoomNo != roomNo) // ถ้าเลขห้องที่อ่านไม่ตรงกับที่ต้องการลบข้ความนั้นก็จะถูกเขียนไป (ไฟล์ใหม่) 😴 หรือ
            {
                tempFile << concatenate_room << endl;
            }
        }

        tempFile << new_Edit_concate << endl;

        fileInOut.close();
        tempFile.close();

        // ลบไฟล์เก่า
        remove("room.txt");
        //! ตรงนี้ [Debug]
        // cout << "Delete Old file.. " << endl;
        // getch();

        // เปลี่ยนชื่อไฟล์ temp.txt เป็น user.txt อิอิ 😴
        rename("temp.txt", Filename.c_str());
        return (true);
    }
    else
    {
        cout << "[ERROR] Can not Write File ." << endl;
        return (false);
    }
}

/**
 *! @brief หลักการทำงานก็คือลบโดยอ้างอิงจากเลขห้อง โดย เลขห้องจะไม่ซ้ำกัน
 * 
 * [🧠] ใช้ในการลบห้อง
 */
bool Room_Delete(ifstream &InFile, const string Filename)
{
    system("CLS");
    string roomNo;
    bool CheckRoomStatus;

    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "Delete Mode ;)" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "[-] Enter Your Room Number To Delete : ";
    cin >> roomNo;

    CheckRoomStatus = Check_Room(InFile, roomNo);
    InFile.close();

    string Confirm_Delete;
    do
    {
        cout << "Are you sure You want to Delete (Y/n) : ";
        cin >> Confirm_Delete;

        if (Confirm_Delete == "Y" || Confirm_Delete == "y")
        {
            if (CheckRoomStatus == false) // false เเปลว่ามี
            {

                string File_RoomNo, File_roomBooking_Day, Room_pricePer_Day, Room_CustomerName, Room_CustomerPhone;
                string line;
                fstream fileInOut(Filename.c_str(), ios::in | ios::out);

                // สร้างไฟล์สำรองขึ้นมาก่อนเเล้ว copy ข้อมูลเเล้วลบบรรทัด
                ofstream tempFile("temp.txt");

                while (fileInOut >> File_RoomNo >> File_roomBooking_Day >> Room_pricePer_Day >> Room_CustomerName >> Room_CustomerPhone)
                {
                    string concatenate_room = File_RoomNo + " " + File_roomBooking_Day + " " + Room_pricePer_Day + " " + Room_CustomerName + " " + Room_CustomerPhone;

                    if (File_RoomNo != roomNo) // ถ้าเลขห้องที่อ่านไม่ตรงกับที่ต้องการลบข้ความนั้นก็จะถูกเขียนไป (ไฟล์ใหม่) 😴
                    {
                        tempFile << concatenate_room << endl;
                    }
                }

                fileInOut.close();
                tempFile.close();

                // ลบไฟล์เก่า
                remove("room.txt");
                //! ตรงนี้ [Debug]
                // cout << "Delete Old file.. " << endl;
                // getch();

                // เปลี่ยนชื่อไฟล์ temp.txt เป็น user.txt อิอิ 😴
                rename("temp.txt", Filename.c_str());
                return (true);
            }
        }
        else
        {
            return (false);
        }

    } while (Confirm_Delete == "Y" || Confirm_Delete == "y");

    return (false);
}
