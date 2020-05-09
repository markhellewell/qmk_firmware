#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_WHITE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

// Colemak
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
							      [0] = LAYOUT(
									   KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
									   KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
									   KC_GESC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
									   KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
									   KC_LCTL, KC_LGUI, KC_LALT, MO(1), MO(2), KC_SPC, KC_SPC, KC_RCTL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
									   ),
                                                              [1] = LAYOUT(
									   KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
									   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL,
									   RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS,
									   KC_LSFT, KC_MUTE, KC_APP, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_MPLY, KC_PSCR, KC_VOLD, KC_VOLU, KC_SFTENT,
									   KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_SPC, KC_SPC, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
									   ),
                                                              [2] = LAYOUT(
									   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
									   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
									   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
									   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
									   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_TOG, KC_NO, KC_NO, KC_NO, RGB_MODE_REVERSE, RGB_MODE_FORWARD
									   )
};
