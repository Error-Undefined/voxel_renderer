#ifndef CAMERA_H
#define CAMERA_H

struct camera
{
    int height;
    int horizon;
    int distance;
    int scale_height;
    float speed;
    float angular_speed;

    s_point_i center;
};
typedef struct camera s_camera;

#endif
