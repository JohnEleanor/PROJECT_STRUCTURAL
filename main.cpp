/** (shortcut / + * + *  + ENTER ) RQ: comment Better
 * @file main.cpp
 * 
 * @author Choritros Suwansoot & Chayanon winyan
 * @brief ทั้งหมดนี้ขอเเค่ใช้ได้ก็พอ
 * @version 0.1
 * @date 2023-10-12
 * @copyright Copyright (c) 2023
 * 
 */


/*
 ! [💻] 12/10/2023 =>  เดี๋ยวมาต่อ พน 😴😴😴😴

TODO: ทำ Create Room UI ให้คำนวน
TODO: ความละเอียดในการเเก้ไขเช่น ต้องการเปลี่ยน Room No. ? OR ต้องการเปลี่ยน Room Price. ? 

*/


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

    string FileRoom = "room.txt";
    ifstream InFileRoom;



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
        CheckUserStatus = Check_User(InFile, username, password);
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
                bool room_add_status, room_delete_status, room_edit_status;

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

                        room_add_status = Room_Insert(InFileRoom, FileRoom);
                        
                        if (room_add_status == true) {
                            alert("[+] Create Room Successfully :)");
                        }else {
                            alert("[-] Room Have Already :(");
                        }


                    }
                    else if (room_select == "2")
                    {

                        room_edit_status = Room_Edit(InFileRoom, FileRoom);
                        
                        if (room_edit_status == true){
                            alert("[+] Edit Your Room Successfully :(");
                        } else {
                            alert("[-] Can not find your Room No. :(");
                        }
                        
                    }
                    else if (room_select == "3")
                    {
                        room_delete_status = Room_Delete(InFileRoom, FileRoom);

                        if (room_delete_status == true) {
                            alert("[+] Delete Room Successfully :)");
                        } else {
                            alert("[-] Can not Delete Room :(");
                        }

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
                        
                        user_add_status = User_insert(InFile, Filename);
                        if ( user_add_status == 1 )
                        {
                            alert("[+] Add User successfully ;)");
                        } else {
                            alert("[-] Your username have been already");
                        }
                    }
                    else if (user_select == "2")
                    {
                        user_edut_status = User_Edit(InFile, Filename);
                        if (user_edut_status == true ) 
                        {
                            alert("[+] Edit User successfully ;)");
                        }
                    }
                    else if (user_select == "3")
                    {
                        
                        user_delete_status = User_Delete(InFile, Filename);
                        if ( user_delete_status == true )
                        {
                            alert("[+] Delete User successfully ;)");
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
   
    alert("Thank You ;)");

    return 0;
}