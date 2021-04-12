// TODO:
// * Add a Clip Studio Paint layer
// * Rethink layers
//   - Fn layer is uncomfortable to use
//   - ÆØÅ worked better on Lower layer
// * Emacs UC mode

#include QMK_KEYBOARD_H
#include "unicode.h"

// Layers
enum planck_layers {
    _QWERTY,
    _COLEMAK_DH,
    _NUMPAD,
    _SYMBOLS,
    _GREEK,
    _EMOJI,
    _CSP,
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
#define KC_NUMPAD  OSL(_NUMPAD)
#define KC_GREEK   OSL(_GREEK)
#define KC_SYMBOLS OSL(_SYMBOLS)
#define KC_EMOJI   OSL(_EMOJI)

// Mod-tap keys
#define KC_CESC  LCTL_T(KC_ESC)
#define KC_SCAPS LSFT_T(KC_CAPS)
#define KC_CQUOT RCTL_T(KC_QUOT)
#define KC_SENT  RSFT_T(KC_ENT)
#define KC_GA    LGUI_T(KC_A)
#define KC_AR    LALT_T(KC_R)
#define KC_CS    LCTL_T(KC_S)
#define KC_ST    LSFT_T(KC_T)
#define KC_SN    RSFT_T(KC_N)
#define KC_CE    RCTL_T(KC_E)
#define KC_AI    LALT_T(KC_I)
#define KC_GO    RGUI_T(KC_O)

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
    [_QWERTY] = KC_KEYMAP(
        TAB,  Q,      W,   E,    R,     T,   Y,   U,     I,    O,     P,       BSPC,
        CESC, A,      S,   D,    F,     G,   H,   J,     K,    L,     SCLN,    QUOT,
        SCAPS, Z,      X,   C,    V,     B,   N,   M,     COMM, DOT,   SLSH,    SENT,
        LGUI, NUMPAD, APP, LALT, LOWER, SPC, SPC, RAISE, RALT, GREEK, SYMBOLS, EMOJI
    ),

    // Default layer, based on ANSI Colemak-DHm
    [_COLEMAK_DH] = KC_KEYMAP(
        TAB,   Q,      W,   F,    P,     B,   J,   L,     U,    Y,     SCLN,    BSPC,
        CESC,  GA,     AR,  CS,   ST,    G,   M,   SN,    CE,   AI,    GO,      QUOT,
        SCAPS, Z,      X,   C,    D,     V,   K,   H,     COMM, DOT,   SLSH,    SENT,
        LGUI,  NUMPAD, APP, LALT, LOWER, SPC, SPC, RAISE, RALT, GREEK, SYMBOLS, EMOJI
    ),

    // Lower layer, with a number row, arrow keys, and some shortcuts
    [_LOWER] = KC_KEYMAP(
        C_DEL, 1,   2,   3,    4,    5,   6,    7,    8,    9,     0, C_BSPC,
        ,      C_A, C_S, LGUI, LALT, _,   LEFT, DOWN, UP,   RIGHT, _, ,
        ,      C_Z, C_X, C_C,  C_V,  _,   HOME, PGDN, PGUP, END,   _, ,
        ,      ,    ,    ,     ,     ENT, ENT,  ,     ,     ,      ,
    ),

    // Raise layer, with common symbols and Danish letters
    [_RAISE] = KC_KEYMAP(
        ESC, EXLM, AT,   LCBR, RCBR, PERC, AMPR, LT,   GT,   EQL,  AA,   DEL,
        ,    CIRC, DLR,  LBRC, RBRC, HASH, ASTR, LPRN, RPRN, PLUS, AE,   OE,
        ,    BSLS, PIPE, GRV,  TILD, QUOT, DQUO, COLN, UNDS, MINS, QUES, ,
        ,    ,     ,     ,     ,     ENT,  ENT,  ,     ,     ,     ,
    ),

    // Adjust layer, with mouse keys and board settings
    [_ADJUST] = KEYMAP(
        RESET,   KC_VOLU, KC_BRIU, QWERTY,     RGB_TOG, ___X___, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN5, ___X___, UC_M_WC,
        _______, KC_VOLD, KC_BRID, COLEMAK_DH, AU_TOG,  ___X___, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ___X___, UC_M_MA,
        _______, KC_PSCR, KC_INS,  KC_CAPS,    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, UC_M_LN,
        _______, _______, KC_EXIT, _______,    _______, KC_WHOM, KC_WHOM, _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY
    ),

    // Numpad layer, with function keys and a numpad
    [_NUMPAD] = KC_KEYMAP(
        , F1, F2,   F3,  F4,  7, 8, 9, COLN, EQL,  CIRC, ,
        , F5, F6,   F7,  F8,  4, 5, 6, MINS, PLUS, ASTR, ,
        , F9, F10,  F11, F12, 1, 2, 3, ,     ,     ,     ,
        , ,   EXIT, ,    ,    0, 0, ,  ,     _,    _,    _
    ),

    // Greek layer, for entering Greek letters
    [_GREEK] = KC_KEYMAP(
        , THETA, OMEGA, EPSILON, RHO, TAU,   UPSILON, PSI, IOTA,  OMICRON, PI, ,
        , ALPHA, SIGMA, DELTA,   PHI, GAMMA, ETA,     _,   KAPPA, LAMBDA,  ,   ,
        , ZETA,  XI,    CHI,     _,   BETA,  NU,      MU,  ,      ,        ,   ,
        , _,     EXIT,  ,        ,    ,      ,        ,    ,      ,        _,  _
    ),

    // Symbols layer, for entering special characters
    [_SYMBOLS] = KC_KEYMAP(
        , HALF,         SQUARED,      EURO,      REGISTERED, TRADEMARK, JPY,        UNION,      INFTY,    NEQ,         DEGREES,    ,
        , INTERSECTION, SQRT,         PARTIAL,   INTEGRAL,   GRADIENT,  LEFT_ARROW, DOWN_ARROW, UP_ARROW, RIGHT_ARROW, TIMES,      EMPTY_SET,
        , SOLID_BLOCK,  MEDIUM_BLOCK, COPYRIGHT, ELEMENT_OF, GBP,       EN_DASH,    EM_DASH,    NOT,      BULLET,      PLUS_MINUS, ,
        , _,            EXIT,         ,          ,           ,          ,           ,           ,         _,           ,           _
    ),

    // Emoji layer, for inputting my favourite emoji
    [_EMOJI] = KC_KEYMAP(
        GRIN,        FLUSHED,    WEARY,   WINK,        ROLLING_EYES,   THINKING,    SHUSH,   CHECK,    POINT_RIGHT, EYES,     MONEY,    ,
        SWEAT_SMILE, HEART_EYES, SOB,     WINK_KISS,   RAISED_EYEBROW, UPSIDE_DOWN, GRIMACE, WARNING,  OK_HAND,     BRAIN,    SPARKLES, SWEAT,
        JOY,         ZANY,       PENSIVE, WINK_TONGUE, UNAMUSED,       POOP,        TRIUMPH, NO_ENTRY, CLAP,        B_BUTTON, HUNDRED,  HEARTS,
        SMILE,       PLEADING,   EXIT,    SMIRK,       ,               ,            ,        ,         THUMBS_UP,   PRAY,     FIRE,
    ),

    // TODO Clip Studio Paint layer, for quick access to my most used tools and shortcuts
    [_CSP] = KC_KEYMAP(
       ,,,,,,,,,,,,
       ,,,,,,,,,,,,
       ,,,,,,,,,,,,
       ,,,,,,,,,,,
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  switch (get_highest_layer(state)) {
    case _NUMPAD:
    case _GREEK:
    case _SYMBOLS:
    case _EMOJI:
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
