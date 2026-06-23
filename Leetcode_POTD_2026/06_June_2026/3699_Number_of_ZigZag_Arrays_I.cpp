class Solution {
public:
    int zigZagArrays(int total_elements, int floor_bound, int ceiling_bound) {
        int span_range = ceiling_bound - floor_bound;
        long long modulo_base = 1e9 + 7;
        std::vector<long long> wave_frequencies(span_range + 1, 1);
        for (int step_idx = 1; step_idx < total_elements; ++step_idx) {
            long long cumulative_tally = 0;
            if (step_idx & 1) {
                for (int slot_idx = 0; slot_idx <= span_range; ++slot_idx) {
                    long long incoming_cache = cumulative_tally + wave_frequencies[slot_idx];
                    wave_frequencies[slot_idx] = cumulative_tally;
                    cumulative_tally = incoming_cache % modulo_base;
                }
            } else {
                for (int slot_idx = span_range; slot_idx >= 0; --slot_idx) {
                    long long incoming_cache = cumulative_tally + wave_frequencies[slot_idx];
                    wave_frequencies[slot_idx] = cumulative_tally;
                    cumulative_tally = incoming_cache % modulo_base;
                }
            }
        }
        long long aggregate_count = 0;
        for (long long individual_tally : wave_frequencies) {
            aggregate_count = (aggregate_count + individual_tally) % modulo_base;
        }
        return (aggregate_count * 2) % modulo_base;
    }
};
