#include <bits/stdc++.h>

using namespace std;

int main() {
	/* (if exists the files bendin.txt
	 * and bendout.txt then uncomment)
	 * takes input from bendin.txt
	 * writes output to bendout.txt
	 */
    // freopen("bendin.txt","r",stdin);
    // freopen("bendout.txt","w",stdout);

    /* input first rectangle
     * (x1,y1) , (x2, y2)
     */
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    /* input second rectangle
     * (x3, y3) , (x4, y4)
     */
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    /* calculate area for
     * rectangle1 and rectangle2
     */
    int area1 = (x2 - x1) * (y2 - y1);
    int area2 = (x4 - x1) * (y4 - y3);

    /* check if intersection exists between rectangles
     * compute left, right, top, bottom
     * of rectangle formed by intersection
     */
    int left = max(x1, x3);
    int right = min(x2, x4);

    int bottom = max(y1, y3);
    int top = min(y2, y4);

    int areaIntersection = 0;

    // condition if intersection exists
    if(left < right && bottom < top) {
    	areaIntersection = (right - left) * (top - bottom);
    }

    cout << area1 + area2 - areaIntersection << endl;
    
    return 0;
}
