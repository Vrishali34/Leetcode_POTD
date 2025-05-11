class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& q) {
        for(int a=2;a<q.size();a++)
            if(q[a]%2 && q[a-1]%2 && q[a-2]%2) return true;
        return false;
    }
};
