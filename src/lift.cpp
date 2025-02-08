#include "main.h"

void set_lift(int value) {
  lift_l.move(value);
  lift_r.move(value);
}

void lift_task() {
  pros::delay(2000);
  while (true) {
    // compute lift speed for PID algorithm
    set_lift(liftPID.compute(lift_rotation.get_position() / 100.0));

    pros::delay(ez::util::DELAY_TIME);
  }
} pros::Task lift_task_task(lift_task);

void lift_wait() {
  while (liftPID.exit_condition({lift_l, lift_r}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
  
}

int state = 0; // 0 is down, 1 is primed, 2 is up
void opcontrol_lift() {

  // neutral wall stake
  if (master.get_digital_new_press(DIGITAL_LEFT)) {
    if (state == 0) {
      liftPID.target_set(40);
      master.rumble("..");
      state = 1;
    }
    else if (state == 1) {
      liftPID.target_set(130);
      master.rumble("...");
      state = 2;
    }
    else if (state == 2) {
      liftPID.target_set(0);
      master.rumble(".");
      state = 0;
    }
  }

  // alliance wall stake
  if (master.get_digital_new_press(DIGITAL_RIGHT)) {
    if (state == 0) {
      liftPID.target_set(40);
      master.rumble("..");
      state = 1;
    }
    else if (state == 1) {
      liftPID.target_set(170);
      master.rumble("...");
      state = 2;
    }
    else if (state == 2) {
      liftPID.target_set(0);
      master.rumble(".");
      state = 0;
    }
  }
  //lift_l.set
}