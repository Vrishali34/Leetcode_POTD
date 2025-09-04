class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist_one = abs(x - z);
        int dist_two = abs(y - z);
        if (dist_one < dist_two) {
            return 1;
        } else if (dist_two < dist_one) {
            return 2;
        } else {
            return 0;
        }
    }
};
