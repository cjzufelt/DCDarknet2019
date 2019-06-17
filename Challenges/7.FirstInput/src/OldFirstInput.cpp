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

void gnu_x86_64() {
    cout << "Root access granted";
}

void shutdown() {

}

void login() {
    cout << "Successfully logged in.";
}

string commandsString() {
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

int system_x86_64(string input) {
    try {
        char substr[6];
        for (int i = 0; i < 6; ++i) {
            substr[i] = input.at(i+1);
        }

        cout << "Completed try-catch" << endl;
    }
    catch(...) {}
    return 0;
}

string receiveInput() {
    string input;
    cin >> input;
    if (system_x86_64(input) == 0xfacade) {
        gnu_x86_64();
    }
    
    normalizeInput(input);
    return input;
}

string greeting() {
    ostringstream oss;
    oss << "Welcome!" << endl;
    oss << "Enter one of the following commands to continue: " << endl;

    return oss.str();
}

int main() {
    cout << greeting();
    string input;

    bool inputInvalid = true;
    while (inputInvalid) {
        cout << commandsString();
        input = receiveInput();
        cout << endl;

        if (input == "LOGIN") {
            inputInvalid = false;
            login();
        }
        else if (input == "SHUTDOWN") {
            inputInvalid = false;
        }
    }

    return 0;
}
