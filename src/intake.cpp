#include "main.h"

///
// Intake Spinner
// - Value is speed of the intake from -127 to 127
///
void intake_spin(int value) {
    intakeL.move(value);
    intakeR.move(value);
}

///
// Intake until Ring is Detected in Robot
// - Keeps the intake spinning until a ring is detected by the distance sensor in the bot
///

void intake_single_ring() {
    intake_spin(127);
    while (true) {
        if (intakeMotors_distance.get() > 10) {
            intake_spin(0);
        }
        pros::delay(ez::util::DELAY_TIME);
    }
}

///
// Operator Control for Intake
///
void opcontrol_intake() {
    if (master.get_digital(DIGITAL_R1)) {
        intake_spin(127.0*INTAKE_SPEED);
    }
    else if (master.get_digital(DIGITAL_L1)) {
        intake_spin(-127.0*INTAKE_SPEED);
    }
    else {
        intake_spin(0);
    }
}