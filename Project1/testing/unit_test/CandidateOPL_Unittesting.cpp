#include "../../src/CandidateOPL.cpp"
#include "../../src/Ballot.cpp"
#include "gtest/gtest.h"

class CandidateOPLTest : public ::testing::Test {
protected:
    CandidateOPL candidate;

    void SetUp() override {
        candidate.setRankingCandidates(5);
        Ballot defaultBallot;
        defaultBallot.setVotes(0);
        candidate.setBallot(defaultBallot);
    }
};

TEST_F(CandidateOPLTest, GetRankingCandidates) {
    EXPECT_EQ(5, candidate.getRankingCandidates());
}

TEST_F(CandidateOPLTest, SetRankingCandidates) {
    candidate.setRankingCandidates(10);
    EXPECT_EQ(10, candidate.getRankingCandidates());
}

TEST_F(CandidateOPLTest, GetBallot) {
    Ballot defaultBallot = candidate.getBallot();
    EXPECT_EQ(0, defaultBallot.getVotes()); 
}
TEST_F(CandidateOPLTest, SetBallot) {
    Ballot newBallot;
    newBallot.setVotes(10);
    candidate.setBallot(newBallot);
    Ballot updatedBallot = candidate.getBallot();
    EXPECT_EQ(10, updatedBallot.getVotes());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

