#include <fstream>
#include <sstream>
typedef unsigned char BYTE;

BYTE hex_to_dec(BYTE* letter) {
    std::stringstream stream;
    unsigned int result;

    stream << letter;
    stream >> std::hex >> result;

    return result;
}

std::string base64_encode(std::ifstream& in) {
    const std::string STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string result;
    unsigned int num_letter;
    in >> num_letter;

    unsigned int num_iteration = num_letter / 3;
    BYTE byte3[3];
    BYTE byte4[4];
    BYTE letter[3];

    while (num_iteration > 0) {
        for (unsigned char & i : byte3) {
            in >> letter;
            i = hex_to_dec(letter);
        }

        byte4[0] = (byte3[0] & 252u) >> 2u;
        byte4[1] = ((byte3[0] & 3u) << 4u) + ((byte3[1] & 240u) >> 4u);
        byte4[2] = ((byte3[1] & 15u) << 2u) + ((byte3[2] & 192u) >> 6u);
        byte4[3] = byte3[2] & 63u;

        for (unsigned char i : byte4) {
            result += STRING[i];
        }

        num_iteration--;
    }

    if (num_letter % 3 != 0) {
        int i = 0;
        while (num_letter % 3) {
            in >> letter;
            byte3[i] = hex_to_dec(letter);

            i++;
            num_letter--;
        }

        for (int j = i; j < 3; j++) {
            byte3[j] = 0;
        }

        byte4[0] = (byte3[0] & 252u) >> 2u;
        byte4[1] = ((byte3[0] & 3u) << 4u) + ((byte3[1] & 240u) >> 4u);
        byte4[2] = ((byte3[1] & 15u) << 2u) + ((byte3[2] & 192u) >> 6u);

        for (int j = 0; j < i + 1; j++) {
            result += STRING[byte4[j]];
        }

        for (int j = 3 - i; j > 0; j--) {
            result += '=';
        }
    }

    return result;
}

int main() {
    std::ifstream in("base64.in");
    std::ofstream out("base64.out");

    out << base64_encode(in);

    in.close();
    out.close();

    return 0;
}