#include <fstream>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int n;
    in >> n;

    int** matrix = new int*[n];
    bool* arr = new bool[n * n + 1]();

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n]();

        for (int j = 0; j < n; j++) {
            int num;
            in >> num;

            if (num != 0) {
                matrix[i][j] = num;
                arr[num] = true;
            }
        }
    }

    int cur_index = 1;

    for (int i = 0; i < n; i++) {
        bool first = true;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                while (arr[cur_index]) {
                    cur_index++;
                }

                matrix[i][j] = cur_index;

                cur_index++;
            }

            if (first) {
                out << matrix[i][j];

                first = false;
            }
            else {
                out << ' ' << matrix[i][j];
            }
        }

        out << '\n';
    }

    in.close();
    out.close();

    return 0;
}
