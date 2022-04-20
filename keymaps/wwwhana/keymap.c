#include QMK_KEYBOARD_H
#include "keymap_user.h"

// windows task Manager

user_config_t user_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_k87_ansi(
        KC_ESC,                 KC_F1,      KC_F2,   KC_F3,      KC_F4,   KC_F5,   KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_SLCK,    KC_PAUSE,
        KC_GRV,     KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,    KC_PGUP,
        KC_TAB,     KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN,
        KC_CAPS,    KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,
        KC_LSFT,                KC_Z,       KC_X,    KC_C,       KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,                KC_UP,
        KC_LCTL,    KC_LGUI,    KC_LALT,                                  KC_SPC,                                      KC_RALT,    MO(_FN),    KC_APP,     KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),
    [_MAC] = LAYOUT_k87_ansi(
        _______,                _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,    _______,      _______,    _______,    _______,    _______,    _______,   _______,
        _______,    _______,    _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,    _______,      _______,    _______,    _______,    _______,    _______,   _______,
        _______,    _______,    _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,    _______,      _______,    _______,    _______,    _______,    _______,   _______,
        _______,    _______,    _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,  TD(TD_COL), TD(TD_QUOT),                _______,
        _______,                _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,    _______,      _______,                _______,                _______,
        _______,    KC_LOPT,    KC_LCMD,                                  _______,                                      KC_RCMD,     _______,    KC_ROPT,    KC_RCTL,    _______,    _______,    _______
    ),
    [_NUM] = LAYOUT_k87_ansi(
	    _______,                _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
	    _______,    KC_ACL0,    KC_ACL1,    KC_ACL2, _______,    _______, _______, _______,    _______,    _______,    KC_PAST,    KC_PMNS,    KC_PPLS,    KC_BSPC,    _______,    _______,    _______,
	    _______,    KC_BTN1,    KC_MS_U,    KC_BTN2, _______,    _______, _______, _______,    _______,      KC_P7,      KC_P8,      KC_P9,     KC_NUM,    KC_PSLS,    _______,    _______,    _______,
	    _______,    KC_MS_L,    KC_MS_D,    KC_MS_R, _______,    _______, _______, _______,    _______,      KC_P4,      KC_P5,      KC_P6,                 KC_ENT,
	    _______,                KC_WH_L,    KC_WH_U, KC_WH_R,    _______, _______, _______,    _______,      KC_P1,      KC_P2,      KC_P3,                _______,                _______,
	    _______,    _______,    KC_WH_D,                                    KC_P0,                                     KC_PDOT,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_FN] = LAYOUT_k87_ansi(
	 TD(TD_RST),                KC_MSEL,      KC_VOLD, KC_VOLU,    KC_MUTE, KC_MSTP, KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MAIL,    KC_WHOM,    KC_CALC,    RGB_TOG,    NK_ON,      NK_OFF,     KC_SLEP,
		_______,       PB_1,       PB_2,         PB_3,    PB_4,       PB_5,    PB_6,    PB_7,       PB_8,       PB_9,      PB_10,    RGB_SPD,    RGB_SPI,    _______,    RGB_M_P,    RGB_M_B,    RGB_M_R,
		_______,    _______,    _______,      _______, _______,      KC_TM, _______, _______,    _______,    _______,    DM_REC1,    DM_REC2,    DM_RSTP,    _______,    RGB_M_SW,   RGB_MOD,    RGB_RMOD,
		_______,    _______,    _______,      _______, _______,    _______, _______, _______,    _______,    _______,    DM_PLY1,    DM_PLY2,                _______,
		_______,                _______,      _______, _______,    _______, _______, _______,       T_WM,    RGB_SAI,    RGB_SAD,      T_NUM,                _______,                RGB_VAI,
		_______,    _______,    _______,                                    _______,                                     KC_LNG1,    _______,    KC_LNG2,    _______,    RGB_HUD,    RGB_VAD,    RGB_HUI
    ),
};

void switchWinMacLayer(void) {
    if(user_config.mac_layer_enabled) {
        layer_on(_MAC);
    } else {
        layer_off(_MAC);
    }
}

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
  user_config.num_layer_enabled = false;
  switchWinMacLayer();
}

void eeconfig_init_user(void) {
  user_config.mac_layer_enabled = false;
  user_config.num_layer_enabled = false;
  eeconfig_update_user(user_config.raw);
  switchWinMacLayer();
}


void dance_bootloader_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // register_code16(KC_ESC);
    }
}

void dance_bootloader_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        eeconfig_init();
        eeconfig_init_user();
        // unregister_code16(KC_ESC);
    } else {
        reset_keyboard();
    }
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_bootloader_finished, dance_bootloader_reset),
    [TD_COL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
        }
        case T_WM:
        {
        if (record->event.pressed) {
            user_config.mac_layer_enabled = !user_config.mac_layer_enabled;
            eeconfig_update_user(user_config.raw);
            switchWinMacLayer();
            return false;
        }
        }
        case T_NUM:
        {
        if (record->event.pressed) {
            user_config.num_layer_enabled = !user_config.num_layer_enabled;
            eeconfig_update_user(user_config.raw);
            if(user_config.num_layer_enabled) {
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
            }
            return false;   
        }
        }
    }
    return true;
};
