#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    cout << "\n===== Student Management System =====\n";
    while(true){
    cout << "\nChoose an option:\n";    
    cout << "1.Add Student\n2.View Students\n3.Search students\n4.Exit" << endl;
    int choice;
    cin >> choice;
    string ans = "yes";
    string line;
    switch (choice)
    {
    case 1:{
        ofstream file("students.txt", ios::app);
        while (ans != "no")
        {
            
            string name;
            int marks;
            cout << "enter name : ";
            getline(cin >> ws, name);
            cout << "enter marks : ";
            cin >> marks;
            file << name << " : " << marks << endl;
            cout << "do you want to enter more data : " << endl;
            cin >> ans;
            if (ans == "no")
            {
                file.close();
                break;
            }
        }
        break;
    }    
    case 2:{
 
        cout<< "total students :\n";
        ifstream file("students.txt", ios::in);
      
        while(getline(file,line)){
            cout << line << endl;
        }
        file.close();
        break;
    }
    case 3:
        {
            cout<<"Enter name that you want to search : \n";
            string name;
            getline(cin >> ws , name);
            int found = 0;
            ifstream file("students.txt");
            while(getline(file,line)){
                if(line.find(name) != string::npos){
                    cout<< line << endl;
                    found = 1;

                }
            }
            if(!found){
                cout<<"student not found\n";
            }
            file.close();
        }
        cout<<"\n";
      
        break;
    case 4:
        cout<<"Exiting...";
        return 0;
    default:
        cout<<"Invalid choice\n";
    }
    }
    return 0;
}