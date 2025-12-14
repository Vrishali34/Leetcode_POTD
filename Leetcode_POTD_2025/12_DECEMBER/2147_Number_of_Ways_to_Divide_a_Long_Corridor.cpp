class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> seat_indices;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') {
                seat_indices.push_back(i);
            }
        }

        int seat_tally = seat_indices.size();
        long long ways_product = 1;
        long long modulus_base = 1e9 + 7;

        if (seat_tally == 0 || seat_tally % 2 != 0) {
            return 0;
        }

        for (int i = 1; i < seat_tally / 2; ++i) {
            long long delta_pos = seat_indices[2 * i] - seat_indices[2 * i - 1];
            ways_product = (ways_product * delta_pos) % modulus_base;
        }

        return ways_product;
    }
};
