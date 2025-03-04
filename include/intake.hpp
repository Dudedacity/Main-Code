#include "main.h"

using namespace pros;

extern Drive chassis;

///
// Motors and Sensors
///
inline Motor intakeL(6);
inline Motor intakeR(-20);
inline Distance intakeMotors_distance(15);

///
// Constants
///
const int INTAKE_SPEED = 100; //percent

///
// Functions
///
void intake_spin(int value);
void intake_single_ring();
void opcontrol_intake();