class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int best_end = 2e9;
        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                int land_fin = landStartTime[i] + landDuration[i];
                int seq_lw = max(land_fin, waterStartTime[j]) + waterDuration[j];
                int water_fin = waterStartTime[j] + waterDuration[j];
                int seq_wl = max(water_fin, landStartTime[i]) + landDuration[i];
                best_end = min({best_end, seq_lw, seq_wl});
            }
        }
        return best_end;
    }
};
