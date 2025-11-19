class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<bool> star_chart(1001, false);
        for (int celestial_body : nums) star_chart[celestial_body] = true;
        while (original <= 1000 && star_chart[original]) original *= 2;
        return original;
    }
};
