#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    Solution obj;

    if (obj.isAnagram(s, t))
        cout << "True (Strings are Anagrams)" << endl;
    else
        cout << "False (Strings are not Anagrams)" << endl;

    return 0;
}