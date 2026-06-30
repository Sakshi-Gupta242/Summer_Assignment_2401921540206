#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {

        stack<int> countStack;
        stack<string> stringStack;

        string currentString = "";
        int currentNum = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(currentNum);
                stringStack.push(currentString);

                currentNum = 0;
                currentString = "";
            }
            else if (ch == ']') {

                int repeat = countStack.top();
                countStack.pop();

                string temp = stringStack.top();
                stringStack.pop();

                for (int i = 0; i < repeat; i++) {
                    temp += currentString;
                }

                currentString = temp;
            }
            else {
                currentString += ch;
            }
        }

        return currentString;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter encoded string: ";
    cin >> s;

    cout << "Decoded String: " << obj.decodeString(s) << endl;

    return 0;
}