class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        firstPlayer--; 
        secondPlayer--;

        map<int, pair<int, int>> dp_states;

        function<pair<int, int>(int, int)> recurse_solve = 
            [&](int current_mask, int round_num) {
            
            if (dp_states.count(current_mask)) {
                return dp_states[current_mask];
            }

            vector<int> active_players;
            for (int i = 0; i < n; ++i) {
                if ((current_mask >> i) & 1) {
                    active_players.push_back(i);
                }
            }

            int num_active = active_players.size();
            int fp_pos = -1, sp_pos = -1;
            for (int i = 0; i < num_active; ++i) {
                if (active_players[i] == firstPlayer) fp_pos = i;
                if (active_players[i] == secondPlayer) sp_pos = i;
            }

            if (fp_pos + sp_pos == num_active - 1) {
                return dp_states[current_mask] = {round_num, round_num};
            }

            int min_possible_round = 1e9;
            int max_possible_round = 0;
            int half_len = (num_active + 1) / 2;

            function<void(int, int)> generate_next_round_masks = 
                [&](int k, int next_mask_gen) {
                if (k == half_len) {
                    pair<int, int> result_next_round = recurse_solve(next_mask_gen, round_num + 1);
                    min_possible_round = min(min_possible_round, result_next_round.first);
                    max_possible_round = max(max_possible_round, result_next_round.second);
                    return;
                }

                int front_p = active_players[k];
                int back_p = active_players[num_active - 1 - k];

                if (k == num_active - 1 - k) { 
                    generate_next_round_masks(k + 1, next_mask_gen | (1 << front_p));
                } else {
                    bool fp_in_match = (front_p == firstPlayer || front_p == secondPlayer);
                    bool sp_in_match = (back_p == firstPlayer || back_p == secondPlayer);

                    if (fp_in_match && sp_in_match) { 
                        return;
                    } else if (fp_in_match) { 
                        generate_next_round_masks(k + 1, next_mask_gen | (1 << front_p));
                    } else if (sp_in_match) { 
                        generate_next_round_masks(k + 1, next_mask_gen | (1 << back_p));
                    } else { 
                        generate_next_round_masks(k + 1, next_mask_gen | (1 << front_p));
                        generate_next_round_masks(k + 1, next_mask_gen | (1 << back_p));
                    }
                }
            };
            generate_next_round_masks(0, 0);
            return dp_states[current_mask] = {min_possible_round, max_possible_round};
        };

        int initial_configuration_mask = (1 << n) - 1;
        pair<int, int> final_result = recurse_solve(initial_configuration_mask, 1);
        return {final_result.first, final_result.second};
    }
};
