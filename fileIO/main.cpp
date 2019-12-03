#include <fstream>

int main()
{
    FILE *inf = fopen("input.txt", "rt");
    FILE *ouf = fopen("output.txt", "wt");
    int a, b;
    fscanf(inf, "%d%d", &a, &b);
    fprintf(ouf, "%d\n", a+b*b);
    return 0;
}
