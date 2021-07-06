#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t, n, m, x, y, steps, max_diff, xmax;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n >> m;
        max_diff = 0, xmax = 0;
        for (int j = 0; j < m; j++)
        {
            std::cin >> x >> y;
            if (xmax < x) xmax = x;
            if (max_diff < x - y) max_diff = x - y;
        }
        n -= xmax;
        steps = 1;
        if (max_diff <= 0 && n > 0)  std::cout << "BRAK METOD" << std::endl;
        else if (n <= 0) std::cout << steps << std::endl;
        else
        {
            if (n % max_diff == 0) steps += (n / max_diff);
            else steps += (n / max_diff) + 1;
            std::cout << steps << std::endl;
        }
    }
    return 0;
}
