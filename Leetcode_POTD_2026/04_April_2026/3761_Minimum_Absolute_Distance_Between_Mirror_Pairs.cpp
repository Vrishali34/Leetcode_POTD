class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mirror_index;
        int min_dist = 1e9, total_nums = nums.size();
        for (int i = 0; i < total_nums; ++i) {
            if (mirror_index.count(nums[i])) 
                min_dist = min(min_dist, i - mirror_index[nums[i]]);
            int original = nums[i], reversed_val = 0;
            while (original > 0) { 
                reversed_val = reversed_val * 10 + (original % 10); 
                original /= 10; 
            }
            mirror_index[reversed_val] = i;
        }
        return (min_dist == 1e9) ? -1 : min_dist;
    }
};
