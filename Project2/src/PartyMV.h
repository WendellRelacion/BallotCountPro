/*****************************************************************//**
 * \file   PartyMV.h
 * \brief 
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/

#ifndef PARTY_MV_H
#define PARTY_MV_H

#include "Party.h"
#include "CandidateMV.h"
#include <map>

/**
 * @class MVParty
 * @brief This is a class that defines the functionalities for the MVParty object
 * 
 */
class MVParty : public Party {
private:
    std::map<std::string, int> votesForCandidate;
    std::vector<CandidateMV> candidateRanking;
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
     * @param newCandidate CandidateMV object 
     * @return none 
     */
    void setCandidateRankings(CandidateMV newCandidate);

    /**
     * @brief Get the rankings for the candidates
     * 
     * @return A vector of type CandidateMV
     */
    std::vector<CandidateMV> getRankings();

    /**
     * @brief Adds a new MV candiate object
     * 
     * @param candidate CandidateMV object to be added
     */
    void addMVCandidate(CandidateMV candidate);
};

#endif /* PARTY_MV_H */
