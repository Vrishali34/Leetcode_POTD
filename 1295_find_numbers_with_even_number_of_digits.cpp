class Solution {
public:
    int findNumbers(vector<int>& a) {
        return count_if(a.begin(), a.end(), [](int b) { return !(int(log10(b) + 1) % 2); });
    }
};
