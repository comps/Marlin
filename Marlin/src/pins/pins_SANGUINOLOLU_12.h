/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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
 *
 */

/**
 * Sanguinololu V1.2 pin assignments
 *
 * Applies to the following boards:
 *
 *  AZTEEG_X1
 *  MELZI
 *  MELZI_CREALITY
 *  MELZI_MAKR3D
 *  SANGUINOLOLU_12
 *  STB_11
 */

#ifndef BOARD_NAME
  #define BOARD_NAME "Sanguinololu 1.2"
#endif

#define SANGUINOLOLU_V_1_2
#include "pins_SANGUINOLOLU_11.h"

// v1.3a below

/*
 * BIG F-ING WARNING - PINOUTS YOU FIND ON WEB ARE WRONG IN MARLIN
 *
 * Images like
 *   http://i.imgur.com/ayagBbM.png
 * show the digital pins following the analog pin numbering, but
 * Marlin's digital pins follow the physical pins.
 *
 * Ie. Marlin's numbering is
 *   A0 -> digital 31
 *   A1 -> digital 30
 *   ...
 *   A7 -> digital 24
 *
 * Thus, the M43 output is correct.
 */

// disable unused features to avoid conflicts
#undef CASE_LIGHT_PIN
#undef SDSS

// unused on pin header
#ifndef FAN_PIN
  #define FAN_PIN 4
#endif

// TMC2130 SPI
#define X_CS_PIN 29
#define Y_CS_PIN 30
#define E0_CS_PIN 31
