/*****************************************************************//**
 * \file   Candidate.h
 * \brief This is a header file for the Candidate class, it defines the variables and methods 
 *        which will be defined in Candidate.cpp
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/

#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include "Party.h" // Assuming Party class is declared in "party.h"

/**
 * @class Party
 * @brief 
 * 
 */
class Party; // Forward declaration

/**
 * @class Candidate
 * @brief This is a class that defines the functionalities for the candidate object
 * 
 */
class Candidate {
protected:
    std::string name;
    Party* party;
    std::string PartyName;

public:
    /**
     * \brief This function gets the Candidate name by returning name of the type string
     * 
     * \param None This function does not take in any parameters
     * \return This function returns a string
     */
    std::string getCandidateName() const;

    /**
    * \brief This function sets the Candidate name 
    * 
    * \param name This function passes in a string name for it to be set for a specific Candidate
    * \return This function does not return anything
    */
    void setCandidateName(std::string name);

    /**
    * \brief This function gets a Party object for the specific Candidate 
    * 
    * \param None This function does not take in any parameters
    * \return This function returns a party object
    */
    Party* getParty();

    /**
    * \brief This function passes in a party object and sets it for said candidate
    * 
    * \param party This function takes in a party object pointer
    * \return none
    */
    void setParty(Party* party);

    /**
    * \brief This function 
    * 
    * \param None This function does not take in any parameters
    * \return This function returns a string
    */
    std::string getPartyName();

    /**
    * \brief This function gets the Candidate name by returning name of the type string
    * 
    * \param PartyName This function does not take in any parameters
    * \return This function returns a string
    */
    void setPartyName(std::string PartyName);
};

#endif /* CANDIDATE_H */
