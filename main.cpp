#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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

        InFile.open(Filename.c_str());  //! เปิดไฟล์เเละเช็ค
        CheckUserStatus = CheckUser(InFile, username, password);
        InFile.close();

        if (CheckUserStatus == false)
        {
            cout << "Login Failed Try Again\n";
        }

    } while (CheckUserStatus == false);


    if (CheckUserStatus == true)    //? 🟢] ถ้า Login ผ่านจึงจะทำงานตาม Code ด้านล่าง
    {
        string select_menu;         //? [🧠] สำหรับเงื่อนไขเมนู

        do
        {

            main_menu(); //? MENU
            cin >> select_menu;

            if (select_menu == "1") // เกี่ยวกับระบบห้อง
            {

                int room_select;
                do
                {
                    room_menu(); //? MENU
                    cin >> room_select;

                    if (room_select == 0)
                    {
                        select_menu = "0";
                        break;
                    }
                    else if (room_select == 1)
                    {

                        cout << "This  is Menu 1 : \n";
                    }
                    else if (room_select == 2)
                    {

                        cout << "this is menu 2 : \n";
                    }
                    else if (room_select == 3)
                    {

                        cout << "This is Menu 3 : \n";
                    }
                    else
                    {
                        cout << "Menu is not found ";
                    }

                } while (room_select != 9 && (room_select <= 4));
            }
            else if (select_menu == "2") // เกี่ยวกับระบบผู้ใช้งาน
            {

                int user_select;
                do
                {
                    user_menu(); //! MENU
                    cin >> user_select;

                    if (user_select == 0)
                    {
                        select_menu = "0";
                        break;
                    }
                    else if (user_select == 1)
                    {

                        cout << "this is menu 1 : \n";
                    }
                    else if (user_select == 2)
                    {

                        cout << "This is menu 2 : \n";
                    }
                    else if (user_select = 3)
                    {

                        cout << "This is menu 3 : \n";
                    }
                    else
                    {
                        cout << "Menu is not found : \n";
                    }

                } while (user_select != 9 && (user_select <= 4));
            }
            else
            {
                cout << "Plase Try Again \n";
            }

        } while (select_menu != "0");
    }
    else
    {
        cout << "Login Failed ";
    }

    cout << setfill('=') << setw(55) << "=" << endl;
    cout << "Thank You For :)";

    return 0;
}