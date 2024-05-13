#include <gtest/gtest.h>
#include "../../src/Election.cpp"
#include "../../src/OPLParty.cpp"
#include "../../src/Ballot.cpp"
#include "../../src/CandidateOPL.cpp"
#include "../../src/Candidate.cpp"
#include "../../src/Seat.cpp"
#include "../../src/Party.cpp"
#include "../../src/CandidateMPO.cpp"
#include "../../src/CandidateMV.cpp"
#include "../../src/PartyMPO.cpp"
#include "../../src/PartyMV.cpp"
#include <iostream> 
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
// #include "../../src/main.cpp"
#include "mainTestingFile.cpp"

class MainSystemTest : public ::testing::Test {
protected:

    void SetUp() override {}
};

//testing if the file exists
TEST_F(MainSystemTest, FileExists) {
    EXPECT_TRUE(fileExists("CPL.csv"));
}


TEST_F(MainSystemTest, FileDoesNotExist) {
    EXPECT_FALSE(fileExists("random.csv"));
}

// Testing multiple files' validity
TEST_F(MainSystemTest, PromptForFiles_ValidFilenames) {
    std::vector<std::string> expectedAnswer = {"OPL.csv", "CPL.csv"};
    int numFiles = expectedAnswer.size();

    std::stringstream input;
    for (const auto& file : expectedAnswer) {
        input << file << std::endl;
    }

    std::cin.rdbuf(input.rdbuf());
    std::vector<std::string> resultAnswer = promptForFiles();
    EXPECT_EQ(numFiles, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
