#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n = s.length();

        // Try every possible substring length
        for (int len = 1; len <= n / 2; len++) {

            if (n % len != 0)
                continue;

            string pattern = s.substr(0, len);
            string temp = "";

            int repeat = n / len;

            for (int i = 0; i < repeat; i++) {
                temp += pattern;
            }

            if (temp == s)
                return true;
        }

        return false;
    }
};

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    Solution obj;

    if (obj.repeatedSubstringPattern(s))
        cout << "True (String is formed by repeating a substring)" << endl;
    else
        cout << "False (String is not formed by repeating a substring)" << endl;

    return 0;
}