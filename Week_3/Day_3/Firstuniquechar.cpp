#include <iostream>
#include <string>
using namespace std;

// Function to find first unique character
int firstUniqChar(string s) {

    int freq[26] = {0};

    // Count frequency
    for (char ch : s) {
        freq[ch - 'a']++;
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

    cout << "Enter a string: ";
    cin >> s;

    int index = firstUniqChar(s);

    if (index != -1)
        cout << "First Unique Character Index: " << index << endl;
    else
        cout << "No Unique Character Found" << endl;

    return 0;
}