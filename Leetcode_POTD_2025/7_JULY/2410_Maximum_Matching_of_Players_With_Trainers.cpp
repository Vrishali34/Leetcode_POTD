class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());

        int match_count = 0;
        int p_idx = 0;
        int t_idx = 0;

        while (p_idx < players.size() && t_idx < trainers.size()) {
            if (players[p_idx] <= trainers[t_idx]) {
                match_count++;
                p_idx++;
                t_idx++;
            } else {
                t_idx++;
            }
        }
        return match_count;
    }
};
