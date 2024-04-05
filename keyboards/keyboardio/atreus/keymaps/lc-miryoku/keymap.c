// Copyright (C) 2022, Hao Xiang Liew

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

enum layer_names {
  BASE,
  MEDIA,
  NAV,
  MOUSE,
  SYM,
  NUM,
  FUN,
};

/* #define _______ KC_TRNS */
/* #define XXXXXXX KC_NO */

// Combos
// Handy generator here: https://codepen.io/mvaneijgen/full/LYEVQXp
enum combos {
  TAB_ENT_ESC,
  T_Y_ESC,
  G_H_ESC,
};

const uint16_t PROGMEM tab_ent_esc[] = { KC_TAB, KC_ENT, COMBO_END};
const uint16_t PROGMEM t_y_esc[] = { KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM g_h_esc[] = { KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
  [TAB_ENT_ESC] = COMBO(tab_ent_esc, KC_ESC),
  [T_Y_ESC] = COMBO(t_y_esc, KC_ESC),
  [G_H_ESC] = COMBO(g_h_esc, KC_ESC),
};


// Tab dance
enum {
  TD_MINUS_PLUS,
};
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for minus, twice for plus
    [TD_MINUS_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_PLUS),
};



/*
| q   | w  | e   | r         | t       |          |       | y     | u       | i | o | p     |
| a   | s  | d   | f         | g       |          |       | h     | j       | k | l | ;     |
| z   | x  | c   | v         | b       |          |       | n     | m       | , | . | /     |
| ESC | S⇑ | GUI | MEDIA/ESC | NAV/SPC | MOUSE/⭾ | SYM/⏎ | NUM/⇦ | FUN/DEL | - | ' | CTRL/⇦ |
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( /* Qwerty */
    KC_Q,        KC_W,        KC_E,             KC_R,              KC_T,                                                KC_Y,            KC_U,          KC_I,        KC_O,        KC_P,
    CTL_T(KC_A), ALT_T(KC_S), GUI_T(KC_D),      SFT_T(KC_F),       KC_G,                                                KC_H,            SFT_T(KC_J),   GUI_T(KC_K), ALT_T(KC_L), CTL_T(KC_SCLN),
    KC_Z,        KC_X,        KC_C,             KC_V,              KC_B,            KC_GRV,           KC_BSLS,          KC_N,            KC_M,          KC_COMM,     KC_DOT,      KC_SLSH,
    KC_ESC,      KC_LSFT,     KC_LGUI,    LT(MEDIA, KC_ESC), LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), LT(SYM, KC_ENT),  LT(NUM, KC_SPC), LT(FUN, KC_BSPC), TD(TD_MINUS_PLUS), KC_QUOT, CTL_T(KC_ENT)),

/*
| ⛑️  |     |     |     |   |   |   |       | 🔇   |      |       |        |
| CTL | ALT | GUI | SFT |   |   |   | 🎵PRV | 🎵⬇️ | 🎵⬆️ | 🎵PRV | 🎵NEXT |
|     |     |     |     |   |   |   | 🎵🛑  | 🎵⏯️ | 🎵🔇 |       |        |
| ⛑️  |     |     |     |   |   | ⏎ | ⇦     | DEL  |      |       |        |
*/
  [MEDIA] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______,                   _______, KC_MUTE, _______, _______, _______,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT,
    _______, _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE, _______, _______,
    QK_BOOT, _______, _______, _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL,  _______, _______, _______),

  [NAV] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    QK_BOOT, _______, _______, _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL,  _______, _______, _______),

  [MOUSE] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______,                   _______, KC_BTN1, KC_BTN2, KC_BTN3, _______,
    _______, _______, _______, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
    QK_BOOT, _______, _______, _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL,  _______, _______, _______),

  [SYM] = LAYOUT(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                   _______, _______, _______, _______, _______, \
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                   _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______, _______, _______),

  [NUM] = LAYOUT(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                   _______, _______, _______, _______, _______, \
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                    _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_DOT,  KC_0,    KC_MINS, _______, _______, _______, _______, _______, _______, _______),

  [FUN] = LAYOUT(
    KC_F12,  KC_F7,   KC_F8,  KC_F9,  KC_PSCR,                   _______, _______, _______, _______, _______, \
    KC_F11,  KC_F4,   KC_F5,  KC_F6,  KC_SCRL,                   _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, \
    KC_F10,  KC_F1,   KC_F2,  KC_F3,  KC_PAUS, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_APP, KC_ESC, KC_SPC,  KC_TAB,  _______, _______, _______, _______, _______, _______),

};
