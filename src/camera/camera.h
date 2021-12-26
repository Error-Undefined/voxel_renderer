#ifndef CAMERA_H
#define CAMERA_H

struct camera
{
    int height;
    int horizon;
    int distance;
    float speed;
    float angular_speed;
};
typedef struct camera s_camera;

#endif
