#include "backlight.h"

void keyboard_post_init_user(void) {
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv(0, 0, 51);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t current_val = rgblight_get_val();
  uint8_t layer = get_highest_layer(state);

  // Console output for debugging/HUD
  switch (layer) {
  case _BASE:
    rgblight_sethsv(0, 0, current_val);
    uprintf("LAYER:BASE\n");
    break;
  case _NUMS:
    rgblight_sethsv(15, 255, current_val);
    uprintf("LAYER:NUMS\n");
    break;
  case _NAV:
    rgblight_sethsv(42, 255, current_val);
    uprintf("LAYER:NAV\n");
    break;
  case _SYSTEM:
    rgblight_sethsv(170, 255, current_val);
    uprintf("LAYER:SYSTEM\n");
    break;
  }
  return state;
}
