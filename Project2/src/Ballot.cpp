#include "Ballot.h"

int Ballot::getVotes() {
    return vote;
}

void Ballot::setVotes(int votes) {
    vote = votes;
}

void Ballot::incrementVotes(){
    vote = vote + 1;
}