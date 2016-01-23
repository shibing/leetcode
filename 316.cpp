/**
 * Remove duplicate letters
 *
 * */

#include <string>
#include <array>
#include <iostream>


class Sloution
{
public:
    std::string removeDuplicateLetters(const std::string& s) 
    {
        std::array<int, 26> times;
        std::array<bool, 26> cand;
        std::array<int, 26> a;
        times.fill(0);
        cand.fill(false);
        for (auto&& c: s) {
            times[c - 'a']++;
        }
        std::string res;
        for (int i = 0; i < s.size(); ++i) {
            times[s[i] - 'a']--;
            if (cand[s['i'] - 'a']) {
                continue;
            }
            while (!res.empty() && times[res.back() - 'a'] >= 1 && s[i] < res.back()) {
                cand[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            cand[s[i] - 'a'] = true;
        }
        return res;
    }
};


int main()
{
    Sloution s;
    std::cout << s.removeDuplicateLetters("bcabc") << std::endl;
}
