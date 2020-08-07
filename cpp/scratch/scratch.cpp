#include <bits/stdc++.h>

/* 240. Search a 2D Matrix II.

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.
Given target = 20, return false.
*/

struct matrix_search_ii
{
	static bool search_matrix(const std::vector<std::vector<int>>& matrix, const int target)
	{
		for (const auto& row : matrix)
		{
			if (row.empty() || row.at(0) > target)
				continue;

			if (std::binary_search(row.begin(), row.end(), target))
				return true;
		}

		return false;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::vector<int>>
	{
		{
			241, 348, 801, 822, 1204, 1438, 1917, 1954, 2030, 2253, 2547, 2723, 3147, 3259, 3635, 3963, 4251, 4440,
			4848, 5195, 5264, 5410, 5537, 5844, 6138, 6604, 6693, 6876, 7148, 7307, 7504, 7788, 7821, 7990, 8112, 8447,
			8588, 8988, 9104, 9532, 9742, 10148, 10391, 10828, 11296, 11699, 12059, 12245, 12741, 12754, 13119, 13178,
			13436, 13798, 14233, 14510, 14775, 15049, 15154, 15192, 15395, 15803, 15941, 16388, 16655, 16676, 16901,
			17220, 17686, 18077, 18239, 18666, 18973, 19323, 19356, 19464, 19743, 19933, 20030, 20183, 20228, 20515,
			20974, 21429, 21524, 21896, 22298, 22447, 22622, 23109, 23214, 23701, 24096, 24434, 24514, 24834, 25029,
			25303, 25336, 25747, 26012, 26455, 26844, 27226, 27291, 27566, 27885, 28343, 28412, 28625, 28806, 29107,
			29358, 29637, 29649, 29970, 30137, 30253, 30657, 31069, 31177, 31576, 31988, 32146, 32545, 32715, 32963,
			32971, 33096, 33530, 33603, 33721, 34091, 34449, 34630, 34886, 35129, 35211, 35659, 36136, 36429, 36734,
			36956, 37137, 37625, 37905, 37980, 38138, 38553, 38563, 38877, 38984, 39065, 39501, 39623, 40118, 40504,
			40782, 40860, 41168, 41508, 41833, 42278, 42757, 43127, 43206, 43399, 43450, 43725, 43884, 44155, 44457,
			44818, 44894
		}
	};

	auto input2 = std::vector<std::vector<int>>{{}};

	const auto result = matrix_search_ii::search_matrix(input1, 20);

	std::cout << result;
	return 0;
}
