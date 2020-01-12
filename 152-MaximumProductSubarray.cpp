#include <algorithm>
#include <vector>
using namespace std;

/**
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * Example 1:
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 * Example 2:
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int max = nums[0];
		int neg, pos;
		pos = 0;
		neg = 0;
		for (auto &i : nums)
		{
			if (i >= 0)
			{
				pos = pos ? pos * i : i;
				neg = neg ? neg * i : 0;
				if (pos > max)
					max = pos;
			}
			else
			{
				int tmp = pos;
				pos = neg ? neg * i : 0;
				if (neg && pos > max)
					max = pos;
				neg = tmp ? tmp * i : i;
			}
		}
		return max;
	}
};