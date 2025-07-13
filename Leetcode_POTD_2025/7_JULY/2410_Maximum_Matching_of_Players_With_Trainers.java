import java.util.Arrays;

class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);

        int match_count = 0;
        int p_idx = 0;
        int t_idx = 0;

        while (p_idx < players.length && t_idx < trainers.length) {
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
}
