// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
    void generateParentheses(int n, int open, int close, string s, vector<string> &ans)
    {
        if (open == n && close == n)
        {
            ans.push_back(s);
            return;
        }
        if (open < n)
        {
            generateParentheses(n, open + 1, close, s + "(", ans);
        }
        if (close < open)
        {
            generateParentheses(n, open, close + 1, s + ")", ans);
        }
    }

    vector<string> AllParenthesis(int n)
    {

        vector<string> ans;
        string s = "";
        generateParentheses(n, 0, 0, s, ans);
        return ans;
    }
};