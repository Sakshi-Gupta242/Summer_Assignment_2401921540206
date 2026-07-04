#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;

        if (p.length() > s.length())
            return result;

        vector<int> countP(26, 0), countS(26, 0);

        // Frequency of p and first window of s
        for (int i = 0; i < p.length(); i++) {
            countP[p[i] - 'a']++;
            countS[s[i] - 'a']++;
        }

        // Check first window
        if (countP == countS)
            result.push_back(0);

        // Slide the window
        for (int i = p.length(); i < s.length(); i++) {

            countS[s[i] - 'a']++;                     // Add new character
            countS[s[i - p.length()] - 'a']--;        // Remove old character

            if (countP == countS)
                result.push_back(i - p.length() + 1);
        }

        return result;
    }
};

int main() {
    string s, p;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string p: ";
    cin >> p;

    Solution obj;

    vector<int> ans = obj.findAnagrams(s, p);

    if (ans.empty()) {
        cout << "No anagrams found." << endl;
    } else {
        cout << "Starting indices: ";
        for (int index : ans) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}