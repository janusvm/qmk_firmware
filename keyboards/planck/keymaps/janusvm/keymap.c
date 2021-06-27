#include QMK_KEYBOARD_H
#include "unicode.h"
#include "tapdance.h"

// Layers
enum planck_layers {
    _QWERTY,
    _COLEMAK_DH,
    _NUMPAD,
    // _SYMBOLS,
    // _GREEK,
    // _EMOJI,
    _CSP,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Keycodes
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK_DH
};

#define KC_EXIT    KC_NO
#define KC_LOWER   LT(_LOWER, KC_SPC)
#define KC_RAISE   LT(_RAISE, KC_BSPC)
// #define KC_NUMPAD  OSL(_NUMPAD)
// #define KC_GREEK   OSL(_GREEK)
// #define KC_SYMBOLS OSL(_SYMBOLS)
// #define KC_EMOJI   OSL(_EMOJI)
#define KC_FNTAB   LT(_NUMPAD, KC_TAB)
#define KC_CSP     TG(_CSP)

// Home row mod layouts
#define HRM_KEYMAP_kc(                                          \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
LAYOUT_ortho_4x12( \
    KC_##k00,        KC_##k01,        KC_##k02,        KC_##k03,        KC_##k04, KC_##k05, KC_##k06, KC_##k07, KC_##k08,        KC_##k09,        KC_##k0a,        KC_##k0b, \
    GUI_T(KC_##k10), ALT_T(KC_##k11), CTL_T(KC_##k12), SFT_T(KC_##k13), KC_##k14, KC_##k15, KC_##k16, KC_##k17, SFT_T(KC_##k18), CTL_T(KC_##k19), ALT_T(KC_##k1a), GUI_T(KC_##k1b), \
    KC_##k20,        KC_##k21,        KC_##k22,        KC_##k23,        KC_##k24, KC_##k25, KC_##k26, KC_##k27, KC_##k28,        KC_##k29,        KC_##k2a,        KC_##k2b, \
    KC_##k30,        KC_##k31,        KC_##k32,        KC_##k33,        KC_##k34, KC_##k35, KC_##k36, KC_##k37, KC_##k38,        KC_##k39,        KC_##k3a,        KC_##k3b \
)
#define HRM_L_KEYMAP_kc( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
LAYOUT_ortho_4x12( \
    KC_##k00,        KC_##k01,        KC_##k02,        KC_##k03,        KC_##k04, KC_##k05, KC_##k06, KC_##k07, KC_##k08, KC_##k09, KC_##k0a, KC_##k0b, \
    GUI_T(KC_##k10), ALT_T(KC_##k11), CTL_T(KC_##k12), SFT_T(KC_##k13), KC_##k14, KC_##k15, KC_##k16, KC_##k17, KC_##k18, KC_##k19, KC_##k1a, KC_##k1b, \
    KC_##k20,        KC_##k21,        KC_##k22,        KC_##k23,        KC_##k24, KC_##k25, KC_##k26, KC_##k27, KC_##k28, KC_##k29, KC_##k2a, KC_##k2b, \
    KC_##k30,        KC_##k31,        KC_##k32,        KC_##k33,        KC_##k34, KC_##k35, KC_##k36, KC_##k37, KC_##k38, KC_##k39, KC_##k3a, KC_##k3b \
)

// Other mod-tap keys
#define KC_SENT  RSFT_T(KC_ENT)

// Combined keys
#define KC_C_BSPC LCTL(KC_BSPC)
#define KC_C_DEL  LCTL(KC_DEL)
#define KC_C_A    LCTL(KC_A)
#define KC_C_S    LCTL(KC_S)
#define KC_C_Z    LCTL(KC_Z)
#define KC_C_X    LCTL(KC_X)
#define KC_C_C    LCTL(KC_C)
#define KC_C_V    LCTL(KC_V)
#define KC_C_N    LCTL(KC_N)
#define KC_C_O    LCTL(KC_O)
#define KC_C_W    LCTL(KC_W)
#define KC_C_ALT  LCA(KC_NO)

// Clip Studio Paint shortcuts
#define KC_CSP_ZI LCTL(KC_EQL)  // Zoom in
#define KC_CSP_ZO LCTL(KC_MINS) // Zoom out
#define KC_CSP_ZF LCTL(KC_0)    // Fit to screen

// Misc keycodes
#define KC_ KC_TRNS
#define KC__ KC_NO
#define ___X___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // QWERTY layer, based on ANSI QWERTY
    [_QWERTY] = HRM_KEYMAP_kc(
        Q, W, E,    R,     T,     _,   _,   Y,     U,   I,    O,   P,
        A, S, D,    F,     G,     _,   _,   H,     J,   K,    L,   DEL,
        Z, X, C,    V,     B,     _,   _,   N,     M,   COMM, DOT, SLSH,
        _, _, CAPS, FNTAB, LOWER, SPC, SPC, RAISE, ESC, ENT,  _,   _
    ),

    // COLEMAK-DH layer, based on ANSI Colemak-DHm
    [_COLEMAK_DH] = HRM_KEYMAP_kc(
        Q,    W,    F,    P,     B,     _,   _,   J,     L,   U,    Y,   DEL,
        A,    R,    S,    T,     G,     _,   _,   M,     N,   E,    I,   O,
        Z_CZ, X_CX, C_CC, D_CV,  V,     _,   _,   K,     H,   COMM, DOT, SLSH,
        _,    _,    CAPS, FNTAB, LOWER, SPC, SPC, RAISE, ESC, ENT,  _,   CSP
    ),

    // LOWER layer, for numbers, navigation and Danish characters
    [_LOWER] = HRM_L_KEYMAP_kc(
        1,   2,   3,   4,   5,   _,   _,   PGUP, HOME, UP,   END,   DEL,
        6,   7,   8,   9,   0,   _,   _,   PGDN, LEFT, DOWN, RIGHT, _,
        C_Z, C_X, C_C, C_V, C_S, _,   _,   _,    AE,   OE,   AA,    _,
        _,   _,   ,    ,    ,    ENT, ENT, ,     ,     ,     _,     _
    ),

    // RAISE layer, for special characters
    [_RAISE] = KC_KEYMAP(
        EXLM, AT,   LCBR, RCBR, PERC, _,   _,   AMPR, LT,   GT,   DQUO, EQL,
        CIRC, DLR,  LBRC, RBRC, HASH, _,   _,   ASTR, LPRN, RPRN, QUOT, PLUS,
        BSLS, PIPE, GRV,  TILD, _,    _,   _,   _,    UNDS, SCLN, COLN, MINS,
        _,    _,    LALT, LCTL, ,     ENT, ENT, ,     RALT, ,     _,    _
    ),

    // Adjust layer, with mouse keys and board settings
    [_ADJUST] = KEYMAP(
        QWERTY,     ___X___, KC_BRIU, KC_VOLU, RGB_TOG, RESET,   UC_M_WC, ___X___, KC_BTN1, KC_MS_U, KC_BTN2, ___X___,
        COLEMAK_DH, ___X___, KC_BRID, KC_VOLD, AU_TOG,  DEBUG,   UC_M_MA, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,
        KC_MAIL,    KC_CALC, KC_WHOM, KC_MYCM, ___X___, ___X___, UC_M_LN, ___X___, ___X___, ___X___, ___X___, ___X___,
        ___X___,    ___X___, _______, _______, _______, _______, _______, _______, _______, _______, ___X___, ___X___
    ),

    // Numpad layer, with function keys and a numpad
    [_NUMPAD] = HRM_KEYMAP_kc(
        F1,  F2,  F3, F4,   F5,  _, _, PSLS, P7,   P8, P9, PEQL,
        F6,  F7,  F8, F9,   F10, _, _, PAST, P4,   P5, P6, PPLS,
        F11, F12, _,  PSCR, _,   _, _, PCMM, P1,   P2, P3, PMNS,
        _,   _,   ,   ,     ,    ,  ,  ,     PDOT, P0, _,  _
    ),

    // Greek layer, for entering Greek letters
    // [_GREEK] = KC_KEYMAP(
    //     , THETA, OMEGA, EPSILON, RHO, TAU,   UPSILON, PSI, IOTA,  OMICRON, PI, ,
    //     , ALPHA, SIGMA, DELTA,   PHI, GAMMA, ETA,     _,   KAPPA, LAMBDA,  ,   ,
    //     , ZETA,  XI,    CHI,     _,   BETA,  NU,      MU,  ,      ,        ,   ,
    //     , _,     EXIT,  ,        ,    ,      ,        ,    ,      ,        _,  _
    // ),

    // // Symbols layer, for entering special characters
    // [_SYMBOLS] = KC_KEYMAP(
    //     , HALF,         SQUARED,      EURO,      REGISTERED, TRADEMARK, JPY,        UNION,      INFTY,    NEQ,         DEGREES,    ,
    //     , INTERSECTION, SQRT,         PARTIAL,   INTEGRAL,   GRADIENT,  LEFT_ARROW, DOWN_ARROW, UP_ARROW, RIGHT_ARROW, TIMES,      EMPTY_SET,
    //     , SOLID_BLOCK,  MEDIUM_BLOCK, COPYRIGHT, ELEMENT_OF, GBP,       EN_DASH,    EM_DASH,    NOT,      BULLET,      PLUS_MINUS, ,
    //     , _,            EXIT,         ,          ,           ,          ,           ,           ,         _,           ,           _
    // ),

    // // Emoji layer, for inputting my favourite emoji
    // [_EMOJI] = KC_KEYMAP(
    //     GRIN,        FLUSHED,    WEARY,   WINK,        ROLLING_EYES,   THINKING,    SHUSH,   CHECK,    POINT_RIGHT, EYES,     MONEY,    ,
    //     SWEAT_SMILE, HEART_EYES, SOB,     WINK_KISS,   RAISED_EYEBROW, UPSIDE_DOWN, GRIMACE, WARNING,  OK_HAND,     BRAIN,    SPARKLES, SWEAT,
    //     JOY,         ZANY,       PENSIVE, WINK_TONGUE, UNAMUSED,       POOP,        TRIUMPH, NO_ENTRY, CLAP,        B_BUTTON, HUNDRED,  HEARTS,
    //     SMILE,       PLEADING,   EXIT,    SMIRK,       ,               ,            ,        ,         THUMBS_UP,   PRAY,     FIRE,
    // ),

    // Clip Studio Paint layer, for quick access to my most used tools and shortcuts
    [_CSP] = KEYMAP(
        C(KC_EQL),  C(KC_0),     KC_MINS,     KC_QUOT,     TD(CSP_M), KC_T,    KC_U,    KC_W,    KC_J,    KC_R,    ___X___, ___X___,
        C(KC_MINS), ALT_T(KC_3), CTL_T(KC_2), SFT_T(KC_1), KC_G,      KC_P,    KC_B,    KC_E,    KC_I,    KC_H,    ___X___, ___X___,
        C(KC_Z),    TD(X_CX),    TD(C_CC),    TD(CSP_F),   TD(CSP_K), KC_COMM, KC_DOT,  KC_0,    KC_Y,    KC_SLSH, ___X___, ___X___,
        KC_PMNS,    KC_PPLS,     C(KC_T),     KC_TAB,      TD(CSP_L), C(KC_S), C(KC_S), C(KC_N), C(KC_O), C(KC_W), ___X___, TG(_CSP)
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  switch (get_highest_layer(state)) {
    case _NUMPAD:
    case _CSP:
    // case _GREEK:
    // case _SYMBOLS:
    // case _EMOJI:
      rgblight_setrgb(0x99, 0xF5, 0xFF);
      break;
    case _LOWER:
      rgblight_setrgb(0x7A, 0xFF, 0x00);
      break;
    case _RAISE:
      rgblight_setrgb(0xBD, 0x00, 0xFF);
      break;
    case _ADJUST:
      rgblight_setrgb(0xFF, 0x7A, 0x00);
      break;
    default:
      rgblight_setrgb(RGB_OFF);
      break;
  }
  return state;
}

// Set initial light to be off
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_setrgb(RGB_OFF);
}

// Make default layer switching persistent
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
    case COLEMAK_DH:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK_DH);
        }
        return false;
        break;
    }
    return true;
}

// Set per key tapping term to differentiate between strong and weak fingers
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LOWER:
        case KC_RAISE:
            return 150;
        case GUI_T(KC_A):
        case GUI_T(KC_O):
            return 250;
        case ALT_T(KC_R):
        case ALT_T(KC_I):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

// Enable HOLD_ON_OTHER_KEY_PRESS for just the LT keys
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LOWER:
        case KC_RAISE:
        case KC_FNTAB:
            return true;
        default:
            return false;
    }
}
