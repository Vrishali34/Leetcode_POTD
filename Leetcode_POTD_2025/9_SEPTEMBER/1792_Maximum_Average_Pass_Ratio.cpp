class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto lambda_func = [](const pair<int, int>& a, const pair<int, int>& b) {
            double before_a = (double)a.first / a.second;
            double after_a = (double)(a.first + 1) / (a.second + 1);
            double gain_a = after_a - before_a;

            double before_b = (double)b.first / b.second;
            double after_b = (double)(b.first + 1) / (b.second + 1);
            double gain_b = after_b - before_b;

            return gain_a < gain_b;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lambda_func)> pq(lambda_func);

        for (auto const& cls : classes) {
            pq.push({cls[0], cls[1]});
        }
        
        while (extraStudents--) {
            auto top_cls = pq.top();
            pq.pop();
            pq.push({top_cls.first + 1, top_cls.second + 1});
        }
        
        double total_ratio = 0.0;
        int n = classes.size();
        while (!pq.empty()) {
            auto cls = pq.top();
            pq.pop();
            total_ratio += (double)cls.first / cls.second;
        }
        
        return total_ratio / n;
    }
};
