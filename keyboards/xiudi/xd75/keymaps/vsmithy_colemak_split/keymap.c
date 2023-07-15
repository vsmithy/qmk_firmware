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

/* Split Mac Colemak -- Base level (L0)
 * .---------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC     | DIM    | BRIGHT | MCTRL  | ACTIVE |SHW DKTP| 1      | 2      | 3      | \      | - ~    | =      | [{(    | )}]    | DEL    |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB     | Q      | W      | F      | P      | G      | 4      | 5      | 6      | J      | L      | U      | Y      | ;      |  ' " ` |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | BACKSP  | A      | R      | S      | T      | D      | 7      | 8      | 9      | H      | N      | E      | I      | O      | ENTER  |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHFT   | Z      | X      | C      | V      | B      | , F11  | 0      | . F12  | K      | M      | < ,    | > .    | UP     |  / ?   |
 * |---------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | L1      | LCTL  | ALT     | CMD    | SPACE  | MACROS | L2     | MACROS | MACROS | SPACE  | CMD    | ALT    | LEFT   | DN     | RIGHT  |
 * '---------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_CM] = { /* Split Mac Colemak -- Base level (L0) */
  { KC_ESC,   KC_BRMD, KC_BRMU, LCTL(KC_UP), LCTL(KC_DOWN), KC_F11,     KC_1,     KC_2,    KC_3,           KC_BSLS,  KC_MINUS,   KC_EQL,    KC_LBRC,  KC_RBRC, KC_DEL  },
  { KC_TAB,   KC_Q,    KC_W,    KC_F,        KC_P,          KC_G,       KC_4,     KC_5,    KC_6,           KC_J,     KC_L,       KC_U,      KC_Y,     KC_SCLN, KC_QUOT },
  { KC_BSPC,  KC_A,    KC_R,    KC_S,        KC_T,          KC_D,       KC_7,     KC_8,    KC_9,           KC_H,     KC_N,       KC_E,      KC_I,     KC_O,    KC_ENT  },
  { KC_LSFT,  KC_Z,    KC_X,    KC_C,        KC_V,          KC_B,       KC_COMM,  KC_0,    KC_DOT,         KC_K,     KC_M,       KC_COMM,   KC_DOT,   KC_UP,   KC_SLSH },
  { MO(_L1),  KC_LCTL, KC_LALT, KC_LGUI,     KC_SPC,        CONFANCY,   MO(_L2),  TERNARY, BLOCK_COMMENT,  KC_SPC,   KC_RGUI,    KC_RALT,   KC_LEFT,  KC_DOWN, KC_RGHT },
 },

/* Split Mac Colemak -- Layer 1
 * ,------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------,
 * |      |       |        |       |        |          |       |         |        |        |    ~    |       | L BRKT | R BRCKT |      |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |       |        |         |  `   |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |       |        |         |      |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |       |        |         |      |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |       |        |         |      |
 * '------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------'
 */
 
 [_L1] = { /* _L1 */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LSFT(KC_GRV),  _______, LSFT(KC_SLSH),  LSFT(KC_SLSH), _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,         _______,      KC_GRV   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,         _______,      _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,         _______,      _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,         _______,      _______  },
 },

/* Split Mac Colemak -- Layer 2
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
