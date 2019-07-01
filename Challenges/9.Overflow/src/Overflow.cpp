#include <iostream>
using std::cout;
using std::endl;
using std::hex;
using std::cin;

int obfuscate(int data) {
    cout << hex << data << endl;
    data ^= 0xffffffff;
    cout << hex << data << endl;
    data = ~data;
    cout << hex << data << endl;
    data ^= 0xffffffff;
    cout << hex << data << endl;
    data += (0b1 << 31);
    cout << hex << data << endl;
    //cout << (data + (0b1 << 31)) << endl;
    //cout << hex << (data + (0b1 << 31)) << endl;
    return data;
}

int main() {
    int input = 0;

    while (true) {
        cin >> input;
        obfuscate(input);
    }

    return 0;
}
