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

#include "Rainbow.h"

namespace tiltowait {
namespace Rainbow {

void configure(void) {
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);
  LEDRainbowWaveEffect.activate();
}

}
}