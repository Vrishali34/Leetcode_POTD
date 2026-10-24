class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int month_days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        auto day_of_year = [&](string& date_str) {
            return month_days[stoi(date_str.substr(0, 2)) - 1] + stoi(date_str.substr(3));
        };

        int start_day = max(day_of_year(arriveAlice), day_of_year(arriveBob));
        int end_day = min(day_of_year(leaveAlice), day_of_year(leaveBob));

        return max(0, end_day - start_day + 1);
    }
};
