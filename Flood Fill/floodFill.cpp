#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* recursive depth-first search*/

void    fill( vector<vector<int>> &image, int r, int c, int color, int old_color)
    {
        if ( r < 0 || r >= image.size() || c < 0 || c >= image[0].size() ) return ;
        if ( image[r][c] != old_color ) return ;
        if ( image[r][c] == color ) return ;
        image[r][c] = color;
        fill(image, r + 1, c, color, old_color);
        fill(image, r - 1, c, color, old_color);
        fill(image, r, c + 1, color, old_color);
        fill(image, r, c - 1, color, old_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return (image);
        fill(image, sr, sc, color, image[sr][sc]);
        return (image);
    }        

/***************************************************/

/* iterative depth-first search*/
 struct pos
    {
        int r;
        int c;
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return (image);
        
        queue<pos> q;
        int oldColor = image[sr][sc];
        int maxRows = image.size();
        int maxCols = image[0].size();
        q.push({.r = sr, .c = sc});
        while (!q.empty())
        {
            pos current = q.front();
            q.pop();
            if (current.r < 0 || current.r >= maxRows || current.c < 0 || current.c >= maxCols) continue ;
            if (image[current.r][current.c] != oldColor) continue ;
            if (image[current.r][current.c] == color) continue ;
            image[current.r][current.c] = color;
            q.push({.r = current.r + 1, .c = current.c});
            q.push({.r = current.r - 1, .c = current.c});
            q.push({.r = current.r, .c = current.c + 1});
            q.push({.r = current.r, .c = current.c - 1});
        }
        return (image);
    }        