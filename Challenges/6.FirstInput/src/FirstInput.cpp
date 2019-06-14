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

void func() {
    cout << "Root access granted";
}

void shutdown() {
    cout << "Goodbye!" << endl;
}

void login() {
    cout << "Successfully logged in." << endl;
}

string openingCommands() {
    ostringstream oss;
    oss << "Commands:" << endl;
    oss << "Login" << setw(20) << "Shutdown" << endl;
    return oss.str();
}

void normalizeInput(string& input) {
    for (int i = 0; i < input.length(); ++i) {
        input.at(i) = toupper(input.at(i));
    }
}

string receiveInput() {
    string input;
    cin >> input;
    normalizeInput(input);
    return input;
}

string greeting() {
    ostringstream oss;
    oss << setw(28) << "Welcome!" << endl;
    oss << "Enter one of the following commands to continue: " << endl;

    return oss.str();
}

int openingMenu() {
    cout << greeting();
    string input;

    while (true) {
        cout << openingCommands(); 
        input = receiveInput();
        cout << endl;

        if (input == "LOGIN") {
            return 1;
        }
        else if (input == "SHUTDOWN") {
            return 2;
        }
        else if (input.at(0) == 0x6) {
            return 3;
        }
    }
}

int main() {
    switch (openingMenu()) {
        case 1:
            login();
            break;

        case 2:
            shutdown();
            break;

        case 3:
            func();
            break;
    }
    return 0;
}
