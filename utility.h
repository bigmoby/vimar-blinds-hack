void reset_selettore_tapparelle() {
  for (int i = 0; i < 15; i++) {
    id(relaySelectMinus).turn_on();
    delay(300);
    id(relaySelectMinus).turn_off();
  }
}

void set_selettore_tapparelle(int scena_tapparella_attuale, int scena_tapparella_voluta) {
  int step = scena_tapparella_voluta - scena_tapparella_attuale;

  if (step > 0) {
    for (int i = 0; i < step; i++) {
      id(relaySelectPlus).turn_on();
      delay(300);
      id(relaySelectPlus).turn_off();
    }
  } else {
    int abs_value_step = abs(step);
    for (int i = 0; i < abs_value_step; i++) {
      id(relaySelectMinus).turn_on();
      delay(300);
      id(relaySelectMinus).turn_off();
    }
  }
}