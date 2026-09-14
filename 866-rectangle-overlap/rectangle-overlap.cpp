class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check horizontal projection overlap: max(x1, x3) < min(x2, x4)
        bool x_overlaps = max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]);

        // Check vertical projection overlap: max(y1, y3) < min(y2, y4)
        bool y_overlaps = max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);

        return x_overlaps && y_overlaps;
    }
};