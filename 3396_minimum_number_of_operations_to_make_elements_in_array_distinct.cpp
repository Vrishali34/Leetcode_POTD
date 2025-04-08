class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        if (s.size() == nums.size()) return 0;  // Already distinct
        
        int operations = 0;
        
        while (nums.size() > 3) {
            nums.erase(nums.begin(), nums.begin() + 3);
            operations++;
            
            unordered_set<int> tempSet(nums.begin(), nums.end());
            if (tempSet.size() == nums.size()) break;  // Distinct elements found
        }
        
        unordered_set<int> finalSet(nums.begin(), nums.end());
        return operations + (finalSet.size() < nums.size());
    }
};
