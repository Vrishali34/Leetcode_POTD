 class Solution {
private:
    void parse_mentions(const std::string& men_str, std::vector<int>& out_mentions, int num_users, const std::vector<int>& re_online_times) {
        if (men_str == "ALL") {
            for (int i = 0; i < num_users; ++i) out_mentions[i]++;
        } else if (men_str == "HERE") {
            for (int i = 0; i < num_users; ++i) {
                if (re_online_times[i] == 0) out_mentions[i]++;
            }
        } else {
            std::stringstream ss(men_str);
            std::string tok;
            while (ss >> tok) {
                int uid = std::stoi(tok.substr(2));
                out_mentions[uid]++;
            }
        }
    }

public:
    std::vector<int> countMentions(int total_folks, std::vector<std::vector<std::string>>& happenings) {
        std::vector<std::tuple<int, int, std::string>> chronological_ops;
        for (const auto& ev : happenings) {
            int time_point = std::stoi(ev[1]);
            int op_type = (ev[0] == "OFFLINE") ? 0 : 1; // 0 for OFFLINE, 1 for MESSAGE (for stable sort)
            chronological_ops.emplace_back(time_point, op_type, ev[2]);
        }

        std::sort(chronological_ops.begin(), chronological_ops.end());

        std::vector<int> folk_comeback_times(total_folks, 0); // 0 means online
        std::vector<int> folk_mention_counts(total_folks, 0);

        for (const auto& op : chronological_ops) {
            int current_time = std::get<0>(op);
            for (int i = 0; i < total_folks; ++i) {
                if (folk_comeback_times[i] > 0 && folk_comeback_times[i] <= current_time) {
                    folk_comeback_times[i] = 0;
                }
            }

            int op_kind = std::get<1>(op);
            const std::string& op_data = std::get<2>(op);

            if (op_kind == 0) { // OFFLINE
                int uid = std::stoi(op_data);
                folk_comeback_times[uid] = current_time + 60;
            } else { // MESSAGE
                parse_mentions(op_data, folk_mention_counts, total_folks, folk_comeback_times);
            }
        }

        return folk_mention_counts;
    }
};
