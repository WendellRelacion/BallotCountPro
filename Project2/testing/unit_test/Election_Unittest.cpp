#include "gtest/gtest.h"
#include "../../src/Election.cpp"
#include "../../src/OPLParty.cpp"
#include "../../src/Ballot.cpp"
#include "../../src/CandidateOPL.cpp"
#include "../../src/Candidate.cpp"
#include "../../src/Seat.cpp"
#include "../../src/CandidateMPO.cpp"
#include "../../src/PartyMPO.cpp"
#include "../../src/Party.cpp"
#include "../../src/PartyMV.cpp"
#include "../../src/CandidateMV.cpp"


class ElectionTest : public ::testing::Test {
protected:
    Election election;

    void SetUp() override {}
};

TEST_F(ElectionTest, SortCandidateVotesTest) {
    // Prepare test data
    std::vector<OPLParty> OPLParties;
    std::vector<CandidateOPL> OPLCandidates;
    std::vector<Ballot> candidateBallots;

    // Add some test data for OPLParties, OPLCandidates, and candidateBallots
    OPLParty party1;
    CandidateOPL candidate1;
    CandidateOPL candidate2;
    candidate1.setCandidateName("Candidate 1");
    candidate2.setCandidateName("Candidate 2");

    //populate the vectors
    party1.setPartyName("Party1");
    party1.addOPLCandidate(candidate1);
    party1.addOPLCandidate(candidate2);
    candidate1.setParty(&party1);
    candidate2.setParty(&party1);

    Ballot ballot1;
    Ballot ballot2;

    ballot1.setVotes(50);
    ballot2.setVotes(100);

    OPLCandidates.push_back(candidate1);
    OPLCandidates.push_back(candidate2);

    OPLParties.push_back(party1);
    
    candidateBallots.push_back(ballot1);
    candidateBallots.push_back(ballot2);

    //run the algorithm and test if the candidates are sorted properly
    election.sortCandidateVotes(OPLParties, OPLCandidates, candidateBallots);

    EXPECT_EQ(OPLParties[0].getCandidates().size(), 2); 
    EXPECT_EQ(party1.getCandidates().at(0).getCandidateName(), "Candidate 1");
    EXPECT_EQ(party1.getCandidates().at(1).getCandidateName(), "Candidate 2");
}

TEST_F(ElectionTest, LargestRemainderSeatAllocationTest_Party) {
    // Prepare test data
    std::vector<Party> parties;
    std::vector<Ballot> partyBallots;
    std::vector<Seat> seats;
    int totalSeats = 2; 
    int totalBallots = 8; 

    //populate the vectors
    Party party1;
    party1.setPartyName("Party A");
    Ballot ballot1;
    ballot1.setVotes(0);
    party1.setBallot(ballot1);
    parties.push_back(party1);
    // Ballot for Party A
    partyBallots.push_back(ballot1); 

    Party party2;
    party2.setPartyName("Party B");
    Ballot ballot2;
    ballot2.setVotes(5);
    party2.setBallot(ballot2);
    parties.push_back(party2);
    // Ballot for Party B
    partyBallots.push_back(ballot2); 

    Party party3;
    party3.setPartyName("Party C");
    Ballot ballot3;
    ballot3.setVotes(0);
    party3.setBallot(ballot3);
    parties.push_back(party3);
    // Ballot for Party C
    partyBallots.push_back(ballot3); 

    Party party4;
    party4.setPartyName("Party D");
    Ballot ballot4;
    ballot4.setVotes(3);
    party4.setBallot(ballot4);
    parties.push_back(party4);
    // Ballot for Party C
    partyBallots.push_back(ballot4); 


    //set the amount of seats
    for (int i = 0; i < parties.size(); i++){
        Seat newSeat;
        seats.push_back(newSeat);
    }

    // Call the function to be tested and check if seats are properly allocated
    election.largest_remainder_seat_allocation(parties, partyBallots, totalSeats, totalBallots, seats);
    EXPECT_EQ(seats.size(), 4);
    EXPECT_EQ(seats[0].getSeats(), 0);
    EXPECT_EQ(seats[1].getSeats(), 1);
    EXPECT_EQ(seats[2].getSeats(), 0);
    EXPECT_EQ(seats[3].getSeats(), 1);
}



TEST_F(ElectionTest, LargestRemainderSeatAllocationTest_OPLParty) {
    // Prepare test data
    std::vector<OPLParty> parties;
    std::vector<Ballot> partyBallots;
    std::vector<Seat> seats;
    int totalSeats = 2;
    int totalBallots = 9;


    //populate the vectors
    OPLParty party1;
    party1.setPartyName("Party X");
    Ballot ballot1;
    ballot1.setVotes(4);
    party1.setBallot(ballot1); 
    parties.push_back(party1);
    partyBallots.push_back(ballot1);

    OPLParty party2;
    party2.setPartyName("Party Y");
    Ballot ballot2;
    ballot2.setVotes(4);
    party2.setBallot(ballot2); 
    parties.push_back(party2);
    partyBallots.push_back(ballot2); 

    OPLParty party3;
    party3.setPartyName("Party Z");
    Ballot ballot3;
    ballot3.setVotes(1);
    party3.setBallot(ballot3); 
    parties.push_back(party3);
    partyBallots.push_back(ballot3);  


    //set the amount of seats
    for (int i = 0; i < parties.size(); i++){
        Seat newSeat;
        seats.push_back(newSeat);
    }

    // Call the function to be tested and check if seats are properly allocated
    election.largest_remainder_seat_allocation(parties, partyBallots, totalSeats, totalBallots, seats);
    EXPECT_EQ(seats[0].getSeats(), 1);
    EXPECT_EQ(seats[1].getSeats(), 1);
    EXPECT_EQ(seats[2].getSeats(), 0);
}

TEST_F(ElectionTest, LargestRemainderSeatAllocationTest_MPOParty) {
    // Prepare test data
    std::vector<CandidateMPO> MPOCandidates;
    std::vector<Ballot> candidateBallots;
    std::vector<Seat> seats;
    int totalSeats = 2;
    int totalBallots = 9;

    //populate the vectors 
    CandidateMPO candidate1;
    candidate1.setCandidateName("candidate1");
    CandidateMPO candidate2;
    candidate2.setCandidateName("candidate2");
    CandidateMPO candidate3;
    candidate3.setCandidateName("candidate3");
    CandidateMPO candidate4;
    candidate4.setCandidateName("candidate4");
    CandidateMPO candidate5;
    candidate5.setCandidateName("candidate5");
    CandidateMPO candidate6;
    candidate6.setCandidateName("candidate6");
    Ballot ballot1;
    ballot1.setVotes(5);
    Ballot ballot2;
    ballot2.setVotes(4);
    Ballot ballot3;
    ballot3.setVotes(0);
    Ballot ballot4;
    ballot4.setVotes(0);
    Ballot ballot5;
    ballot5.setVotes(0);
    Ballot ballot6;
    ballot6.setVotes(0);
    candidateBallots.push_back(ballot1);
    candidateBallots.push_back(ballot2);
    candidateBallots.push_back(ballot3);
    candidateBallots.push_back(ballot4);
    candidateBallots.push_back(ballot5);
    candidateBallots.push_back(ballot6);
    MPOCandidates.push_back(candidate1);
    MPOCandidates.push_back(candidate2);
    MPOCandidates.push_back(candidate3);
    MPOCandidates.push_back(candidate4);
    MPOCandidates.push_back(candidate5);
    MPOCandidates.push_back(candidate6);

    //set the amount of seats
    for (int i = 0; i < MPOCandidates.size(); ++i) {
        Seat newSeat;
        seats.push_back(newSeat);
    }

    //run the algorithm and check if seats are properly allocated 
    election.largest_remainder_seat_allocation(MPOCandidates, candidateBallots, totalSeats, totalBallots, seats);
    EXPECT_EQ(seats.size(), 6);
    EXPECT_EQ(seats[0].getSeats(), 1);
    EXPECT_EQ(seats[1].getSeats(), 1);
}

TEST_F(ElectionTest, LargestRemainderSeatAllocationTest_MVParty) {
    // Prepare test data
    std::vector<CandidateMV> MVCandidates;
    std::vector<Ballot> candidateBallots;
    std::vector<Seat> seats;
    int totalSeats = 3;
    int totalBallots = 9;

    //populate the vectors
    CandidateMV candidate1;
    candidate1.setCandidateName("candidate1");
    CandidateMV candidate2;
    candidate2.setCandidateName("candidate2");
    CandidateMV candidate3;
    candidate3.setCandidateName("candidate3");
    CandidateMV candidate4;
    candidate4.setCandidateName("candidate4");
    CandidateMV candidate5;
    candidate5.setCandidateName("candidate5");
    CandidateMV candidate6;
    candidate6.setCandidateName("candidate6");
    Ballot ballot1;
    ballot1.setVotes(4);
    Ballot ballot2;
    ballot2.setVotes(3);
    Ballot ballot3;
    ballot3.setVotes(3);
    Ballot ballot4;
    ballot4.setVotes(4);
    Ballot ballot5;
    ballot5.setVotes(4);
    Ballot ballot6;
    ballot6.setVotes(2);
    candidateBallots.push_back(ballot1);
    candidateBallots.push_back(ballot2);
    candidateBallots.push_back(ballot3);
    candidateBallots.push_back(ballot4);
    candidateBallots.push_back(ballot5);
    candidateBallots.push_back(ballot6);
    MVCandidates.push_back(candidate1);
    MVCandidates.push_back(candidate2);
    MVCandidates.push_back(candidate3);
    MVCandidates.push_back(candidate4);
    MVCandidates.push_back(candidate5);
    MVCandidates.push_back(candidate6);

    //set the amount of seats 
    for (int i = 0; i < MVCandidates.size(); ++i) {
        Seat newSeat;
        seats.push_back(newSeat);
    }

    //run the algorithm and check if seats are properly allocated 
    election.largest_remainder_seat_allocation(MVCandidates, candidateBallots, totalSeats, totalBallots, seats);
    EXPECT_EQ(seats.size(), 6);
    EXPECT_EQ(seats[0].getSeats(), 1);
    EXPECT_EQ(seats[3].getSeats(), 1);
    EXPECT_EQ(seats[4].getSeats(), 1);
}

TEST_F(ElectionTest, OutputFunction1) {
    std::vector<OPLParty> parties;
    std::vector<Ballot> partyBallots;
    std::vector<Seat> seats;
    int totalSeats = 2;
    int totalBallots = 9;

    //populate the vectors
    OPLParty party1;
    party1.setPartyName("Party X");
    Ballot ballot1;
    ballot1.setVotes(4);
    party1.setBallot(ballot1); 
    parties.push_back(party1);
    partyBallots.push_back(ballot1);

    OPLParty party2;
    party2.setPartyName("Party Y");
    Ballot ballot2;
    ballot2.setVotes(4);
    party2.setBallot(ballot2); 
    parties.push_back(party2);
    partyBallots.push_back(ballot2); 

    OPLParty party3;
    party3.setPartyName("Party Z");
    Ballot ballot3;
    ballot3.setVotes(1);
    party3.setBallot(ballot3); 
    parties.push_back(party3);
    partyBallots.push_back(ballot3);  

    //set the amount of seats
    for (int i = 0; i < parties.size(); i++){
        Seat newSeat;
        seats.push_back(newSeat);
    }


    ifstream file("OPL.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
    }

    //run algorithms and check if output returns 0
    string header;
    getline(file, header);
    election.largest_remainder_seat_allocation(parties, partyBallots, totalSeats, totalBallots, seats);
    election.runOPL(file);
    int result = election.output(parties, seats);
    EXPECT_EQ(result, 0);
}

TEST_F(ElectionTest, OutputFunction2) {
    std::vector<Party> parties;
    std::vector<Ballot> partyBallots;
    std::vector<Seat> seats;
    int totalSeats = 2;
    int totalBallots = 9;

    //populate the vectors
    Party party1;
    party1.setPartyName("Party A");
    Ballot ballot1;
    ballot1.setVotes(1);
    party1.setBallot(ballot1); 
    parties.push_back(party1);
    partyBallots.push_back(ballot1);

    Party party2;
    party2.setPartyName("Party B");
    Ballot ballot2;
    ballot2.setVotes(4);
    party2.setBallot(ballot2); 
    parties.push_back(party2);
    partyBallots.push_back(ballot2); 

    Party party3;
    party3.setPartyName("Party C");
    Ballot ballot3;
    ballot3.setVotes(0);
    party3.setBallot(ballot3); 
    parties.push_back(party3);
    partyBallots.push_back(ballot3);  

    Party party4;
    party4.setPartyName("Party D");
    Ballot ballot4;
    ballot4.setVotes(2);
    party4.setBallot(ballot4); 
    parties.push_back(party4);
    partyBallots.push_back(ballot4);

    Party party5;
    party5.setPartyName("Party E");
    Ballot ballot5;
    ballot5.setVotes(1);
    party5.setBallot(ballot5); 
    parties.push_back(party5);
    partyBallots.push_back(ballot5); 

    Party party6;
    party6.setPartyName("Party F");
    Ballot ballot6;
    ballot6.setVotes(1);
    party6.setBallot(ballot6); 
    parties.push_back(party6);
    partyBallots.push_back(ballot6);  

    //set the amount of seats
    for (int i = 0; i < parties.size(); i++){
        Seat newSeat;
        seats.push_back(newSeat);
    }

    ifstream file("CPL.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
    }

    //run algorithms and check if output returns 0
    string header;
    getline(file, header);
    election.largest_remainder_seat_allocation(parties, partyBallots, totalSeats, totalBallots, seats);
    election.runOPL(file);
    int result = election.output(parties, seats);
    EXPECT_EQ(result, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}