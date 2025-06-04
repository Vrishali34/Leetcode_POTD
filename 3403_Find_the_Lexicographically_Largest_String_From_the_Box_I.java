class Solution {
    public String answerString(String word, int numFriends) {
        if (numFriends == 1) return word;
        String res = "";
        for (int i = 0; i < word.length(); i++)
            res = res.compareTo(word.substring(i, Math.min(word.length(), i + word.length() - numFriends + 1))) < 0 ? word.substring(i, i + word.length() - numFriends + 1) : res;
        return res;
    }
}
