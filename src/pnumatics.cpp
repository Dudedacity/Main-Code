#include "main.h"

void set_doinker(bool value) {
    if (value == true) {
        doinker.set(true);
    }
    else {
        doinker.set(false);
    }
}
void opcontrol_doinker() {
    doinker.button_toggle(master.get_digital_new_press(DIGITAL_Y));
}

bool value = false;
void set_mogo_clamp(bool value) {
    if (value == true) {
        mogo_clamp.set(false);
    }
    else {
        mogo_clamp.set(true);
    }
}
void opcontrol_mogo_clamp() {
    mogo_clamp.button_toggle(master.get_digital_new_press(DIGITAL_X));

    
}