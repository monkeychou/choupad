#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_4x3(RGB_TOG, KC_NO, KC_NO,
  KC_7, KC_8, KC_9,
  KC_4, KC_5, KC_6,
  KC_1, KC_2, KC_3
),
    [1] = LAYOUT_4x3(RGB_TOG, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};


void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } 
}
