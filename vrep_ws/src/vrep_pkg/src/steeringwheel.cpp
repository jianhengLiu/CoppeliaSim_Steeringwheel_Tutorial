//
// Created by chrisliu on 2019/9/25.
//


//#include <cmath>
#include "steeringwheel.h"
#import <math.h>

wheel_t wheel;
float delta[4]={3*PI/4, PI/4, 7*PI/4, 5*PI/4};
void fwc(float V, float theta, float Omega)
{
    for(int i=0;i<4;i++)
    {
        wheel.w_angle[i] = atan2((Omega*AFA*sin(delta[i])+V*sin(theta)) ,(Omega*AFA*cos(delta[i])+V*cos(theta)))+PI/2;
        wheel.w_vol[i] = sqrt(pow(Omega*AFA,2)+V*V+ 2*V*Omega*AFA*cos(delta[i]-theta));
    }

}
