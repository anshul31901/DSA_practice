https://leetcode.com/problems/flood-fill/description/
class Solution {
public:

    void ff(vector<vector<int>>& image, int row, int col, int icolor,int fcolor){
      
        int n = image.size();
        int m = image[0].size();
      //check for edge cases that if row and column are our of bounds or initial color ==final color
      //or if the given color is not equal to initial color
        if(icolor==fcolor)return;
        if(row>=n || col>=m||row<0||col<0)return;

        if( image[row][col]!=icolor) return;

        image[row][col]=fcolor;
    //left
        ff(image,row,col-1,icolor,fcolor);
    //right
        ff(image,row,col+1,icolor,fcolor);
    //up
        ff(image,row-1,col,icolor,fcolor);
    //down
        ff(image,row+1,col,icolor,fcolor);

        return;

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m = image[0].size();
        int icolor = image[sr][sc];
        ff(image,sr,sc,icolor,color);
        return image;
    }
};
