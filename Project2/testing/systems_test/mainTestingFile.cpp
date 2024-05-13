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