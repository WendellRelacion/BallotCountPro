#include "Candidate.h"
#include "Party.h"
#include <iostream>

using namespace std;

string Candidate::getCandidateName() const {
    return name;
}

void Candidate::setCandidateName(string name) {
    this->name = name;
}

Party* Candidate::getParty() {
    return party;
}

void Candidate::setParty(Party* party) {
    this->party = party;
}

std::string Candidate::getPartyName(){
    return PartyName;
}

void  Candidate::setPartyName(std::string Name){
    PartyName = Name;
}