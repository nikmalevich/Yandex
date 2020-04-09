#include <fstream>
#include <regex>

int main() {
    std::ifstream in("taxi.in");
    std::ofstream out("taxi.out");

    unsigned int num_cars;
    in >> num_cars;
    char num_car[21];
    in.getline(num_car, 21);
    std::regex reg_num("([1-6]T[AB]X [0-9]{4})|(7T[ABE]X [0-9]{4})");
    std::regex not_reg_num("[0-9A-Za-z\\- ]{5}0000");
    unsigned int num_taxi = 0;

    for (int i = 0; i < num_cars; i++) {
        in.getline(num_car, 21);

        if (std::regex_match(num_car, reg_num)) {
            if(!std::regex_match(num_car, not_reg_num)) {
                num_taxi++;
            }
        }
    }

    out << num_taxi;

    in.close();
    out.close();

    return 0;
}
