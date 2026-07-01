class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; ++i) {
            // Resize the current row to hold i + 1 elements and default them to 1
            triangle[i].resize(i + 1, 1);
            
            // Fill in the interior elements of the row
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};