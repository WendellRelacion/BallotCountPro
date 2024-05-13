#include "Party.h"

std::string Party::getPartyName() const{
    return partyName;
}

void Party::setPartyName(std::string name) {
    partyName = name;
}

std::vector<Candidate> Party::getCandidates() {
    return candidateNames;
}


void Party::addCandidate(Candidate candidate){
    candidateNames.push_back(candidate);
}

Ballot Party::getBallot(){
    return ballot;
}

void Party::setBallot(Ballot newBallot){
    ballot = newBallot;
}

Ballot Party::getRemainder(){
    return remainder;
}

void Party::setRemainder(Ballot newBallot){
    remainder = newBallot;
}

vector<int> Party::getAllocatedSeats(){
    return allocatedSeats;
}


void Party::setAllocatedSeats(int idx, int seat){
    if(idx == 0){
        allocatedSeats[0] = seat;
    }
    else{
        allocatedSeats[1] = 1;
    }
    return;
}