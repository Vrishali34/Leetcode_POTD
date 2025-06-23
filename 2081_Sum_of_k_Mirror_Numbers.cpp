class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum_of_mirrors = 0;
        int count_found = 0;
        for (long long digits_count = 1; ; ++digits_count) {
            long long start_num = pow(10, (digits_count - 1) / 2);
            long long end_num = pow(10, (digits_count + 1) / 2);
            for (long long i = start_num; i < end_num; ++i) {
                string s = to_string(i);
                string pal = s;
                reverse(pal.begin(), pal.end());
                string full_pal = s;
                if (digits_count % 2 == 1) {
                    full_pal += pal.substr(1);
                } else {
                    full_pal += pal;
                }
                long long current_base10_num = stoll(full_pal);
                string basek_rep = "";
                long long temp_num = current_base10_num;
                while (temp_num > 0) {
                    basek_rep += to_string(temp_num % k);
                    temp_num /= k;
                }
                reverse(basek_rep.begin(), basek_rep.end());
                string reversed_basek_rep = basek_rep;
                reverse(reversed_basek_rep.begin(), reversed_basek_rep.end());
                if (basek_rep == reversed_basek_rep) {
                    sum_of_mirrors += current_base10_num;
                    count_found++;
                    if (count_found == n) {
                        return sum_of_mirrors;
                    }
                }
            }
        }
    }
};
