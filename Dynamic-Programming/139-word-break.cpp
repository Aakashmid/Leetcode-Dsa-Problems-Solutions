


bool wordBreak(string s, vector<string> &wordDict)
{
    int s_size = s.length();
    vector<bool> dp(s_size + 1, false);
    dp[s_size] = true;

    for (int i = s_size; i >= 0; i--)
    {
        for (string st : wordDict)
        {
            int st_length = st.length();
            if ((i + st_length <= s_size) && (s.substr(i, st_length) == st))
            {
                dp[i] = dp[i + st_length];
            }

            if (dp[i])
                break;
        }
    }

    return dp[0];
}