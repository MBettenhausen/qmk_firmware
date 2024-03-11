/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC │   1  │   2  │   3  │   4  │   5  │   -  │  │   =  │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   [  │  │   ]  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │FNCAPS│   A  │   S  │   D  │   F  │   G  │   (  │  │   )  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │   {  │  │   }  │   N  │   M  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │  Alt │  RGB │ ADJ  │      │ DEL  │  │ Enter│      │  FN  │ Left │ Down │ Up   │Right │
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Space├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ DEL  │  │ Enter│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _QWERTY,
    _SPECIAL,
    _GAME,
    _FN,
    _ADJUST
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

// Tap Dance declarations
enum {
    TD_F12,
    TD_F12_2,
    TD_ALTENTR_CTRLSHFTR
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, LCTL(KC_F12)),
    [TD_F12_2] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_F12), LALT(KC_F12)),
    [TD_ALTENTR_CTRLSHFTR] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_ENTER), LCTL(LSFT(KC_ENTER))),
};

// Two Key Combos
const uint16_t PROGMEM FD_CTRL[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM JK_CTRL[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM FS_ALT[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM JL_ALT[] = {KC_J, KC_L, COMBO_END};

const uint16_t PROGMEM FA_WIN[] = {KC_F, KC_A, COMBO_END};
const uint16_t PROGMEM JSEMI_WIN[] = {KC_J, KC_SEMICOLON, COMBO_END};

// Tree Key Combos
const uint16_t PROGMEM FDS_CTRL_ALT[] = {KC_F,KC_D , KC_S,  COMBO_END};
const uint16_t PROGMEM JKL_CTRL_ALT[] = {KC_J,KC_K , KC_L, COMBO_END};

const uint16_t PROGMEM FDA_CTRL_WIN[] = {KC_F,KC_D , KC_A,  COMBO_END};
const uint16_t PROGMEM JKSEMI_CTRL_WIN[] = {KC_J,KC_K , KC_SEMICOLON, COMBO_END};

const uint16_t PROGMEM FSA_ALT_WIN[] = {KC_F,KC_S , KC_A,  COMBO_END};
const uint16_t PROGMEM JLSEMI_ALT_WIN[] = {KC_J,KC_L , KC_SEMICOLON, COMBO_END};

const uint16_t PROGMEM FDSPACE_CTRL[] = {KC_F, KC_D, KC_SPACE, COMBO_END};
const uint16_t PROGMEM JKSPACE_CTRL[] = {KC_J, KC_K, KC_SPACE, COMBO_END};

const uint16_t PROGMEM FSSPACE_ALT[] = {KC_F, KC_S, KC_SPACE, COMBO_END};
const uint16_t PROGMEM JLSPACE_ALT[] = {KC_J, KC_L, KC_SPACE, COMBO_END};

const uint16_t PROGMEM FASPACE_WIN[] = {KC_F, KC_A, KC_SPACE, COMBO_END};
const uint16_t PROGMEM JSEMISPACE_WIN[] = {KC_J, KC_SEMICOLON, KC_SPACE, COMBO_END};

// Four Key Combos
const uint16_t PROGMEM FDSA_CTRL_ALT_WIN[] = {KC_F, KC_D, KC_S , KC_A,  COMBO_END};
const uint16_t PROGMEM JKLSEMI_CTRL_ALT_WIN[] = {KC_J,KC_K, KC_L , KC_SEMICOLON, COMBO_END};

const uint16_t PROGMEM FDSSPACE_CTRL_ALT[] = {KC_F,KC_D , KC_S, KC_SPACE, COMBO_END};
const uint16_t PROGMEM JKLSPACE_CTRL_ALT[] = {KC_J,KC_K , KC_L, KC_SPACE, COMBO_END};

const uint16_t PROGMEM FDASPACE_CTRL_WIN[] = {KC_F,KC_D , KC_A, KC_SPACE, COMBO_END};
const uint16_t PROGMEM JKSEMISPACE_CTRL_WIN[] = {KC_J,KC_K , KC_SEMICOLON,KC_SPACE,  COMBO_END};

const uint16_t PROGMEM FSASPACE_ALT_WIN[] = {KC_F,KC_S , KC_A, KC_SPACE, COMBO_END};
const uint16_t PROGMEM JLSEMISPACE_ALT_WIN[] = {KC_J,KC_L , KC_SEMICOLON, KC_SPACE, COMBO_END};

// Five Key Combos
const uint16_t PROGMEM FDSASPACE_CTRL_ALT_WIN[] = {KC_F, KC_D, KC_S , KC_A, KC_SPACE, COMBO_END};
const uint16_t PROGMEM JKLSEMISPACE_CTRL_ALT_WIN[] = {KC_J,KC_K, KC_L , KC_SEMICOLON, KC_SPACE, COMBO_END};

combo_t key_combos[] = {
    // Two Key Combos
        COMBO(FD_CTRL, KC_LEFT_CTRL),
        COMBO(JK_CTRL, KC_RIGHT_CTRL),

        COMBO(FS_ALT, KC_LEFT_ALT),
        COMBO(JL_ALT, KC_LEFT_ALT),

        COMBO(FA_WIN, KC_LEFT_GUI),
        COMBO(JSEMI_WIN, KC_RIGHT_GUI),
    // Tree Key Combos
        COMBO(FDS_CTRL_ALT, LALT(KC_LEFT_CTRL)),
        COMBO(JKL_CTRL_ALT, LALT(KC_RIGHT_CTRL)),

        COMBO(FDA_CTRL_WIN, LGUI(KC_RIGHT_CTRL)),
        COMBO(JKSEMI_CTRL_WIN, LGUI(KC_RIGHT_CTRL)),

        COMBO(FSA_ALT_WIN, LALT(KC_LEFT_GUI)),
        COMBO(JLSEMI_ALT_WIN, LALT(KC_LEFT_GUI)),

        COMBO(FDSPACE_CTRL, LSFT(KC_LEFT_CTRL)),
        COMBO(JKSPACE_CTRL, RSFT(KC_RIGHT_CTRL)),

        COMBO(FSSPACE_ALT, LSFT(KC_LEFT_ALT)),
        COMBO(JLSPACE_ALT, RSFT(KC_LEFT_ALT)),

        COMBO(FASPACE_WIN, LSFT(KC_LEFT_GUI)),
        COMBO(JSEMISPACE_WIN, RSFT(KC_RIGHT_GUI)),

    // Four Key Combos

        COMBO(FDSA_CTRL_ALT_WIN, LALT(LGUI(KC_LEFT_CTRL))),
        COMBO(JKLSEMI_CTRL_ALT_WIN, LALT(LGUI(KC_RIGHT_CTRL))),

        COMBO(FDSSPACE_CTRL_ALT, LSFT(LALT(KC_LEFT_CTRL))),
        COMBO(JKLSPACE_CTRL_ALT, RSFT(LALT(KC_RIGHT_CTRL))),

        COMBO(FDASPACE_CTRL_WIN, LSFT(LGUI(KC_RIGHT_CTRL))),
        COMBO(JKSEMISPACE_CTRL_WIN, RSFT(LGUI(KC_RIGHT_CTRL))),

        COMBO(FSASPACE_ALT_WIN, LSFT(LALT(KC_LEFT_GUI))),
        COMBO(JLSEMISPACE_ALT_WIN, RSFT(LALT(KC_LEFT_GUI))),
    // Five Key Combos
        COMBO(FDSASPACE_CTRL_ALT_WIN, LSFT(LALT(LGUI(KC_LEFT_CTRL)))),
        COMBO(JKLSEMISPACE_CTRL_ALT_WIN, RSFT(LALT(LGUI(KC_RIGHT_CTRL)))),

    
};

#define FN       MO(_FN)
#define ADJUST   MO(_ADJUST)
#define SPECIAL  LT(_SPECIAL)
#define GAME     DF(_GAME)
#define QWERTY   DF(_QWERTY)
#define FN_CAPS  LT(_FN, QK_CAPS_WORD_TOGGLE)
#define SPECIAL_BSPC LT(_SPECIAL, KC_BSPC)
#define SPECIAL_DEL LT(_SPECIAL, KC_DEL)
//#define RGB_ADJ  LT(_ADJUST, RGB_TOG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    LSFT(LALT(KC_PGDN)),                             KC_EQL,  KC_6,    KC_7,    KC_8    ,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TD(TD_F12),                          KC_RBRC, KC_Y,    KC_U,    KC_I    ,    KC_O,    KC_P,    KC_BSLS,
        FN_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    TD(TD_F12_2),                        KC_RPRN, KC_H,    KC_J,    KC_K    ,    KC_L,    KC_SCLN, KC_QUOT,
        SC_SENT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TD(TD_ALTENTR_CTRLSHFTR),                      KC_RCBR, KC_N,    KC_M,    KC_COMM , KC_DOT,  KC_SLSH, SC_SENT,
        KC_LCTL,  KC_LGUI, KC_LALT, KC_LEFT, KC_RIGHT,  KC_SPC,  KC_HOME, SPECIAL_BSPC,   SPECIAL_DEL,  KC_END, KC_SPC,  KC_DOWN, KC_UP, KC_RALT, ADJUST, KC_RCTL,

        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_MS_WH_DOWN, KC_MS_WH_UP, KC_PGDN, _______, KC_PGUP
    ),

    [_SPECIAL] = LAYOUT(
        _______, _______, _______, _______              , _______                   , _______          , _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,    KC_SCLN, _______,
        _______, KC_Q,LSFT(KC_MINUS), KC_LEFT_BRACKET      , KC_RIGHT_BRACKET       , KC_EQUAL         , _______,                   _______, _______, KC_P4,   KC_P5,   KC_P6,    KC_O, _______,
        _______, KC_A,    KC_GRAVE  , LSFT(KC_LEFT_BRACKET), LSFT(KC_RIGHT_BRACKET) , KC_MINUS         , _______,                   _______, _______, KC_P1,   KC_P2,   KC_P3,  KC_SLSH,    _______,
        _______, KC_Z,LSFT(KC_GRAVE), LSFT(KC_COMMA)       , LSFT(KC_DOT)           , LSFT(KC_EQUAL)   , _______,                   _______, _______, KC_P0,   KC_PDOT, KC_NUM, _______, _______,
        _______, _______, _______   , _______           , _______            , _______          , _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, KC_F1,                     KC_F5,   _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F2,                     KC_F6,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F3,                     KC_F7,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F4,                     KC_F8,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_FN] = LAYOUT(
        _______, KC_F1  , KC_F2     , KC_F3     ,   KC_F4   ,   KC_F5       ,  KC_F11 ,                    KC_F12     ,  KC_F6    ,   KC_F7   ,   KC_F8   ,   KC_F9   ,   KC_F10  ,  _______,
        _______, KC_HOME, KC_UP     , KC_END    ,  _______  , _______       ,  _______,                   _______     , KC_PGUP   , KC_HOME   , KC_UP     ,   KC_END  ,  KC_PSCR  , KC_PGUP,
        _______, KC_LEFT, KC_DOWN   , KC_RGHT   , _______   , _______       ,  _______,                   _______     , KC_PGDN   , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_INS    ,  KC_PGDN,
        _______, AU_TOGG, MU_TOGG   , MU_NEXT   , _______   , _______       ,  _______,                   _______     , _______   , _______   , _______   , _______   , _______   , _______,
        _______, CK_TOGG, CK_UP     , KC_MS_LEFT   , KC_MS_RIGHT, _______   ,  _______, _______, KC_MS_BTN2, KC_MS_BTN3  , KC_MS_BTN1, KC_MS_DOWN, KC_MS_UP  , KC_MUTE   , KC_VOLD   , KC_VOLU,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, QK_BOOT,   _______, _______,                   _______, _______, _______, _______, _______,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, DM_REC1,                   _______, _______,   _______, _______, _______,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, DM_RSTP,                   _______, _______,   AU_TOGG, MU_TOGG, MU_NEXT,   _______, GAME,
        _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______,   CK_TOGG,   CK_UP, CK_DOWN,  QWERTY,  _______,

        _______, _______, _______, _______, _______,                                                       RGB_VAD, RGB_VAI, _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        case _SPECIAL:
            oled_write_ln_P(PSTR("Colemk"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game  "), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN   "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
                  ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1 ... 4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                  ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
