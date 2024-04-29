#define SOLARPIN A0
#define THRESHOLD 550

int ambientReading = 0;

void setup() {
  pinMode(SOLARPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Reading the ambient light intensity
  ambientReading = analogRead(A0);
  
  // Check if the ambient light intensity crosses the threshold
  if (ambientReading > THRESHOLD) {
    int bits[8];

    // Start bit detection
    for (int i = 0; i < 8; i++) {
      if (analogRead(SOLARPIN) > THRESHOLD) {
        bits[i] = 1;
      } else {
        bits[i] = 0;
      }
      delay(10);
    }

    int m = 0;
    // Converting bits to character
    for (int j = 1; j < 8; j++) {
      if (bits[j] == 1) {
        m = m + (1 << (7 - j));
      }
    }
  
    char n = m;
    // Sending the character over serial
    Serial.print(n);
  }
}
