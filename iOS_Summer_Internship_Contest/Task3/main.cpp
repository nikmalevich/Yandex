#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    std::string str;
    in >> str;

    std::vector<std::string> blocks;
    int index = 0;
    int num = 1;

    blocks.push_back(str.substr(index, num));
    index++;

    while (index + num < str.size()) {
        std::string substr = str.substr(index, num);

        if (std::find(blocks.begin(), blocks.end(), substr) == blocks.end()) {
            blocks.push_back(str.substr(index, num));

            index += num;
            num = 1;
        }
        else {
            num++;
        }
    }

    blocks.push_back(str.substr(index, num));

    for (std::string& block : blocks) {
        out << block << ' ';
    }

    in.close();
    out.close();

    return 0;
}
