#include <bits/stdc++.h>
#include <array>

/*733. Flood Fill.

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

*/

class image_fill
{
public:

	/// <summary>
	/// flood fill
	///
	/// standard dfs search procedure via recursion
	/// 
	/// </summary>
	/// <param name="image">img</param>
	/// <param name="row">row</param>
	/// <param name="col">col</param>
	/// <param name="new_color">old col</param>
	/// <param name="old_color">new col</param>
	static void fill( std::vector<std::vector<int>>& image,
		const int row, const int col, 
		const int new_color, const int old_color )
	{
		const int num_rows = image.size();
		const int num_cols = image[ 0 ].size();
		
		if( row < 0 || row >= num_rows || 
			col < 0 || col >= num_cols ) return;

		if( image[ row ][ col ] == new_color ||
			image[ row ][ col ] != old_color ) return;
		
		image[ row ][ col ] = new_color;
		
		fill( image, row - 1, col, new_color, old_color );
		fill( image, row + 1, col, new_color, old_color );
		fill( image, row, col - 1, new_color, old_color );
		fill( image, row, col + 1, new_color, old_color );
	}

	/// <summary>
	/// flood fill implemented via dfs
	/// </summary>
	/// <param name="image">image to fill</param>
	/// <param name="sr">starting row</param>
	/// <param name="sc">starting col</param>
	/// <param name="new_color">new col</param>
	/// <returns>flood filled image</returns>
	static std::vector<std::vector<int>> flood_fill( std::vector<std::vector<int>>& image, 
		const int sr, const int sc, const int new_color )
	{
		if( image.empty() || image[ 0 ].empty() ) return image;

		const auto old_color = image[ sr ][ sc ];
		
		fill( image, sr, sc, new_color, old_color );

		return image;
	}
};

auto main() -> int
{
	auto input = std::vector<std::vector<int>>
	{
		{1, 1, 1},
		{1, 1, 0},
		{1, 0, 1}
	};

	const auto result = image_fill::flood_fill( input, 1, 1, 2 );
	
	return 0;
}