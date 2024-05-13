/*****************************************************************//**
 * \file   CandidateMPO.h
 * \brief 
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/
#ifndef CANDIDATEMPO_H
#define CANDIDATEMPO_H

#include "Candidate.h"
#include "Ballot.h"

/**
 * @brief CandidateMPO
 * 
 */
class CandidateMPO : public Candidate {
private:
    int rankingCandidates;
    Ballot ballot;

public:
    /**
     * \brief This function returns int rankingCandidates which is the rank for the Candidate
     * 
     * \param None This function does not take in any parameters
     * \return This function returns an integer
     */
    int getRankingCandidates();

    /**
     * \brief This function sets the ranking Candidate in the MPO election
     * 
     * \param rankingCandidates This function takes in the rankingCandidates integer
     * \return This function does not return any values
     */
    void setRankingCandidates(int rankingCandidates);

    /**
     * \brief This function returns a Ballot object for a specifc Candidate in the MPO election
     * 
     * \param None This function does not take in any parameters
     * \return This function returns a Ballot object
     */
    Ballot getBallot();

    /**
     * \brief This function sets the Ballot for a specific Candidate in the MPO election
     * 
     * \param ballot This function takes in a ballot object
     * \return This function does not return any values
     */
    void setBallot(Ballot ballot);
};


#endif /* CANDIDATEMPO_H */
