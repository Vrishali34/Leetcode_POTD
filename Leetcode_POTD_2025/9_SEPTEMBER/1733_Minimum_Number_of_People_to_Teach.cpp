class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> uncommunicative_users;
        for (const auto& friendship : friendships) {
            int user1 = friendship[0] - 1;
            int user2 = friendship[1] - 1;
            bool common_language = false;
            for (int lang1 : languages[user1]) {
                for (int lang2 : languages[user2]) {
                    if (lang1 == lang2) {
                        common_language = true;
                        break;
                    }
                }
                if (common_language) break;
            }
            if (!common_language) {
                uncommunicative_users.insert(user1);
                uncommunicative_users.insert(user2);
            }
        }
        int min_learners = 1e9;
        for (int lang_to_teach = 1; lang_to_teach <= n; ++lang_to_teach) {
            int current_learners = 0;
            for (int user : uncommunicative_users) {
                bool knows_lang = false;
                for (int lang_known : languages[user]) {
                    if (lang_known == lang_to_teach) {
                        knows_lang = true;
                        break;
                    }
                }
                if (!knows_lang) {
                    current_learners++;
                }
            }
            min_learners = min(min_learners, current_learners);
        }
        return min_learners;
    }
};
