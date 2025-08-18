class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> cosmic_arr(cards.begin(), cards.end());
        return cosmic_quest(cosmic_arr);
    }

private:
    bool cosmic_quest(vector<double> realm) {
        if (realm.size() == 1) {
            return abs(realm[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < realm.size(); ++i) {
            for (int j = i + 1; j < realm.size(); ++j) {
                vector<double> new_realms;
                for (int k = 0; k < realm.size(); ++k) {
                    if (k != i && k != j) {
                        new_realms.push_back(realm[k]);
                    }
                }

                vector<double> temp_ops;
                temp_ops.push_back(realm[i] + realm[j]);
                temp_ops.push_back(realm[i] * realm[j]);
                temp_ops.push_back(realm[i] - realm[j]);
                temp_ops.push_back(realm[j] - realm[i]);
                if (realm[j] != 0) temp_ops.push_back(realm[i] / realm[j]);
                if (realm[i] != 0) temp_ops.push_back(realm[j] / realm[i]);

                for (double val : temp_ops) {
                    vector<double> next_realm = new_realms;
                    next_realm.push_back(val);
                    if (cosmic_quest(next_realm)) return true;
                }
            }
        }
        return false;
    }
};
