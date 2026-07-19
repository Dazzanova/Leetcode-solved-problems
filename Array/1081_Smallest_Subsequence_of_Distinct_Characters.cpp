class Solution {
    public:
string smallestSubsequence(string s) {
    vector<int> lastIndex(26, -1);
    for (int i = 0; i < s.size(); i++) lastIndex[s[i]-'a'] = i;

    string stack;
    vector<bool> inStack(26, false);

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (inStack[c - 'a']) continue;

        while (!stack.empty() && stack.back() > c && lastIndex[stack.back() - 'a'] > i) {
            inStack[stack.back() - 'a'] = false;
            stack.pop_back();
        }

        stack += c;
        inStack[c - 'a'] = true;
    }
    return stack;
}
};