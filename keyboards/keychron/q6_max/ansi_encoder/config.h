/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#pragma once

#ifdef DYNAMIC_MACRO_ENABLE
#    define DYNAMIC_MACRO_SIZE 128
#endif

#ifdef RGB_MATRIX_ENABLE
/* RGB Matrix driver configuration */
#    define DRIVER_COUNT 2
#    define RGB_MATRIX_LED_COUNT 108

#    define SPI_SCK_PIN A5
#    define SPI_MISO_PIN A6
#    define SPI_MOSI_PIN A7

#    define DRIVER_CS_PINS \
        { B8, B9 }
#    define SNLED23751_SPI_DIVISOR 16
#    define SPI_DRIVER SPID1

/* Set LED driver current */
#    define SNLED27351_CURRENT_TUNE \
        { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 }

/* Set to infinit, which is use in USB mode by default */
#    define RGB_MATRIX_TIMEOUT RGB_MATRIX_TIMEOUT_INFINITE

/* Allow shutdown of led driver to save power */
#    define RGB_MATRIX_DRIVER_SHUTDOWN_ENABLE
/* Turn off backlight on low brightness to save power */
#    define RGB_MATRIX_BRIGHTNESS_TURN_OFF_VAL 32

/* Indications */
#    define NUM_LOCK_INDEX 36
#    define CAPS_LOCK_INDEX 59
#    define SCROLL_LOCK_INDEX 14
#    define TAGGLE_LAYER1_INDEX 0
#    define TAGGLE_LAYER4_INDEX 19
#    define TAGGLE_LAYER5_INDEX 5
#    define TAGGLE_LAYER6_INDEX 6
#    define TAGGLE_LAYER7_INDEX 7
#    define LOW_BAT_IND_INDEX \
        { 98 }

#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_TRIGGER_ON_KEYDOWN

#endif

#define MIDI_BASIC
