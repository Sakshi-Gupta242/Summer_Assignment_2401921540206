#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Count frequency of s1 and first window of s2
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Check first window
        if (freq1 == freq2)
            return true;

        // Slide the window
        for (int i = s1.length(); i < s2.length(); i++) {

            freq2[s2[i] - 'a']++;                    // Add new character
            freq2[s2[i - s1.length()] - 'a']--;      // Remove old character

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};

int main() {
    Solution obj;

    string s1, s2;

    cout << "Enter first string (s1): ";
    cin >> s1;

    cout << "Enter second string (s2): ";
    cin >> s2;

    if (obj.checkInclusion(s1, s2))
        cout << "Output: True" << endl;
    else
        cout << "Output: False" << endl;

    return 0;
}
