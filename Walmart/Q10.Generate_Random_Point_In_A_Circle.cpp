class Solution
{
public:
    double R, X, Y;
    Solution(double radius, double x_center, double y_center)
    {
        R = radius;
        X = x_center;
        Y = y_center;
    }

    double random()
    {
        return (double)rand() / RAND_MAX;
    }

    vector<double> randPoint()
    {

        vector<double> random_pt(2);
        double len = sqrt(random()) * R;
        double deg = 2 * M_PI * random();
        random_pt[0] = X + len * cos(deg);
        random_pt[1] = Y + len * sin(deg);

        return random_pt;
    }
};
