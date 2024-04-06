/* Thoughts:
 *
 * for each element in array, calculate the rectangle area that use the element height to be the height
 * and find the largest
 */

import java.util.Stack;

class Solution {

    private int nsr[] = new int[100000];
	private int nsl[] = new int[100000];

    public void getNextSmallerRightIdx(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        for (int i = heights.length - 1; i >= 0; --i) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                nsr[i] = heights.length;
            } else {
                nsr[i] = stack.peek();
            }
            stack.push(i);
        }
    }

    public void getNextSmallerLeftIdx(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < heights.length; i++){
            while(!stack.isEmpty() && heights[stack.peek()] >= heights[i] ){
                stack.pop();
            }
            if(stack.isEmpty()){
                nsl[i]= -1;
            }else{
                nsl[i] = stack.peek();
            }
            stack.push(i);
        }
    }

    public int largestRectangleArea(int[] heights) {
        int largestArea = 0;
        for (int i = 0; i < heights.length; ++i) {
            getNextSmallerLeftIdx(heights);
            getNextSmallerRightIdx(heights);
            largestArea = (heights[i] * (nsr[i] - nsl[i] - 1) > largestArea) ? (heights[i] * (nsr[i] - nsl[i] - 1)) : largestArea;
        }
        return largestArea;
    }

}
