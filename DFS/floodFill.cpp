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
    void dfs(vector<vector<int>>& image, int sr, int sc, int prevColor, int newColor, int r, int c)  {
        if(sr < 0 || sr >= r || sc < 0 || sc >= c || image[sr][sc]!=prevColor) return;
        if(image[sr][sc] == newColor) return;
        image[sr][sc] = newColor;
        vector<pair<int, int>> dirs = {{0,1}, {1, 0}, {-1,0}, {0, -1}};
        for(int i = 0; i < 4; ++i) {
            int ir = sr + dirs[i].first;
            int ic = sc + dirs[i].second;
            dfs(image, ir, ic, prevColor, newColor, r, c);
        }
        return;
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevColor = image[sr][sc];
        dfs(image, sr, sc, prevColor, newColor, image.size(), image[0].size());
        return image;
    }
};
