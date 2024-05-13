#include <iostream>
#include <fstream>
#include <vector>
#include <random>

void generateRandomFile(const std::string& filename, int lines) {
    std::ofstream outfile(filename);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4);

    for (int i = 0; i < lines; ++i) {
        std::vector<int> line(5, 0);
        int ones = dis(gen) + 1; // At least one 1 and less than three 1s
        for (int j = 0; j < ones; ++j) {
            int pos = dis(gen);
            while (line[pos] == 1) {
                pos = dis(gen);
            }
            line[pos] = 1;
        }

        for (int j = 0; j < 5; ++j) {
            outfile << (line[j] == 1 ? "1" : "") << (j < 4 ? "," : "\n");
        }
    }

    outfile.close();
}

int main() {
    generateRandomFile("output.txt", 10);
    return 0;
}
