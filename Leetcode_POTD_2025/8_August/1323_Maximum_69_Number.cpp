class Solution {
public:
    int maximum69Number (int num) {
        int zeta = num;
        int eta = -1;
        int theta = 0;
        while (zeta > 0) {
            theta++;
            if (zeta % 10 == 6) {
                eta = theta;
            }
            zeta /= 10;
        }
        if (eta == -1) {
            return num;
        }
        return num + 3 * pow(10, eta - 1);
    }
};
