#include "backlight.h"

void keyboard_post_init_user(void) {
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv(0, 0, 51);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t current_hue = rgblight_get_hue();
  uint8_t current_sat = rgblight_get_sat();
  uint8_t layer = get_highest_layer(state);

  // Console output for debugging/HUD
  switch (layer) {
  case _BASE:
    rgblight_sethsv(current_hue, current_sat, 25);
    uprintf("LAYER:BASE\n");
    break;
  case _NUMS:
    rgblight_sethsv(current_hue, current_sat, 75);
    uprintf("LAYER:NUMS\n");
    break;
  case _NAV:
    rgblight_sethsv(current_hue, current_sat, 150);
    uprintf("LAYER:NAV\n");
    break;
  case _SYSTEM:
    rgblight_sethsv(current_hue, current_sat, 255);
    uprintf("LAYER:SYSTEM\n");
    break;
  }
  return state;
}
