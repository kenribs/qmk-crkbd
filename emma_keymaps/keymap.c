#include QMK_KEYBOARD_H

#define KX_SFCP TD(TD_LSFT_CAPS)

//SECTION: windows controls only
#define KX_LOCK LGUI(KC_L)
#define KX_WIN_CLOSE LGUI(LCTL(KC_F4))
#define KX_WIN_NEW   LGUI(LCTL(KC_D))
#define KX_WIN_NEXT  LGUI(LCTL(KC_RIGHT))
#define KX_WIN_PREV  LGUI(LCTL(KC_LEFT))

#define KX_EMOJI    LGUI(KC_SCLN)
#define KX_CLIPB    LGUI(KC_V) // opens up the clipboard history

// NOTE: customized keys
#define KX_CTL_SPC  LCTL(KC_SPC)
#define KX_CYC_DSK  LGUI(KC_TAB)
#define KX_NEW_TAB  LCTL(KC_T)
#define KX_SFT_TAB  SFT_T(KC_TAB)
#define KX_SFT_ENT  SFT_T(KC_ENT)
#define KX_UDN_SRC  LSFT(KC_MINS) // shortcut: _
// !SECTION

enum layer_names {
    _BASE = 0,
    _NUMS,
    _NAV,
    _SYSTEM
};

enum {
    TD_LSFT_CAPS
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

// Force white RGB on startup
void keyboard_post_init_user(void) {
    rgblight_enable();                          // Enable RGB
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);  // Set to solid color mode
    rgblight_sethsv(0, 0, 51);                 // Set to white with brightness at 20%
}

// Change RGB color based on layer while preserving brightness
// Add console debug output for layer changes
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
            uprintf("NAVIGATION\n");
            break;
        case _SYSTEM:
            rgblight_sethsv(170, 255, current_val);
            uprintf("LAYER:SYSTEM\n");
            break;
    }
    return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
        KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,      KC_PGUP,        KC_NO,      KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    MS_BTN4,
        KX_SFT_TAB, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,      KC_PGDN,        KC_BSPC,    KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        MO(_NAV),   KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                                  KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KX_SFCP,
                                              KC_LALT,   KC_LCTL,   KC_SPC,         KX_SFT_ENT, MO(_NUMS),   MO(_SYSTEM)
    ),

    [_NUMS] = LAYOUT_split_3x6_3_ex2(
        KC_NO,     KC_F10,  KC_F11,   KC_NO,    KC_EQL,    KC_MINS, KC_HOME,        KC_NO,       KC_NO,      KC_7,   KC_8,    KC_9,    KC_GRV,  MS_BTN5,
        KX_SFT_TAB,KC_F8,   KC_F5,    KC_NO,    KC_LBRC,   KC_RBRC, KC_END,         KC_BSPC,     KC_NO,      KC_4,   KC_5,    KC_6,    KC_NO ,  KC_NO,
        MO(_NAV),  KC_F2,   KC_F12,   KC_NO,    KC_NO,     KC_NO,                                KX_UDN_SRC, KC_1,   KC_2,    KC_3,    KC_BSLS, KX_SFCP,
                                                KC_DEL,    KC_LCTL, KC_SPC,         KX_SFT_ENT,  KC_NO,      KC_0
    ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
        KC_NO,      KC_NO,   KC_UP,     KC_NO,     KC_PGUP,  KC_HOME,   KC_NO,      KC_NO,       KC_NO,       KC_NO,   KC_NO,    KC_NO,    KC_NO,  KC_NO,
        KX_SFT_TAB, KC_NO,   KX_EMOJI,  KX_CLIPB,  KC_PGDN,  KC_END,    KC_NO,      KC_BSPC,     KC_LEFT,     KC_DOWN, KC_UP,    KC_RIGHT, KC_NO,  KC_NO,
        KC_NO,      KC_NO,   KC_NO,     KC_NO,     KC_NO,    KC_NO,                              KC_NO,       KC_NO,   KC_NO,    KC_NO,    KC_NO,  KC_NO,
                                                   KC_LALT,  KC_LCTL,   KC_SPC,     KX_SFT_ENT,  MO(_NUMS),   KC_APP
    ),

    [_SYSTEM] = LAYOUT_split_3x6_3_ex2(
        KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,    KC_NO,   KC_NO,      KC_NO,     KC_NO,    KX_WIN_CLOSE,  KX_LOCK,       KC_NO,        KC_NO,  KC_NO,
        KC_NO, UG_TOGG, UG_VALU, UG_VALD, KC_NO,    KC_NO,   KC_NO,      KC_NO,     KC_NO,    KX_WIN_NEW,    KX_WIN_PREV,   KX_WIN_NEXT,  KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_BRID, KC_BRIU, KC_NO,    KC_NO,                          KC_NO,    KX_CTL_SPC,    KX_NEW_TAB,    KX_CYC_DSK,   KC_NO,  KC_NO,
                                          KC_MPRV,  KC_MNXT, KC_SPC,     KC_NO,     KC_NO,    KC_NO
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [_NUMS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [_NAV] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [_SYSTEM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
