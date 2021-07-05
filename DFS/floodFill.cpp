/**
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
**/


class Solution {
public:
    void floodFillUtil(vector<vector<int>>& image, int sr, int sc, int prevColor, int newColor, int n, int rowSize) {
        // out of the image
        if(sr < 0 || sr >= n || sc < 0 || sc >= rowSize) return;
        if(image[sr][sc] == newColor || image[sr][sc] != prevColor) return; // flood fills applies to only those pixels having the same color as the starting pixel
        image[sr][sc] = newColor;
        floodFillUtil(image, sr + 1, sc, prevColor, newColor, n, rowSize); // flood fill to the south 
        floodFillUtil(image, sr - 1, sc, prevColor, newColor, n, rowSize); // flood fill to the north
        floodFillUtil(image, sr , sc +1, prevColor, newColor, n, rowSize); // flood fill to the east
        floodFillUtil(image, sr , sc -1, prevColor, newColor, n, rowSize);// flood fill to the west
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int rowSize = image[0].size();
        if(image[sr][sc] == newColor) return image;
        int prevColor= image[sr][sc];
        floodFillUtil(image, sr, sc, prevColor, newColor, n, rowSize);
        
        return image;
    }
};
