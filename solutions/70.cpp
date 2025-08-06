#include <cstdio>

int main() {
    int n = 5;
    int res = n;

    if (n <= 2)
        return n;

    int first = 1, second = 2;

    for (int i = 3; i <= n; i++) {
        res = first + second;
        first = second;
        second = res;
    }

    return res;
}