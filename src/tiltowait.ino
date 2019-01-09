// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "tiltowait"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for disabling LEDs after inactivity
#include "Kaleidoscope-IdleLEDs.h"

// Support for host power management (sleep/wake)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for "Numlock" mode, which is mostly just the Numlock specific LED mode
#include "Kaleidoscope-NumPad.h"

#include "keymaps.h"
#include "Rainbow.h"
#include "Qukeys.h"

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
    LEDControl,
    IdleLEDs,
    HostPowerManagement,
    LEDOff,
    LEDRainbowWaveEffect,
    NumPad,
    MouseKeys,
    Qukeys
  );

/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

void setup() {
  Kaleidoscope.setup();

  NumPad.numPadLayer = NUMPAD;

  tiltowait::Rainbow::configure();
  tiltowait::Q::configure();
}

void loop() {
  Kaleidoscope.loop();
}
