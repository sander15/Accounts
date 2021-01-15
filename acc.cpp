#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>


using namespace std;


void login();
void registr();
void forgot();


int main()
{
    int choice;
    string choice2;


    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                        Accounts Manager                              " << endl;
    cout << "                        made by sander15                              " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Forgot Password (or) Username?" << endl;
    cout << "4. Exit" << endl;
    cout << "\nSelect an option: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "Ok.. bye  :(\n\n";
        break;
    default:
        system("CLS");
        cout << "WORNG!\nPlease, Enter a valid option" << endl;
        cin >> choice2;
        main();
        break;
    }

}

void login()
{
    int count;
    string user, pass, u, p;

    system("CLS");
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    ifstream input("users.txt");

    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            count = 1;
            system("CLS");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "LOGIN SUCESS" << "\nHi, " << user << "\nWe're glad that you're here.\n";
        cout << "-------------------------------------------------" << endl;
        cin.get();
        cin.get();
        system("CLS");
        main();
    }
    else
    {
        cout << "\nERROR!\nCheck your username and password\n";
        cout << "-------------------------------------------------" << endl;
        cin.get();
        cin.get();
        system("CLS");
        main();
    }
}

void registr()
{

    string reguser, regpass, ru, rp;
    system("CLS");
    cout << "Enter the username: ";
    cin >> reguser;
    cout << "\nEnter the password: ";
    cin >> regpass;

    ofstream reg("users.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    system("CLS");
    cout << "\nRegistration Sucessful  :)\n";
    cout << "-------------------------------------------------" << endl;
    cin.get();
    cin.get();
    system("CLS");
    main();
}

void forgot()
{
    int ch;
    system("CLS");
    cout << "HELP CENTER\n";
    cout << "1. Search your id by Username" << endl;
    cout << "2. Search your id by Password" << endl;
    cout << "3. Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        int count = 0;
        string searchuser, su, sp;
        cout << "\nEnter your remembered username: ";
        cin >> searchuser;

        ifstream searchu("users.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << "\n\nCool, we found your account\n";
            cout << "\nYour password is: " << sp;
            cout << "\n-------------------------------------------------" << endl;
            cin.get();
            cin.get();
            system("CLS");
            main();
        }
        else
        {
            cout << "\nSorry, We couldn`t found your User in our database\n";
            cout << "-------------------------------------------------" << endl;
            cin.get();
            cin.get();
            system("CLS");
            main();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\nEnter the remembered password: ";
        cin >> searchpass;

        ifstream searchp("users.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                count = 1;
            }
        }
        searchp.close();
        if (count == 1)
        {
            cout << "\nGreat, We found your password in the database \n";
            cout << "\nYour User is: " << su2;
            cout << "-----------------------------------------------------" << endl;
            cin.get();
            cin.get();
            system("CLS");
            main();
        }
        else
        {
            cout << "\nSorry, We couldn`t found your password in our database \n";
            cout << "--------------------------------------------------------" << endl;
            cin.get();
            cin.get();
            system("CLS");
            main();
        }

        break;
    }

    case 3:
    {
        cin.get();
        main();
    }
    default:
        cout << "Please select a valid option!" << endl;
        forgot();
    }
}