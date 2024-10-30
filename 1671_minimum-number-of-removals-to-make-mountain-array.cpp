class Solution {
public:
    int minimumMountainRemovals(vector<int>& v) {
        int s = v.size(), peak = 0;
        vector<int> left(s, 1), right(s, 1);
        
        for (int i = 1; i < s; ++i)
            for (int j = 0; j < i; ++j)
                if (v[i] > v[j]) left[i] = max(left[i], left[j] + 1);
        
        for (int i = s - 2; i >= 0; --i)
            for (int j = s - 1; j > i; --j)
                if (v[i] > v[j]) right[i] = max(right[i], right[j] + 1);
        
        for (int i = 1; i < s - 1; ++i)
            if (left[i] > 1 && right[i] > 1) peak = max(peak, left[i] + right[i] - 1);
        
        return s - peak;
    }
};
