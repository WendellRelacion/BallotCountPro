#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Election.h"

using namespace std;

string promptForFile() {
    string fileName;
    cout << "Enter the name of the file: ";
    cin >> fileName;
    return fileName;
}

int main(int argc, char* argv[]) {
    Election election;
    string fileName;
    fileName = promptForFile();
    election.run(fileName);
    return 0;
}