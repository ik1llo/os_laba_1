#include <stdio.h>
#include <stdlib.h>

#include "pnt.h"

int main () {
    int pnts_n;

    printf("[points count]: ");
    scanf("%d", &pnts_n);

    Pnt* pnts = (Pnt*) malloc(pnts_n * sizeof(Pnt));
    for (int k = 0; k < pnts_n; k++) {
        printf("[x & y & mass for point #%d]: ", k + 1);
        scanf("%lf %lf %lf", &pnts[k].x, &pnts[k].y, &pnts[k].mass);
    }

    printf("\n");
    while (pnts_n > 1) {
        int idx = get_min_mass_pnt_idx (pnts, pnts_n);

        int min_distance_idx = -1;
        double min_distance_value = __DBL_MAX__;

        for (int k = 0; k < pnts_n; k++) {
            if (k != idx) {
                double distance = get_distance_between_pnts (pnts[idx], pnts[k]);
                if (distance < min_distance_value) {
                    min_distance_value = distance;
                    min_distance_idx = k;
                }
            }
        }

        printf(
            "Point with a mass of %.2f has vanished and transferred its mass to the point with a mass of %.2f\n", 
            pnts[idx].mass,
            pnts[min_distance_idx].mass
        );

        pnts[min_distance_idx].mass += pnts[idx].mass;

        pnts[idx] = pnts[pnts_n - 1];
        pnts_n--;
    }
    printf("\n");
 
    printf(
        "Remaining point: (x: %.2f, y: %.2f, mass: %.2f)\n", 
        pnts[0].x,
        pnts[0].y, 
        pnts[0].mass
    );

    free(pnts);

    return 0;
}  