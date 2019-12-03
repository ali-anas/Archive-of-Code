/* USING STREAMS

#include <fstream>
int main()
{
    std::ifstream infile("input.txt");
    std::ofstream oufile("output.txt");
    int a,b;
    infile >> a >> b;
    oufile << a+b << std::endl;
    return 0;
}
*/

/* USING C FILES - FILE POINTER - faster method
  */

#include <cstdio>

int main()
{
    FILE *inf = fopen("input.txt", "rt");
    FILE *ouf = fopen("output.txt", "wt");
    int a, b;
    fscanf(inf, "%d%d",&a,&b);
    fprintf(ouf,"%d\n",a+b);
    return 0;
}
