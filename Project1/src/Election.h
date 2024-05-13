/*****************************************************************//**
 * \file   Party.h
 * \brief 
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/
#ifndef ELECTION_H
#define ELECTION_H

using namespace std;

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Party.h"
#include "Ballot.h"
#include "Seat.h"
#include "OPLParty.h"

/**
 * @class Election
 * @brief Election class which contains the data parsing methods, seat allocation methods, producing audit file and also outputting the results 
 * 
 */
class Election {
private:
    std::string header;
    int numSeats;
    int numBallots;
    // int numParties;
    int numCandidatesOrParties;
    std::vector<Party> parties;
    std::vector<OPLParty> OPLParties;
    std::vector<Ballot> partyBallots; 
    std::vector<Ballot> candidateBallots;
    std::vector<CandidateOPL> OPLCandidates;
    std::vector<Seat> seats;
    std::vector<std::vector<Candidate>> candidates;
    bool isTie;
    int sizeOfParties;
public:
    /**
     * @brief This function handles parsing through the different CSV files and storing the data from the CSV file in their respective objects. It also calls helper functions for proper seat allocation
     * 
     * \param fileName This function takes in a string fileName which is the filename the user will be prompted to type in 
     * \return This function returns an int 
     */
    int run(std::string fileName);

    /**
     * @brief This function handles the seat allocation for the respective candidates/parties involved. It uses the largest remainder algorithm to allocate the seats and also handles the tiebreakers
     * 
     * \param parties This is a vector of OPLParty objects which stores the different parties 
     * \param partyBallots This is a vector of Ballot objects which stores the different ballots(votes) for each party
     * \param total_seats This is an int that stores the total amount of seats that can be allocated to each party
     * \param totalBallots This is an int that stores the total votes from every ballot
     * \param seats This is a vector of seat objects that stores the seats given to a specific party 
     * \return This function does not have a return value
     */
    void largest_remainder_seat_allocation(std::vector<OPLParty>& parties, std::vector<Ballot>& partyBallots, int total_seats, int totalBallots, std::vector<Seat>& seats);

    /**
     * @brief This function handles the seat allocation if the Election type is CPL. It uses the largest remainder algorithm to allocate the seats and also handles the tiebreakers
     * 
     * \param parties This is a vector of Party objects which stores the different parties 
     * \param partyBallots This is a vector of Ballot objects which stores the different ballots(votes) for each party
     * \param total_seats This is an int that stores the total amount of seats that can be allocated to each party
     * \param totalBallots This is an int that stores the total votes from every ballot
     * \param seats This is a vector of seat objects that stores the seats given to a specific party 
     * \return This function does not have a return value
     */
    void largest_remainder_seat_allocation(std::vector<Party>& parties, std::vector<Ballot>& partyBallots, int total_seats, int totalBallots, std::vector<Seat>& seats);

    /**
     * @brief This function sorts the candidate votes so that the candidates with the highest votes are ranked from top to bottom
     * 
     * \param OPLParties This is a vector of OPLParty objects which stores the different parties 
     * \param OPLCandidates This is a vector of CandidateOPL objects which stores the candidates from the OPL election
     * \param candidateBallots This is a vector of Ballot objects which stores the votes for each candidate 
     * \return This function does not have a return value
     */
    void sortCandidateVotes(std::vector<OPLParty>& OPLParties, std::vector<CandidateOPL>&  OPLCandidates, std::vector<Ballot>& candidateBallots);

    /**
     * @brief This function creates a new file called 'auditFile.txt', and writes into it all relevent information from the electin, such as seat allocations
     * 
     * \param parties This is a vector of Party objects which stores the the different parties 
     * \param seats This is a vector of seats which stores the different seats that are allocated to each respective party
     * \return This function returns an int for error checking
     */
    int output(std::vector<Party> parties, std::vector<Seat> seats);

    /**
     * @brief This function creates a new file called 'auditFile.txt', and writes into it all relevent information from the electin, such as seat allocations
     * 
     * \param parties This is a vector of OPLParty objects which stores the the different parties 
     * \param seats This is a vector of seats which stores the different seats that are allocated to each respective party
     * \return This function returns an int for error checking
     */
    int output(std::vector<OPLParty> parties, std::vector<Seat> seats);
};

#endif /* ELECTION_H */
