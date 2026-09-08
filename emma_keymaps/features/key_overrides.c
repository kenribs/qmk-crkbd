#include "key_overrides.h"

const key_override_t alt_1_to_f1 = ko_make_basic(MOD_MASK_ALT, KC_1, KC_F1);
const key_override_t alt_2_to_f2 = ko_make_basic(MOD_MASK_ALT, KC_2, KC_F2);
const key_override_t alt_3_to_f3 = ko_make_basic(MOD_MASK_ALT, KC_3, KC_F3);
const key_override_t alt_4_to_f4 = ko_make_basic(MOD_MASK_ALT, KC_4, KC_F4);
const key_override_t alt_5_to_f5 = ko_make_basic(MOD_MASK_ALT, KC_5, KC_F5);
const key_override_t alt_6_to_f6 = ko_make_basic(MOD_MASK_ALT, KC_6, KC_F6);
const key_override_t alt_7_to_f7 = ko_make_basic(MOD_MASK_ALT, KC_7, KC_F7);
const key_override_t alt_8_to_f8 = ko_make_basic(MOD_MASK_ALT, KC_8, KC_F8);
const key_override_t alt_9_to_f9 = ko_make_basic(MOD_MASK_ALT, KC_9, KC_F9);
const key_override_t alt_0_to_f10 = ko_make_basic(MOD_MASK_ALT, KC_0, KC_F10);
const key_override_t alt_min_to_f11 =
    ko_make_basic(MOD_MASK_ALT, KC_MINS, KC_F11);
const key_override_t alt_eql_to_f12 =
    ko_make_basic(MOD_MASK_ALT, KC_EQL, KC_F12);
const key_override_t shift_bspc_to_del =
    ko_make_basic(MOD_MASK_CTL, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &alt_1_to_f1,       &alt_2_to_f2,  &alt_3_to_f3,    &alt_4_to_f4,
    &alt_5_to_f5,       &alt_6_to_f6,  &alt_7_to_f7,    &alt_8_to_f8,
    &alt_9_to_f9,       &alt_0_to_f10, &alt_min_to_f11, &alt_eql_to_f12,
    &shift_bspc_to_del, NULL};
