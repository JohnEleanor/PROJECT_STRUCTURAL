#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 * [🧠] MENU ZONE
 */
void main_menu();
void room_menu();

/*
 * [🧠] ROOM ZONE
 */
void InsertData(ofstream &OutFile);
bool CheckUser(ifstream &InFile, string param_username, string param_password);

int main()
{
    string Filename = "user.txt";
    ifstream InFile;
    ofstream OutFile;
    bool CheckUserStatus;

    string username, password;
    cout << "username : ";
    cin >> username;
    cout << "password : ";
    cin >> password;

    /*
        ? เปิดไฟล์เเละเช็ค
    */
    InFile.open(Filename.c_str());
    CheckUserStatus = CheckUser(InFile, username, password);
    InFile.close();

    if (CheckUserStatus == true)
    {
        int choice_num_set = 2;
        int select_menu;

        do
        {

            main_menu(); //! MENU
            cin >> select_menu;

            if (select_menu == 1)
            {

                int room_select;
                do
                {
                    room_menu(); //! MENU
                    cin >> room_select;

                    if (room_select == 0)
                    {
                        select_menu = 0;
                        break;
                    }

                } while (room_select != 9 && (room_select <= 4));
            }

        } while (select_menu != 0 && select_menu <= choice_num_set);
    }else {
        cout << "Login Failed ";
    }

    return 0;
}

void main_menu()
{
    system("CLS");
    cout << "===== Welcome =====" << endl;
    cout << "[1] Room management \n";
    cout << "[2] User management \n";
    cout << "[0] EXIT Program \n";
    cout << "===================\n";
    cout << "[+] Plase Enter Your Choice : ";
}

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

void InsertData(ofstream &OutFile)
{
    string Id, Name, SurName;
    cout << endl;
}


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