#include <fstream>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int num_tasks;
    int num_devices;
    in >> num_tasks;
    in >> num_devices;

    int *tasks_time = new int[num_tasks];
    for (int i = 0; i < num_tasks; i++) {
        in >> tasks_time[i];
    }

    qsort(tasks_time, num_tasks, sizeof(int), [](const void *a, const void *b) {
        int arg1 = *static_cast<const int *>(a);
        int arg2 = *static_cast<const int *>(b);

        return arg2 - arg1;
    });

    long result = 0;

    for (int i = 0; i < num_tasks; i++) {
        result += tasks_time[i] * (2 * (i / num_devices) + 1);
    }

    out << result;

    in.close();
    out.close();

    return 0;
}
