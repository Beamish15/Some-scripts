#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> //  String manipulation if needed

// Function to convert hexadecimal string to a vector of bytes
std::vector<unsigned char> hexToBytes(const std::string& hex) {
    std::vector<unsigned char> bytes;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        unsigned char byte = (unsigned char)strtol(byteString.c_str(), NULL, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

int main() {
    std::string hex_cipher = "CYPHER_TEXT_HERE"; // <-- Replace with actual hex cipher
    std::vector<unsigned char> c = hexToBytes(hex_cipher);

    std::vector<unsigned char> known_prefix = {'T', 'H', 'M', '{'};
    
    std::vector<unsigned char> key_4bytes(4);
    for (int i = 0; i < 4; i++) {
        key_4bytes[i] = c[i] ^ known_prefix[i];
    }

    std::cout << "[*] Running..." << std::endl; // This is for testing

    for (int last_byte = 0; last_byte < 256; last_byte++) {
        std::vector<unsigned char> full_key = key_4bytes;
        full_key.push_back((unsigned char)last_byte);

        std::string p = "";
        for (size_t i = 0; i < c.size(); i++) {
            p += (char)(c[i] ^ full_key[i % full_key.size()]);
        }

        if (p.rfind("THM{", 0) == 0 && p.back() == '}') {
            std::cout << "[+] Key found: ";
            for (auto b : full_key) std::cout << b;
            std::cout << "\n[+] Flag: " << p << std::endl;
            break;
        }
    }

    return 0;
}