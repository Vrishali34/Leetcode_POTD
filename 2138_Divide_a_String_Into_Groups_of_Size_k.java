import java.util.ArrayList;
import java.util.List;

class Solution {
    public String[] divideString(String s, int k, char fill) {
        List<String> groups = new ArrayList<>();
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            StringBuilder currentGroup = new StringBuilder();
            for (int j = 0; j < k; j++) {
                if (i + j < n) {
                    currentGroup.append(s.charAt(i + j));
                } else {
                    currentGroup.append(fill);
                }
            }
            groups.add(currentGroup.toString());
        }
        return groups.toArray(new String[0]);
    }
}
