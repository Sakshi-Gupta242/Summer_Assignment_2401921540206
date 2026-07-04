#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == m)
                return i;
        }

        return -1;
    }
};

int main() {
    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    Solution obj;

    int index = obj.strStr(haystack, needle);

    if (index != -1)
        cout << "First occurrence found at index: " << index << endl;
    else
        cout << "Substring not found (-1)" << endl;

    return 0;
}