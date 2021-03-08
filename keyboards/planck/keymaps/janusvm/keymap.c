#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum unicode_names {
    AE_L,
    AE_U,
    OE_L,
    OE_U,
    AA_L,
    AA_U,
    U_HALF,
    U_SQRD,
    U_EUR,
    U_REG,
    U_TM,
    U_ALPHA,
    U_SIGMA,
    U_DIFF,
    U_INT,
    U_GRAD,
    U_MULT,
    U_ARROW,
    U_CHI,
    U_CR,
    U_BLOCK,
    U_BETA,
    U_END,
    U_EMD,
    U_DEG,
    U_BULLET,
    U_NOT,
    U_GBP
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_L]     = L'æ',
    [AE_U]     = L'Æ',
    [OE_L]     = L'ø',
    [OE_U]     = L'Ø',
    [AA_L]     = L'å',
    [AA_U]     = L'Å',
    [U_HALF]   = L'½',
    [U_SQRD]   = L'²',
    [U_EUR]    = L'€',
    [U_REG]    = L'®',
    [U_TM]     = L'™',
    [U_ALPHA]  = L'ɑ',
    [U_SIGMA]  = L'σ',
    [U_DIFF]   = L'∂',
    [U_INT]    = L'∫',
    [U_GRAD]   = L'∇',
    [U_MULT]   = L'×',
    [U_ARROW]  = L'→',
    [U_CHI]    = L'χ',
    [U_CR]     = L'©',
    [U_BLOCK]  = L'█',
    [U_BETA]   = L'β',
    [U_END]    = L'–',
    [U_EMD]    = L'—',
    [U_DEG]    = L'°',
    [U_BULLET] = L'•',
    [U_NOT]    = L'¬',
    [U_GBP]    = L'£'
};

// TODO: https://emacs.stackexchange.com/questions/55994/unicode-input-from-keyboard-qmk-to-emacs
#define KC_AE XP(AE_L, AE_U)
#define KC_OE XP(OE_L, OE_U)
#define KC_AA XP(AA_L, AA_U)

// Layer modifiers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Mod-tap keys
#define C_ESC LCTL_T(KC_ESC)
#define LS_CAPS LSFT_T(KC_CAPS)
#define RS_ENT RSFT_T(KC_ENT)
#define C_BSPC LCTL(KC_BSPC)
#define C_DEL LCTL(KC_DEL)

// Combined modifiers
#define CTL_ALT LCA(KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        C_ESC,   KC_A,    KC_S,   KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        LS_CAPS, KC_Z,    KC_X,   KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
        CTL_ALT, KC_LGUI, KC_APP, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
        ),

    [_LOWER] = LAYOUT_planck_grid(
        C_DEL,   X(U_HALF),  X(U_SQRD),  X(U_EUR),  X(U_REG),   X(U_TM),   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,      KC_AA,   C_BSPC,
        KC_LCTL, X(U_ALPHA), X(U_SIGMA), X(U_DIFF), X(U_INT),   X(U_GRAD), KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,    KC_AE,   X(U_MULT),
        KC_LSFT, X(U_ARROW), X(U_CHI),   X(U_CR),   X(U_BLOCK), X(U_BETA), X(U_END), X(U_EMD), X(U_DEG), X(U_BULLET), KC_OE,   X(U_NOT),
        _______, _______,    _______,    _______,   _______,    KC_ENT,    KC_ENT,   _______,  _______,  _______,     _______, _______
        ),

    [_RAISE] = LAYOUT_planck_grid(
        KC_ESC,  KC_EXLM, KC_AT,   KC_HASH,  KC_AMPR, KC_LBRC, KC_RBRC, KC_7,    KC_8, KC_9,    KC_EQL,  KC_DEL,
        KC_LCTL, KC_CIRC, KC_DLR,  X(U_GBP), KC_PERC, KC_LPRN, KC_RPRN, KC_4,    KC_5, KC_6,    KC_PLUS, KC_ASTR,
        KC_LSFT, KC_BSLS, KC_PIPE, KC_GRV,   KC_TILD, KC_LCBR, KC_RCBR, KC_1,    KC_2, KC_3,    KC_MINS, KC_UNDS,
        _______, _______, _______, _______,  _______, KC_ENT,  KC_ENT,  _______, KC_0, KC_DOT,  KC_COMM, _______
        ),

    [_ADJUST] = LAYOUT_planck_grid(
        RESET,   KC_BTN1, KC_MS_U, KC_BTN2, RGB_TOG, RGB_HUD, RGB_HUI, KC_F7,   KC_F8,   KC_F9,   KC_F12,  UC_M_WC,
        KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, AU_TOG,  RGB_SAD, RGB_SAI, KC_F4,   KC_F5,   KC_F6,   KC_F11,  UC_M_MA,
        KC_LSFT, KC_PSCR, KC_INS,  KC_CAPS, MU_TOG,  RGB_VAD, RGB_VAI, KC_F1,   KC_F2,   KC_F3,   KC_F10,  UC_M_LN,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
        )

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
