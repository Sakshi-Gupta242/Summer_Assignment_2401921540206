#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};

        // Count characters in magazine
        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        // Check if ransomNote can be formed
        for (char ch : ransomNote) {
            if (freq[ch - 'a'] == 0) {
                return false;
            }
            freq[ch - 'a']--;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string ransomNote, magazine;

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine: ";
    cin >> magazine;

    if (obj.canConstruct(ransomNote, magazine))
        cout << "true";
    else
        cout << "false";

    return 0;
}