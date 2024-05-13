#include "CandidateMV.h"

int CandidateMV::getRankingCandidates() {
    return rankingCandidates;
}

void CandidateMV::setRankingCandidates(int rankingCandidates) {
    this->rankingCandidates = rankingCandidates;
}


Ballot CandidateMV::getBallot(){
    return ballot;
}

void CandidateMV::setBallot(Ballot newBallot){
    ballot = newBallot;
}
