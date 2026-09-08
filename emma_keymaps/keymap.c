#include QMK_KEYBOARD_H
#include "features/layers.h"
#include "features/key_overrides.h"

//SECTION: windows controls only
#define KX_WIN_LOCK LGUI(KC_L)
#define KX_WIN_CLOSE LGUI(LCTL(KC_F4))
#define KX_WIN_NEW   LGUI(LCTL(KC_D))
#define KX_WIN_NEXT  LGUI(LCTL(KC_RIGHT))
#define KX_WIN_PREV  LGUI(LCTL(KC_LEFT))
#define KX_WIN_SNIP  LGUI(LSFT(KC_S))
#define KX_WIN_EXP   LGUI(KC_E)

#define KX_EMOJI    LGUI(KC_SCLN)
#define KX_CLIPB    LGUI(KC_V) // opens up the clipboard history

// NOTE: customized keys
#define KX_CTL_SPC  LCTL(KC_SPC)
#define KX_CYC_TAB  LCTL(KC_TAB)
#define KX_NEW_TAB  LCTL(KC_T)
#define KX_SFT_TAB  SFT_T(KC_TAB)
#define KX_SFT_ENT  SFT_T(KC_ENT)
#define KX_SFT_CAPS SFT_T(KC_CAPS)
#define KX_UDN_SRC  LSFT(KC_MINS) // shortcut: _

#define KX_WIN_UW LGUI(KC_UP)
#define KX_WIN_DW LGUI(KC_DOWN)
#define KX_WIN_LW LGUI(KC_LEFT)
#define KX_WIN_RW LGUI(KC_RIGHT)

// !SECTION


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
        KC_ESC,     KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_PGUP,         KC_APP,     KC_Y, KC_U, KC_I,    KC_O,   KC_P,    MS_BTN4,
        KX_SFT_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,   KC_PGDN,         KC_BSPC,    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        MO(_NAV),   KC_Z, KC_X, KC_C, KC_V, KC_B,                                KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KX_SFT_CAPS,
                                KC_LALT,  KC_LCTL,  KC_SPC,          KX_SFT_ENT, MO(_NUMS),   MO(_SYSTEM)
    ),

    [_NUMS] = LAYOUT_split_3x6_3_ex2(
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL,  KC_NO,       KC_APP,    KC_NO,      KC_7,   KC_8,    KC_9,    KC_GRV,  MS_BTN5,
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO,       KC_BSPC,   KC_NO,      KC_4,   KC_5,    KC_6,    KC_NO ,  KC_NO,
        MO(_NAV),KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                           KX_UDN_SRC, KC_1,   KC_2,    KC_3,    KC_BSLS, KX_SFT_CAPS,
                               KC_LALT,  KC_LCTL,  KC_SPC,           KX_SFT_ENT,  KC_NO,    KC_0
    ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
        KC_NO,   KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,   KC_NO,         KC_NO,     KX_WIN_LW, KX_WIN_DW, KX_WIN_UW, KX_WIN_RW, KC_NO, KC_NO,
        KC_LSFT, KC_NO, KC_NO, KX_EMOJI, KX_CLIPB, KC_NO,   KC_NO,         KC_BSPC,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_NO, KC_NO,
        KC_NO,   KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,                             KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO, KC_NO,
                                         KC_LALT,  KC_LCTL, KC_SPC,       KX_SFT_ENT, KC_NO,     KC_NO
    ),

    [_SYSTEM] = LAYOUT_split_3x6_3_ex2(
        KC_NO, KC_MUTE, KC_VOLD, KC_NO,   KC_NO,   KC_NO,   KC_VOLU,      KC_NO, KC_NO, KX_WIN_CLOSE, KX_WIN_LOCK, KX_WIN_EXP,  KX_WIN_SNIP, KC_NO,
        KC_NO, UG_TOGG, UG_VALU, KC_NO,   KC_NO,   KC_NO,   KC_VOLD,      KC_NO, KC_NO, KX_WIN_NEW,   KX_WIN_PREV, KX_WIN_NEXT, KC_NO,       KC_NO,
        KC_NO, KC_NO,   KC_BRID, KC_BRIU, KC_NO,   KC_NO,                        KC_NO, KX_CTL_SPC,   KX_NEW_TAB,  KX_CYC_TAB,  KC_NO,       KC_NO,
                                          KC_MPRV, KC_MNXT, KC_MPLY,      KC_NO, KC_NO, KC_NO
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
