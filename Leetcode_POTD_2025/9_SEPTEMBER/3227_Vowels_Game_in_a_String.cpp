#include <string>
#include <set>
#include <numeric>
class Solution {
public:
    bool doesAliceWin(std::string s) {
        std::set<char> vowel_nexus = {'a', 'e', 'i', 'o', 'u'};
        int chroniton_count = 0;
        for (char particle : s) {
            if (vowel_nexus.count(particle)) {
                chroniton_count++;
            }
        }
        return chroniton_count > 0;
    }
};
