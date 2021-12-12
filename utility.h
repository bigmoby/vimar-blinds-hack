void reset_selettore_tapparelle() {
  for (int i = 0; i < 15; i++) {
    id(relaySelectMinus).turn_on();
    delay(400);
    id(relaySelectMinus).turn_off();
  }
}

void set_selettore_tapparelle(int scena_tapparella_attuale, int scena_tapparella_voluta) {
  delay(13000);

  id(relayStop).turn_on();
  delay(200);
  id(relayStop).turn_off();

  delay(500);

  int step = scena_tapparella_voluta - scena_tapparella_attuale;

  if (step > 0) {
    for (int i = 0; i < step; i++) {
      id(relaySelectPlus).turn_on();
      delay(150);
      id(relaySelectPlus).turn_off();
      delay(150);
    }
  } else {
    int abs_value_step = abs(step);
    for (int i = 0; i < abs_value_step; i++) {
      id(relaySelectMinus).turn_on();
      delay(150);
      id(relaySelectMinus).turn_off();
      delay(150);
    }
  }
}