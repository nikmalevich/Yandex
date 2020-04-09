#include <fstream>
#include <algorithm>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int n;
    in >> n;

    int* canonical_arr = new int[n];

    for (int i = 0; i < n; i++) {
        in >> canonical_arr[i];
    }

    std::sort(canonical_arr, canonical_arr + n);

    int m;
    in >> m;

    for (int i = 0; i < m; i++) {
        int num;
        int first = 0;
        int last = n - 1;
        int mid = 0;

        in >> num;

        while (first <= last) {
            mid = (first + last) / 2;

            if (num == canonical_arr[mid]) {
                out << num << '\n';

                break;
            }
            else if (num < canonical_arr[mid]) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }

        if (num != canonical_arr[mid]) {
            if (last <= -1) {
                out << canonical_arr[0] << '\n';
            } else if (first >= n) {
                out << canonical_arr[n - 1] << '\n';
            } else {
                if (std::abs(num - canonical_arr[first]) <= std::abs(num - canonical_arr[last])) {
                    out << canonical_arr[first] << '\n';
                } else {
                    out << canonical_arr[last] << '\n';
                }
            }
        }
    }

    in.close();
    out.close();

    return 0;
}
