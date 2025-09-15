class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        String[] words = text.split(" ");
        int typed_count = 0;
        
        for (String word : words) {
            boolean can_type = true;
            for (char broken_char : brokenLetters.toCharArray()) {
                if (word.indexOf(broken_char) != -1) {
                    can_type = false;
                    break;
                }
            }
            if (can_type) {
                typed_count++;
            }
        }
        
        return typed_count;
    }
}
