#include <vector>
using namespace std;

/**
 * Given a 32 - bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 * Input: 123
 * Output: 321
 *
 * Example 2:
 * Input: -123
 * Output: -321
 *
 * Example 3:
 * Input: 120
 * Output: 21
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

class Solution
{
public:
	int reverse(int x)
	{
		int sign, s = 0;
		sign = x > 0;
		x = x > 0 ? x : -x;
		bool flag = true;
		while (x > 0)
		{
			int i = x % 10;
			x /= 10;
			if (flag)
				flag = false;
			else
			{
				int j = s * 10;
				if (j / 10 != s)
					return 0;
				else s = j;
			}
			s += i;
			if (s < 0)
				return 0;
		}
		return sign ? s : -s;
	}
};