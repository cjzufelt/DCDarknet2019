#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::ostringstream;

enum Commands {LOGIN, SHUTDOWN, LOGOFF, SECRET, ESCALATE};

void normalizeInput();
string receiveInput();
void escalate();
void shutdown();
string loginCommands();
int loginMenu();
void rootMenu();
string rootCommands();
string greeting();

void escalate() {
    cout << "Root access granted" << endl << endl;
}

string loginCommands() {
    ostringstream oss;
    oss << "Commands:" << endl;
    oss << "Echo" << setw(20) << "Logoff" << endl;
    return oss.str();
}

int loginMenu() {
    cout << "Successfully logged in" << endl << endl;
    string input;

    while (true) {
        cout << loginCommands(); 
        input = receiveInput();
        cout << endl;

        if (input.substr(0,5) == "ECHO ") {
            cout << input.substr(5) << endl << endl;
        }
        else if (input == "LOGOFF") {
            return LOGOFF;
        }
        else if (input.at(0) == 0x6) {
            escalate();
            return ESCALATE;
        }
    }
}

string rootCommands() {
    ostringstream oss;
    oss << "Commands:" << endl;
    oss << "Login" << setw(20) << "Shutdown" << endl;
    return oss.str();
}

void rootMenu() {
    string input;

    while (true) {
        cout << rootCommands(); 
        input = receiveInput();
        cout << endl;

        if (input == "LOGIN") {
            int loginReturn = loginMenu();
            if (loginReturn == LOGOFF) {
                cout << "Successfully logged off" << endl << endl;
            }
            else if (loginReturn == ESCALATE) {
                return;
            }
        }
        else if (input == "SHUTDOWN") {
            cout << "Goodbye!" << endl;
            return;
        }
    }
}

string greeting() {
    ostringstream oss;
    oss << setw(28) << "Welcome!" << endl;
    oss << "Enter one of the following commands to continue: " << endl << endl;

    return oss.str();
}

void normalizeInput(string& input) {
    for (int i = 0; i < input.length(); ++i) {
        if (isspace(input.at(i))) {
            break;
        }
        input.at(i) = toupper(input.at(i));
    }
}

string receiveInput() {
    string input;
    getline(cin, input);
    normalizeInput(input);
    return input;
}

int main() {
    cout << greeting();
    rootMenu();

    return 0;
}
