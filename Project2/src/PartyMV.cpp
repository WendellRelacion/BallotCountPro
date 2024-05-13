#include "PartyMV.h"
#include <cstdlib>

int MVParty::getCandidateVote(std::string candidateName) {
    return votesForCandidate[candidateName];
}

void MVParty::setCandidateVote(std::string candidateName, int votes) {
    votesForCandidate[candidateName] = votes;
}

void MVParty::setCandidateRankings(CandidateMV newCandidate) {
    if(candidateRanking.size() == 0){
        candidateRanking.push_back(newCandidate);
    }
    else{
        bool inserted = false;
        for (size_t i = 0; i < candidateRanking.size(); ++i) {
            if (newCandidate.getBallot().getVotes() > candidateRanking[i].getBallot().getVotes()) {
                candidateRanking.insert(candidateRanking.begin() + i, newCandidate);
                inserted = true;
                break;
            }
            else if (newCandidate.getBallot().getVotes() == candidateRanking[i].getBallot().getVotes()) {
                //random num gen
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(1, INT32_MAX); // Generate numbers between 1 and 100
                int randNumBig = dis(gen);
                int randomNum = randNumBig  % 2; // Generate 0 or 1
                if (randomNum == 1) { // Randomly choose to insert newCandidate
                    candidateRanking.insert(candidateRanking.begin() + i, newCandidate);
                    inserted = true;
                    break;
                }
            }
        }
        if (!inserted) {
            // If not inserted in any position (lowest votes), add it at the end
            candidateRanking.push_back(newCandidate);
        }
    }
}

std::vector<CandidateMV> MVParty::getRankings() {
    return candidateRanking;
}

void MVParty::addMVCandidate(CandidateMV candidate){
    bool candidateExists = false;
    for (const auto& cand : candidateNames) {
        if (cand.getCandidateName() == candidate.getCandidateName()) {
            candidateExists = true;
            break;
        }
    }

    // If the candidate doesn't exist, add it to the vector
    if (!candidateExists) {
        candidateNames.push_back(candidate);
    }
}



