/*****************************************************************//**
 * \file   Party.h
 * \brief 
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/

#ifndef PARTY_H
#define PARTY_H

#include <string>
#include <vector>
#include "Candidate.h"
#include "Ballot.h"
#include <random>

/**
 * @class Candidate
 * @brief This is a forward declaration for the class Candidate
 * 
 */
class Candidate; // Forward declaration

/**
 * @class Party
 * @brief This is a class that defines the functionalites for both OPLParties and CPL_Party
 * 
 */
class Party {
protected:
    std::string partyName;
    std::vector<Candidate> candidateNames;
    Ballot ballot;
    Ballot remainder;
    vector<int> allocatedSeats = {0,0};
public:

    /**
     * @brief This functions returns the partyName string for the specific Party
     * 
     * \param None This function does not take in any parameters
     * \return This function returns string partyName
     */
    std::string getPartyName() const;
    
    /**
     * @brief Set the Party Name object
     * 
     * @param name This function takes in a string name
     * \return This function does not return any values
     */
    void setPartyName(std::string name);

    /**
     * @brief This function returns a vector of type Candidate which contains all the candidates 
     * 
     * @param None This function does not have any parameters
     * \return This function returns a vector of type Candidate 
     */
    std::vector<Candidate> getCandidates();

    /**
     * @brief This function takes in a Candidate object and it pushes it into the candidateNames vector
     * 
     * @param candidate This function takes in candidate object
     * \return This function does not return any values
     */
    void addCandidate(Candidate candidate);

    /**
     * @brief This function gets the Ballot for the party 
     * 
     * @param None This function does not take any parameters
     * \return This function returns a ballot object
     */
    Ballot getBallot();

    /**
     * @brief This function sets the ballot for the party by taking in a ballot object and then pushing that object into the partyBallots vector
     * 
     * @param ballot This function takes in a ballot object
     * \return This function does not return any values
     */
    void setBallot(Ballot ballot);


    /**
     * @brief This function gets the remainder after doing the allocation and returns a ballot object which is the remainder votes
     * 
     * @param None This function does not take any parameters
     * \return This function returns a ballot object
     */

    Ballot getRemainder();

    /**
     * @brief This function sets the remainder by taking in a ballot object and it updates the remainder variable to the new ballot passed in
     * 
     * @param ballot This function takes in a ballot object
     * \return This function does not return any variables
     */
    void setRemainder(Ballot ballot);

    /**
     * @brief This function returns a vector of the allocated seats after the seat allocation process
     * 
     * @param None This function does not take in any parameters
     * \return This function returns a int vector called allocatedSeats
     */
    vector<int> getAllocatedSeats();

    /**
     * @brief This function sets the seats that were allocated by taking in the index and the amount of seats 
     * 
     * @param idx This is an int that is an index for where the seat will be set in the allocatedSeats vector
     * @param seat This is an int that represents the amount of seats that are allocated 
     * @return none
     */
    void setAllocatedSeats(int idx, int seat);

};

#endif /* PARTY_H */
