#include "main.h"
using namespace ez;

extern Drive chassis;

///
// Ports and Devices
///
inline Piston doinker('g', false);
inline Piston mogo_clamp('h', true);

///
// Functions
///
void set_doinker(bool value);
void opcontrol_doinker();

void set_mogo_clamp(bool value);
void opcontrol_mogo_clamp();