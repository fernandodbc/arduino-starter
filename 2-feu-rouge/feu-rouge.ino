int etatDeLInterrupteur = LOW;
bool lancerLaBoucle = false;

void setup() {
  // ce code ne s'execute que quand la carte s'allume
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // tourne en boucle une fois que setup() a fini

  // lit le pin digital numéro 2 pour voir si l'electricité passe ou pas
  // s'il y a de la tension ca va retourner HIGH (1), sinon LOW (0)
  etatDeLInterrupteur = digitalRead(2);

  if (etatDeLInterrupteur == HIGH && lancerLaBoucle == true) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lancerLaBoucle = false;
    delay(250);
  } else if (etatDeLInterrupteur == HIGH && lancerLaBoucle == false) {
    lancerLaBoucle = true;
    delay(250);
  }
  

  if (lancerLaBoucle) {
    digitalWrite(3, HIGH);
    delay(8000);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    delay(1500);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(4000);
    digitalWrite(5, LOW);
  }

}
