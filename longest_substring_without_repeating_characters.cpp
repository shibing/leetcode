class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        if (s.empty()) return 0;
        int max = 1;
        for (int i = 0; i <  s.size(); ++i) {
            for(int j = i + 1; j < s.size(); ++j) {
                int k;
               for (k = i; k < j; k++) {
                   if (s[j] == s[k]) {
                       break;
                   }
               }
               if (k < j) {
                   break;
               } else {
                   int cur_max = j - i + 1;
                   if (cur_max > max) max = cur_max;
               }
            }
        }
        return max;
    }
};
