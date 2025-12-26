class Solution {
public:
    int bestClosingTime(string customers) {
        int best_hour = 0, net_score = 0, min_score = 0;
        for (int i_hr = 0; i_hr < customers.size(); ++i_hr) {
            if (customers[i_hr] == 'Y') net_score--;
            else net_score++;
            if (net_score < min_score) {
                min_score = net_score;
                best_hour = i_hr + 1;
            }
        }
        return best_hour;
    }
};
