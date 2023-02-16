#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
string name[100];
string password[100];
string role[100];
void logo();
void welcome();
void loading();
void login();
void signup();
void view_available_physicians();
void signin();
void view_blood_bank_status();
void blood_bank_status(int);
int lab_test_helper_variable = 0;
void lab_test(int);
void view_lab_test_rates();
string test_type[20];
int test_rate[20];
int rooms_helper_variable = 0;
void rooms(int);
void room_selection();
int no_of_rooms[20];
string room_type[20];
int rates[20];
void delete_patient_record(string, string);
string blood_type[20];
int blood_packet[20];
int blood_data_helper_variable = 0;
string docter_name[100];
string docter_specialization[100];
string docters_degrees[100];
string docter_number[100];
string docter_age[100];
string docter_id[100];
string docters_timings[100];
string patient_name[100];
string patient_number[100];
string patient_father_name[100];
string patient_blood_group[100];
string patient_desease[100];
string patient_age[100];
string patient_id[100];
void recommendations(string);
int docter_data_helper_variable = 0;
int patient_data_helper_variable = 0;
string admin_menu();
int revenue_calculator();
string user_menu();
void add_patient_details();
void add_docter_details();
void view_patient_details(string, string);
void view_docter_details(string, string);
void blood_bank_details();
int check_bill();
string choice;
int loop1_variable = 0;
int loop2_variable;
int enter = 0;
int helper;
int helper1;
int helper2 = 0;
string user_decision;
string admin_decision;
main()
{
     logo();
    welcome();
    loading();
    string madad;
    while (enter < 100)
    {
        system("cls");
        logo();
        madad = "B";
        login();
        if (choice == "1")
        {
            helper1 = 0;
            for (int m = 0; helper1 <= 2; m++)
            {
                signup();
            }
            if (helper1 > 2)
            {
                enter++;
                loop1_variable++;
            }
        }
        else if (choice == "2")
        {
            for (int m = 0; helper2 == 0; m++)
            {
                signin();
            }
            helper2 = 0;
            if (role[loop2_variable] == "admin" || role[loop2_variable] == "ADMIN")
            {
                string docter_name_variable;
                string docter_id_variable;
                string patient_name_variable;
                string patient_id_variable;
                while (madad != "Exit")
                {
                    admin_decision = admin_menu();
                    if (admin_decision == "1")
                    {
                        system("cls");
                        logo();
                        add_docter_details();
                    }
                    else if (admin_decision == "2")
                    {
                        system("cls");
                        logo();
                        add_patient_details();
                    }
                    else if (admin_decision == "3")
                    {
                        system("cls");
                        logo();
                        cout << "Enter docter name ";
                        cin.ignore(100, '\n');
                        getline(cin, docter_name_variable, '\n');
                        cout << "Enter docter id";
                        cin >> docter_id_variable;
                        view_docter_details(docter_name_variable, docter_id_variable);
                    }
                    else if (admin_decision == "4")
                    {
                        system("cls");
                        logo();
                        cout << "Enter patient name ";
                        cin.ignore(100, '\n');
                        getline(cin, patient_name_variable, '\n');
                        cout << "Enter patient id";
                        cin >> patient_id_variable;
                        view_patient_details(patient_name_variable, patient_id_variable);
                    }
                    else if (admin_decision == "5")
                    {
                        int blood_range;
                        cout << "How many type of bloods are available in the hospital: ";
                        cin >> blood_range;
                        blood_type[blood_range];
                        blood_packet[blood_range];
                        blood_bank_status(blood_range);
                    }
                    else if (admin_decision == "6")
                    {
                        int size;
                        cout << "Enter number of types of rooms in hospital ";
                        cin >> size;
                        rooms(size);
                    }
                    else if (admin_decision == "7")
                    {

                        int size1;
                        cout << "How many type of tests will be available in your hospital ";
                        cin >> size1;
                        lab_test(size1);
                    }
                    else if (admin_decision == "8")
                    {

                        int total;
                        total = revenue_calculator();
                        cout << "Total revenue generated by hospital today is " << total << " Rs " << endl;
                    }
                    else if (admin_decision == "9")
                    {
                        system("cls");
                        logo();
                        cout << "Enter patient name ";
                        cin.ignore(100, '\n');
                        getline(cin, patient_name_variable, '\n');
                        cout << "Enter patient id";
                        cin >> patient_id_variable;
                        delete_patient_record(patient_name_variable, patient_id_variable);
                    }
                    else if (admin_decision == "10")
                    {
                        madad = "Exit";
                    }
                    else
                    {
                        cout << "An invalid entry " << endl;
                    }
                    if (madad != "Exit")
                    {
                        cout << " Press any key from your keyboard to go back on admin menu ";
                        getch();
                    }
                }
            }
            if (role[loop2_variable] == "user" || role[loop2_variable] == "USER")
            {
                while (madad != "Exit")
                {
                    user_decision = user_menu();
                    if (user_decision == "1")
                    {
                        system("cls");
                        logo();
                        view_blood_bank_status();
                    }
                    else if (user_decision == "2")
                    {
                        system("cls");
                        logo();
                        view_available_physicians();
                    }
                    else if (user_decision == "3")
                    {
                        system("cls");
                        logo();
                        view_lab_test_rates();
                    }
                    else if (user_decision == "4")
                    {
                        system("cls");
                        logo();
                        room_selection();
                    }
                    else if (user_decision == "5")
                    {
                        int total;
                        system("cls");
                        logo();
                        total = check_bill();
                        cout << "YOUR BILL IS:            " << total;
                    }
                    else if (user_decision == "6")
                    {
                        string desease;
                        cout << "Enter the affected body part  ";
                        cin >> desease;
                        system("cls");
                        logo();
                        recommendations(desease);
                    }
                    else if (user_decision == "7")
                    {
                        madad = "Exit";
                    }
                    else
                    {
                        cout << "An invalid entry " << endl;
                    }
                    if (madad != "Exit")
                    {
                        cout << " Press any key from your keyboard to go back on admin menu ";
                        getch();
                    }
                }
            }
        }
        else if (choice == "3")
        {
            cout << "                                            Exiting";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(500);
            }
            system("cls");
            break;
        }
        else
        {
            cout << "An invalid entry ";
            cout << "Press any key from your keyboard to go back on login menu ";
            getch();
            enter--;
        }
    }
}
void logo()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                   *****************************************************************                  " << endl;
    cout << "                                   *                                                               *                   " << endl;
    cout << "                                   *                                                               *                   " << endl;
    cout << "                                   *                                                               *                   " << endl;
    cout << "                                   *                 HOSPITAL MANAGEMENT SYSTEM                    *                   " << endl;
    cout << "                                   *                                                               *                   " << endl;
    cout << "                                   *                                                               *                   " << endl;
    cout << "                                   *                                                               *                   " << endl;
    cout << "                                   *                                                               *                   " << endl;
    cout << "                                   *****************************************************************                  " << endl;
    cout << endl;
    cout << endl;
}
void welcome()
{

    cout << "                                       *      * **** *      ****   *****  *    * ****                     " << endl;
    cout << "                                       *   *  * **** *     *      *     * *  * * ****        " << endl;
    cout << "                                       * *  * * *    *     *      *     * *    * *          " << endl;
    cout << "                                       *      * **** *****  ****   *****  *    * ****       " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}
void loading()
{
    int p = 0;
    for (int n = 0; p == 0; n++)
    {
        system("cls");
        logo();
        welcome();
        cout << "Press Y to go on login menu " << endl;
        string starter;
        cin >> starter;
        if (starter == "Y")
        {
            system("cls");
            logo();
            p++;
            cout << "                                      LOADING";
            for (int x = 0; x < 5; x++)
            {
                cout << ".";
                Sleep(500);
            }
            cout << endl;
        }
        else
        {
            cout << "AN INVALID ENTERY" << endl;
            cout << endl;
            cout << " Press any key from your keyboard to go back on welcome menu ";
            getch();
        }
    }
}
void login()
{
    system("cls");
    logo();
    cout << "------------------------------------------LOGIN MENU-----------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "PRESS 1 FOR SIGNUP PRESS 2 FOR SIGNIN AND 3 FOR EXITING FROM APPLICATION  " << endl;
    cout << "-)SIGNUP     " << endl;
    cout << "-)SIGNIN " << endl;
    cout << "-)EXIT " << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Here ";
    cin >> choice;
}
void signup()
{
    system("cls");
    logo();
    cout << "--------------------------------------SIGN UP------------------------------------------------" << endl;
    cout << "Name: ";
    cin.ignore(100, '\n');
    getline(cin, name[loop1_variable], '\n');
    helper = 0;
    helper++;
    cout << "Note:Password must be of eight characters " << endl;
    cout << "Password: ";
    cin >> password[loop1_variable];
    if (password[loop1_variable].length() < 8)
    {
        cout << "Wrong Password" << endl;
        cout << endl;
        cout << "Press any key from your keyboard to go back on signup option ";
        getch();
        return;
    }
    else
    {
        helper++;
    }
    cout << "Enter Role: ";
    cin >> role[loop1_variable];
    if ((role[loop1_variable] != "user") && (role[loop1_variable] != "USER") && (role[loop1_variable] != "admin") && (role[loop1_variable] != "ADMIN"))
    {
        cout << "That Role does not exist " << endl;
        cout << endl;
        cout << " Press any key from your keyboard to go back on signup option ";
        getch();
        return;
    }
    else if ((role[loop1_variable] == "user") || (role[loop1_variable] == "USER") || (role[loop1_variable] == "admin") || (role[loop1_variable] == "ADMIN"))
    {
        helper++;
        cout << "Sign up sucessfully " << endl;
        cout << "Press any key from your keyboard to go back on login menu ";
        getch();
    }
    if (helper == 3)
    {
        helper1 = helper;
    }
}
void signin()
{

    string name1;
    string password1;
    system("cls");
    logo();
    cout << "--------------------------------------SIGN IN------------------------------------------------" << endl;
    cout << "Name: ";
    cin.ignore(100, '\n');
    getline(cin, name1, '\n');
    cout << "Password: ";
    cin >> password1;
    for (loop2_variable = 0; loop2_variable <= 99; loop2_variable++)
    {
        if (name1 == name[loop2_variable] && password1 == password[loop2_variable])
        {
            helper2++;
            cout << "Sucessfully Signin ";
            Sleep(300);
            break;
        }
    }
    if (helper2 == 0)
    {
        cout << "An invalid entry ";
        cout << endl;
        cout << " Press any key from your keyboard to go back on signin option  ";
        getch();
    }
}
string admin_menu()
{
    system("cls");
    logo();
    cout << "-----------------------------------ADMIN MENU---------------------------------------------";
    cout << endl;
    cout << endl;
    cout << "1-Enter personal details of docter of hospital " << endl;
    cout << "2-Enter personal details of patient of hospital " << endl;
    cout << "3-View personal details of docters of hospital " << endl;
    cout << "4-View personal details of patients of hospital " << endl;
    cout << "5-Enter blood bank status " << endl;
    cout << "6-Enter rates of different rooms  of hospital " << endl;
    cout << "7-Enter and modify lab test rates " << endl;
    cout << "8-Calculation of revenue generated in a day " << endl;
    cout << "9-Delete record of any patient " << endl;
    cout << "10-Exit " << endl;
    string choice1;
    cout << "Enter Here ";
    cin >> choice1;
    return choice1;
}
string user_menu()
{
    system("cls");
    logo();
    cout << "-----------------------------------USER MENU---------------------------------------------";
    cout << endl;
    cout << endl;
    cout << "1-View blood bank status and choose if any required" << endl;
    cout << "2-View available physicians " << endl;
    cout << "3-View lab test rates " << endl;
    cout << "4-Check rates of rooms in hospital and select if any reqiured  " << endl;
    cout << "5-Check your bill   " << endl;
    cout << "6-Recommendations    " << endl;
    cout << "7-Exit" << endl;
    string choice2;
    cout << "Enter Here ";
    cin >> choice2;
    return choice2;
}
void add_docter_details()
{
    int flag=0;
    int a;
    for (; docter_data_helper_variable <= 99;)
    {
        cout << "Enter the details of docter " << endl;
        cout << endl;
        cin.ignore(100, '\n');
        cout << "Enter docter name ";
        getline(cin, docter_name[docter_data_helper_variable], '\n');
        cout << "Enter docter specilaization ";
        getline(cin, docter_specialization[docter_data_helper_variable], '\n');
        cout << "Enter docter degrees ";
        getline(cin, docters_degrees[docter_data_helper_variable], '\n');
        cout << "Enter docter contact number ";
        cin >> docter_number[docter_data_helper_variable];
        for(int i=0;i<docter_number[docter_data_helper_variable].length();i++)
        {
            a=docter_number[docter_data_helper_variable][i];
            if(!(a>=48 && a<=57))
            {
                cout<<"AN INVALID CONTACT NUMBER ENTER BY THE ADMIN "<<endl;
                flag++;
                break;
            }
        }
        if(flag!=0)
        {
            docter_data_helper_variable--;
            break;
        }
        cin.ignore(100, '\n');
        cout << "Enter docter days in hospital ";
        getline(cin, docters_timings[docter_data_helper_variable], '\n');
        cout << "Enter docter's age  ";
        cin >> docter_age[docter_data_helper_variable];
        cout << "Enter docter's id  ";
        cin >> docter_id[docter_data_helper_variable];
        docter_data_helper_variable++;
        break;
    }
}
void add_patient_details()
{
    int flag1=0;
    int b;
    for (; patient_data_helper_variable <= 99;)
    {
        cout << "Enter the details of patient " << endl;
        cout << endl;
        cin.ignore(100, '\n');
        cout << "Enter patient name ";
        getline(cin, patient_name[patient_data_helper_variable], '\n');
        cout << "Enter father name  of patient ";
        getline(cin, patient_father_name[patient_data_helper_variable], '\n');
        cout << "Enter patient blood group ";
        cin >> patient_blood_group[patient_data_helper_variable];
        cout << "Enter patient age ";
        cin >> patient_age[patient_data_helper_variable];
        cout << "Enter patient id ";
        cin >> patient_id[patient_data_helper_variable];
        cout << "Enter patient contact number ";
        cin >> patient_number[patient_data_helper_variable];
        for(int i=0;i<patient_number[patient_data_helper_variable].length();i++)
        {
            b=patient_number[patient_data_helper_variable][i];
            if(!(b>=48 && b<=57))
            {
                cout<<"AN INVALID CONTACT NUMBER ENTER BY THE ADMIN ";
                flag1++;
                break;
            }
        }
        if(flag1!=0)
        {
            patient_data_helper_variable--;
            break;
        }
        cin.ignore(100, '\n');
        cout << "Enter desease of patient ";
        getline(cin,patient_desease[patient_data_helper_variable],'\n');
        patient_data_helper_variable++;
        break;
    }
}
void view_docter_details(string docter_name_variable, string docter_id_varible)
{
    int flag1 = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (docter_name_variable == docter_name[i] && docter_id_varible == docter_id[i])
        {
            cout << "-------------------------------------------Docter's Details--------------------------------------------------" << endl;
            cout << endl;
            cout << " Name: " << docter_name[i] << endl;
            cout << " Contact number: " << docter_number[i] << endl;
            cout << " Age: " << docter_age[i] << endl;
            cout << " Days of docter: " << docters_timings[i] << endl;
            cout << " Docter's id: " << docter_id[i] << endl;
            cout << " Docter's Specialization: " << docter_specialization[i] << endl;
            cout << " Docter's Degrees: " << docters_degrees[i] << endl;
            flag1++;
            break;
        }
    }
    if (flag1 == 0)
    {
        cout << " An invalid entry of docters name or id " << endl;
    }
}
void view_patient_details(string patient_name_variable, string patient_id_varible)
{
    int flag2 = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (patient_name_variable == patient_name[i] && patient_id_varible == patient_id[i])
        {
            cout << "-------------------------------------------Patient's Details--------------------------------------------------" << endl
                 << endl
                 << endl;
            cout << " Name: " << patient_name[i] << endl;
            cout << " Contact number: " << patient_number[i] << endl;
            cout << " Age: " << patient_age[i] << endl;
            cout << " Father name of patient: " << patient_father_name[i] << endl;
            cout << " Patient's id: " << patient_id[i] << endl;
            cout << " Patient's Desease: " << patient_desease[i] << endl;
            cout << " Patient's Blood Group: " << patient_blood_group[i] << endl
                 << endl;
            flag2++;
            break;
        }
    }
    if (flag2 == 0)
    {
        cout << " An invalid entry of patient name or id " << endl;
    }
}
void blood_bank_status(int blood_range)
{
    for (; blood_data_helper_variable < blood_range; blood_data_helper_variable++)
    {
        system("cls");
        logo();
        cout << "-----------------------------------------------Blood Bank-------------------------------------------------------------" << endl
             << endl;
        cout << "Enter blood type: ";
        cin >> blood_type[blood_data_helper_variable];
        cout << "Enter number of packets in kg of respective blood type ";
        cin >> blood_packet[blood_data_helper_variable];
    }
}
void rooms(int size)
{
    room_type[size];
    rates[size];
    no_of_rooms[size];
    for (rooms_helper_variable=0; rooms_helper_variable < size; rooms_helper_variable++)
    {
        system("cls");
        logo();
        cout << "--------------------------------------------------------ROOMS--------------------------------------------------" << endl;
        cout << endl;
        cout << "Enter name of room  ";
        cin>> room_type[rooms_helper_variable];
        cout << "Enter rate of respective room  ";
        cin >> rates[rooms_helper_variable];
        cout << "Enter no of rooms available of this type in the hospital ";
        cin >> no_of_rooms[rooms_helper_variable];
    }
}
void lab_test(int size1)
{
    test_type[size1];
    test_rate[size1];
    for (lab_test_helper_variable=0; lab_test_helper_variable < size1; lab_test_helper_variable++)
    {
        system("cls");
        logo();
        cout << "--------------------------------------------------------LAB TEST RATES--------------------------------------------------" << endl;
        cout << endl;
        cout << "Enter type of test:  ";
        cin >> test_type[lab_test_helper_variable];
        cout << "Enter test rate: ";
        cin >> test_rate[lab_test_helper_variable];
    }
}
int revenue_calculator()
{
    int sum = 0;
    string test;
    int test_count;
    int room_count;
    string room;
    system("cls");
    logo();
    cout << "--------------------------------------------------------MONEY RECORD----------------------------------------------------------------";
    cout << endl;
    cout << endl;
    cout << "Number of tests taken today ";
    cin >> test_count;
    cout << "Number of rooms alloted today ";
    cin >> room_count;
    for (int i = 0; i < test_count; i++)
    {
        system("cls");
        logo();
        cout << "--------------------------------------------------------TEST COUNT----------------------------------------------------------------";
        cout << endl;
        cout << endl;
        int flag = 0;
        cout << "Enter test name: ";
        cin >> test;
        for (int n = 0; n < lab_test_helper_variable; n++)
        {
            if (test == test_type[n])
            {
                sum = sum + test_rate[n];
                flag++;
            }
        }
        if (flag == 0)
        {
            cout << "An invalid entry that test does not available in our hospital ";            
        }
    }
    for (int m = 0; m < room_count; m++)
    {
        system("cls");
        logo();
        cout << "--------------------------------------------------------ROOMS COUNT----------------------------------------------------------------";
        cout << endl;
        cout << endl;
        int flag = 0;
        cout << "Enter room name: ";
        cin>>room;
        for (int p = 0; p < rooms_helper_variable; p++)
        {
            if (room == room_type[p])
            {
                sum = sum + rates[p];
                flag++;
            }
        }
        if (flag == 0)
        {
            cout << "An invalid entry that room  does not available in our hospital ";
        }
    }
    return sum;
}
void view_blood_bank_status()
{
    int flag=0;
    string blood;
    int packet;
    cout << "-----------------------------------------------Blood Bank-------------------------------------------------------------" << endl;
    cout << endl;
    for (int i = 0; i < blood_data_helper_variable; i++)
    {
        cout << "BLOOD TYPE:    " << blood_type[i]  << endl;
        cout << "NO OF PACKETS AVAILABLE:    " << blood_packet[i]<<endl;
        cout<<endl;
    }
    cout << "Enter blood type you need ";
    cin >> blood;
    cout << "Enter no of packets you need ";
    cin >> packet;
    for (int i = 0; i < blood_data_helper_variable; i++)
    {
        if (blood == blood_type[i])
        {
            if (packet <= blood_packet[i])
            {
                blood_packet[i] = blood_packet[i] - packet;
                cout << "Sucessfully Booked " << endl;
            }
            else
            {
                cout << "We have not much packets available of that particular type of blood "<<endl;
            }
            flag++;    
        }
    }
    if(flag==0)
    {
    cout << "That type of blood is not available here in our blood bank " << endl;
    }
}
void view_available_physicians()
{
    cout << "-------------------------------------------Docters Details--------------------------------------------------" << endl;
    cout << endl;
    for (int i = 0; i < docter_data_helper_variable; i++)
    {
        cout << " Name: " << docter_name[i] << endl;
        cout << " Contact number: " << docter_number[i] << endl;
        cout << " Age: " << docter_age[i] << endl;
        cout << " Days of docter: " << docters_timings[i] << endl;
        cout << " Docter's id: " << docter_id[i] << endl;
        cout << " Docter's Specialization: " << docter_specialization[i] << endl;
        cout << " Docter's Degrees: " << docters_degrees[i] << endl;
        cout << endl;
    }
}
void view_lab_test_rates()
{
    for (int i = 0; i < lab_test_helper_variable; i++)
    {
        system("cls");
        logo();
        cout << "--------------------------------------------------------LAB TEST RATES--------------------------------------------------" << endl;
        cout << endl;
        cout << "TEST NAME: " << test_type[i] << endl;
        cout<< "TEST RATE:  " << test_rate[i]<<endl;
        cout<<endl;         
    }
}
void delete_patient_record(string patient_name_variable, string patient_id_variable)
{
    for (int i = 0; i <= 9; i++)
    {
        if (patient_name_variable == patient_name[i] && patient_id_variable == patient_id[i])
        {
            patient_name[i] = "RECORD DELETED";
            patient_number[i] = "RECORD DELETED";
            patient_father_name[i] = "RECORD DELETED";
            patient_blood_group[i] = "RECORD DELETED";
            patient_desease[i] = "RECORD DELETED";
            patient_age[i] = "RECORD DELETED";
            patient_id[i] = "RECORD DELETED";
        }
    }
}
void room_selection()
{
    int flag = 0;
    string select_room;
    cout << "-----------------------------------------------------------------ROOMS RATES-------------------------------------------------------------" << endl;
    for (int n = 0; n < rooms_helper_variable; n++)
    {
        cout << "Room Name:     " << room_type[n] <<endl;
        cout<< "ROOM RATE:        " << rates[n] << endl;
        cout<<endl;
    }
    cout << endl;
    cout << "Enter room you want to book      "<<endl;
    cin >> select_room;
    for (int n = 0; n < rooms_helper_variable; n++)
    {
        if (select_room == room_type[n])
        {
            if (no_of_rooms[n] >= 1)
            {
                cout << "YOUR ROOM IS SUCEESSFULLY BOOKED "<<endl;
            }
            else
            {
                cout << "All the rooms of this type are totally booked "<<endl;
            }
            flag++;
        }
    }
    if (flag == 0)
    {
        cout << "THAT TYPE OF ROOM DOES NOT EXIST IN OUR HOSPITAL "<<endl;
    }
    flag = 0;
}
int check_bill()
{
    string room_booked;
    int no_of_test;
    string test_name;
    int sum1 = 0;
    int flag1 = 0;
    cout << "Enter number of tests you have ";
    cin >> no_of_test;
    cout << "Enter name of your room: ";
    cin >> room_booked;
    for (int i = 0; i < no_of_test; i++)
    {
        int flag = 0;
        cout << "Enter Name of Test: ";
        cin >> test_name;
        for (int n = 0; n < lab_test_helper_variable; n++)
        {
            if (test_name == test_type[n])
            {
                sum1 = sum1 + test_rate[n];
                flag++;
            }
        }
        if (flag == 0)
        {
            cout << "An invalid entry that test does not available in our hospital "<<endl;
            i--;
        }
    }
    for (int n = 0; n <= rooms_helper_variable; n++)
    {
        if (room_booked == room_type[n])
        {
            flag1++;
            sum1 = sum1 + rates[n];
        }
    }
    if (flag1 == 0)
    {
        cout << "That room does not exist in our hospital "<<endl;
    }
    return sum1;
}
void recommendations(string desease)
{
    int flag=0;
    if (desease == "TROUGHT" || desease == "NOSE" || desease == "EAR")
    {
        for (int i = 0; docter_specialization[i] == "ENT"; i++)
        {
            cout << "YOU ARE RECOMMENDED TO GO  " << docter_name[i] << endl;
            flag++;
        }
    }
    else
    {
        for (int i = 0; i < docter_data_helper_variable; i++)
        {
            if(desease==docter_specialization[1])
            {
            cout << "YOU ARE RECOMMENDED TO GO  " << docter_name[i] << endl;
            flag++;
            }
        }
    }
    if(flag==0)
    {
        cout<<"DOCTER OF THAT DESEASE IS NOT AVAILABLE IN OUR HOSPITAL "<<endl;
    }
}
