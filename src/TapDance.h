// -*- mode: c++ -*-
// <DESCRIPTION GOES HERE>
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

#pragma once

#include <Kaleidoscope-TapDance.h>

enum { BACK, FORWARD };

#define TD_BACK     TD(BACK)
#define TD_FORWARD  TD(FORWARD)

void tapDanceAction(uint8_t tap_dance_index, byte row, byte col,
                    uint8_t tap_count,
                    kaleidoscope::TapDance::ActionType tap_dance_action);