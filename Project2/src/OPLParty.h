/*****************************************************************//**
 * \file   OPLParty.h
 * \brief 
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/

#ifndef OPL_PARTY_H
#define OPL_PARTY_H

#include "Party.h"
#include "CandidateOPL.h"
#include <map>

/**
 * @class OPLParty
 * @brief This is a class that defines the functionalities for the OPLParty object
 * 
 */
class OPLParty : public Party {
private:
    std::map<std::string, int> votesForCandidate;
    std::vector<CandidateOPL> candidateRanking;
public:

     /**
    * @brief Get the number of votes for a candidate
    * 
    * @param candidateName String representing the name of the candidate
    * @return Returns an integer representing the number of votes a candidate has
    */
    int getCandidateVote(std::string candidateName);

    /**
     * @brief Sets the number of votes for a candidate
     * 
     * @param candidateName String representing the name of a candidate
     * @param votes An integer representing the number of votes a candidate has
     * @return none 
     */
    void setCandidateVote(std::string candidateName, int votes);

    /**
     * @brief Sets the rankings for the candidate
     * 
     * @param newCandidate CandidateOPL object 
     * @return none 
     */
    void setCandidateRankings(CandidateOPL newCandidate);

    /**
     * @brief Get the rankings for the candidates
     * 
     * @return A vector of type CandidateOPL
     */
    std::vector<CandidateOPL> getRankings();

    /**
     * @brief Adds a new OPL candiate object
     * 
     * @param candidate CandidateOPL object to be added
     */
    void addOPLCandidate(CandidateOPL candidate);
};

#endif /* OPL_PARTY_H */
