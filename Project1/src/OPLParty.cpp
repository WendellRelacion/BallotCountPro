#include "OPLParty.h"
#include <cstdlib>

int OPLParty::getCandidateVote(std::string candidateName) {
    return votesForCandidate[candidateName];
}

void OPLParty::setCandidateVote(std::string candidateName, int votes) {
    votesForCandidate[candidateName] = votes;
}

void OPLParty::setCandidateRankings(CandidateOPL newCandidate) {
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

std::vector<CandidateOPL> OPLParty::getRankings() {
    return candidateRanking;
}

void OPLParty::addOPLCandidate(CandidateOPL candidate){
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





// class OPL_Party : public Party {
// private:
//     map<string, int> votesForCandidate;

// public:
//     int getCandidateVote(string candidateName) { return votesForCandidate[candidateName]; }
//     void setCandidateVote(string candidateName, int votes) { votesForCandidate[candidateName] = votes; }
//     void sortCandidateDict(map<string, int>& votesForCandidate) {
//         // sort the map by value
//     }
//     void setCandidateRankings() {
//         sortCandidateDict(votesForCandidate);
//         int ranking = 1;
//         for (auto& candidate : candidateNames) {
//             CandidateOPL* cand = dynamic_cast<CandidateOPL*>(candidate);
//             cand->setRankingCandidates(ranking++);
//         }
//     }
// };