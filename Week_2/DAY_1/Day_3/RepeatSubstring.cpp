#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

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
    Solution obj;
    string s;

    cout << "Enter string: ";
    cin >> s;

    if (obj.repeatedSubstringPattern(s))
        cout << "Output: True" << endl;
    else
        cout << "Output: False" << endl;

    return 0;
}