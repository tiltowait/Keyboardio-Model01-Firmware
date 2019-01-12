/* -*- mode: c++ -*-
 * Model01-Sketch -- tiltowait's Model01 Sketch
 * Copyright (C) 2019 Jared Lindsay
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "00-Config.h"  // Defines conditional compilation options

// Kaleidoscope core and chosen plugins
#include "Kaleidoscope.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-IdleLEDs.h"
#include "Kaleidoscope-NumPad.h"

// Headers particular to this sketch
#include "keymaps.h"
#include "Rainbow.h"
#include "Qukeys.h"

// Conditionally included plugins
#if WITH_PROPER_SHIFTING
#include "ProperShifting.h"
#endif

#if WITH_HOST_POWER_MANAGEMENT
#include "Kaleidoscope-HostPowerManagement.h"

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
#endif

// The order here can be important. For instance, LED effects are added in the
// order listed. Also, plugins can consume keystrokes, making them unavailable
// to others. For this reason, IdleLEDs needs to be first.
KALEIDOSCOPE_INIT_PLUGINS(
  LEDControl
  , IdleLEDs
#if WITH_PROPER_SHIFTING
  , ProperShifting
#endif
#if WITH_HOST_POWER_MANAGEMENT
  , HostPowerManagement
#endif
  , LEDOff
  , LEDRainbowWaveEffect
  , NumPad
  , MouseKeys
  , Qukeys
);

// The 'setup' function is one of the two standard Arduino sketch functions.
// It's called when your keyboard first powers up. This is where you set up
// Kaleidoscope and any plugins.
void setup() {
  Kaleidoscope.setup();

  NumPad.numPadLayer = NUMPAD;

  tiltowait::Rainbow::configure();
  tiltowait::Q::configure();
}

void loop() {
  Kaleidoscope.loop();
}
