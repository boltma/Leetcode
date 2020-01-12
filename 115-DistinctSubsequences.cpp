#include <string>
using namespace std;

/**
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Example 1:
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 *
 * Example 2:
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 *   ^  ^^
 * babgbag
 *     ^^^
 */

class Solution
{
public:
	int numDistinct(string s, string t)
	{
		int m = s.length(), n = t.length();
		if (!m || !n)
			return 0;
		int dp[m][n];
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (!i && !j)
					dp[i][j] = s[i] == t[j] ? 1 : 0;
				else if (!j)
					dp[i][j] = dp[i - 1][j] + (s[i] == t[j] ? 1 : 0);
				else if (!i)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i - 1][j] + (s[i] == t[j] ? dp[i - 1][j - 1] : 0);
			}
		return dp[m - 1][n - 1];
	}
};