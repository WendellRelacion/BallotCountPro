#include "gtest/gtest.h"
#include "../../src/Party.cpp"
#include "../../src/Ballot.cpp"
#include "../../src/Candidate.cpp"



class PartyTest : public ::testing::Test {
protected:
    Party party;

    void SetUp() override {
        party.setPartyName("Test Party");
        Candidate candidate1, candidate2;
        candidate1.setCandidateName("Candidate 1");
        candidate2.setCandidateName("Candidate 2");
        party.addCandidate(candidate1);
        party.addCandidate(candidate2);
        Ballot ballot;
        party.setBallot(ballot);
        party.setRemainder(ballot);
    }
};

TEST_F(PartyTest, GetPartyName) {
    EXPECT_EQ(party.getPartyName(), "Test Party");
}

TEST_F(PartyTest, SetPartyName) {
    party.setPartyName("New Party Name");
    EXPECT_EQ(party.getPartyName(), "New Party Name");
}

TEST_F(PartyTest, GetCandidates) {
    std::vector<Candidate> candidates = party.getCandidates();
    ASSERT_EQ(candidates.size(), 2);
    EXPECT_EQ(candidates[0].getCandidateName(), "Candidate 1");
    EXPECT_EQ(candidates[1].getCandidateName(), "Candidate 2");
}

TEST_F(PartyTest, BallotFunctions) {
    Ballot ballot;
    ballot.setVotes(100);
    party.setBallot(ballot);
    Ballot retrievedBallot = party.getBallot();
    EXPECT_EQ(retrievedBallot.getVotes(), 100);
}

TEST_F(PartyTest, RemainderFunctions) {
    Ballot remainder;
    remainder.setVotes(50);
    party.setRemainder(remainder);
    Ballot retrievedRemainder = party.getRemainder();
    EXPECT_EQ(retrievedRemainder.getVotes(), 50);
}

TEST_F(PartyTest, AllocatedSeatsFunctions) {
    party.setAllocatedSeats(0, 5);
    party.setAllocatedSeats(1, 1);
    std::vector<int> allocatedSeats = party.getAllocatedSeats();
    ASSERT_EQ(allocatedSeats.size(), 2);
    EXPECT_EQ(allocatedSeats[0], 5);
    EXPECT_EQ(allocatedSeats[1], 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}