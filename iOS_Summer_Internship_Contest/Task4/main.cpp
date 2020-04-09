#include <fstream>
#include <vector>
#include <algorithm>

//int get_num(std::pair<int, int>* arr, int index) {
//    if (arr[index].first == 0) {
//        return 0;
//    }
//    else if (arr[index].second != 0) {
//        return arr[index].second + 1;
//    }
//    else {
//        return get_num(arr, arr[index].first - 1) + 1;
//    }
//}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int n;
    in >> n;

    int* arr = new int[n];
    int director_index = 0;
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        in >> arr[i];

        if (arr[i] == 0) {
            director_index = i;
        }

        if (arr[i] > max_index) {
            max_index = arr[i];
        }
    }

    std::vector<int> indexes;
    std::vector<int> cur_indexes;
    cur_indexes.push_back(director_index + 1);

    while (arr[cur_indexes[0]] < max_index) {
        for (int i = 0; i < n; i++) {
            if (std::find(cur_indexes.begin(), cur_indexes.end(), arr[i]) != cur_indexes.end()) {
                arr[i] = arr[cur_indexes[0] - 1] + 1;

                indexes.push_back(i + 1);
            }
        }

        cur_indexes = indexes;
        indexes.clear();
    }

    for (int i = 0; i < n; i++) {
        out << arr[i] << ' ';
    }

    in.close();
    out.close();

    return 0;
}
