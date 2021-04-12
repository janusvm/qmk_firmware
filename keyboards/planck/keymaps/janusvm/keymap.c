#include QMK_KEYBOARD_H
#include "unicode.h"

// Layers
enum planck_layers {
    _QWERTY,
    _COLEMAK_DH,
    _NUMPAD,
    // _SYMBOLS,
    // _GREEK,
    // _EMOJI,
    // _CSP,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK_DH
};

#define KC_EXIT    KC_NO
#define KC_LOWER   MO(_LOWER)
#define KC_RAISE   MO(_RAISE)
// #define KC_NUMPAD  OSL(_NUMPAD)
// #define KC_GREEK   OSL(_GREEK)
// #define KC_SYMBOLS OSL(_SYMBOLS)
// #define KC_EMOJI   OSL(_EMOJI)
#define KC_NUMSPC  LT(_NUMPAD, KC_SPC)

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
#define KC_C_ALT  LCA(KC_NO)

// Misc keycodes
#define KC_ KC_TRNS
#define KC__ KC_NO
#define ___X___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default layer, based on ANSI QWERTY
    // [_QWERTY] = KC_KEYMAP(
    //     TAB,   Q,      W,   E,    R,     T,   Y,   U,     I,    O,     P,       BSPC,
    //     CESC,  A,      S,   D,    F,     G,   H,   J,     K,    L,     SCLN,    QUOT,
    //     SCAPS, Z,      X,   C,    V,     B,   N,   M,     COMM, DOT,   SLSH,    SENT,
    //     LGUI,  NUMPAD, APP, LALT, LOWER, SPC, SPC, RAISE, RALT, GREEK, SYMBOLS, EMOJI
    // ),

    [_QWERTY] = HRM_KEYMAP_kc(
        Q,    W,   E,    R,     T,      _,    _,    Y,    U,     I,    O,   P,
        A,    S,   D,    F,     G,      _,    _,    H,    J,     K,    L,   DEL,
        Z,    X,   C,    V,     B,      _,    _,    N,    M,     COMM, DOT, SLSH,
        CAPS, APP, TAB,  LOWER, NUMSPC, SENT, SENT, BSPC, RAISE, ESC,  _,   _
    ),

    // Default layer, based on ANSI Colemak-DHm
    // [_COLEMAK_DH] = KC_KEYMAP(
    //     TAB,   Q,      W,   F,    P,     B,   J,   L,     U,    Y,     SCLN,    BSPC,
    //     CESC,  GA,     AR,  CS,   ST,    G,   M,   SN,    CE,   AI,    GO,      QUOT,
    //     SCAPS, Z,      X,   C,    D,     V,   K,   H,     COMM, DOT,   SLSH,    SENT,
    //     LGUI,  NUMPAD, APP, LALT, LOWER, SPC, SPC, RAISE, RALT, GREEK, SYMBOLS, EMOJI
    // ),

    [_COLEMAK_DH] = HRM_KEYMAP_kc(
        Q,    W,   F,    P,     B,      _,    _,    J,    L,     U,    Y,   DEL,
        A,    R,   S,    T,     G,      _,    _,    M,    N,     E,    I,   O,
        Z,    X,   C,    D,     V,      _,    _,    K,    H,     COMM, DOT, SLSH,
        CAPS, APP, TAB,  LOWER, NUMSPC, SENT, SENT, BSPC, RAISE, ESC,  _,   _
    ),

    // DEL layer, with a number row, arrow keys, and some shortcuts
    // [_LOWER] = KC_KEYMAP(
    //     C_DEL, 1,   2,   3,    4,    5,   6,    7,    8,    9,     0, C_BSPC,
    //     ,      C_A, C_S, LGUI, LALT, _,   LEFT, DOWN, UP,   RIGHT, _, ,
    //     ,      C_Z, C_X, C_C,  C_V,  _,   HOME, PGDN, PGUP, END,   _, ,
    //     ,      ,    ,    ,     ,     ENT, ENT,  ,     ,     ,      ,
    // ),

    [_LOWER] = HRM_L_KEYMAP_kc(
        1,   2,   3,   4,   5,   _, _, PGUP,   HOME, UP,   END,   C_DEL,
        6,   7,   8,   9,   0,   _, _, PGDN,   LEFT, DOWN, RIGHT, _,
        C_Z, C_X, C_C, C_V, C_S, _, _, _,      AE,   OE,   AA,    _,
        _,   _,   ,    ,    ,    ,  ,  C_BSPC, ,     ,     _,     _
    ),

    // Raise layer, with common symbols and Danish letters
    // [_RAISE] = KC_KEYMAP(
    //     ESC, EXLM, AT,   LCBR, RCBR, PERC, AMPR, LT,   GT,   EQL,  AA,   DEL,
    //     ,    CIRC, DLR,  LBRC, RBRC, HASH, ASTR, LPRN, RPRN, PLUS, AE,   OE,
    //     ,    BSLS, PIPE, GRV,  TILD, QUOT, DQUO, COLN, UNDS, MINS, QUES, ,
    //     ,    ,     ,     ,     ,     ENT,  ENT,  ,     ,     ,     ,
    // ),

    [_RAISE] = KC_KEYMAP(
        EXLM, AT,   LCBR, RCBR, PERC, _, _, AMPR, LT,   GT,   EQL,  DQUO,
        CIRC, DLR,  LBRC, RBRC, HASH, _, _, ASTR, LPRN, RPRN, PLUS, QUOT,
        BSLS, PIPE, GRV,  SCLN, _,    _, _, _,    COLN, UNDS, MINS, QUES,
        _,    _,    RALT, ,     TILD, ,  ,  ,     ,     ,     _,    _
    ),

    // Adjust layer, with mouse keys and board settings
    // [_ADJUST] = KEYMAP(
    //     RESET,   KC_VOLU, KC_BRIU, QWERTY,     RGB_TOG, ___X___, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN5, ___X___, UC_M_WC,
    //     _______, KC_VOLD, KC_BRID, COLEMAK_DH, AU_TOG,  ___X___, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ___X___, UC_M_MA,
    //     _______, KC_PSCR, KC_INS,  KC_CAPS,    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, UC_M_LN,
    //     _______, _______, KC_EXIT, _______,    _______, KC_WHOM, KC_WHOM, _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY
    // ),

    [_ADJUST] = KEYMAP(
        QWERTY,     ___X___, KC_BRIU, KC_VOLU, RGB_TOG, RESET,   UC_M_WC, ___X___, KC_BTN1, KC_MS_U, KC_BTN2, ___X___,
        COLEMAK_DH, ___X___, KC_BRID, KC_VOLD, AU_TOG,  DEBUG,   UC_M_MA, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,
        KC_MAIL,    KC_CALC, KC_WHOM, KC_MYCM, ___X___, ___X___, UC_M_LN, ___X___, ___X___, ___X___, ___X___, ___X___,
        ___X___,    ___X___, _______, _______, _______, _______, _______, _______, _______, _______, ___X___, ___X___
    ),

    // Numpad layer, with function keys and a numpad
    // [_NUMPAD] = KC_KEYMAP(
    //     , F1, F2,   F3,  F4,  7, 8, 9, COLN, EQL,  CIRC, ,
    //     , F5, F6,   F7,  F8,  4, 5, 6, MINS, PLUS, ASTR, ,
    //     , F9, F10,  F11, F12, 1, 2, 3, ,     ,     ,     ,
    //     , ,   EXIT, ,    ,    0, 0, ,  ,     _,    _,    _
    // ),

    [_NUMPAD] = HRM_L_KEYMAP_kc(
        F1,  F2,  F3, F4, F5,   _, _, COMM, 7,   8, 9, EQL,
        F6,  F7,  F8, F9, F10,  _, _, ASTR, 4,   5, 6, PLUS,
        F11, F12, _,  _,  PSCR, _, _, MINS, 1,   2, 3, SLSH,
        _,   _,   ,   ,   ,     ,  ,  ,     DOT, 0, _, _
    )

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

    // // TODO Clip Studio Paint layer, for quick access to my most used tools and shortcuts
    // [_CSP] = KC_KEYMAP(
    //    ,,,,,,,,,,,,
    //    ,,,,,,,,,,,,
    //    ,,,,,,,,,,,,
    //    ,,,,,,,,,,,
    // )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  switch (get_highest_layer(state)) {
    case _NUMPAD:
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
