#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::hex;
using std::cin;
using std::string;

string obfuscate(string data) {
    for (size_t i = 0; i < data.length(); ++i) {
        data.at(i) ^= 0xffff;
        data.at(i) = ~data.at(i);
        data.at(i) += (0x8);
    }

    cout << data << endl;

    return data;
}

int main() {
    string input;

    while (true) {
        cin >> input;
        obfuscate(input);
    }

    return 0;
}
