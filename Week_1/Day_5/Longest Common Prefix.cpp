#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix.pop_back();

            if (prefix.empty()) {
                return "";
            }
        }
    }

    return prefix;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << "Longest Common Prefix: " << longestCommonPrefix(strs);

    return 0;
}