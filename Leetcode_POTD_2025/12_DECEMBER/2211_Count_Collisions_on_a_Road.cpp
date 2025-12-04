class Solution {
public:
    int countCollisions(string directions) {
        int galaxy_size = directions.length();
        int star_left = 0;
        int star_right = galaxy_size - 1;
        while (star_left < galaxy_size && directions[star_left] == 'L') {
            star_left++;
        }
        while (star_right >= 0 && directions[star_right] == 'R') {
            star_right--;
        }
        int cosmic_impacts = 0;
        for (int i = star_left; i <= star_right; i++) {
            if (directions[i] != 'S') {
                cosmic_impacts++;
            }
        }
        return cosmic_impacts;
    }
};
