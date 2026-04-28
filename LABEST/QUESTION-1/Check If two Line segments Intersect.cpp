class Solution {
    int orientation(int a[], int b[], int c[]) {
        long long val = (long long)(b[1] - a[1]) * (c[0] - a[0])
                      - (long long)(b[0] - a[0]) * (c[1] - a[1]);
        if (val > 0) return 1;
        if (val < 0) return -1;
        return 0;
    }

    bool onSegment(int a[], int b[], int c[]) {
        return b[0] <= max(a[0], c[0]) && b[0] >= min(a[0], c[0])
            && b[1] <= max(a[1], c[1]) && b[1] >= min(a[1], c[1]);
    }

public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int d1 = orientation(p2, q2, p1);
        int d2 = orientation(p2, q2, q1);
        int d3 = orientation(p1, q1, p2);
        int d4 = orientation(p1, q1, q2);

        if (d1 * d2 < 0 && d3 * d4 < 0)
            return "true";

        if (d1 == 0 && onSegment(p2, p1, q2)) return "true";
        if (d2 == 0 && onSegment(p2, q1, q2)) return "true";
        if (d3 == 0 && onSegment(p1, p2, q1)) return "true";
        if (d4 == 0 && onSegment(p1, q2, q1)) return "true";

        return "false";
    }
};