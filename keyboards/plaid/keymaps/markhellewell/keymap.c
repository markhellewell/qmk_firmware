#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    oled_write_ln_P(PSTR(" "), false);

    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("DEFAULT"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("FUNCTION"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("UNDEFINED"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
							      [0] = LAYOUT_plaid_mit(
										     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
										     KC_GESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
										     KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
										     KC_LCTL, KC_LGUI, KC_LALT, MO(1), MO(2), KC_SPC, KC_RCTL, KC_UP, KC_DOWN, KC_LEFT, KC_RGHT
										     ),
							      [1] = LAYOUT_plaid_mit(
										     KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
										     RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSLS,
										     KC_LSFT, KC_MUTE, KC_APP, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_MPLY, KC_VOLU, KC_VOLD, KC_PSCR, KC_SFTENT,
										     KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_SPC, KC_INS, KC_PGUP, KC_PGDN, KC_HOME, KC_END
										     ),
							      [2] = LAYOUT_plaid_mit(
										     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
										     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
										     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
										     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
										     )
};
