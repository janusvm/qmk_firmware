#include QMK_KEYBOARD_H
#include "muse.h"
#include "unicode.h"

// Layers
enum planck_layers {
    _QWERTY,
    _NUMPAD,
    _SYMBOLS,
    _GREEK,
    _EMOJI,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define KC_EXIT    TO(_QWERTY)
#define KC_LOWER   MO(_LOWER)
#define KC_RAISE   MO(_RAISE)
#define KC_NUMPAD  TT(_NUMPAD)
#define KC_GREEK   TT(_GREEK)
#define KC_SYMBOLS TT(_SYMBOLS)
#define KC_EMOJI   TT(_EMOJI)

// Mod-tap keys
#define KC_CESC  LCTL_T(KC_ESC)
#define KC_SCAPS LSFT_T(KC_CAPS)
#define KC_CQUOT RCTL_T(KC_QUOT)
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

// TODO: Language toggle buttons
// TODO: https://emacs.stackexchange.com/questions/55994/unicode-input-from-keyboard-qmk-to-emacs
#define EN_MODE KC_NO
#define DA_MODE KC_NO

// Misc keycodes
#define KC_ KC_TRNS
#define KC__ KC_NO
#define ___X___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default layer, based on ANSI QWERTY
    [_QWERTY] = KC_KEYMAP(
        TAB,  Q,      W,   E,    R,     T,   Y,   U,     I,    O,     P,       BSPC,
        CESC, A,      S,   D,    F,     G,   H,   J,     K,    L,     SCLN,    QUOT,
        LSFT, Z,      X,   C,    V,     B,   N,   M,     COMM, DOT,   SLSH,    SENT,
        LGUI, NUMPAD, APP, LALT, LOWER, SPC, SPC, RAISE, RALT, GREEK, SYMBOLS, EMOJI
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
        RESET,   KC_VOLU, KC_BRIU, EN_MODE, RGB_TOG, ___X___, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN5, ___X___, UC_M_WC,
        _______, KC_VOLD, KC_BRID, DA_MODE, AU_TOG,  ___X___, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ___X___, UC_M_MA,
        _______, KC_PSCR, KC_INS,  KC_CAPS, MU_TOG,  ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, UC_M_LN,
        _______, _______, KC_EXIT, _______, _______, KC_WHOM, KC_WHOM, _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY
    ),

    // Numpad layer, with function keys and a numpad
    [_NUMPAD] = KC_KEYMAP(
        , F1, F2,   F3,  F4,  7, 8, 9, COLN, EQL,  CIRC, ,
        , F5, F6,   F7,  F8,  4, 5, 6, MINS, PLUS, ASTR, ,
        , F9, F10,  F11, F12, 1, 2, 3, ,     ,     ,     ,
        , ,   EXIT,    ,    ,    0, 0, ,  ,     ,     ,
    ),

    // Greek layer, for entering Greek letters
    [_GREEK] = KC_KEYMAP(
        , THETA, OMEGA, EPSILON, RHO, TAU,   UPSILON, PSI, IOTA,  OMICRON, PI, ,
        , ALPHA, SIGMA, DELTA,   PHI, GAMMA, ETA,     _,   KAPPA, LAMBDA,  ,   ,
        , ZETA,  XI,    CHI,     _,   BETA,  NU,      MU,  ,      ,        ,   ,
        , ,      EXIT,  ,        ,    ,      ,        ,    ,      ,        ,
    ),

    // Symbols layer, for entering special characters
    [_SYMBOLS] = KC_KEYMAP(
        , HALF,         SQUARED,      EURO,      REGISTERED, TRADEMARK, JPY,        UNION,      INFTY,    NEQ,         DEGREES,    ,
        , INTERSECTION, SQRT,         PARTIAL,   INTEGRAL,   GRADIENT,  LEFT_ARROW, DOWN_ARROW, UP_ARROW, RIGHT_ARROW, TIMES,      EMPTY_SET,
        , SOLID_BLOCK,  MEDIUM_BLOCK, COPYRIGHT, ELEMENT_OF, GBP,       EN_DASH,    EM_DASH,    NOT,      BULLET,      PLUS_MINUS, ,
        , ,             EXIT,         ,          ,           ,          ,           ,           ,         ,            ,
    ),

    // Emoji layer, for inputting my favourite emoji
    [_EMOJI] = KC_KEYMAP(
        GRIN,        FLUSHED,    WEARY,   WINK,        ROLLING_EYES,   THINKING,    SHUSH,   CHECK,    POINT_RIGHT, EYES,     MONEY,    ,
        SWEAT_SMILE, HEART_EYES, SOB,     WINK_KISS,   RAISED_EYEBROW, UPSIDE_DOWN, GRIMACE, WARNING,  OK_HAND,     BRAIN,    SPARKLES, SWEAT,
        JOY,         ZANY,       PENSIVE, WINK_TONGUE, UNAMUSED,       POOP,        TRIUMPH, NO_ENTRY, CLAP,        B_BUTTON, HUNDRED,  HEARTS,
        SMILE,       PLEADING,   EXIT,    SMIRK,       ,               ,            ,        ,         THUMBS_UP,   PRAY,     FIRE,
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

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case KC_RAISE:
    case KC_LOWER:
      return false;
    default:
      return true;
  }
}
