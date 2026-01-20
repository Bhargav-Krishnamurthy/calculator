#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

# define pi 3.141592653589793238462

double sin(double x_target) {
  double h = 0.01;
  double x = 0.0, y = 0.0, z = 1.0;
  double k1, k2, k3, k4, l1, l2, l3, l4;
  double angle = x_target;
  int k = (int)(angle / (2*pi));
  angle -= k * (2*pi);
  if (angle < 0){
    angle = angle +  (2*pi);
  }
  x_target = angle;   

  while(x < x_target) {
       if(x + h > x_target){
        h = x_target - x;
      }
      k1 = h *  z;
      l1 = -h * y;

      k2 = h * (z + l1/2);
      l2 = -(h * (y + k1/2));

      k3 = h * (z + l2/2);
      l3 = - h * (y + k2/2);

      k4 = h * (z + l3);
      l4 =  -h * (y + k3);

      y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
      z = z + (l1 + 2*l2 + 2*l3 + l4)/6;

      x = x + h;
  }

  return y;
}

double cos(double x_target) {
    return sin(pi/2 - x_target);
}

double tan(double x){
	  return sin(x) / cos(x);
}

