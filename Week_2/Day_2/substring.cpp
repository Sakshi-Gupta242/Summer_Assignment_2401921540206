#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }

            mp[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    Solution obj;

    cout << "Length of Longest Substring Without Repeating Characters: "
         << obj.lengthOfLongestSubstring(s) << endl;

    return 0;
}
