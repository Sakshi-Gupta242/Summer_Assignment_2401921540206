#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int read = 0;

        while (read < n) {
            char current = chars[read];
            int count = 0;

            while (read < n && chars[read] == current) {
                read++;
                count++;
            }

            chars[write++] = current;

            if (count > 1) {
                string s = to_string(count);
                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    Solution obj;
    int len = obj.compress(chars);

    cout << "Compressed length: " << len << endl;
    cout << "Compressed array: ";

    for (int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    return 0;
}