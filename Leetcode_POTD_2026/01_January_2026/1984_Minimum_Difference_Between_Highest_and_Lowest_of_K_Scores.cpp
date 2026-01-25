class Solution {
public:
    int minimumDifference(vector<int>& scores, int span) {
        sort(scores.begin(), scores.end());
        int min_gap = scores[span - 1] - scores[0];
        for (int i = span; i < scores.size(); ++i) {
            min_gap = min(min_gap, scores[i] - scores[i - span + 1]);
        }
        return min_gap;
    }
};
