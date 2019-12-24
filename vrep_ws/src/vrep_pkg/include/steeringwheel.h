//
// Created by chrisliu on 2019/9/25.
//

#ifndef VREP_PKG_FWC_H
#define VREP_PKG_FWC_H
struct wheel_t{
    float w_vol[4];
    float w_angle[4];
};
const float PI = 3.1415;
const int AFA = 30;         //轮子到底盘中心距离
extern wheel_t wheel;
void fwc(float V, float theta, float Omega);
#endif //VREP_PKG_FWC_H
