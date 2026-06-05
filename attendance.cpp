#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{

    // names of the 2028 engineering class
    vector<string> students = {
        "Envy",
        "Ilyas",
        "Damon",
        "Hamir",
        "Anthony",
        "Bode",
        "George",
        "Jordan",
        "Christopher",
        "Caleb",
        "Seth",
        "Ryan",
        "Tiahna",
        "Bailin",
        "Elijah",
        "Connor"
    };

    // declaring variables;
    string date;
    int present;
    int k = 0;

    // user input
    cout << "==============================================\n";
    cout << "Enter the date in month, day, year format\n";
    cout << "==============================================\n";
    getline (cin, date); // used for potential spaces or special characters
    do {
        k++;
        if (date[k] == '/') {
            cout << "Please enter it again without any slashes\n";
            getline (cin, date);
        }
    } while (k < date.length());
    
    cout << "==============================================\n";
    ofstream myFile("Attendance - " + date + ".txt");

    // for loop
    for (int i; i < students.size(); i++) {
        cout << "Type [1] if " << students[i] << " is present. Type [2] if they are not: ";
        cin >> present;

        if (present == 1) { // if student is present
            myFile << students[i] << " is present\n\n";
        } else if (present == 2) { // if student is not present
            myFile << students[i] << " is not present\n\n";
        } else if (present < 1 || present > 2) {
            cout << "Please try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> present;
        }
    }
}
