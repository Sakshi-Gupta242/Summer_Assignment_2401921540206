#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0, j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.length();
    }
};

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    Solution obj;

    if (obj.isSubsequence(s, t))
        cout << "True (s is a subsequence of t)" << endl;
    else
        cout << "False (s is not a subsequence of t)" << endl;

    return 0;
}