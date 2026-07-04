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
    string ransomNote, magazine;

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine: ";
    cin >> magazine;

    Solution obj;

    if (obj.canConstruct(ransomNote, magazine))
        cout << "True (Ransom note can be constructed)" << endl;
    else
        cout << "False (Ransom note cannot be constructed)" << endl;

    return 0;
}