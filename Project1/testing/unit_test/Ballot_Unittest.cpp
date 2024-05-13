#include "../../src/Ballot.cpp"
#include "gtest/gtest.h"

class BallotTest : public ::testing::Test {
protected:
    Ballot ballot;

    void SetUp() override {
        ballot.setVotes(0);
    }
};

TEST_F(BallotTest, GetVotes) {
    ballot.setVotes(9);
    EXPECT_EQ(ballot.getVotes(), 9);
}

TEST_F(BallotTest, SetVotes) {
    ballot.setVotes(5);
    EXPECT_EQ(ballot.getVotes(), 5);
}

TEST_F(BallotTest, IncrementVotes) {
    ballot.incrementVotes();
    EXPECT_EQ(ballot.getVotes(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}