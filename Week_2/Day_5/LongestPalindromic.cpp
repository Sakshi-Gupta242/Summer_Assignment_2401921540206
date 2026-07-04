#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution obj;
    cout << "Longest Palindromic Substring: " << obj.longestPalindrome(s) << endl;

    return 0;
}