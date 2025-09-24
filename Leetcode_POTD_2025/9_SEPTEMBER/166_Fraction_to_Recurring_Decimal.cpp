class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result_str = "";
        long long num_ll = numerator, den_ll = denominator;
        if ((num_ll > 0) ^ (den_ll > 0)) result_str += "-";
        num_ll = abs(num_ll);
        den_ll = abs(den_ll);
        result_str += to_string(num_ll / den_ll);
        long long rem_ll = num_ll % den_ll;
        if (rem_ll == 0) return result_str;
        result_str += ".";
        unordered_map<long long, int> tracker_map;
        while (rem_ll != 0) {
            if (tracker_map.count(rem_ll)) {
                result_str.insert(tracker_map[rem_ll], "(");
                result_str += ")";
                return result_str;
            }
            tracker_map[rem_ll] = result_str.size();
            rem_ll *= 10;
            result_str += to_string(rem_ll / den_ll);
            rem_ll %= den_ll;
        }
        return result_str;
    }
};
