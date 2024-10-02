typedef struct {
    double x;
    double y;
    double mass; 
} Pnt;

double get_distance_between_pnts (Pnt a, Pnt b);
int get_min_mass_pnt_idx (Pnt* pnts, int pnts_n);