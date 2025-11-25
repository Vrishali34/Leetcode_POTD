class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int current_drift = 0;
        for (int milestone_marker = 1; milestone_marker <= k; ++milestone_marker) {
            current_drift = (current_drift * 10 + 1) % k;
            if (current_drift == 0) return milestone_marker;
        }
        return -1;
    }
};
