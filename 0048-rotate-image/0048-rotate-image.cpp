class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int size = n / 2;
        for (int i = 0; i < size; i++) {
            int len = n - i - 1;
            swap(matrix[i], matrix[len]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

}
;