#include "CandidateOPL.h"

int CandidateOPL::getRankingCandidates() {
    return rankingCandidates;
}

void CandidateOPL::setRankingCandidates(int rankingCandidates) {
    this->rankingCandidates = rankingCandidates;
}


Ballot CandidateOPL::getBallot(){
    return ballot;
}

void CandidateOPL::setBallot(Ballot newBallot){
    ballot = newBallot;
}
