const int dataPin = 11;
const int clockPin = 12;
const int latchPin = 8;

byte data = 0;

//String inputString = "";
int count = 0;
bool stringComplete = false;

// EXAMPLE 
// 0000000000000000000000000000000000000000000000000000011100000101000000010010000100010100100011111110111000001100000111100011111100000000000000000000000000000000000000001000000011100000000000000000010111000000111110001111110011111101111111001111111011111111

int pix[] = {
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,1,0,0,0,0,
  0,0,1,0,1,0,0,0,
  0,0,0,1,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,1,0,0,
  0,0,0,1,1,0,0,0,
  1,1,1,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,1,0,0,0,0,
  0,0,0,1,0,0,0,0,
  0,1,1,0,1,1,0,0,
  0,0,0,1,0,0,0,0,
  0,0,0,1,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,1,0,0,0,0,0,
  0,0,0,1,1,0,0,0,
  0,0,0,0,0,1,1,1,
  0,0,0,0,0,0,0,0
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  Serial.begin(115200);
  Serial.println("FREKVENS");

  clearScreen();
  canvas();
}

void loop() {
  if (stringComplete) {
    canvas();
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    pix[count] = atoi(inChar);
    count++;
    if (inChar == '\n') {
      count = 0;
      stringComplete = true;
    }
  }
}

void clearScreen() {
  int tmp[] = {0,0,0,0,0,0,0,0};
  for (int i = 0; i < 32; i++) {
    writeLine(tmp);
  }
  create();
}

void clearLine() {
  for (int x = 0; x < 8; x++) {
    bitWrite(data, x, LOW);
  }
}

void create() {
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);  
}

void writeLine(int pix[]) {
  for (int i = 0; i < 8; i++) {
    bitWrite(data, i, pix[i]);
  }
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  clearLine();
}

void canvas() {
  int tmp[] = {0,0,0,0,0,0,0,0};
  for (int y = 0; y < 32; y++) {    
    for (int x = 0; x < 8; x++) {
      tmp[x] = pix[(y*8)+x];
    }
    writeLine(tmp);
  }
  create();
}
