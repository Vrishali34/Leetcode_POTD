class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int letter_counts[26] = {0};
        for (char ch : text) {
            letter_counts[ch - 'a']++;
        }
        int max_words = letter_counts['b' - 'a'];
        max_words = min(max_words, letter_counts['a' - 'a']);
        max_words = min(max_words, letter_counts['l' - 'a'] / 2);
        max_words = min(max_words, letter_counts['o' - 'a'] / 2);
        max_words = min(max_words, letter_counts['n' - 'a']);
        return max_words;
    }
};
