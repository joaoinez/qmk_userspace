/*
This is the c configuration file for the keymap

Copyright 2019 @foostan
Copyright 2023 @asdfire1
Copyright 2021 @daliusd
Copyright 2024 @joaoinez

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define QUICK_TAP_TERM 0
// #define TAPPING_TERM 175

// #define SPLIT_USB_DETECT
// #define SPLIT_WATCHDOG_ENABLE
// #define SPLIT_USB_TIMEOUT      2000
// #define SPLIT_USB_TIMEOUT_POLL 10
// #define SPLIT_WATCHDOG_TIMEOUT 3000

#undef SPLIT_USB_DETECT
#define USB_VBUS_PIN GP19

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define FLOW_COUNT                 17
#define FLOW_LAYERS_COUNT          1

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_WPM_ENABLE // Enable WPM across split keyboards (+268).
#define NO_ACTION_ONESHOT
// #define SPLIT_OLED_ENABLE

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
