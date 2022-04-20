void reset_selettore_tapparelle() {
  for (int i = 0; i < 15; i++) {
    id(relaySelectMinus).turn_on();
    delay(400);
    id(relaySelectMinus).turn_off();
  }
}

void set_selettore_tapparelle(int scena_tapparella_voluta) {
  
  id(relay8).turn_on(); // Disalimento il telecomando
  delay(200);
  id(relayStop).turn_on(); // workaround per fare scaricare il circuito dalla corrente residua
  delay(500);
  id(relayStop).turn_off();
  delay(200);
  id(relay8).turn_off();
  
  delay(200);

  id(relayStop).turn_on();
  delay(200);
  id(relayStop).turn_off();

  delay(500);

  int scena_tapparella_attuale = 1; // dopo il reset il telecomando parte sempre da 1
  int step = scena_tapparella_voluta - scena_tapparella_attuale;
  
  for (int i = 0; i < step; i++) {
    id(relaySelectPlus).turn_on();
    delay(150);
    id(relaySelectPlus).turn_off();
    delay(150);
  }
 
}