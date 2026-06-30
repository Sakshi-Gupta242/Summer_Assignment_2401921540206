#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        vector<int> freqP(26, 0), freqS(26, 0);

        // Frequency count of p and first window of s
        for (int i = 0; i < p.length(); i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        // Check first window
        if (freqP == freqS)
            ans.push_back(0);

        // Slide the window
        for (int i = p.length(); i < s.length(); i++) {
            freqS[s[i] - 'a']++;
            freqS[s[i - p.length()] - 'a']--;

            if (freqP == freqS)
                ans.push_back(i - p.length() + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s, p;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string p: ";
    cin >> p;

    vector<int> result = obj.findAnagrams(s, p);

    cout << "Output: ";

    if (result.empty()) {
        cout << "No anagrams found";
    } else {
        for (int index : result) {
            cout << index << " ";
        }
    }

    cout << endl;

    return 0;
}