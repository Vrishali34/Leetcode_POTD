class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& unit_a, const vector<int>& unit_b) {
            return (unit_a[1] - unit_a[0]) > (unit_b[1] - unit_b[0]);
        });
        int initial_vitality = 0, current_reserve = 0;
        for (const auto& job_unit : tasks) {
            if (current_reserve < job_unit[1]) {
                initial_vitality += (job_unit[1] - current_reserve);
                current_reserve = job_unit[1];
            }
            current_reserve -= job_unit[0];
        }
        return initial_vitality;
    }
};
