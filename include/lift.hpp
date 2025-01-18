#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "main.h"

extern Drive chassis;


///
// Lift Motors and Sensors
///
inline pros::Motor lift_l(1);
inline pros::Motor lift_r(-2);
inline pros::Rotation lift_rotation(3);

/// 
// PID group setup
///
inline ez::PID liftPID{0.45, 0, 0, 0, "LadyBrown"};

///
// Functions
///
void lift_auto(double target);
void set_lift(double value);
void opcontrol_lift();