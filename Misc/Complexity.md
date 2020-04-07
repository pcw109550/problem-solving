# Desired Time Complexity on `N`

|  size of `N` | Allowed Complexity |
|:-:|:-:|
| `N <= 11`        |  `O(N!)`              |
| `N <= 25`        |  `O(2 ** N)`          |
| `N <= 100`       |  `O(N ** 4)`          |
| `N <= 500`       |  `O(N ** 3)`          |
| `N <= 3000`      |  `O(N ** 2 * log(N))` |
| `N <= 5000`      |  `O(N ** 2)`          |
| `N <= 1000000`   |  `O(N * log(N))`      |
| `N <= 10000000`  |  `O(N)`               |
| `N >= 10000000`  |  `O(log(N))`, `O(1)`  |
