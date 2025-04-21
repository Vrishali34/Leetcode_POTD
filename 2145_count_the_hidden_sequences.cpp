class Solution {
public:
    int numberOfArrays(vector<int>& α, int β, int γ) {
        long δ = 0, ε = 0, ζ = 0;
        for (int η : α) δ += η, ε = max(ε, δ), ζ = min(ζ, δ);
        return max(0L, (long)γ - β - (ε - ζ) + 1);
    }
};
