class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0, left = 0;
        int freq[3] = {0};

        for (char c : s) {
            freq[c - 'a']++;

            while (freq[0] && freq[1] && freq[2]) {
                freq[s[left++] - 'a']--;
            }

            count += left;
        }

        return count;
    }
};
