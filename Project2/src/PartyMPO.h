/*****************************************************************//**
 * \file   PartyMPO.h
 * \brief 
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/

#ifndef PARTY_MPO_H
#define PARTY_MPO_H

#include "Party.h"
#include "CandidateMPO.h"
#include <map>

/**
 * @class MPOParty
 * @brief This is a class that defines the functionalities for the MPOParty object
 * 
 */
class MPOParty : public Party {
private:
    std::map<std::string, int> votesForCandidate;
    std::vector<CandidateMPO> candidateRanking;
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
     * @param newCandidate CandidateMPO object 
     * @return none 
     */
    void setCandidateRankings(CandidateMPO newCandidate);

    /**
     * @brief Get the rankings for the candidates
     * 
     * @return A vector of type CandidateMPO
     */
    std::vector<CandidateMPO> getRankings();

    /**
     * @brief Adds a new MPO candiate object
     * 
     * @param candidate CandidateMPO object to be added
     */
    void addMPOCandidate(CandidateMPO candidate);
};

#endif /* PARTY_MPO_H */
