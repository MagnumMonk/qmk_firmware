/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum crkbd_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define UNTAB LSFT(KC_TAB)
#define WCLIP LGUI(LSFT(KC_S))
#define LCLIP LSFT(KC_PSCR)
#define MTSFT MT(MOD_LSFT, KC_SPC)
#define MTBSP MT(MOD_LCTL, KC_BSPC)
#define MTDEL MT(MOD_LCTL, KC_DEL)
#define ALTF4 LALT(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI,
                                        KC_LALT,  LOWER,   MTSFT,  KC_SPC,   RAISE,   MTBSP
  ),
 
  [_LOWER] = LAYOUT(
    UNTAB,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,   XXXXXXX,
    KC_LSFT, KC_LT,   KC_LPRN, KC_LBRC, KC_LCBR, KC_QUOT,                   KC_DQUO, KC_RCBR, KC_RBRC, KC_RPRN, KC_GT,    XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_GRV,                    KC_TILD,  KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX,
                                        KC_LALT, LOWER,   MTSFT,  KC_SPC,   RAISE,   MTDEL

  ),

  [_RAISE] = LAYOUT(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   XXXXXXX,
    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_VOLU, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  WCLIP,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_VOLD, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,  LCLIP,
                                        KC_LALT, LOWER,   MTSFT,  KC_SPC,   RAISE,   MTBSP
  ),


  [_ADJUST] = LAYOUT(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ALTF4,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
                                        XXXXXXX, LOWER,  XXXXXXX, XXXXXXX,  RAISE,   XXXXXXX
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    clear_oneshot_mods();
    return state;
}
