/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define BOARD_INFO_NAME "BTT SKR V1.3"

//
// Trinamic Stallguard pins
//
#define X_DIAG_PIN                         P1_29  // X-
#define Y_DIAG_PIN                         P1_27  // Y-
#define Z_DIAG_PIN                         P1_25  // Z-
#define E0_DIAG_PIN                        P1_28  // X+
#define E1_DIAG_PIN                        P1_26  // Y+

//
// Limit Switches
//
#ifdef X_STALL_SENSITIVITY
  #define X_STOP_PIN                  X_DIAG_PIN
  #if X_HOME_DIR < 0
    #define X_MAX_PIN                      P1_28  // X+
  #else
    #define X_MIN_PIN                      P1_28  // X+
  #endif
#else
  #define X_MIN_PIN                        P1_29  // X-
  #define X_MAX_PIN                        P1_28  // X+
#endif

#ifdef Y_STALL_SENSITIVITY
  #define Y_STOP_PIN                  Y_DIAG_PIN
  #if Y_HOME_DIR < 0
    #define Y_MAX_PIN                      P1_26  // Y+
  #else
    #define Y_MIN_PIN                      P1_26  // Y+
  #endif
#else
  #define Y_MIN_PIN                        P1_27  // Y-
  #define Y_MAX_PIN                        P1_26  // Y+
#endif

#ifdef Z_STALL_SENSITIVITY
  #define Z_STOP_PIN                  Z_DIAG_PIN
  #if Z_HOME_DIR < 0
    #define Z_MAX_PIN                      P1_24  // Z+
  #else
    #define Z_MIN_PIN                      P1_24  // Z+
  #endif
#else
  #define Z_MIN_PIN                        P1_25  // Z-
  #define Z_MAX_PIN                        P1_24  // Z+
#endif

#define ONBOARD_ENDSTOPPULLUPS                    // Board has built-in pullups

//
// Servos
//
#ifndef SERVO0_PIN
  #define SERVO0_PIN                       P2_00
#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                  P1_24
#endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                   P1_28
#endif

//
// Steppers
//
#define X_STEP_PIN                         P2_02
#define X_DIR_PIN                          P2_06
#define X_ENABLE_PIN                       P2_01
#ifndef X_CS_PIN
  #define X_CS_PIN                         P1_17
#endif

#define Y_STEP_PIN                         P0_19
#define Y_DIR_PIN                          P0_20
#define Y_ENABLE_PIN                       P2_08
#ifndef Y_CS_PIN
  #define Y_CS_PIN                         P1_15
#endif

#define Z_STEP_PIN                         P0_22
#define Z_DIR_PIN                          P2_11
#define Z_ENABLE_PIN                       P0_21
#ifndef Z_CS_PIN
  #define Z_CS_PIN                         P1_10
#endif

#define E0_STEP_PIN                        P2_13
#define E0_DIR_PIN                         P0_11
#define E0_ENABLE_PIN                      P2_12
#ifndef E0_CS_PIN
  #define E0_CS_PIN                        P1_08
#endif

#ifndef E1_CS_PIN
  #define E1_CS_PIN                        P1_01
#endif

//
// Software SPI pins for TMC2130 stepper drivers
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI                    P4_28
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO                    P0_05
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK                     P0_04
  #endif
#endif

#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
  #define X_SERIAL_TX_PIN                  P4_29
  #define X_SERIAL_RX_PIN                  P1_17

  #define Y_SERIAL_TX_PIN                  P1_16
  #define Y_SERIAL_RX_PIN                  P1_15

  #define Z_SERIAL_TX_PIN                  P1_14
  #define Z_SERIAL_RX_PIN                  P1_10

  #define E0_SERIAL_TX_PIN                 P1_09
  #define E0_SERIAL_RX_PIN                 P1_08

  #define E1_SERIAL_TX_PIN                 P1_04
  #define E1_SERIAL_RX_PIN                 P1_01

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE                    19200
#endif

/**
 *               _____                                              _____
 *           NC | 1 2 | GND                                     5V | 1 2 | GND
 *        RESET | 3 4 | 1.31 (SD_DETECT)             (LCD_D7) 1.23 | 3 4 | 1.22 (LCD_D6)
 *  (MOSI) 0.18 | 5 6   3.25 (BTN_EN2)               (LCD_D5) 1.21 | 5 6   1.20 (LCD_D4)
 * (SD_SS) 0.16 | 7 8 | 3.26 (BTN_EN1)               (LCD_RS) 1.19 | 7 8 | 1.18 (LCD_EN)
 *   (SCK) 0.15 | 9 10| 0.17 (MISO)                 (BTN_ENC) 0.28 | 9 10| 1.30 (BEEPER)
 *               -----                                              -----
 *               EXP2                                               EXP1
 */

#define EXPA1_03_PIN                       P1_23
#define EXPA1_04_PIN                       P1_22
#define EXPA1_05_PIN                       P1_21
#define EXPA1_06_PIN                       P1_20
#define EXPA1_07_PIN                       P1_19
#define EXPA1_08_PIN                       P1_18
#define EXPA1_09_PIN                       P0_28
#define EXPA1_10_PIN                       P1_30

#define EXPA2_03_PIN                       -1
#define EXPA2_04_PIN                       P1_31
#define EXPA2_05_PIN                       P0_18
#define EXPA2_06_PIN                       P3_25
#define EXPA2_07_PIN                       P0_16
#define EXPA2_08_PIN                       P3_26
#define EXPA2_09_PIN                       P0_15
#define EXPA2_10_PIN                       P0_17

#if HAS_SPI_LCD

  /* RH i2.5 custom LCD pinout */
  #define LCD_PINS_RS      P1_22  //EXPA1_04_PIN
  #define LCD_PINS_ENABLE  P1_23  //EXPA1_03_PIN
  #define LCD_PINS_D4      P1_18  //EXPA1_08_PIN
  #define LCD_PINS_D5      P1_19  //EXPA1_07_PIN
  #define LCD_PINS_D6      P1_20  //EXPA1_06_PIN
  #define LCD_PINS_D7      P1_21  //EXPA1_05_PIN
  #define BTN_ENC          P1_31
  #define BTN_EN1          P3_25  //EXPA2_06_PIN
  #define BTN_EN2          P3_26  //EXPA2_08_PIN
  /* RH unused */
  //#define BEEPER_PIN
  //#define LCD_SDSS
  //#define SD_DETECT_PIN

#endif // HAS_SPI_LCD

//
// SD Support
//

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION                  LCD
#endif

#if SD_CONNECTION_IS(LCD)
  #define SS_PIN                    EXPA2_07_PIN
#endif

/**
 * Special pins
 *   P1_30  (37) (NOT 5V tolerant)
 *   P1_31  (49) (NOT 5V tolerant)
 *   P0_27  (57) (Open collector)
 *   P0_28  (58) (Open collector)
 */

// Include common SKR pins
#include "pins_BTT_SKR_common.h"
