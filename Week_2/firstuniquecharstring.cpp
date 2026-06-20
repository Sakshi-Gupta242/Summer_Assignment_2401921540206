#include <iostream>
#include <vector>
using namespace std;

int firstUniqChar(string s) {

    vector<int> freq(26, 0);

    // Count frequency of each character
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    // Find first unique character
    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i] - 'a'] == 1)
            return i;
    }

    return -1;
}

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    int ans = firstUniqChar(s);

    cout << "First Unique Character Index: " << ans << endl;

    return 0;
}