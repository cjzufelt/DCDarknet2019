long obfuscator(long value) {
    return value ^ 0x0123456789abcdef;
}

int main() {
    obfuscator(1);
    return 0;
}
