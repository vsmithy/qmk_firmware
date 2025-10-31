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
  FUNC,
  STRUCT,
  TERNARY,
  NEWLINE,
  CONSOLE,
  CCOMPILE,
  INCLUDE,
  DEFINE,
  ENUM,
  PRINTF,
  COUT,
  CLASS,
  QMK,
  QMKFLASH
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
 * | LSHFT   | Z      | X      | C      | V      | B      | VOLD   | 0      | VOLU   | K      | M      | < ,    | > .    | UP     |  / ?   |
 * |---------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | L1      | LCTL  | ALT     | CMD    | SPACE  | MACROS | L2     | MACROS | MACROS | SPACE  | CMD    | ALT    | LEFT   | DN     | RIGHT  |
 * '---------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_CM] = { /* Split Mac Colemak -- Base level (L0) */
  { KC_ESC,   KC_BRMD, KC_BRMU, LCTL(KC_UP), LCTL(KC_DOWN), KC_F11,     KC_1,     KC_2,    KC_3,            KC_BSLS,  KC_MINUS,   KC_EQL,    KC_LBRC,  KC_RBRC, KC_DEL  },
  { KC_TAB,   KC_Q,    KC_W,    KC_F,        KC_P,          KC_G,       KC_4,     KC_5,    KC_6,            KC_J,     KC_L,       KC_U,      KC_Y,     KC_SCLN, KC_QUOT },
  { KC_BSPC,  KC_A,    KC_R,    KC_S,        KC_T,          KC_D,       KC_7,     KC_8,    KC_9,            KC_H,     KC_N,       KC_E,      KC_I,     KC_O,    KC_ENT  },
  { KC_LSFT,  KC_Z,    KC_X,    KC_C,        KC_V,          KC_B,       KC_VOLD,  KC_0,    KC_VOLU,         KC_K,     KC_M,       KC_COMM,   KC_DOT,   KC_UP,   KC_SLSH },
  { MO(_L1),  KC_LCTL, KC_LALT, KC_LGUI,     KC_SPC,        NEWLINE,    MO(_L2),  CCOMPILE, BLOCK_COMMENT,  KC_SPC,   KC_RGUI,    KC_RALT,   KC_LEFT,  KC_DOWN, KC_RGHT },
 },

/* Split Mac Colemak -- Layer 1
 * ,------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------,
 * |      |       |        |       |        |          |  F1   |   F2    |   F3   |     /  |    ~    |       | L BRKT | R BRCKT |BACKSP|
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------|
 * |      |       |        |       |        |          |  F4   |   F5    |   F6   |        |         |       |        |         |  `   |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------|
 * |      |       |        |       |        |          |  F7   |   F8    |   F9   |        |    J    |   K   |    L   |    ;    |      |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------|
 * |      |       |        |       |        |          |  F10  |   F11   |   F12  |        |         |       |        |         |      |
 * |------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------|
 * |      |       |        |       |        |          |       |         |        |        |         |       |        |         |      |
 * '------+-------+--------+-------+--------+----------+-------+---------+--------+--------+---------+-------+--------+---------+------'
 */
 
 [_L1] = { /* _L1 */
  { _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_SLSH, LSFT(KC_GRV),  _______, LSFT(KC_SLSH),  LSFT(KC_SLSH), KC_BSPC  },
  { _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______,       _______, _______,        _______,       KC_GRV   },
  { _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   _______, KC_J,          KC_K,    KC_L,           KC_SCLN,       _______  },
  { _______, _______, _______, _______, _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______,       _______, _______,        _______,       _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,        _______,       _______  },
 },

/* Split Mac Colemak -- Layer 2
 * _L2   STILL FIGURING OUT WHAT TO DO WITH THIS LAYER...
 * .--------------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | macros | macros | macros |      |      |      |      |      |      |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | macros | macros | macros |      |      |      |      |      |      |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | macros | macros | macros |      |      |      |      |      |      |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | macros | macros | macros |      |      |      |      |      |      |
 * |------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |        |        |      |      |      |      |      |      |
 * '------+------+------+------+------+------+--------+--------+--------+------+------+------+------+------+------'
 */
 
 [_L2] = { /* _L2 */
  { _______, _______, _______, _______, _______, _______, STRUCT,  FUNC,    CLASS,   _______, _______, _______,  _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, INCLUDE, DEFINE,  TERNARY, _______, _______, _______,  _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, ENUM,    COUT,    PRINTF,  _______, _______, _______,  _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, QMK    , CONSOLE, QMKFLASH, _______, _______, _______,  _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______  },
 },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FUNC:
      if (record->event.pressed) {
        // when keycode FUNC is pressed
        SEND_STRING("void uart_txrx_init(void);");
      } else {
        // when keycode FUNC is released
      }
      break;
    case CONSOLE:
      if (record->event.pressed) {
        // when keycode CONSOLE is pressed
        SEND_STRING("console.log(`stuffs ${stuffs}`)");
      } else {
        // when keycode CONSOLE is released
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
		case INCLUDE:
			if (record->event.pressed){
				// when the keycode INCLUDE is pressed
				SEND_STRING("#include <vvvvv.h>");
			} else {
				// when INCLUDE is released
			}
			break;
		case DEFINE:
			if (record->event.pressed){
				SEND_STRING("#define");
			} else {
				// when DEFINE is released
			}
			break;
		case TERNARY:
			if (record->event.pressed){
				SEND_STRING("stuffs ? itemA : itemB");
			} else {
				// when TERNARY is released
			}
			break;
		case NEWLINE:
			if (record->event.pressed){
				SEND_STRING("/n");
			} else {
				// when NEWLINE is released
			}
			break;
		case CCOMPILE:
			if (record->event.pressed){
				SEND_STRING("clang -o -Wall output_file_name source_file.c");
			} else {
				// when CCOMPILE is released
			}
			break;
		case STRUCT:
			if (record->event.pressed){
				SEND_STRING("struct Person {\nchar name[50];\nint age;\nfloat height;\n};");
			} else {
				// when STRUCT is released
			}
			break;
		case ENUM:
			if (record->event.pressed){
				SEND_STRING("enum custom_keycodes {};");
			} else {
				// when ENUM is released
			}
			break;
		case QMKFLASH:
			if (record->event.pressed){
				SEND_STRING("qmk compile -kb xiudi/xd75 -km vsmithy_colemak_split_mac");
			} else {
				// when QMKFLASH is released
			}
			break;
		case COUT:
			if (record->event.pressed){
				SEND_STRING("std::cout << \"Hello, \" << \"World!\" << std::endl;");
			} else {
				// when COUT is released
			}
			break;
		case PRINTF:
			if (record->event.pressed){
				SEND_STRING("printf(\"You are %d years old.\n\", age);");
			} else {
				// when PRINTF is released
			}
			break;
		case QMK:
			if (record->event.pressed){
				SEND_STRING("qmk compile -kb xiudi/xd75 -km vsmithy_colemak_split_mac");
			} else {
				// when QMK is released
			}
			break;
		case CLASS:
			if (record->event.pressed){
				SEND_STRING("class MyClass {\npublic:\n// Public members (accessible from outside the class)\nint public_data;\nvoid public_method();\nprivate:\n// Private members (accessible only from within the class)\nint private_data;\nvoid private_method();\nprotected:\n// Protected members (accessible from within the class and derived classes)\nint protected_data;\nvoid protected_method();\n};");
			} else {
				// when CLASS is released
			}
			break;
  }
  return true;
};
