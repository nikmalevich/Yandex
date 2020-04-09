#include <fstream>
#include <algorithm>
#include <vector>

std::vector<int> get_max_distance(const std::vector<std::pair<int, int>> &products, int max_weight) {
    std::vector<std::vector<int>> matrix(products.size() + 1, std::vector<int>(max_weight + 1, 0));
    for (int i = 1; i <= products.size(); i++) {
        for (int j = 1; j <= max_weight; j++) {
            if (products[i - 1].first <= j) {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - products[i - 1].first] + products[i - 1].second);
            } else {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    return matrix[products.size()];
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int max_weight;
    in >> max_weight;
    int num_foods;
    in >> num_foods;

    std::vector<std::pair<int, int>> foods;
    int weight;
    int distance;

    for (int i = 0; i < num_foods; i++) {
        in >> weight;
        in >> distance;

        foods.emplace_back(weight, distance);
    }

    int num_drinks;
    in >> num_drinks;

    std::vector<std::pair<int, int>> drinks;

    for (int i = 0; i < num_drinks; i++) {
        in >> weight;
        in >> distance;

        drinks.emplace_back(weight, distance);
    }

    std::sort(foods.begin(), foods.end());
    std::sort(drinks.begin(), drinks.end());

    auto food_distances = get_max_distance(foods, max_weight);
    auto drink_distances = get_max_distance(drinks, max_weight);
    int result = 0;

    for (int i = 0; i < food_distances.size(); i++) {
        if (result < std::min(food_distances[i], drink_distances[max_weight - i])) {
            result = std::min(food_distances[i], drink_distances[max_weight - i]);
        }
    }

    out << result;

    in.close();
    out.close();

    return 0;
}
