class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), freq[3] = {}, ans = n, left = 0;
        for (auto c : s) freq[c - 'a']++;
        if (*min_element(freq, freq + 3) < k) return -1;
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']--;
            while (left <= right && *min_element(freq, freq + 3) < k) freq[s[left++] - 'a']++;
            ans = min(ans, n - (right - left + 1));
        }
        return ans;
    }
};
