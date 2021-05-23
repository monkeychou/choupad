#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_4x3(RGB_TOG, KC_TRNS, KC_TRNS,
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

// #ifdef RGBLIGHT_ENABLE
// // 以下为RGB灯带作为层切换指示灯的实现
// // Light LEDs 13 in SPRINGGREEN when keyboard layer 1 is active
// const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 9, HSV_MAGENTA}
// );
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 9, HSV_CYAN}
// );
// // Light LEDs 13 in GOLD when keyboard layer 2 is active
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 9, HSV_WHITE}
// );
// // Light LEDs 13 in WHITE when keyboard layer 3 is active
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 9, HSV_PURPLE}
// );

// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_numlock_layer,
//     my_layer1_layer,    // Overrides caps lock layer
//     my_layer2_layer,    // Overrides other layers
//     my_layer3_layer     // Overrides other layers
// );

// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Both layers will light up if both kb layers are active
//     rgblight_set_layer_state(1, layer_state_cmp(state, 1));
//     rgblight_set_layer_state(2, layer_state_cmp(state, 2));
// 	rgblight_set_layer_state(3, layer_state_cmp(state, 3));
//     return state;
// }
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.num_lock);
//     return true;
// }
// #endif


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0, 1);
        if (keycode >= MACRO00 && keycode <= MACRO15) {
            dynamic_keymap_macro_send(keycode - MACRO00);
        } else {
            register_code16(keycode);
            wait_ms(10);
            unregister_code16(keycode);
        }
    } else {
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0, 2);
        if (keycode >= MACRO00 && keycode <= MACRO15) {
            dynamic_keymap_macro_send(keycode - MACRO00);
        } else {
            register_code16(keycode);
            wait_ms(10);
            unregister_code16(keycode);
        }
    }
}
#endif


