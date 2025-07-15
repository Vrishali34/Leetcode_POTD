class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        bool has_vowel = false;
        bool has_consonant = false;
        for (char cosmic_char : word) {
            if (!isalnum(cosmic_char)) return false;
            if (isalpha(cosmic_char)) {
                char stellar_char = tolower(cosmic_char);
                if (stellar_char == 'a' || stellar_char == 'e' || stellar_char == 'i' || stellar_char == 'o' || stellar_char == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            }
        }
        return has_vowel && has_consonant;
    }
};
