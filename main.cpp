#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h> // ใช้สำหรับ getch(); (Press Enter to Continue)


#include "functional.h"

using namespace std;

int main()
{
    //?[📂] About File
    string Filename = "user.txt";
    ifstream InFile;
    ofstream OutFile;



    //?[📂] About User
    bool CheckUserStatus;
    string username, password;

    do
    {

        cout << setfill('=') << setw(55) << "=" << endl;
        cout << setfill(' ') << setw(25) << "Username : ";
        cin >> username;
        cout << setfill(' ') << setw(25) << "Password : ";
        cin >> password;
        cout << setfill('=') << setw(55) << "=" << endl;


        if (!InFile) {
            cout << "Error To connect user.txt Plase Check ";
        }

        //! การดึงไฟล์มาอ่าน
        InFile.open(Filename.c_str()); //! เปิดไฟล์เเละเช็ค
        CheckUserStatus = CheckUser(InFile, username, password);
        InFile.close();

        if (CheckUserStatus == false)
        {
            system("CLS");
            cout << setfill('=') << setw(55) << "=" << endl;
            cout << setfill(' ') << setw(30);
            cout << "Login Failed Try Again" << endl;
        }

    } while (CheckUserStatus == false);

    if (CheckUserStatus == true) //? 🟢] ถ้า Login ผ่านจึงจะทำงานตาม Code ด้านล่าง
    {
        string select_menu; //? [🧠] สำหรับเงื่อนไขเมนู

        do
        {

            main_menu(); //? MENU
            cin >> select_menu;

            if (select_menu == "1") // เกี่ยวกับระบบห้อง
            {
                cout << setfill('=') << setw(55) << "=" << endl;
                cout << setfill(' ') << setw(25) << "Login Successfully Welcome" << setfill('=') << setw(5) << endl;
                cout << setfill('=') << setw(55) << "=" << endl;
                string room_select;
                do
                {
                    room_menu(); //? MENU
                    cin >> room_select;

                    if (room_select == "0")
                    {
                        select_menu = "0";
                        break;
                    }
                    else if (room_select == "1")
                    {

                        cout << "This  is Menu 1 : \n";
                    }
                    else if (room_select == "2")
                    {

                        cout << "this is menu 2 : \n";
                    }
                    else if (room_select == "3")
                    {

                        cout << "This is Menu 3 : \n";
                    }
                    else
                    {
                        cout << "Menu is not found ";
                    }

                } while (room_select != "9" && (room_select <= "4"));
            }
            else if (select_menu == "2") // เกี่ยวกับระบบผู้ใช้งาน
            {
                /*
                    ! [🟢] user.txt
                */
                string user_select;
                bool user_add_status, user_delete_status, user_edut_status;
                do
                {
                    InFile.open(Filename.c_str()); //! เปิดไฟล์เเละเช็ค

                    user_menu(); //? MENU
                    cin >> user_select;

                    if (user_select == "0")
                    {
                        select_menu = "0";
                        break;
                    }
                    else if (user_select == "1")
                    {
                        
                        user_add_status = Insert_User(InFile);
                        if ( user_add_status == 1 )
                        {
                            system("CLS");
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << setfill(' ') << setw(35);
                            cout << "Add User successfully ;)" << endl;
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << "Press Any key to Continue... ";
                            getch();
                        }else {
                            system("CLS");
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << setfill(' ') << setw(35);
                            cout << "Have Already username password" << endl;
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << "Press Any key to Continue... ";
                            getch();
                        }
                    }
                    else if (user_select == "2")
                    {
                        user_edut_status = Edit_User(InFile, Filename);
                        if (user_edut_status == true ) 
                        {
                            system("CLS");
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << setfill(' ') << setw(35);
                            cout << "Edit User successfully ;)" << endl;
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << "Press Any key to Continue... ";
                            getch(); 
                        }else {
                            system("CLS");
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << setfill(' ') << setw(35);
                            cout << "Edit User Went Wrong ;(" << endl;
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << "Press Any key to Continue... ";
                            getch();
                            
                        }
                    }
                    else if (user_select == "3")
                    {
                        
                        user_delete_status = Delete_User(InFile, Filename);
                        if ( user_delete_status == true )
                        {
                            system("CLS");
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << setfill(' ') << setw(35);
                            cout << "Delete User successfully ;)" << endl;
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << "Press Any key to Continue... ";
                            getch();
                        }else if( user_delete_status == false) {
                            system("CLS");
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << setfill(' ') << setw(35);
                            cout << "[+] Something went wrong" << endl;
                            cout << setfill('=') << setw(55) << "=" << endl;
                            cout << "Press Any key to Continue... ";
                            getch();
                        }
                    }
                    else
                    {
                        cout << "Menu is not found ";
                    }

                    InFile.close();

                } while (user_select != "9" && (user_select <= "4"));
            }
            else
            {
                cout << "Plase Try Again \n";
            }

        } while (select_menu != "0");
    }
   
    system("CLS");
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ') << setw(35);
    cout << "Thank You ;)" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "Press Any key to Exit... ";
    getch();

    return 0;
}