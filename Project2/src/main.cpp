#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Election.h"
// #include "../../testing/systems_test/main_SystemTest.cpp"


using namespace std;

// string promptForFile() {
//     string fileName;
//     cout << "Enter the name of the file: ";
//     cin >> fileName;
//     return fileName;
// }


// int main(int argc, char* argv[]) {
//     Election election;
//     string fileName;
//     fileName = promptForFile();
//     election.run(fileName);
//     return 0;
// }
bool fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.good();
}

std::vector<std::string> promptForFiles() {
    int numFiles;
    std::cout << "Enter the number of files: ";
    std::cin >> numFiles;
    std::vector<std::string> fileNames;

    for (int i = 0; i < numFiles; ++i) {
        std::cout << "Enter the name of file " <<  i + 1 << ": ";
        std::string fileName;
        std::cin >> fileName;
        if(fileExists(fileName)){
            
            fileNames.push_back(fileName);
        }
        else{
            cout << "File does not exist, please enter another." << endl;
            i--;
        }
    }
    return fileNames;
}

int main(int argc, char* argv[]) {
    Election election;
    std::vector<std::string> fileNames;
    fileNames = promptForFiles();
    election.run(fileNames);
    return 0;
}


