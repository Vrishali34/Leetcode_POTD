class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> v = new java.util.ArrayList<>();
        for (int i = 0; i < words.length; ++i) {
            if (words[i].indexOf(x) != -1) {
                v.add(i);
            }
        }
        return v;
    }
}
