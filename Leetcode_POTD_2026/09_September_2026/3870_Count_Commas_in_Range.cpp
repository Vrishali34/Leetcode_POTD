class Solution {
public:
    int countCommas(int n) {
        int comma_total = n - 999;
        return comma_total > 0 ? comma_total : 0;
    }
};
