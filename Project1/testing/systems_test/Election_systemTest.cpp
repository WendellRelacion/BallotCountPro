#include "gtest/gtest.h"
#include "../../src/Election.cpp"
#include "../../src/OPLParty.cpp"
#include "../../src/Ballot.cpp"
#include "../../src/CandidateOPL.cpp"
#include "../../src/Candidate.cpp"
#include "../../src/Seat.cpp"
#include "../../src/Party.cpp"



class ElectionSystemTest : public ::testing::Test {
protected:
    Election election;

    void SetUp() override {
        
    }
};

TEST_F(ElectionSystemTest, RunOPLSystemTest) {
    std::string fileName = "OPL.csv";
    int result = election.run(fileName);
    ASSERT_EQ(result, 0); 
}

TEST_F(ElectionSystemTest, RunCPLSystemTest) {
    std::string fileName = "CPL.csv";
    int result = election.run(fileName);
    ASSERT_EQ(result, 0); 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
