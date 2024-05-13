class OPL_Party : public Party {
private:
    map<string, int> votesForCandidate;

public:
    int getCandidateVote(string candidateName) { return votesForCandidate[candidateName]; }
    void setCandidateVote(string candidateName, int votes) { votesForCandidate[candidateName] = votes; }
    void sortCandidateDict(map<string, int>& votesForCandidate) {
    }
    void setCandidateRankings() {
        sortCandidateDict(votesForCandidate);
        int ranking = 1;
        for (auto& candidate : candidateNames) {
            CandidateOPL* cand = dynamic_cast<CandidateOPL*>(candidate);
            cand->setRankingCandidates(ranking++);
        }
    }
};