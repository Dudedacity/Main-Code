#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "main.h"

extern Drive chassis;


///
// Lift Motors and Sensors
///
inline pros::Motor lift_l(-17);
inline pros::Motor lift_r(3);
inline pros::Rotation lift_rotation(8);

/// 
// PID group setup
///
inline ez::PID liftPID{1, 0, 0, 0, "LadyBrown"};

///
// Functions
///
void lift_auto(double target);
void set_lift(int value);
void opcontrol_lift();
void lift_task();
void lift_wait();
void lift_down();