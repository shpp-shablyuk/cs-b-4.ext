
#include <iostream>
#include "gwindow.h"
#include <cmath>
using namespace std;

const double SIZE = 100;
const int ORDER = 7;
const double REDUCTION_RATIO = 0.7;
const string TRUNC_COLOR = "#926239";

void drawTree(GWindow & gw, GPoint pt, double r, double theta, int order);

int main() {
    GWindow gw(800, 800);
    gw.setColor(TRUNC_COLOR);

    double cx = gw.getWidth() / 2;
    double yWindowHeight = gw.getHeight();

    GPoint pt(cx, yWindowHeight * 0.7);
    gw.drawLine(cx, yWindowHeight, cx, yWindowHeight * 0.7);
    drawTree(gw, pt, SIZE, 90, ORDER);

	return 0;
}

void drawTree(GWindow & gw, GPoint pt, double r, double theta, int order) {
    if (order != 0) {
        if (order < 4) {
            gw.setColor("GREEN");
        } else {
            gw.setColor(TRUNC_COLOR);
        }
        GPoint pt1 = gw.drawPolarLine(pt, r, theta - 45);
        GPoint pt2 = gw.drawPolarLine(pt, r, theta);
        GPoint pt3 = gw.drawPolarLine(pt, r, theta + 45);

        drawTree(gw, pt1, r * REDUCTION_RATIO, theta - 45, order - 1);
        drawTree(gw, pt2, r * REDUCTION_RATIO, theta, order - 1);
        drawTree(gw, pt3, r * REDUCTION_RATIO, theta + 45, order - 1);
    }
}
