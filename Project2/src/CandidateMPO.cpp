#include "CandidateMPO.h"

int CandidateMPO::getRankingCandidates() {
    return rankingCandidates;
}

void CandidateMPO::setRankingCandidates(int rankingCandidates) {
    this->rankingCandidates = rankingCandidates;
}


Ballot CandidateMPO::getBallot(){
    return ballot;
}

void CandidateMPO::setBallot(Ballot newBallot){
    ballot = newBallot;
}
