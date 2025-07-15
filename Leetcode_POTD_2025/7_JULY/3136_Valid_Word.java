class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) return false;
        boolean has_vowel = false;
        boolean has_consonant = false;
        for (char cosmic_char : word.toCharArray()) {
            if (!Character.isLetterOrDigit(cosmic_char)) return false;
            if (Character.isLetter(cosmic_char)) {
                char stellar_char = Character.toLowerCase(cosmic_char);
                if (stellar_char == 'a' || stellar_char == 'e' || stellar_char == 'i' || stellar_char == 'o' || stellar_char == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            }
        }
        return has_vowel && has_consonant;
    }
}
