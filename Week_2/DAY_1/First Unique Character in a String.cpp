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

        // Find the first unique character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = obj.firstUniqChar(s);

    cout << "Index of first unique character: " << result << endl;

    return 0;
}