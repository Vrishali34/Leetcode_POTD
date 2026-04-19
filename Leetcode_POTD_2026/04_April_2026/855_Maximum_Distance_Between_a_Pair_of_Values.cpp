class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int peak_dist = 0, p1 = 0, p2 = 0;
        int sz1 = nums1.size(), sz2 = nums2.size();
        while (p1 < sz1 && p2 < sz2) {
            if (nums1[p1] <= nums2[p2]) {
                peak_dist = max(peak_dist, p2 - p1);
                p2++;
            } else {
                p1++;
            }
        }
        return peak_dist;
    }
};
