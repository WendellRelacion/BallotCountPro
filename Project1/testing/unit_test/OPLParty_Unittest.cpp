#include "gtest/gtest.h"
#include "../../src/OPLParty.cpp"
#include "../../src/Party.cpp"
#include "../../src/Ballot.cpp"
#include "../../src/CandidateOPL.cpp"
#include "../../src/Candidate.cpp"

class OPLPartyTest : public ::testing::Test {
protected:
    OPLParty oplParty;

    void SetUp() override {
        CandidateOPL candidate1, candidate2;
        candidate1.setCandidateName("Candidate 1");
        candidate2.setCandidateName("Candidate 2");
        oplParty.addOPLCandidate(candidate1);
        oplParty.addOPLCandidate(candidate2);
    }
};

TEST_F(OPLPartyTest, CandidateVoteFunctions) {
    oplParty.setCandidateVote("Candidate 1", 100);
    EXPECT_EQ(oplParty.getCandidateVote("Candidate 1"), 100);
}

TEST_F(OPLPartyTest, SetCandidateRankings) {
    CandidateOPL candidate;
    CandidateOPL candidate2;
    Ballot ballot;
    ballot.setVotes(50);
    candidate.setBallot(ballot);
    Ballot newballot;
    newballot.setVotes(40);
    candidate2.setBallot(newballot);
    oplParty.setCandidateRankings(candidate);
    oplParty.setCandidateRankings(candidate2);
    std::vector<CandidateOPL> rankings = oplParty.getRankings();
    ASSERT_EQ(rankings.size(), 2); 
    EXPECT_EQ(rankings[0].getBallot().getVotes(), 50);
    EXPECT_EQ(rankings[1].getBallot().getVotes(), 40);
}

TEST_F(OPLPartyTest, GetRankings) {
    std::vector<CandidateOPL> rankings = oplParty.getRankings();
    ASSERT_EQ(rankings.size(), 0);
}

TEST_F(OPLPartyTest, AddOPLCandidate) {
    CandidateOPL candidate;
    candidate.setCandidateName("Candidate 3");
    oplParty.addOPLCandidate(candidate);
    std::vector<Candidate> candidates = oplParty.getCandidates();
    ASSERT_EQ(candidates.size(), 3);
    EXPECT_EQ(candidates[2].getCandidateName(), "Candidate 3");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}