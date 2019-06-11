#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;

void login() {
    cout << "Welcome" << endl;
}

/*void openingInput(const string& input) {
    switch(input) {
        case "LOGIN":
            login();
            break;

        case"OBFUSCATE":
            obfuscate();
            break;

        case "QUIT":
            break;

        default:
            openingInput(input);
    }
}*/
string everytimeOutput() {
    
}

string greeting() {
    ostringstream oss;
    oss << "Welcome!" << endl;
    oss << "Enter one of the following commands to continue: " << endl;

    return oss.str();
}

string receiveInput() {
    string input;
    cin >> input;
    normalizeInput(input);
    return input;
}

void normalizeInput(string& input) {
    for (int i = 0; i < input.length(); ++i) {
        input.at(i) = toupper(input.at(i));
    }
}

int main() {
    cout << greeting();
    string input;
    cout << "Enter command: ";
    cin >> input;

    normalizeInput(input);
    //openingInput()

    return 0;
}
