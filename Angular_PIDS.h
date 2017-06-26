  
#ifndef ESC_H_INCLUDED
#define ESC_H_INCLUDED
#define Kppr 1.4
#define Kipr 0.05
#define Kdpr 15
#define Kpy 4
#define Kiy 0.02
#define Kdy 0
  double u1 ( double z );
  double u2 (double pitch_desired);
  double u3 (double roll_desired);
  double u4 (double yaw_desired);
  double U_time (double desired_distance, double angle ) ;
    #endif
