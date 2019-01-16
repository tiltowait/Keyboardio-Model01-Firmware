// -*- mode: c++ -*-
// Model01-Sketch -- tiltowait's Model01 Sketch
// Copyright (C) 2019 Jared Lindsay
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "TapDance.h"

void tapDanceAction(uint8_t tap_dance_index, byte row, byte col,
                    uint8_t tap_count,
                    kaleidoscope::TapDance::ActionType tap_dance_action) {
  switch (tap_dance_index) {
  // 1. Left control
  // 2. Shift+[
  case BACK:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_LeftControl,
                              LGUI(Key_LeftBracket));
  // 1. Right control
  // 2. Shift+]
  case FORWARD:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_RightControl,
                              LGUI(Key_RightBracket));
  }
}