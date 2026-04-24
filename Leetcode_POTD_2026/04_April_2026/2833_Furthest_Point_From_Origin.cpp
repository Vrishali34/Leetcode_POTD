class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int net_drift = 0, wild_cards = 0;
        for (char motion : moves) {
            if (motion == 'L') net_drift--;
            else if (motion == 'R') net_drift++;
            else wild_cards++;
        }
        return abs(net_drift) + wild_cards;
    }
};
