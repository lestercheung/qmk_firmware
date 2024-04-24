#ifndef LC_TAPDANCE_H_
#define LC_TAPDANCE_H_

// Tab dance
enum {
  TD_SLASH_BACKSLASH,
  TD_MINUS_PLUS,
  TD_QUOT_SCLN,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_SLASH_BACKSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BACKSLASH),
    // Tap once for minus, twice for plus
    [TD_MINUS_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_PLUS),
    [TD_QUOT_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
};


#endif // TAPDANCE_H_
