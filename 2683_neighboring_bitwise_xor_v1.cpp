class Solution {
public:
    bool doesValidArrayExist(vector<int>& v1) {
        int x = 0;
        for (int i : v1) x ^= i;
        return x == 0;
    }
};
