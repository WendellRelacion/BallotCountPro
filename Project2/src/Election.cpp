#include "Election.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random> 

using namespace std;

void Election::sortCandidateVotes(std::vector<OPLParty>& OPLParties, std::vector<CandidateOPL>&  OPLCandidates, std::vector<Ballot>& candidateBallots) {
    //set each candidate's ballots
    for(int i = 0; i < OPLCandidates.size(); i++){
        OPLCandidates[i].setBallot(candidateBallots[i]);
    }

    //set candidate rankings simply puts the candidate into order of
    //most ballots to least in their respective party
    for (int i = 0; i < OPLCandidates.size(); i++) {
        for (int j = 0; j < OPLParties.size(); j++) {
            if ((OPLCandidates[i].getPartyName() == OPLParties[j].getPartyName())) {
                OPLParties[j].setCandidateRankings(OPLCandidates[i]);
            }
        }
    }
}

void Election::largest_remainder_seat_allocation(std::vector<Party>& parties, std::vector<Ballot>& partyBallots, int total_seats, int totalBallots, std::vector<Seat>& seats){
    for (int i = 0; i < parties.size(); i++){
        parties[i].setBallot(partyBallots[i]);
    }

    int quota = totalBallots / total_seats;
    int remaining_seats = total_seats;
    vector<int> seats_allocated;

    // Allocate seats based on whole number of quotas
    // first round of allocation
    for (int i = 0; i < parties.size(); ++i) {
        seats[i].setSeats(parties[i].getBallot().getVotes() / quota);
        parties[i].setAllocatedSeats(0, (parties[i].getBallot().getVotes() / quota));
        remaining_seats -= seats[i].getSeats();
        //give partyBallotsRemaining seats
        int partyRemainder = parties[i].getBallot().getVotes() - (seats[i].getSeats() * quota);
        Ballot remainderBallot;
        remainderBallot.setVotes(partyRemainder);
        parties[i].setRemainder(remainderBallot);

    }

    vector<Party> partyRanking;
    partyRanking.push_back(parties[0]);
   
    //second round of allocation
    bool hasTie = false;
    for (int j = 0; j < parties.size(); j++){
        bool inserted = false;
        for (int i = 0; i < partyRanking.size(); i++){
            //set i to index of tied element
            if (parties[j].getPartyName() != partyRanking[i].getPartyName()){
                if (parties[j].getRemainder().getVotes() > partyRanking[i].getRemainder().getVotes()) {
                    partyRanking.insert(partyRanking.begin() + i, parties[j]);
                    inserted = true;
                    break;
                }
                else if (parties[j].getRemainder().getVotes() == partyRanking[i].getRemainder().getVotes()) {
                    //random num gen
                    std::random_device rd;
                    std::mt19937 gen(rd()); //supposedly pseudorandom
                    std::uniform_int_distribution<> dis(1, INT32_MAX); // Generate numbers between 1 and int max
                    int randNumBig = dis(gen);
                    int randomNum = randNumBig  % 2; // Generate 0 or 1
                    if (randomNum == 1) { // Randomly choose to insert newCandidate
                        partyRanking.insert(partyRanking.begin() + i, parties[j]);
                        inserted = true;
                        break;
                    }
                }
            }
        }
        if (!inserted) {
            // If not inserted in any position (lowest votes), add it at the end
            partyRanking.push_back(parties[j]);
        }
    }

    //adds the remaining seats
    for(int i = 0; i < remaining_seats; i++){
        for(int j = 0; j < parties.size(); j++){
            if (partyRanking[i].getPartyName() == parties[j].getPartyName()){
                seats[j].incSeats();
                parties[j].setAllocatedSeats(1, 1);
            }
        }
    } 
}

void Election::largest_remainder_seat_allocation(std::vector<OPLParty>& parties, std::vector<Ballot>& partyBallots, int total_seats, int totalBallots, std::vector<Seat>& seats) {
    for (int i = 0; i < parties.size(); i++){
        parties[i].setBallot(partyBallots[i]);
    }

    cout << totalBallots << total_seats << endl;
    
    int quota = totalBallots / total_seats;

    cout << quota << endl;
    int remaining_seats = total_seats;
    vector<int> seats_allocated;
    // Allocate seats based on whole number of quotas
    // first round of allocation
    for (int i = 0; i < parties.size(); ++i) {
        seats[i].setSeats(parties[i].getBallot().getVotes() / quota);
        parties[i].setAllocatedSeats(0, (parties[i].getBallot().getVotes() / quota));
        remaining_seats -= seats[i].getSeats();

        // give partyBallotsRemaining seats for later calculation
        int partyRemainder = parties[i].getBallot().getVotes() - (seats[i].getSeats() * quota);
        Ballot remainderBallot;
        remainderBallot.setVotes(partyRemainder);
        parties[i].setRemainder(remainderBallot);
        
    }

    vector<OPLParty> partyRanking;
    partyRanking.push_back(parties[0]);

    //start of second round of allocation
    bool hasTie = false;
    for (int j = 0; j < parties.size(); j++){
        bool inserted = false;
        for (int i = 0; i < partyRanking.size(); i++){
            //set i to index of tied elementF
            if (parties[j].getPartyName() != partyRanking[i].getPartyName()){
                if (parties[j].getRemainder().getVotes() > partyRanking[i].getRemainder().getVotes()) {
                    partyRanking.insert(partyRanking.begin() + i, parties[j]);
                    inserted = true;
                    break;
                }
                else if (parties[j].getRemainder().getVotes() == partyRanking[i].getRemainder().getVotes()) {
                    //random num gen
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dis(1, INT32_MAX); // Generate numbers between 1 and int max
                    int randNumBig = dis(gen);
                    int randomNum = randNumBig  % 2; // Generate 0 or 1
                    if (randomNum == 1) { // Randomly choose to insert newCandidate
                        partyRanking.insert(partyRanking.begin() + i, parties[j]);
                        inserted = true;
                        break;
                    }
                }
            }
        }
        if (!inserted) {
            // If not inserted in any position (lowest votes), add it at the end
            partyRanking.push_back(parties[j]);
        }
    }
    //add remaining seats
    for(int i = 0; i < remaining_seats; i++){
        for(int j = 0; j < parties.size(); j++){
            if (partyRanking[i].getPartyName() == parties[j].getPartyName()){
                seats[j].incSeats();
                parties[j].setAllocatedSeats(1, 1);
            }
        }
    }
}


void Election::largest_remainder_seat_allocation(std::vector<CandidateMPO>& MPOCandidates, std::vector<Ballot>& candidateBallots, int total_seats, int totalBallots, std::vector<Seat>& seats){
    //do something
    cout << "AYE THIS DOES SOMETHING!!!" << endl;
    
    for (int i = 0; i < MPOCandidates.size(); i++){
        MPOCandidates[i].setBallot(candidateBallots[i]);

        // checks ballots working

    }

    cout << totalBallots << " - " << total_seats << endl;
    
    int quota = totalBallots / total_seats;

    cout << quota << endl;

    vector<CandidateMPO> candidateRanking;
    candidateRanking.push_back(MPOCandidates[0]);
    cout << candidateRanking[0].getCandidateName() << endl;

    bool hasTie = false;

    for (int j = 0; j < MPOCandidates.size(); j++){
        bool inserted = false;
        for (int i = 0; i < candidateRanking.size(); i++){
            //set i to index of tied elementF
            if (MPOCandidates[j].getCandidateName() != candidateRanking[i].getCandidateName()){
                if (MPOCandidates[j].getBallot().getVotes() > candidateRanking[i].getBallot().getVotes()) {
                    candidateRanking.insert(candidateRanking.begin() + i, MPOCandidates[j]);
                    inserted = true;
                    break;
                }
                else if (MPOCandidates[j].getBallot().getVotes() == candidateRanking[i].getBallot().getVotes()) {
                    //random num gen
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dis(1, INT32_MAX); // Generate numbers between 1 and int max
                    int randNumBig = dis(gen);
                    int randomNum = randNumBig  % 2; // Generate 0 or 1
                    if (randomNum == 1) { // Randomly choose to insert newCandidate
                        candidateRanking.insert(candidateRanking.begin() + i, MPOCandidates[j]);
                        inserted = true;
                        break;
                    }
                }
            }
        }
        if (!inserted) {
            // If not inserted in any position (lowest votes), add it at the end
            if(candidateRanking.at(candidateRanking.size()-1).getCandidateName() != MPOCandidates[j].getCandidateName()){
                candidateRanking.push_back(MPOCandidates[j]);
                cout << "candidate" << MPOCandidates[j].getCandidateName() << endl;
            }
            
        }
   
    }

    for(int i = 0; i < candidateRanking.size(); i++){
        cout << candidateRanking[i].getCandidateName() << " - " << candidateRanking[i].getBallot().getVotes() << endl;
    }

    cout << endl;
    for(int i = 0; i < candidateRanking.size(); i++){
        cout << MPOCandidates[i].getCandidateName()  << " - " << MPOCandidates[i].getBallot().getVotes() << endl;
    }

    cout << "total seats: " << total_seats << endl;
    for(int i = 0; i < total_seats; i++){
        for(int j = 0; j < MPOCandidates.size(); j++){
            if (candidateRanking[i].getCandidateName() == MPOCandidates[j].getCandidateName()){
                seats[j].incSeats();
                // cout << ":ldsfa" << seats[j].getSeats() << endl;
            }
        }
    }

    for(int i = 0; i < seats.size(); i++){
        cout << "Candidate: "  << MPOCandidates[i].getCandidateName() << " Seat Gathered" << ": " << seats[i].getSeats() << endl;
    }
    //no need for 2 rounds of seating, give it to howmever has the most (should be pretty simple. Hopefully...)
    return;
}

void Election::largest_remainder_seat_allocation(std::vector<CandidateMV>& MVCandidates, std::vector<Ballot>& candidateBallots, int total_seats, int totalBallots, std::vector<Seat>& seats){
    for (int i = 0; i < MVCandidates.size(); i++){
        MVCandidates[i].setBallot(candidateBallots[i]);
        // checks ballots working
    }

    cout << totalBallots << " - " << total_seats << endl;
    
    int quota = totalBallots / total_seats;

    cout << quota << endl;

    vector<CandidateMV> candidateRanking;
    candidateRanking.push_back(MVCandidates[0]);
    cout << candidateRanking[0].getCandidateName() << endl;

    bool hasTie = false;

    for (int j = 0; j < MVCandidates.size(); j++){
        bool inserted = false;
        for (int i = 0; i < candidateRanking.size(); i++){
            //set i to index of tied elementF
            if (MVCandidates[j].getCandidateName() != candidateRanking[i].getCandidateName()){
                if (MVCandidates[j].getBallot().getVotes() > candidateRanking[i].getBallot().getVotes()) {
                    candidateRanking.insert(candidateRanking.begin() + i, MVCandidates[j]);
                    inserted = true;
                    break;
                }
                else if (MVCandidates[j].getBallot().getVotes() == candidateRanking[i].getBallot().getVotes()) {
                    //random num gen
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dis(1, INT32_MAX); // Generate numbers between 1 and int max
                    int randNumBig = dis(gen);
                    int randomNum = randNumBig  % 2; // Generate 0 or 1
                    if (randomNum == 1) { // Randomly choose to insert newCandidate
                        candidateRanking.insert(candidateRanking.begin() + i, MVCandidates[j]);
                        inserted = true;
                        break;
                    }
                }
            }
        }
        if (!inserted) {
            // If not inserted in any position (lowest votes), add it at the end
            if(candidateRanking.at(candidateRanking.size()-1).getCandidateName() != MVCandidates[j].getCandidateName()){
                candidateRanking.push_back(MVCandidates[j]);
                cout << "candidate" << MVCandidates[j].getCandidateName() << endl;
            }
            
        }
   
    }

    for(int i = 0; i < candidateRanking.size(); i++){
        cout << candidateRanking[i].getCandidateName() << " - " << candidateRanking[i].getBallot().getVotes() << endl;
    }

    cout << endl;
    for(int i = 0; i < candidateRanking.size(); i++){
        cout << MVCandidates[i].getCandidateName()  << " - " << MVCandidates[i].getBallot().getVotes() << endl;
    }
    cout << "total seats: " << total_seats << endl;
    for(int i = 0; i < total_seats; i++){
        for(int j = 0; j < MVCandidates.size(); j++){

            cout << (candidateRanking[i].getCandidateName() == MVCandidates[j].getCandidateName()) << endl;
            if (candidateRanking[i].getCandidateName() == MVCandidates[j].getCandidateName()){
                cout << "goes in here hopefhfeol sicze - " << seats.size() << endl;
                seats[j].incSeats();
                // cout << ":ldsfa" << seats[j].getSeats() << endl;
            }
        }
    }

    for(int i = 0; i < seats.size(); i++){
        cout << "Candidate: "  << MVCandidates[i].getCandidateName() << " Seat Gathered" << ": " << seats[i].getSeats() << endl;
    }
    //no need for 2 rounds of seating, give it to howmever has the most (should be pretty simple. Hopefully...)
    return;
}

int Election::runMPO(std::ifstream& file){
    file >> numSeats >> numCandidatesOrParties;
    
    //grabs empty line
    string line;
    getline(file, line);
    
    cout << numSeats << endl;
    cout << numCandidatesOrParties << endl;
    
    //grabs empty line
    getline(file, line);
    stringstream ss(line);
    string candidateName;
    int o = 0;
    int candOrPart = 0;

    //start stoarage of candidates and Parties.
    while (getline(ss, candidateName, ',')) {
        // Remove leading and trailing spaces and brackets
        //candidate initialization
        candidateName.erase(0, candidateName.find_first_not_of(" ["));
        CandidateMPO candidate;
        candidate.setCandidateName(candidateName);
        // cout << candidate.getCandidateName() << endl;

        // Party initialization;
        string partyName;
        getline(ss, partyName, ',');
        partyName = partyName.substr(1);
        partyName.erase(partyName.find_last_not_of(" ]") + 1);
        // cout << partyName << endl;
        MPOParty party;
        party.setPartyName(partyName);
        // cout << party.getPartyName() << endl;

        candidate.setParty(&party);
        candidate.setPartyName(party.getPartyName());
        MPOCandidates.push_back(candidate);

        if (o == 0) {
            //since party candidate arry is empty, add
            party.addMPOCandidate(candidate);
            MPOParties.push_back(party);
            o++;
        } else {
            // o++;
            // Check if party name already exists in parties if so, do not add need to keep party array uniquewba
            for (int k = 0; k < MPOParties.size(); k++) {
                bool partyExists = false;
                for (int j = 0; j < MPOParties.size(); j++) {
                    if ((party.getPartyName() == MPOParties[j].getPartyName()) && !partyExists) {
                        // cout << "exists" << endl;
                        MPOParties[j].addMPOCandidate(candidate);
                        partyExists = true;
                    }
                }
                if (!partyExists) {
                    // cout << "existssdfdsf" << endl;
                    MPOParties.push_back(party);
                }
            }
        }
    }


    //checks for parties in 
    for (int i = 0; i < MPOParties.size(); i++){
        cout << "here: " << MPOParties.at(i).getPartyName() << endl;
    }

    //adds each parties' candidates to a 2d candidates vector [[PartyCanidates1][partycandidates2][ETC]]
    for (size_t i = 0; i < MPOParties.size(); ++i) {
        candidates.push_back(MPOParties[i].getCandidates());
        vector<Candidate> testRun;
        testRun = MPOParties[i].getCandidates();
    }

    //creates new ballots for each party
    for (int i = 0; i <  MPOParties.size(); ++i) {
        Ballot newBallot;
        newBallot.setVotes(0);
        partyBallots.push_back(newBallot);
    }

    // Ballots for each candidate for easier calculation
    for (int i = 0; i < MPOCandidates.size(); ++i) {
        Ballot newBallot;
        newBallot.setVotes(0);
        candidateBallots.push_back(newBallot);
    }

    getline(file, line);
    numBallots = std::stoi(line);

    int amntFiles = vectorFileNames.size();

    // store everything // not working rn
    for (int l = 0; l < amntFiles; l++){
        //Read and process ballots
        if (0 == l){
            megaTotalBallots += numBallots;
            cout << "first megaBallots: " << megaTotalBallots << endl;
            for (int i = 0; i < numBallots; ++i) {
                string line;
                getline(file, line);

                // Check if the line is not empty
                if (!line.empty()) {
                    // Iterate through each character in the line to find index of ballot
                    for (int j = 0; j < numCandidatesOrParties; ++j) {
                        // Check if the character is '1' and 
                        if (line[j] == '1') {
                            // Increment the votes for the corresponding candidate
                            candidateBallots[j].incrementVotes();
                            //check what index party name is in OPLParties
                            //once there,increment OPLParty ballots in thatspecific index
                            string partyName =  MPOCandidates[j].getPartyName();
                            for (size_t k = 0; k < MPOParties.size(); ++k) {
                                if (MPOParties[k].getPartyName() == partyName) {
                                    // Increment the ballots for the party
                                    partyBallots[k].incrementVotes();
                                    break; // No need to continue searching
                                }
                            }
                        }
                    }
                }
            }


        file.close();
        }
        else{

            ifstream file(vectorFileNames.at(l)); 
            if (!file.is_open()) {
                std::cerr << "Failed to open the file." << std::endl;
                return 1;
            }
            getline(file, header);
            file >> numSeats >> numCandidatesOrParties;

            //bug
                //Grabs and clears empty string. for some reason the getline command grabs nothing
            string line;
            getline(file, line);

            //grabs the whole thing with parties and allies
            getline(file, line);

            getline(file, line);
            numBallots = std::stoi(line);
            cout << "mult file numballots " << numBallots << endl;
            megaTotalBallots += numBallots;
            cout << megaTotalBallots << endl;


            for (int i = 0; i < numBallots; ++i) {
                string line;
                getline(file, line);

                // Check if the line is not empty
                if (!line.empty()) {
                    // Iterate through each character in the line to find index of ballot
                    for (int j = 0; j < numCandidatesOrParties; ++j) {
                        // Check if the character is '1' and 
                        if (line[j] == '1') {
                            // Increment the votes for the corresponding candidate
                            candidateBallots[j].incrementVotes();
                            //check what index party name is in OPLParties
                            //once there,increment OPLParty ballots in thatspecific index
                            string partyName =  MPOCandidates[j].getPartyName();
                            for (size_t k = 0; k < MPOParties.size(); ++k) {
                                if (MPOParties[k].getPartyName() == partyName) {
                                    // Increment the ballots for the party
                                    partyBallots[k].incrementVotes();
                                    break; // No need to continue searching
                                }
                            }
                        }
                    }
                }
            }
        file.close();
        }
    }
    cout << "candidate size" << MPOCandidates.size() << endl;


    for (int i = 0; i < MPOCandidates.size(); i++){
        Seat newSeat;
        seats.push_back(newSeat);
    }

    for (int i = 0; i < MPOCandidates.size(); i++){
        cout << "Candidates: " << MPOCandidates[i].getPartyName() << endl;
    }

    largest_remainder_seat_allocation(MPOCandidates, candidateBallots, numSeats, megaTotalBallots, seats);

    return 0;
}

int Election::runOPL(std::ifstream& file){
    file >> numSeats >> numBallots >> numCandidatesOrParties;
    megaTotalBallots += numBallots;
    //bug
    //Grabs and clears empty string. for some reason the getline command grabs nothing
    string line;
    getline(file, line);

    //vector<Candidate> partyCandidates;
    for (int i = 0; i < numCandidatesOrParties; ++i) {

        //grab Party name and create object to add to vector
        getline(file, line);
        string partyName = line.substr(0, line.find(','));
        OPLParty party; 
        party.setPartyName(partyName);
        size_t pos = line.find(',');

        //finds candidate after party name
        while (pos != std::string::npos) {
            size_t nextPos = line.find(',', pos + 1);
            string candidateName = line.substr(pos + 2, nextPos - pos - 2);
            CandidateOPL candidate;
            //set candidate attributes
            candidate.setCandidateName(candidateName);
            candidate.setParty(&party);
            candidate.setPartyName(party.getPartyName());
            OPLCandidates.push_back(candidate);

            pos = nextPos;
            if (i == 0) {
                //since party candidate arry is empty, add
                party.addOPLCandidate(candidate);
                OPLParties.push_back(party);
            } else {
                // Check if party name already exists in parties if so, do not add need to keep party array uniquewba
                for (int k = 0; k < OPLParties.size(); k++) {
                    bool partyExists = false;
                    for (int j = 0; j < OPLParties.size(); j++) {
                        if ((party.getPartyName() == OPLParties[j].getPartyName()) && !partyExists) {
                            OPLParties[j].addOPLCandidate(candidate);
                            partyExists = true;
                        }
                    }
                    if (!partyExists) {
                        OPLParties.push_back(party);
                    }
                }
            }
        }
    }   

    //adds each parties' candidates to a 2d candidates vector [[PartyCanidates1][partycandidates2][ETC]]
    for (size_t i = 0; i < OPLParties.size(); ++i) {
        candidates.push_back(OPLParties[i].getCandidates());
        vector<Candidate> testRun;
        testRun = OPLParties[i].getCandidates();
    }

    //creates new ballots for each party
    for (int i = 0; i < OPLParties.size(); ++i) {
        Ballot newBallot;
        newBallot.setVotes(0);
        partyBallots.push_back(newBallot);
    }
    // Ballots for each candidate for easier calculation
    for (int i = 0; i < OPLCandidates.size(); ++i) {
        Ballot newBallot;
        newBallot.setVotes(0);
        candidateBallots.push_back(newBallot);
    }
    // cout << "here" << endl;
    int amntFiles = vectorFileNames.size();
    
    
    for (int l = 0; l < amntFiles; l++){
        //Read and process ballots
        if (0 == l){
            
            for (int i = 0; i < numBallots; ++i) {
                string line;
                getline(file, line);

                // Check if the line is not empty
                if (!line.empty()) {
                    // Iterate through each character in the line to find index of ballot
                    for (int j = 0; j < numCandidatesOrParties; ++j) {
                        // Check if the character is '1' and 
                        if (line[j] == '1') {
                            // Increment the votes for the corresponding candidate
                            candidateBallots[j].incrementVotes();
                            //check what index party name is in OPLParties
                            //once there,increment OPLParty ballots in thatspecific index
                            string partyName =  OPLCandidates[j].getPartyName();
                            for (size_t k = 0; k < OPLParties.size(); ++k) {
                                if (OPLParties[k].getPartyName() == partyName) {
                                    // Increment the ballots for the party
                                    partyBallots[k].incrementVotes();
                                    break; // No need to continue searching
                                }
                            }
                        }
                    }
                }
            }
        file.close();
        }

        else{

            ifstream file(vectorFileNames.at(l)); 
            if (!file.is_open()) {
                std::cerr << "Failed to open the file." << std::endl;
                return 1;
            }
            getline(file, header);
            file >> numSeats >> numBallots >> numCandidatesOrParties;
            megaTotalBallots += numBallots;
            //Grabs and clears empty string. for some reason the getline command grabs nothing
            string line;
            getline(file, line);
            
            
            for (int i = 0; i < numCandidatesOrParties; ++i){
                getline(file, line);
            }


            for (int i = 0; i < numBallots; ++i) {
                string line;
                getline(file, line);

                // Check if the line is not empty
                if (!line.empty()) {
                    // Iterate through each character in the line to find index of ballot
                    for (int j = 0; j < numCandidatesOrParties; ++j) {
                        // Check if the character is '1' and 
                        if (line[j] == '1') {
                            // Increment the votes for the corresponding candidate
                            candidateBallots[j].incrementVotes();
                            //check what index party name is in OPLParties
                            //once there,increment OPLParty ballots in thatspecific index
                            string partyName =  OPLCandidates[j].getPartyName();
                            for (size_t k = 0; k < OPLParties.size(); ++k) {
                                if (OPLParties[k].getPartyName() == partyName) {
                                    // Increment the ballots for the party
                                    partyBallots[k].incrementVotes();
                                    break; // No need to continue searching
                                }
                            }
                        }
                    }
                }
            }
        file.close();
        }
    }
    


    sortCandidateVotes(OPLParties, OPLCandidates, candidateBallots);
    for (int i = 0; i < OPLParties.size(); i++){
        Seat newSeat;
        seats.push_back(newSeat);
    }

    cout << "NumSeats " << numSeats << endl;
    largest_remainder_seat_allocation(OPLParties, partyBallots, numSeats, numBallots, seats);
    
    output(OPLParties, seats);

    file.close(); 
    return 0;

}

int Election::runCPL(std::ifstream& file){
    file >> numSeats >> numBallots >> numCandidatesOrParties;
    string line;
    megaTotalBallots += numBallots;
    //read party names and candidates
    //inital number line is empty (could be a problem later)
    getline(file, line);
    for (int i = 0; i < numCandidatesOrParties; ++i) {
        getline(file, line);
        vector<Candidate> partyCandidates;
        Candidate currCandidate;

        // return count; //possibly delete as well
        //grabs party name
        size_t pos = line.find(',');
        string partyName = line.substr(0, pos); 
        Party party;
        party.setPartyName(partyName);
        parties.push_back(party);   
        
        size_t lastPos = pos + 1;
        while ((pos = line.find(',', lastPos)) != std::string::npos) {
            std::string candidate = line.substr(lastPos, pos - lastPos);
            // Remove leading and trailing spaces
            candidate.erase(0, candidate.find_first_not_of(' '));
            candidate.erase(candidate.find_last_not_of(' ') + 1);
            // Skip empty names
            currCandidate.setParty(&party);
            currCandidate.setCandidateName(candidate);
            if (!candidate.empty()) {
                partyCandidates.push_back(currCandidate);
            }
            lastPos = pos + 1;
        }
        // Process the last candidate (no comma after)
        std::string lastCandidate = line.substr(lastPos);
        lastCandidate.erase(0, lastCandidate.find_first_not_of(' '));
        lastCandidate.erase(lastCandidate.find_last_not_of(' ') + 1);

        currCandidate.setCandidateName(lastCandidate);
        if (!lastCandidate.empty()) {
            partyCandidates.push_back(currCandidate);
        }
        candidates.push_back(partyCandidates);
    
    }
    //make ballots
    for (int i = 0; i < numCandidatesOrParties; ++i) {
        Ballot newBallot;
        newBallot.setVotes(0);
        partyBallots.push_back(newBallot);
    }

    int amntFiles = vectorFileNames.size();
    //store ballots

    for (int l = 0; l < amntFiles; l++){
        //Read and process ballots
        if (0 == l){
            
            while(getline(file,line)){
                size_t index = line.find("1");
                int idx;
                if (index != std::string::npos) {
                    idx = static_cast<int>(index);
                } else {
                    cout << "Substring not found" << endl;
                }

                partyBallots[idx].incrementVotes();
            }
        file.close();
        }

        else{

            ifstream file(vectorFileNames.at(l)); 
            if (!file.is_open()) {
                std::cerr << "Failed to open the file." << std::endl;
                return 1;
            }
            getline(file, header);
            file >> numSeats >> numBallots >> numCandidatesOrParties;
            megaTotalBallots += numBallots; 
            getline(file, line);
            
            
            for (int i = 0; i < numCandidatesOrParties; ++i){
                getline(file, line);
            }


            while(getline(file,line)){
                size_t index = line.find("1");
                int idx;
                if (index != std::string::npos) {
                    idx = static_cast<int>(index);
                } else {
                    cout << "Substring not found" << endl;
                }

                partyBallots[idx].incrementVotes();
            }
        file.close();
        }
    }
    for (int i = 0; i < parties.size(); i++){
        Seat newSeat;
        seats.push_back(newSeat);
    }
    largest_remainder_seat_allocation(parties, partyBallots, numSeats, numBallots, seats);
    
    output(parties, seats);

    return 0;
}

int Election::runMV(std::ifstream& file){
    file >> numSeats >> numCandidatesOrParties;
    
    //grabs empty line
    string line;
    getline(file, line);
    
    cout << numSeats << endl;
    cout << numCandidatesOrParties << endl;
    
    //grabs empty line
    getline(file, line);
    stringstream ss(line);
    string candidateName;
    int o = 0;
    int candOrPart = 0;

    //start stoarage of candidates and Parties.
    while (getline(ss, candidateName, ',')) {
        // Remove leading and trailing spaces and brackets
        //candidate initialization
        candidateName.erase(0, candidateName.find_first_not_of(" ["));
        // cout << candidateName << endl;
        CandidateMV candidate;
        candidate.setCandidateName(candidateName);
        // cout << candidate.getCandidateName() << endl;

        // Party initialization;
        string partyName;
        getline(ss, partyName, ',');
        partyName = partyName.substr(1);
        partyName.erase(partyName.find_last_not_of(" ]") + 1);
        // cout << partyName << endl;
        MVParty party;
        party.setPartyName(partyName);
        // cout << party.getPartyName() << endl;

        candidate.setParty(&party);
        candidate.setPartyName(party.getPartyName());
        MVCandidates.push_back(candidate);

        if (o == 0) {
            //since party candidate arry is empty, add
            party.addMVCandidate(candidate);
            MVParties.push_back(party);
            o++;
        } else {
            // o++;
            // Check if party name already exists in parties if so, do not add need to keep party array uniquewba
            for (int k = 0; k < MVParties.size(); k++) {
                bool partyExists = false;
                for (int j = 0; j < MVParties.size(); j++) {
                    if ((party.getPartyName() == MVParties[j].getPartyName()) && !partyExists) {
                        // cout << "exists" << endl;
                        MVParties[j].addMVCandidate(candidate);
                        partyExists = true;
                    }
                }
                if (!partyExists) {
                    // cout << "existssdfdsf" << endl;
                    MVParties.push_back(party);
                }
            }
        }
    }

    //checks for parties in 
    for (int i = 0; i < MVParties.size(); i++){
        cout << "here: " << MVParties.at(i).getPartyName() << endl;
    }

    //adds each parties' candidates to a 2d candidates vector [[PartyCanidates1][partycandidates2][ETC]]
    for (size_t i = 0; i < MVParties.size(); ++i) {
        candidates.push_back(MVParties[i].getCandidates());
        vector<Candidate> testRun;
        testRun = MVParties[i].getCandidates();
    }

    //creates new ballots for each party
    for (int i = 0; i <  MVParties.size(); ++i) {
        Ballot newBallot;
        newBallot.setVotes(0);
        partyBallots.push_back(newBallot);
    }

    // Ballots for each candidate for easier calculation
    for (int i = 0; i < MVCandidates.size(); ++i) {
        Ballot newBallot;
        newBallot.setVotes(0);
        candidateBallots.push_back(newBallot);
    }

    getline(file, line);
    numBallots = std::stoi(line);



    int amntFiles = vectorFileNames.size();

    // store everything 
    for (int l = 0; l < amntFiles; l++){
        //Read and process ballots
        if (0 == l){
            megaTotalBallots += numBallots;
            cout << "first megaBallots: " << megaTotalBallots << endl;
            for (int i = 0; i < numBallots; ++i) {
                string line;
                getline(file, line);

                // Check if the line is not empty
                if (!line.empty()) {
                    // Iterate through each character in the line to find index of ballot
                    int idxOfOne = 0;
                    for (int j = 0; j < line.size(); ++j) {
                        // Check if the character is '1' and 
                    
                        if (line[j] == '1') {
                            // Increment the votes for the corresponding candidate
                            candidateBallots[idxOfOne].incrementVotes();
                            //check what index party name is in OPLParties
                            //once there,increment OPLParty ballots in thatspecific index
                            string partyName =  MVCandidates[idxOfOne].getPartyName();
                            for (size_t k = 0; k < MVParties.size(); ++k) {
                                if (MVParties[k].getPartyName() == partyName) {
                                    // Increment the ballots for the party
                                    partyBallots[k].incrementVotes();
                                }
                            }
                        }
                        else if (line[j] == ','){
                            idxOfOne++;
                        }
                    }
                }
            }

        for (int i = 0; i < numCandidatesOrParties; i++){
            cout << "candidate ballot " << i << " :" << candidateBallots.at(i).getVotes() << endl;
        }
        file.close();
        }
        else{

            ifstream file(vectorFileNames.at(l)); 
            if (!file.is_open()) {
                std::cerr << "Failed to open the file." << std::endl;
                return 1;
            }
            getline(file, header);
            file >> numSeats >> numCandidatesOrParties;
            string line;
            getline(file, line);

            //grabs the whole thing with parties and allies
            getline(file, line);

            getline(file, line);
            numBallots = std::stoi(line);
            cout << "mult file numballots " << numBallots << endl;
            megaTotalBallots += numBallots;
            cout << megaTotalBallots << endl;
            
            //for loop so the votes can be incremented
            for (int i = 0; i < numBallots; ++i) {
                string line;
                getline(file, line);

                // Check if the line is not empty
                if (!line.empty()) {
                    // Iterate through each character in the line to find index of ballot
                    int idxOfOne = 0;
                    for (int j = 0; j < line.size(); ++j) {
                        // Check if the character is '1' and 
                    
                        if (line[j] == '1') {
                            // Increment the votes for the corresponding candidate
                            candidateBallots[idxOfOne].incrementVotes();
                            //check what index party name is in OPLParties
                            //once there,increment OPLParty ballots in thatspecific index
                            string partyName =  MVCandidates[idxOfOne].getPartyName();
                            for (size_t k = 0; k < MVParties.size(); ++k) {
                                if (MVParties[k].getPartyName() == partyName) {
                                    // Increment the ballots for the party
                                    partyBallots[k].incrementVotes();
                                }
                            }
                        }
                        else if (line[j] == ','){
                            idxOfOne++;
                        }
                    }
                }
            }
        file.close();
        }
        for (int i = 0; i < numCandidatesOrParties; i++){
            cout << "candidate ballot " << i << " :" << candidateBallots.at(i).getVotes() << endl;
        }
    }

    for (int i = 0; i < MVCandidates.size(); i++){
        Seat newSeat;
        seats.push_back(newSeat);
    }

    for (int i = 0; i < MVCandidates.size(); i++){
        cout << "Candidates: " << MVCandidates[i].getPartyName() << endl;
    }


    largest_remainder_seat_allocation(MVCandidates, candidateBallots, numSeats, megaTotalBallots, seats);
   
    return 0;
}

int Election::run(const std::vector<std::string>& fileNameVector) {
    //open file
    vectorFileNames = fileNameVector;

    ifstream file(fileNameVector.at(0)); 
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    
    //grab header information
    getline(file, header);
  
    //check if OPL or CPL and proceed accordingly
    if (header == "OPL") {
        runOPL(file); 
        return 0;
    }
    else if (header == "CPL") {
        runCPL(file);
        return 0;
    }
    else if (header == "MPO") {
        runMPO(file);
        return 0;
    }
    else if (header == "MV") {
        runMV(file);
        return 0;
    }
    return 1;
}

int Election::output(std::vector<Party> parties, std::vector<Seat> seats) {
    std::ofstream outputfile;
    outputfile.open("auditFile.txt");

    if (!outputfile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }

    outputfile << "Type of Election: " << header << std::endl;
    cout << "Type of Election: " << header << endl;

    outputfile << "Number of Parties: " << parties.size() << std::endl;
    cout << "Number of Parties: " << parties.size() << endl;

    outputfile << "Number of Ballots: " << megaTotalBallots << std::endl;
    cout << "Number of Ballots: " << megaTotalBallots << endl;

    outputfile << "Number of Seats: " << numSeats << std::endl;
    cout << "Number of Seats: " << numSeats << endl;

    // cout << parties.size() << endl;
    for (int i = 0; i < seats.size(); i++){
        cout << parties[i].getPartyName() << ": ";
        outputfile << parties[i].getPartyName() << ": ";
        for(int k = 0; k < candidates[i].size(); k++){
            cout << candidates[i][k].getCandidateName();
            outputfile << candidates[i][k].getCandidateName();
            if (k < (candidates[i].size() - 1)){
                cout << ", ";
                outputfile << ", ";
            }
        }
        cout << endl;
        outputfile << endl;
    }

    //header for the table
    cout << setw(90) << setfill('-') << "" << endl;
    cout << setw(12) << left << "Parties" << setw(8) << right << "Votes" 
       << setw(18) << right << "First" << setw(18) << right << "Remaining" 
       << setw(15) << right << "Second" << setw(9) << right << "Final" 
       << setw(12) << right << "% of Vote" << setw(12) << right << "% of Seats" << endl;
    cout << setw(90) << setfill('-') << "" << endl;
    outputfile << setw(12) << left << "Parties" << setw(8) << right << "Votes" 
       << setw(18) << right << "First" << setw(18) << right << "Remaining" 
       << setw(15) << right << "Second" << setw(9) << right << "Final" 
       << setw(12) << right << "% of Vote" << setw(12) << right << "% of Seats" << endl;
    outputfile << setw(90) << setfill('-') << "" << endl;

    
    for (int i = 0; i < parties.size(); i++){
       cout << setw(12) << left << parties[i].getPartyName() << setw(8) << right << parties[i].getBallot().getVotes() 
       << setw(18) << right << parties[i].getAllocatedSeats()[0] << setw(18) << right << parties[i].getRemainder().getVotes()
       << setw(15) << right << parties[i].getAllocatedSeats()[1] << setw(9) << right << seats[i].getSeats()
       << setw(12) << right << (static_cast<double>(parties[i].getBallot().getVotes())/(numBallots))*100.0 << "% of Vote" 
       << setw(12) << right << (static_cast<double>(seats[i].getSeats())/numSeats)*100 << "%" << "% of Seats" << endl;

       outputfile << setw(12) << left << parties[i].getPartyName() << setw(8) << right << parties[i].getBallot().getVotes() 
       << setw(18) << right << parties[i].getAllocatedSeats()[0] << setw(18) << right << parties[i].getRemainder().getVotes()
       << setw(15) << right << parties[i].getAllocatedSeats()[1] << setw(9) << right << seats[i].getSeats()
       << setw(12) << right << (static_cast<double>(parties[i].getBallot().getVotes())/(numBallots))*100.0 << "% of Vote" 
       << setw(12) << right << (static_cast<double>(seats[i].getSeats())/numSeats)*100 << "%" << "% of Seats" << endl;
    }

    //outputting the results to the terminal through nested for loop
    for (int i = 0; i < seats.size(); i++){
        if (seats[i].getSeats() > 0){
            cout << parties[i].getPartyName() << ": ";
            outputfile << parties[i].getPartyName() << ": ";
            for(int k = 0; k < candidates[i].size(); k++){
                cout << candidates[i][k].getCandidateName();
                outputfile << candidates[i][k].getCandidateName();
                if (k < (candidates[i].size() - 1)){
                    cout << ", ";
                    outputfile << ", ";
                }
            }
            cout << endl;
            outputfile << endl;
        }
    }
    outputfile.close();
    return 0;
}

int Election::output(std::vector<OPLParty> parties, std::vector<Seat> seats) {
    std::ofstream outputfile;
    outputfile.open("auditFile.txt");

    if (!outputfile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }

    outputfile << "Type of Election: " << header << std::endl;
    cout << "Type of Election: " << header << endl;

    outputfile << "Number of Parties: " << parties.size() << std::endl;
    cout << "Number of Parties: " << parties.size() << endl;

    outputfile << "Number of Ballots: " << megaTotalBallots << std::endl;
    cout << "Number of Ballots: " << megaTotalBallots << endl;

    outputfile << "Number of Seats: " << numSeats << std::endl;
    cout << "Number of Seats: " << numSeats << endl;


    for (int i = 0; i < seats.size(); i++){
        cout << parties[i].getPartyName() << ": ";
        outputfile << parties[i].getPartyName() << ": ";
        for(int k = 0; k < candidates[i].size(); k++){
            cout << candidates[i][k].getCandidateName();
            outputfile << candidates[i][k].getCandidateName();
            if (k < (candidates[i].size() - 1)){
                cout << ", ";
                outputfile << ", ";
            }
        }
        cout << endl;
        outputfile << endl;
    }
    cout << setw(90) << setfill('-') << "" << endl;
    cout << setw(12) << left << "Parties" << setw(8) << right << "Votes" 
       << setw(18) << right << "First" << setw(18) << right << "Remaining" 
       << setw(15) << right << "Second" << setw(9) << right << "Final" 
       << setw(12) << right << "% of Vote" << setw(12) << right << "% of Seats" << endl;
    cout << setw(90) << setfill('-') << "" << endl;

    outputfile << setw(12) << left << "Parties" << setw(8) << right << "Votes" 
       << setw(18) << right << "First" << setw(18) << right << "Remaining" 
       << setw(15) << right << "Second" << setw(9) << right << "Final" 
       << setw(12) << right << "% of Vote" << setw(12) << right << "% of Seats" << endl;
    outputfile << setw(90) << setfill('-') << "" << endl;


    
    for (int i = 0; i < parties.size(); i++){
       cout << setw(12) << left << parties[i].getPartyName() << setw(8) << right << parties[i].getBallot().getVotes() 
       << setw(18) << right << parties[i].getAllocatedSeats()[0] << setw(18) << right << parties[i].getRemainder().getVotes()
       << setw(15) << right << parties[i].getAllocatedSeats()[1] << setw(9) << right << seats[i].getSeats()
       << setw(12) << right << (static_cast<double>(parties[i].getBallot().getVotes())/(numBallots))*100.0 << "% of Vote" 
       << setw(12) << right << (static_cast<double>(seats[i].getSeats())/numSeats)*100 << "%" << "% of Seats" << endl;

       outputfile << setw(12) << left << parties[i].getPartyName() << setw(8) << right << parties[i].getBallot().getVotes() 
       << setw(18) << right << parties[i].getAllocatedSeats()[0] << setw(18) << right << parties[i].getRemainder().getVotes()
       << setw(15) << right << parties[i].getAllocatedSeats()[1] << setw(9) << right << seats[i].getSeats()
       << setw(12) << right << (static_cast<double>(parties[i].getBallot().getVotes())/(numBallots))*100.0 << "% of Vote" 
       << setw(12) << right << (static_cast<double>(seats[i].getSeats())/numSeats)*100 << "%" << "% of Seats" << endl;
    }

    //outputting the results to the terminal through nested for loop
    for (int i = 0; i < seats.size(); i++){
        if (seats[i].getSeats() > 0){

            cout << parties[i].getPartyName() << ": ";
            outputfile << parties[i].getPartyName() << ": ";
            for(int k = 0; k < candidates[i].size(); k++){
                for(int j = 0; j < OPLCandidates.size(); j++){
                    if(candidates[i][k].getCandidateName() == OPLCandidates[j].getCandidateName()){
                        cout << candidates[i][k].getCandidateName()  << "-" << OPLCandidates[j].getBallot().getVotes();
                        outputfile << candidates[i][k].getCandidateName()  << "-" << OPLCandidates[j].getBallot().getVotes();
                            if (k < (candidates[i].size() - 1)){
                                cout << ", ";
                                outputfile << ", ";
                            }
                        }
                    }
                    
                    
                }

            cout << endl;
            outputfile << endl;
        }
    }
    outputfile.close();
    return 0;
}


