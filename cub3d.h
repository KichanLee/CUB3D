#ifndef CUB3D
#define CUB3D

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "./minilibx_opengl_20191021/mlx.h"


typedef struct s_ray
{   
    double posX;
    double posY;
    double planeX;
    double planeY;
    double time;
    double oldtime;
    
}   t_ray;

#endif