#include "gtest/gtest.h"
#include "../../src/Election.cpp"
#include "../../src/OPLParty.cpp"
#include "../../src/Ballot.cpp"
#include "../../src/CandidateOPL.cpp"
#include "../../src/Candidate.cpp"
#include "../../src/Seat.cpp"
#include "../../src/Party.cpp"
#include "../../src/CandidateMPO.cpp"
#include "../../src/PartyMPO.cpp"
// #include "../../src/main.cpp"
#include "../../src/PartyMV.cpp"
#include "../../src/CandidateMV.cpp"


class ElectionSystemTest : public ::testing::Test {
protected:
    Election election;

    void SetUp() override {}
};


TEST_F(ElectionSystemTest, RunOPLSystemTest) {
    std::ifstream inputFile("OPL.csv");
    string header;
    EXPECT_TRUE(inputFile.is_open()) << "Failed to open input file";
    getline(inputFile, header);

    //check to see if result is 0 after running
    int result = election.runOPL(inputFile);
    EXPECT_EQ(result, 0);
}

TEST_F(ElectionSystemTest, RunCPLSystemTest) {
    std::ifstream inputFile("CPL.csv");
    string header;
    EXPECT_TRUE(inputFile.is_open()) << "Failed to open input file";
    getline(inputFile, header);

    
    //check to see if result is 0 after running
    int result = election.runCPL(inputFile);
    EXPECT_EQ(result, 0);
}

TEST_F(ElectionSystemTest, RunMPOSystemTest) {
    std::ifstream inputFile("MPO.csv");
    string header;
    EXPECT_TRUE(inputFile.is_open()) << "Failed to open input file";
    getline(inputFile, header);

    
    //check to see if result is 0 after running
    int result = election.runMPO(inputFile);
    EXPECT_EQ(result, 0);
}

TEST_F(ElectionSystemTest, RunMVSystemTest) {
    std::ifstream inputFile("MV.csv");
    string header;
    EXPECT_TRUE(inputFile.is_open()) << "Failed to open input file";
    getline(inputFile, header);

    
    //check to see if result is 0 after running
    int result = election.runMPO(inputFile);
    EXPECT_EQ(result, 0);
}

TEST_F(ElectionSystemTest, RunFunction) {
    std::vector<std::string> fileNameVector;
    fileNameVector.push_back("OPL.csv");
    fileNameVector.push_back("CPL.csv");

    
    //check to see if result is 0 after running
    int result = election.run(fileNameVector);
    EXPECT_EQ(result, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}