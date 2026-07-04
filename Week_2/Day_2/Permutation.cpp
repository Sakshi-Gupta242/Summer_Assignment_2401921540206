#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        vector<int> count1(26, 0), count2(26, 0);

        // Frequency of s1 and first window of s2
        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // Check first window
        if (count1 == count2)
            return true;

        // Slide the window
        for (int i = s1.length(); i < s2.length(); i++) {
            count2[s2[i] - 'a']++;                   // Add new character
            count2[s2[i - s1.length()] - 'a']--;     // Remove old character

            if (count1 == count2)
                return true;
        }

        return false;
    }
};

int main() {
    string s1, s2;

    cout << "Enter first string (s1): ";
    cin >> s1;

    cout << "Enter second string (s2): ";
    cin >> s2;

    Solution obj;

    if (obj.checkInclusion(s1, s2))
        cout << "True (Permutation exists)" << endl;
    else
        cout << "False (Permutation does not exist)" << endl;

    return 0;
}