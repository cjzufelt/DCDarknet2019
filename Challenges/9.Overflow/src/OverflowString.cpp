#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::hex;
using std::cin;
using std::string;

string obfuscate(string data) {
    //cout << hex << data << endl;
    data ^= 0xffffffff;
    cout << data << endl;
    data = ~data;
    cout << data << endl;
    data += (0b1 << 31);
    cout << data << endl;
    //cout << (data + (0b1 << 31)) << endl;
    //cout << hex << (data + (0b1 << 31)) << endl;
    return data;
}

int main() {
    char input[9];

    while (true) {
        cin >> input;
        obfuscate(input);
    }

    return 0;
}
