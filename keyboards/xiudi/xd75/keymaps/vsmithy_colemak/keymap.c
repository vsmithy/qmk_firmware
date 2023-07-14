/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _CM 0
#define _L1 1
#define _L2 2
#define _L3 3


// Custom keycodes for macros
enum custom_keycodes {
  BLOCK_COMMENT = SAFE_RANGE,
	REACT_CLOSE,
	TRI_EQUALS,
	TERNARY,
  AVAIL,
  CONSOLE,
  CONFANCY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* MyColemak
 * .---------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC     | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | PG UP  | DEL    |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB     | Q      | W      | F      | P      | G      | J      | L      | U      | Y      | ;      | '      | 7      | 8      | 9      |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | BACKSP  | A      | R      | S      | T      | D      | H      | N      | E      | I      | O      | ENTER  | 4      | 5      | 6      |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHFT   | Z      | X      | C      | V      | B      | K      | M      | < ,    | > .    | ? /    | L2     | 1      | 2      | 3      |
 * |---------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | L1      | LCTL  | CMD     | ALT    | MACROS | MACROS | SPACE  | SPACE  | LEFT   | UP     | DOWN   | RIGHT  | 0      | L3     | .      |
 * '---------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_CM] = { /* MY COLEMAK */
  { KC_ESC,   KC_1,    KC_2,    KC_3,        KC_4,          KC_5,           KC_6,     KC_7,        KC_8,      KC_9,    KC_0,    KC_MINUS, KC_EQL,  KC_PGUP, KC_DEL },
  { KC_TAB,   KC_Q,    KC_W,    KC_F,        KC_P,          KC_G,           KC_J,     KC_L,        KC_U,      KC_Y,    KC_SCLN, KC_QUOT,  KC_P7,   KC_P8,   KC_P9  },
  { KC_BSPC,  KC_A,    KC_R,    KC_S,        KC_T,          KC_D,           KC_H,     KC_N,        KC_E,      KC_I,    KC_O,    KC_ENT,   KC_P4,   KC_P5,   KC_P6  },
  { KC_LSFT,  KC_Z,    KC_X,    KC_C,        KC_V,          KC_B,           KC_K,     KC_M,        KC_COMM,   KC_DOT,  KC_SLSH, MO(_L2),  KC_P1,   KC_P2,   KC_P3  },
  { MO(_L1),  KC_LCTL, KC_LGUI, KC_LALT,     CONSOLE,       CONFANCY,       KC_SPC,   KC_SPC,      KC_LEFT,   KC_UP,   KC_DOWN, KC_RGHT,  KC_P0,   MO(_L3), KC_DOT },
 },

/* _L1   Adds additional mac kbd functionality such as volume, brightness, launchpad, etc...
 * ,------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+------+------+------,
 * |   `  | DIM   | BRIGHT | MCTRL | ACTIVE | SHW DKTP | MUTE  | VOL DN  | VOL UP | L BRKT | R BRCKT |       |       | PGDN |     |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+------+------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |   \   |       |     |      |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+------+------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |       |       |     |      |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+------+------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |       |       |     |      |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+------+------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |       |MACROS|MACROS|MACROS|
 * '------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+------+------+------'
 */
 
 [_L1] = { /* _L1 */
  { KC_GRV,  KC_BRMD, KC_BRMU, LCTL(KC_UP), LCTL(KC_DOWN), KC_F11,  KC_MUTE,  KC__VOLDOWN, KC__VOLUP, KC_LBRC, KC_RBRC, _______, _______,       KC_PGDN, _______  },
  { _______, _______, _______, _______,     _______,       _______, _______,  _______,     _______,   _______, _______, KC_BSLS, _______,       _______, _______  },
  { _______, _______, _______, _______,     _______,       _______, _______,  _______,     _______,   _______, _______, _______, _______,       _______, _______  },
  { _______, _______, _______, _______,     _______,       _______, _______,  _______,     _______,   _______, _______, _______, _______,       _______, _______  },
  { _______, _______, _______, _______,     _______,       _______, _______,  _______,     _______,   _______, _______, _______, BLOCK_COMMENT, AVAIL,   TERNARY  },
 },

/* _L2   STILL FIGURING OUT WHAT TO DO WITH THIS LAYER...
 * .---------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   ?  |   `  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |MACRO |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | PIPE |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * '------+------+------+------+------+------+------+------+------+------+------+------+------+------+------'
 */
 
 [_L2] = { /* _L2 */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC,       _______,     _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LSFT(KC_SLSH), KC_GRV,      _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       TRI_EQUALS,  _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LSFT(KC_BSLS), _______,     _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,     _______, _______, _______  },
 },

/* _L3 NOT SURE WHAT TO DO WITH THIS ONE YET EITHER...
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_L3] = { /* _L3 */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12   },
  { KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL,  RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS  },
  { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,  RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, KC_NLCK, _______  },
  { KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,   RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______  },
  { _______, _______, RGB_TOG, RGB_RMOD, _______, RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, _______, _______, _______, _______  },
 }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CONSOLE:
      if (record->event.pressed) {
        // when keycode BLOCK_COMMENT is pressed
        SEND_STRING("console.log( stuffs )");
      } else {
        // when keycode BLOCK_COMMENT is released
      }
      break;
    case CONFANCY:
      if (record->event.pressed) {
        // when keycode BLOCK_COMMENT is pressed
        SEND_STRING("console.log(`stuffs ${stuffs}`)");
      } else {
        // when keycode BLOCK_COMMENT is released
      }
      break;
    case BLOCK_COMMENT:
      if (record->event.pressed) {
        // when keycode BLOCK_COMMENT is pressed
        SEND_STRING("/* vvvvvv */");
      } else {
        // when keycode BLOCK_COMMENT is released
      }
      break;
		case AVAIL:
			if (record->event.pressed){
				// when the keycode REACT_CLOSE is pressed
				SEND_STRING("whatsavailable");
			} else {
				// when REACT_CLOSE is released
			}
			break;
		case TRI_EQUALS:
			if (record->event.pressed){
				SEND_STRING("===");
			} else {
				// when TRI_EQUALS is released
			}
			break;
		case TERNARY:
			if (record->event.pressed){
				SEND_STRING("stuffs ? itemA : itemB");
			} else {
				// when TERNARY is released
			}
			break;
  }
  return true;
};


// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [0] = {
//     {MY_CUSTOM_MACRO, MY_OTHER_MACRO}
//   }
// };
