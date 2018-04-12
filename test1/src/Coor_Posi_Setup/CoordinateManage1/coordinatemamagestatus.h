#ifndef COORDINATEMAMAGESTATUS_H
#define COORDINATEMAMAGESTATUS_H

#define DELAY_TIME1 5000
#define DELAY_TIME2 3000

typedef enum
{
    NO_PLANE = -1,
    XY_PLANE = 0,
    YZ_PLANE,
    ZX_PLANE
}CMPlaneSelect;//CM: coordinate manage

extern  bool Interface_Enable_Status;

extern bool buf[3][10];
extern bool buf_coor[3];

#endif // COORDINATEMAMAGESTATUS_H
