#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Find first unique character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    Solution obj;
    int index = obj.firstUniqChar(s);

    if (index != -1) {
        cout << "First Unique Character Index: " << index << endl;
        cout << "Character: " << s[index] << endl;
    } else {
        cout << "No unique character found." << endl;
    }

    return 0;
}