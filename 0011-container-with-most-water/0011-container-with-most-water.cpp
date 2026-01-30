class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0;
        int right = height.size() - 1;
        int maxAreaValue = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int width = right - left;
            int area = h * width;
            maxAreaValue = max(maxAreaValue, area);

            // Move the pointer of the smaller line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxAreaValue;
    }
};