#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> m;
        for (auto& t : nums) m.insert(stoi(t, nullptr, 2));
        for (int x = 0; x <= nums.size(); x++) 
            if (!m.count(x)) return bitset<16>(x).to_string().substr(16 - nums.size());
        return "";
    }
};
