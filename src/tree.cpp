
#include <iostream>
#include "gwindow.h"
#include <cmath>
using namespace std;

const int ORDER = 6;
const double SIZE = 100;
const double REDUCTION_RATIO = 0.6;
const int WINDOW_SIZE = 600;
const int TILT_BRANCH = 45;
const int TILT_TREE = 90; //  tilt a tree trunk

void drawTree(GWindow & gw, GPoint pt, double r, double theta, int order);

int main() {
    GWindow gw(WINDOW_SIZE, WINDOW_SIZE);

    double cx = gw.getWidth() / 2;
    double yWindowHeight = gw.getHeight();

    GPoint pt(cx, yWindowHeight * REDUCTION_RATIO);
    //  to draw a tree trunk
    gw.drawLine(cx, yWindowHeight, cx, yWindowHeight * REDUCTION_RATIO);
    drawTree(gw, pt, SIZE, TILT_TREE, ORDER);

	return 0;
}

void drawTree(GWindow & gw, GPoint pt, double r, double theta, int order) {
    if (order != 0) {
        GPoint pt1 = gw.drawPolarLine(pt, r, theta - TILT_BRANCH);
        drawTree(gw, pt1, r * REDUCTION_RATIO, theta - TILT_BRANCH, order - 1);

        GPoint pt3 = gw.drawPolarLine(pt, r, theta + TILT_BRANCH);
        drawTree(gw, pt3, r * REDUCTION_RATIO, theta + TILT_BRANCH, order - 1);

    }
}
