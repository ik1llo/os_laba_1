#include <math.h>

#include "pnt.h"

double get_distance_between_pnts (Pnt a, Pnt b) { 
    double pow_x_rst = pow(a.x - b.x, 2);
    double pow_y_rst = pow(a.y - b.y, 2);

    return sqrt(pow_x_rst + pow_y_rst);
}

int get_min_mass_pnt_idx (Pnt* pnts, int pnts_n) {
    int idx = 0;

    for (int k = 1; k < pnts_n; k++)
        if (pnts[k].mass < pnts[idx].mass)
            idx = k;

    return idx;
}