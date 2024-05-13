#include "../../src/Candidate.cpp"
#include "../../src/Party.cpp"
#include "gtest/gtest.h"

class CandidateTest : public ::testing::Test {
protected:
    Candidate candidate;
    Party party;

    void SetUp() override {
        candidate.setCandidateName("Arzab B");
        party.setPartyName("Party1");
        candidate.setParty(&party);
    }
};

TEST_F(CandidateTest, GetCandidateName) {
    candidate.setCandidateName("Jake B");
    EXPECT_EQ(candidate.getCandidateName(), "Jake B");
}

TEST_F(CandidateTest, SetCandidateName) {
    candidate.setCandidateName("John A");
    EXPECT_EQ(candidate.getCandidateName(), "John A");
}

TEST_F(CandidateTest, GetParty) {
    EXPECT_EQ(candidate.getParty(), &party);
}

TEST_F(CandidateTest, SetParty) {
    Party newParty;
    newParty.setPartyName("Party2");
    candidate.setParty(&newParty);
    EXPECT_EQ(candidate.getParty(), &newParty);
}

TEST_F(CandidateTest, GetPartyName) {
    candidate.setPartyName("Sample Party");
    EXPECT_EQ(candidate.getPartyName(), "Sample Party");
}

TEST_F(CandidateTest, SetPartyName) {
    candidate.setPartyName("Updated Party");
    EXPECT_EQ(candidate.getPartyName(), "Updated Party");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
