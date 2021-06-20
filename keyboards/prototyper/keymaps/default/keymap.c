/* Copyright 2020 HamSolo
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    KVM_1 = SAFE_RANGE,
    KVM_2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
                                                              [0] = LAYOUT(
                                                                           KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
                                                                           KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
                                                                           KC_GESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                                                                           KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
                                                                           KC_LCTL, KC_LCMD, KC_LALT, KC_RCTL, MO(_LOWER), KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
                                                                           ),
							      // lower
                                                              [1] = LAYOUT(
                                                                           KC_NO, KVM_1, KVM_2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                                           KC_NO, KC_NO, KC_NO, KC_NO, DYN_REC_START1, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DYN_REC_STOP, KC_NO, DYN_MACRO_PLAY1,
                                                                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
                                                                           ),
							      // raise
                                                              [2] = LAYOUT(
                                                                           KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL,
                                                                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EQL,
                                                                           RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS,
                                                                           KC_LSFT, KC_MUTE, KC_APP, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_MPLY, KC_PSCR, KC_VOLD, KC_VOLU, KC_SFTENT,
                                                                           KC_LCTL, KC_LCMD, KC_LALT, KC_NO, KC_NO, KC_SPC, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
                                                                           )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KVM_1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SLCK) SS_TAP(X_SLCK) SS_TAP(X_KP_1));
            } else {
                // when keycode KVM_1 is released
            }
            break;
	case KVM_2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SLCK) SS_TAP(X_SLCK) SS_TAP(X_KP_2));
            } else {
                // when keycode KVM_2 is released
            }
            break;
    }
    return true;
}
