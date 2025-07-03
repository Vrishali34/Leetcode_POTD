class Solution {
    public char kthCharacter(int k) {
        long current_len = 1;
        char prime_char = 'a';
        while (k > current_len)
            current_len *= 2;
        while (current_len > 1) {
            long half_len = current_len / 2;
            if (k > half_len) {
                k -= half_len;
                prime_char = (char) ((prime_char - 'a' + 1) % 26 + 'a');
            }
            current_len = half_len;
        }
        return prime_char;
    }
}
