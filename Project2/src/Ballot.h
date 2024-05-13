/*****************************************************************//**
 * \file   Ballot.h
 * \brief 
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/

#ifndef BALLOT_H
#define BALLOT_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @class Ballot
 * @brief This is a class that defines the functionalities for the Ballot class 
 * 
 */
class Ballot {
private:
    int vote;

public:
    /**
    * \brief This function gets the vote for the Ballot object
    * 
    * \param None
    * \return Returns an integer representing the number of votes
    */
    int getVotes();

    /**
    * \brief This function sets the vote for the Ballot object
    * 
    * \param votes An integer representing the number of votes
    * \return none
    */
    void setVotes(int votes);
    
    /**
    * \brief This function adds 1 to the current vote value
    * 
    * \param None
    * \return none
    */
    void incrementVotes();
};

#endif /* BALLOT_H */
