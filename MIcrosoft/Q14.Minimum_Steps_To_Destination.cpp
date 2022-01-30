class Solution
{
public:
    int minSteps(int D)
    {

        int steps = 0, sum = 0;

        while (sum < D)
        {
            steps++;
            sum += steps;
        }

        if (sum == D)
            return steps;
        else
        {
            int diff = sum - D;

            if (diff % 2 == 0)
                return steps;
            else
            {
                steps++;
                diff += steps;

                if (diff % 2 == 0)
                    return steps;

                else
                    return steps + 1;
            }
        }
        return 0;
    }
};