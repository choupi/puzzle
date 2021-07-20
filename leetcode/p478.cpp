class Solution {
public:
    double r;
    double x;
    double y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
        srand(time(NULL));
    }
    
    vector<double> randPoint() {
        double x0 = r * (rand()/(double)RAND_MAX);
        double y0 = r * (rand()/(double)RAND_MAX);
        while (x0*x0 + y0*y0 > r*r) {
            x0 = r * (rand()/(double)RAND_MAX);
            y0 = r * (rand()/(double)RAND_MAX);
        }
        int sx = rand()%2==0?1:-1;
        int sy = rand()%2==0?1:-1;
        vector<double> res({x+sx*x0, y+sy*y0});
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
