/*
Copyright 2019 @foostan
Copyright 2021 @HellSingCoder
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

#include QMK_KEYBOARD_H

#include "flow.h"

enum layers {
    // default layers
    _BASE,
    _SYM,
    _NAV,
    _FUNC,
    // League of Legends layer
    _LOL,
    // keyboard configuration
    _CONF
};

// custom oneshot mod implementation
enum keycodes {
    OS_CONF = SAFE_RANGE,
};

#define MO_BASE  MO(_BASE)
#define MO_SYM   MO(_SYM)
#define MO_NAV   MO(_NAV)
#define MO_FUNC  MO(_FUNC)
#define MO_LOL   MO(_LOL)
#define MO_CONF  MO(_CONF)

#define TO_BASE  TO(_BASE)
#define TO_LOL   TO(_LOL)

#define LCTL_1   LCTL(KC_1)
#define LCTL_2   LCTL(KC_2)
#define LCTL_3   LCTL(KC_3)
#define LCTL_4   LCTL(KC_4)
#define LCTL_5   LCTL(KC_5)

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    // symbols layer
    {MO_SYM, KC_RGUI},
    {MO_SYM, KC_RSFT},
    {MO_SYM, KC_RALT},
    {MO_SYM, KC_RCTL},
    // navigation layer
    {MO_NAV, KC_LGUI},
    {MO_NAV, KC_LSFT},
    {MO_NAV, KC_LALT},
    {MO_NAV, KC_LCTL},
};

// for layers configuration follow this format:
// * custom layer key
// * layer name
const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_CONF, _CONF},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO_FUNC,  MO_SYM,  KC_SPC,     KC_ENT, KC_LSFT,  MO_NAV
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, KC_BSLS, KC_LBRC, KC_RBRC, KC_PLUS,                       KC_EQL, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_UNDS,                      KC_MINS, KC_TILD, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_PGUP, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F11,  KC_F12, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, OS_CONF
                                      //`--------------------------'  `--------------------------'
  ),

    [_LOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_Q,    KC_W,    KC_E,    KC_R,                       LCTL_1,  LCTL_2,  LCTL_3,  LCTL_4,  LCTL_5, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_2,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_3,    KC_Z,    KC_C,    KC_V,    KC_B,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  KC_SPC, KC_LALT,       KC_P, XXXXXXX, OS_CONF
                                      //`--------------------------'  `--------------------------'
  ),

    [_CONF] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      TO_BASE,  TO_LOL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE

/* 32 * 32 logo */
static void render_logo(void) {
  static const char PROGMEM hexagram_logo[] = {
      0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
      0xc0, 0x70, 0x18, 0x06, 0x06, 0x18, 0x70, 0xc0, 0x80, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07,
      0x1f, 0x32, 0x66, 0xc4, 0x6c, 0x38, 0x1e, 0x37, 0x61, 0xc0, 0x80, 0x80,
      0x80, 0x80, 0xc0, 0x61, 0x37, 0x1e, 0x38, 0x6c, 0xc4, 0x66, 0x32, 0x1f,
      0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0x4c, 0x66, 0x23,
      0x36, 0x1c, 0x78, 0xec, 0x86, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0x86,
      0xec, 0x78, 0x1c, 0x36, 0x23, 0x66, 0x4c, 0xf8, 0xe0, 0x80, 0x00, 0x00,
      0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
      0x03, 0x0e, 0x18, 0x60, 0x60, 0x18, 0x0e, 0x03, 0x01, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00};

  oled_write_raw_P(hexagram_logo, sizeof(hexagram_logo));
}

/* settings */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED  40

/* advanced settings */
// how long each frame lasts in ms
#define ANIM_FRAME_DURATION 200
// number of bytes in array. If you change sprites, minimize for adequate firmware size. Max is 1024
#define ANIM_SIZE           96

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isRunning  = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
  /* Sit */
  static const char PROGMEM sit[2][ANIM_SIZE] = {
      /* 'sit1', 32x22px */
      {
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04,
          0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08,
          0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06,
          0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20,
          0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      },

      /* 'sit2', 32x22px */
      {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9,
       0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02,
       0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20,
       0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

  /* Walk */
  static const char PROGMEM walk[2][ANIM_SIZE] = {
      /* 'walk1', 32x22px */
      {
          0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90,
          0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90,
          0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00,
          0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f,
          0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e,
          0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      },

      /* 'walk2', 32x22px */
      {
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20,
          0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20,
          0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01,
          0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
          0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05,
          0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32,
          0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      }};

  /* Run */
  static const char PROGMEM run[2][ANIM_SIZE] = {
      /* 'run1', 32x22px */
      {
          0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80,
          0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04,
          0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00,
          0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03,
          0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32,
          0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
      },

      /* 'run2', 32x22px */
      {
          0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10,
          0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01,
          0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10,
          0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e,
          0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      }};

  /* Bark */
  static const char PROGMEM bark[2][ANIM_SIZE] = {
      /* 'bark1', 32x22px */
      {
          0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18,
          0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01,
          0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48,
          0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28,
          0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05,
          0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      },

      /* 'bark2', 32x22px */
      {
          0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90,
          0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01,
          0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0,
          0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28,
          0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05,
          0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      }};

  /* Sneak */
  static const char PROGMEM sneak[2][ANIM_SIZE] = {
      /* 'sneak1', 32x22px */
      {
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40,
          0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80,
          0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02,
          0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09,
          0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11,
          0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04,
          0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
      },

      /* 'sneak2', 32x22px */
      {
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40,
          0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03,
          0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04,
          0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09,
          0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06,
          0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
      }};

  /* animation */
  void animate_luna(void) {
    /* jump */
    if (isJumping || !showedJump) {
      /* clear */
      oled_set_cursor(LUNA_X, LUNA_Y + 2);
      oled_write("     ", false);

      oled_set_cursor(LUNA_X, LUNA_Y - 1);

      showedJump = true;
    } else {
      /* clear */
      oled_set_cursor(LUNA_X, LUNA_Y - 1);
      oled_write("     ", false);

      oled_set_cursor(LUNA_X, LUNA_Y);
    }

    /* switch frame */
    current_frame = (current_frame + 1) % 2;

    /* current status */
    if (led_usb_state.caps_lock) {
      oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

    } else if (isSneaking) {
      oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

    } else if (current_wpm <= MIN_WALK_SPEED) {
      oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

    } else if (current_wpm <= MIN_RUN_SPEED) {
      oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

    } else if (isRunning) {
      oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);

    } else {
      oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
    }
  }

  /* animation timer */
  if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
    anim_timer = timer_read32();
    animate_luna();
  }

  /* this fixes the screen on and off bug */
  if (current_wpm > 0) {
    oled_on();
    anim_sleep = timer_read32();
  } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
    /* clear */
    oled_set_cursor(0, 0);
    oled_write("                                                               "
               "                                     ",
               false);
    oled_off();
    oled_set_cursor(LUNA_X, LUNA_Y);
  }
}

static void print_logo_narrow(void) {
  render_logo();
  if (current_wpm > 0) {
    anim_sleep = timer_read32();
    /* wpm counter */
    oled_set_cursor(0, 14);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);

    oled_set_cursor(0, 15);
    oled_write(" WPM", false);

    /* this fixes the screen on and off bug */

  } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
    /* clear */
    oled_set_cursor(0, 0);
    oled_write("                                                               "
               "                                                         ",
               false);
    oled_off();
  }
}

// Switch underglow on layer change
// layer_state_t layer_state_set_user(layer_state_t state) {
//   switch (get_highest_layer(state)) {
//   case 0:
//     rgb_matrix_reload_from_eeprom();
//     break;
//   case 1:
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
//     rgb_matrix_sethsv_noeeprom(HSV_TEAL);
//     break;
//   case 2:
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
//     rgb_matrix_sethsv_noeeprom(HSV_PINK);
//     break;
//   case 3:
//     rgb_matrix_reload_from_eeprom();
//     break;
//   case 4:
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
//     rgb_matrix_sethsv_noeeprom(HSV_RED);
//     break;
//   }
//   return state;
// }

static void print_status_narrow(void) {

  /* Print current layer */
  oled_write("LAYER", false);

  oled_set_cursor(0, 6);

  switch (get_highest_layer(layer_state)) {
  case _BASE:
    oled_write("Base ", false);
    break;
  case _SYM:
    oled_write("Sym  ", false);
    break;
  case _NAV:
    oled_write("Nav  ", false);
    break;
  case _FUNC:
    oled_write("Func ", false);
    break;
  case _LOL:
    oled_write("LOL  ", false);
    break;
  case _CONF:
    oled_write("Conf ", false);
    break;
  default:
    oled_write("Undef", false);
  }

  render_luna(0, 13);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

bool oled_task_user(void) {
  current_wpm = get_current_wpm();
  led_usb_state = host_keyboard_led_state();

  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    print_logo_narrow();
  }
  return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;

  switch (keycode) {
  case KC_LCTL:
    isSneaking = record->event.pressed;
    break;
  case KC_SPC:
    isJumping = record->event.pressed;
    if (isJumping) {
      showedJump = false;
    }
    break;
  case KC_RSFT:
    isRunning = record->event.pressed;
    break;
  case KC_LSFT:
    isRunning = record->event.pressed;
    break;
  }

  return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}
