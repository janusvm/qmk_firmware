#ifndef __TAPDANCE_H_
#define __TAPDANCE_H_

typedef enum {
  TD_NONE,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD
} td_state_t;

enum planck_tap_dances {
    Z_CZ,
    X_CX,
    C_CC,
    D_CV,
    CSP_F,
    CSP_K,
    CSP_L,
    CSP_M
};

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
            else return TD_SINGLE_HOLD;
        case 2:
            if (state->pressed) return TD_DOUBLE_HOLD;
            else return TD_DOUBLE_TAP;
        default: return TD_NONE;
    }
}

// Z, X, and C tap dances: Ctrl'd keystroke on hold ----------------------------
static td_state_t z_cz_state = TD_NONE;
void z_cz_finished(qk_tap_dance_state_t *state, void *user_data) {
    z_cz_state = cur_dance(state);
    switch (z_cz_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_Z);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            tap_code(KC_Z);
            register_code(KC_Z);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(C(KC_Z));
            break;
        default: break;
    }
}
void z_cz_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (z_cz_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_Z);
            break;
        default: break;
    }
    z_cz_state = TD_NONE;
}

static td_state_t x_cx_state = TD_NONE;
void x_cx_finished(qk_tap_dance_state_t *state, void *user_data) {
    x_cx_state = cur_dance(state);
    switch (x_cx_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_X);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            tap_code(KC_X);
            register_code(KC_X);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(C(KC_X));
            break;
        default: break;
    }
}
void x_cx_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (x_cx_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_X);
            break;
        default: break;
    }
    x_cx_state = TD_NONE;
}

static td_state_t c_cc_state = TD_NONE;
void c_cc_finished(qk_tap_dance_state_t *state, void *user_data) {
    c_cc_state = cur_dance(state);
    switch (c_cc_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_C);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            tap_code(KC_C);
            register_code(KC_C);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(C(KC_C));
            break;
        default: break;
    }
}
void c_cc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (c_cc_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_C);
            break;
        default: break;
    }
    c_cc_state = TD_NONE;
}

// D tap dance: D when tapped, C-v when held (for Colemak-DH) ------------------
static td_state_t d_cv_state = TD_NONE;
void d_cv_finished(qk_tap_dance_state_t *state, void *user_data) {
    d_cv_state = cur_dance(state);
    switch (d_cv_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_D);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            tap_code(KC_D);
            register_code(KC_D);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(C(KC_V));
            break;
        default: break;
    }
}
void d_cv_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (d_cv_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_D);
            break;
        default: break;
    }
    d_cv_state = TD_NONE;
}

// CSP L tap dance -------------------------------------------------------------
// - L when tapped (light table tool)
// - Space when held (pan canvas)
static td_state_t csp_l_state = TD_NONE;
void csp_l_finished(qk_tap_dance_state_t *state, void *user_data) {
    csp_l_state = cur_dance(state);
    switch (csp_l_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_L);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_SPC);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            tap_code(KC_L);
            tap_code(KC_L);
            break;
        default: break;
    }
}
void csp_l_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (csp_l_state) {
    case TD_SINGLE_HOLD:
        unregister_code(KC_SPC);
        break;
    default: break;
    }
    csp_l_state = TD_NONE;
}

// CSP M tap dance -------------------------------------------------------------
// - Send m when tapped once (lasso tool)
// - Send C-a when double tapped (select all)
// - Send C-m when held (toggle quick mask)
// - Send C-a C-m when tapped-then-held (quick mask whole canvas)
static td_state_t csp_m_state = TD_NONE;
void csp_m_finished(qk_tap_dance_state_t *state, void *user_data) {
    csp_m_state = cur_dance(state);
    switch (csp_m_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_M);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(C(KC_A));
            break;
        case TD_SINGLE_HOLD:
            tap_code16(C(KC_M));
            break;
        case TD_DOUBLE_HOLD:
            tap_code16(C(KC_A));
            tap_code16(C(KC_M));
            break;
        default: break;
    }
}
void csp_m_reset(qk_tap_dance_state_t *state, void *user_data) {
    csp_m_state = TD_NONE;
}

// CSP K tap dance -------------------------------------------------------------
// - Send k when tapped (move layer tool)
// - Send o when held (object tool)
// - Send d when double tapped (select layer tool)
static td_state_t csp_k_state = TD_NONE;
void csp_k_finished(qk_tap_dance_state_t *state, void *user_data) {
    csp_k_state = cur_dance(state);
    switch (csp_k_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_K);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_O);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            tap_code(KC_D);
            break;
        default: break;
    }
}
void csp_k_reset(qk_tap_dance_state_t *state, void *user_data) {
    csp_k_state = TD_NONE;
}

// CSP F tap dance -------------------------------------------------------------
// - Send F when tapped (custom brush tool, not a default binding)
// - Send C-v when held (paste)
static td_state_t csp_f_state = TD_NONE;
void csp_f_finished(qk_tap_dance_state_t *state, void *user_data) {
    csp_f_state = cur_dance(state);
    switch (csp_f_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_F);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            tap_code(KC_F);
            register_code(KC_F);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(C(KC_V));
            break;
        default: break;
    }
}
void csp_f_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (csp_f_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F);
            break;
        default: break;
    }
    csp_f_state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [Z_CZ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_cz_finished, z_cz_reset),
    [X_CX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_cx_finished, x_cx_reset),
    [C_CC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, c_cc_finished, c_cc_reset),
    [D_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, d_cv_finished, d_cv_reset),
    [CSP_F] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, csp_f_finished, csp_f_reset),
    [CSP_K] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, csp_k_finished, csp_k_reset),
    [CSP_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, csp_l_finished, csp_l_reset),
    [CSP_M] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, csp_m_finished, csp_m_reset)
};

#define KC_Z_CZ TD(Z_CZ)
#define KC_X_CX TD(X_CX)
#define KC_C_CC TD(C_CC)
#define KC_D_CV TD(D_CV)
#define KC_CSP_F TD(CSP_F)
#define KC_CSP_K TD(CSP_K)
#define KC_CSP_L TD(CSP_L)
#define KC_CSP_M TD(CSP_M)

#endif // __TAPDANCE_H_
