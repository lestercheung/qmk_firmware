#ifndef LC_COMBOS_H_
#define LC_COMBOS_H_

// Combos
// Handy generator here: https://codepen.io/mvaneijgen/full/LYEVQXp
enum combos {
  Q_W,
  T_Y,
  G_H,
  Y_U,
  U_I,
  I_O,
  O_P,
  M_COMM,
  L_QUOTE,
};

const uint16_t PROGMEM q_w[] = { KC_Q, KC_W, COMBO_END };
const uint16_t PROGMEM t_y[] = { KC_T, KC_Y, COMBO_END };
const uint16_t PROGMEM g_h[] = { KC_G, KC_H, COMBO_END };
const uint16_t PROGMEM y_u[] = { KC_Y, KC_U, COMBO_END };
const uint16_t PROGMEM u_i[] = { KC_U, KC_I, COMBO_END };
const uint16_t PROGMEM i_o[] = { KC_I, KC_O, COMBO_END };
const uint16_t PROGMEM o_p[] = { KC_O, KC_P, COMBO_END };
const uint16_t PROGMEM m_comm[] = { KC_M, KC_COMM, COMBO_END };
const uint16_t PROGMEM l_quote[] = { ALT_T(KC_L), CTL_T(KC_QUOTE), COMBO_END };

combo_t key_combos[] = {
  [Q_W] = COMBO(q_w, KC_GRAVE),
  [T_Y] = COMBO(t_y, KC_ESC),
  [G_H] = COMBO(g_h, KC_MINS),
  [Y_U] = COMBO(y_u, KC_PLUS),
  [U_I] = COMBO(u_i, KC_MINS),
  [I_O] = COMBO(i_o, KC_EQUAL),
  [O_P] = COMBO(o_p, KC_BSLS),
  [M_COMM] = COMBO(m_comm, KC_UNDERSCORE),
  [L_QUOTE] = COMBO(l_quote, KC_SCLN),
};



#endif // LC_COMBOS_H_
