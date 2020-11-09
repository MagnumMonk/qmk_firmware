#include "kb.h"

enum {
	TD_GUI_EXP,
	LANG_SC,
	BACK_SC,
	RESET_SC
};

enum layers {
	_DEF,
	_FNC,
	_MED
};

static uint16_t reset_timer;

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_GUI_EXP] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),	
};

#define TD_E TD(TD_GUI_EXP)
#define LANG_SC LGUI(KC_SPC)
#define BACK_SC LCTL(KC_Z)
#define RESET_DELAY 5000

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_DEF] = LAYOUT(
		KC_ESC,   KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,     KC_7,     KC_8,      KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, 
		KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,      KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_DEL, 
		KC_LSFT,  KC_A,    KC_S,     KC_D,     KC_F,    KC_G,    KC_H,     KC_J,     KC_K,      KC_L,     KC_SCLN,  KC_QUOT,  KC_GRV,   KC_ENT, 
		LANG_SC,  KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    KC_N,     KC_M,     KC_COMM,   KC_DOT,   KC_SLSH,  KC_BSLS,  KC_PSCR,  KC_RSFT,
		KC_LCTL,  TD_E,    KC_LALT,  KC_LSFT,  MO(_FNC),     KC_SPC,       MO(_MED), KC_BSPC,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_RCTL
	),

	[_FNC] = LAYOUT(
		_______,  KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,     KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______, 
		_______,  KC_EXLM, KC_AT,   KC_HASH,   KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR,  KC_ASTR,   _______,  _______,  _______,  _______,  _______, 
		_______,  KC_MINS, KC_PLUS, KC_UNDS,   KC_EQL,  KC_LPRN, KC_RPRN,  KC_LCBR,  KC_RCBR,   KC_LBRC,  KC_RBRC,  _______,  _______,  _______, 
		_______,  _______, _______, KC_TILD,   KC_DQUO, KC_GRV,  KC_PIPE,  KC_QUOT,  KC_BSLS,   _______,  _______,  _______,  _______,  _______, 
		_______,  _______, _______, _______,   _______,     KC_ENT,        _______,   KC_DEL,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______
	),

	[_MED] = LAYOUT(
		RESET_SC, _______, _______, _______,   _______, _______, _______,  _______,  _______,   _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______, 
		_______,  KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,     KC_7,     KC_8,      KC_9,     KC_0,     _______,  _______,  _______, 
		KC_CAPS,  _______, _______, _______,   _______, _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______, 
		_______,  _______, _______, _______,   _______, _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______, 
		_______,  _______, _______, _______,   _______,      _______,      _______,  _______,   KC_MPRV,  KC_MSTP,  KC_MPLY,  KC_MNXT,  _______
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case RESET_SC:
      if (record->event.pressed) {
        register_code (KC_ESC);
        reset_timer = timer_read();
      } else {
        unregister_code (KC_ESC);
        if (timer_elapsed(reset_timer) > RESET_DELAY) {
		   reset_keyboard();
        }
      }
      break;    
  }
  return true;
}