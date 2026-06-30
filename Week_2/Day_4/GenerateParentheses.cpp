#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(int open, int close, string current, vector<string>& ans) {

        if (open == 0 && close == 0) {
            ans.push_back(current);
            return;
        }

        if (open > 0) {
            solve(open - 1, close, current + "(", ans);
        }

        if (close > open) {
            solve(open, close - 1, current + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        solve(n, n, "", ans);
        return ans;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<string> result = obj.generateParenthesis(n);

    cout << "Output:" << endl;

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}