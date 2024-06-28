/*
 * Thoughts:
 * to find the maximum area of the rectangle, we can see the area as the histograms.
 * first we look at the first row and consider it as a one level histogram,
 * and then look at the first and second row and consider it as a two level histogram, as so on.
 * As soon as we find those maximum area in each histograms, we can get the max area of the rectangle.
 *
 * And we also need to build a height matrix to record the height of each histograms using dynamic programming.
 */


class Solution {
    
    int[][] dpHeight;

    public void init(char[][] matrix) {
        dpHeight = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; ++i) {
            for (int j = 0; j < matrix[0].length; ++j) {
                if (i == 0) {
                    dpHeight[i][j] = matrix[i][j] - '0';
                } else {
                    if ((matrix[i][j] - '0') != 0)
                        dpHeight[i][j] = (matrix[i][j] - '0') + dpHeight[i - 1][j];
                    else
                        dpHeight[i][j] = 0;
                }
            }
        }
    }

    public int largestRectangleArea(int[] heights) {
        int result = 0;
        for (int i = 0; i < heights.length; ++i) {
            int lptr = i - 1, rptr = i + 1;
            while (lptr >= 0 && heights[lptr] >= heights[i])
                lptr--;
            while (rptr < heights.length && heights[rptr] >= heights[i])
                rptr++;
            int tmp = (rptr - lptr - 1) * heights[i];
            result = tmp > result ? tmp : result;
        }
        return result;
    }

    public int maximalRectangle(char[][] matrix) {
        init(matrix);
        int baseline = 0;
        int max = 0;
        for (baseline = 0; baseline < matrix.length; ++baseline) {
            int result = largestRectangleArea(dpHeight[baseline]);
            System.out.println("dpHeight[baseline]: " + Arrays.toString(dpHeight[baseline]));
            System.out.println("baseline: " + baseline);
            System.out.println("result: " + result);
            max = result > max ? result : max;
        }
        return max;
    }
}
