class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> lexicon = new HashSet<>(Arrays.asList(wordlist));
        Map<String, String> capital_map = new HashMap<>();
        Map<String, String> vowel_map = new HashMap<>();

        for (String w : wordlist) {
            String lowercase = w.toLowerCase();
            capital_map.putIfAbsent(lowercase, w);
            vowel_map.putIfAbsent(w.replaceAll("[aeiou]", "#").toLowerCase(), w);
        }

        String[] rectifications = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String q = queries[i];
            if (lexicon.contains(q)) {
                rectifications[i] = q;
            } else {
                String lc_q = q.toLowerCase();
                String vowel_q = lc_q.replaceAll("[aeiou]", "#");
                if (capital_map.containsKey(lc_q)) {
                    rectifications[i] = capital_map.get(lc_q);
                } else if (vowel_map.containsKey(vowel_q)) {
                    rectifications[i] = vowel_map.get(vowel_q);
                } else {
                    rectifications[i] = "";
                }
            }
        }
        return rectifications;
    }
}
