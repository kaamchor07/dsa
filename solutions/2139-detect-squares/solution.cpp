class DetectSquares {
private:
    unordered_map<int, int> pointCount;
    vector<pair<int, int>> points;
public:
    DetectSquares() {}
    void add(vector<int> point) {
        int key = point[0] * 1001 + point[1];
        pointCount[key]++;
        points.push_back({point[0], point[1]});
    }

    int count(vector<int> point) {
        int x0 = point[0], y0 = point[1];
        int totalSquares = 0;

        for (const auto& [x1, y1] : points) {
            int dx = abs(x1 - x0);
            int dy = abs(y1 - y0);
            if (dx > 0 && dx == dy) {
                int p2Key = x0 * 1001 + y1; // Point (x0, y1)
                int p3Key = x1 * 1001 + y0; // Point (x1, y0)

                if (pointCount.count(p2Key) && pointCount.count(p3Key)) {
                    totalSquares += pointCount[p2Key] * pointCount[p3Key];
                }
            }
        }

        return totalSquares;
    }
};
