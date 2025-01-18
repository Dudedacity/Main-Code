#include "main.h"

void set_lift(double value) {
  lift_l.move(value);
  lift_r.move(value);
}

void lift_auto(double target) {
  liftPID.target_set(target);
  while (liftPID.exit_condition({lift_l, lift_r}, true) == ez::RUNNING) {
    // if lift hasn't met exit condition, keep going until we do
    double output = liftPID.compute(lift_rotation.get_position() / 100.0 ); // rotation measured in centidegrees
    set_lift(output);
    pros::delay(ez::util::DELAY_TIME);
  }
  // set lift velocity to zero once done
  set_lift(0);
  // hold motors in same spot
  lift_l.set_brake_mode_all(pros::E_MOTOR_BRAKE_BRAKE);
  lift_r.set_brake_mode_all(pros::E_MOTOR_BRAKE_BRAKE);
}

void opcontrol_lift() {
  // controls for lady brown control
  while (true) {
    if (master.get_digital(DIGITAL_LEFT)) {
      // if left is pressed, put lift in out-of-way position for normal intake operation
      lift_auto(10);
    }
    else if (master.get_digital(DIGITAL_RIGHT)) {
      // if right is pressed, put lift in ready position for lady brown mech use
      lift_auto(0);
    }
    else if (master.get_digital(DIGITAL_R2)) {
      // full speed up
      set_lift(127);
    }
    else if (master.get_digital(DIGITAL_L2)) {
      // full speed down
      set_lift(-127);
    }
    else {
      set_lift(0);
      
    }
    // compute lift speed for PID algorithm
    set_lift(liftPID.compute(lift_rotation.get_position()));
  }
}