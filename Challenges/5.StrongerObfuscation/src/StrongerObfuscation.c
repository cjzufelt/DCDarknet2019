long obfuscation(long value) {
    value ^= 0xafafafafafafafaf;
    value += 0xf;
    value = __builtin_bswap64(value);

    return value;
}

int main() {
    return 0;
}
