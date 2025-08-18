import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean judgePoint24(int[] cards) {
        List<Double> cosmic_arr = new ArrayList<>();
        for (int card : cards) {
            cosmic_arr.add((double) card);
        }
        return cosmic_quest(cosmic_arr);
    }

    private boolean cosmic_quest(List<Double> realm) {
        if (realm.size() == 1) {
            return Math.abs(realm.get(0) - 24.0) < 1e-6;
        }

        for (int i = 0; i < realm.size(); ++i) {
            for (int j = i + 1; j < realm.size(); ++j) {
                List<Double> new_realms = new ArrayList<>();
                for (int k = 0; k < realm.size(); ++k) {
                    if (k != i && k != j) {
                        new_realms.add(realm.get(k));
                    }
                }

                List<Double> temp_ops = new ArrayList<>();
                temp_ops.add(realm.get(i) + realm.get(j));
                temp_ops.add(realm.get(i) * realm.get(j));
                temp_ops.add(realm.get(i) - realm.get(j));
                temp_ops.add(realm.get(j) - realm.get(i));
                if (realm.get(j) != 0) temp_ops.add(realm.get(i) / realm.get(j));
                if (realm.get(i) != 0) temp_ops.add(realm.get(j) / realm.get(i));

                for (double val : temp_ops) {
                    List<Double> next_realm = new ArrayList<>(new_realms);
                    next_realm.add(val);
                    if (cosmic_quest(next_realm)) return true;
                }
            }
        }
        return false;
    }
}
