const int touchPin = 25;

const int leds[6] = {13, 14, 27, 33, 26, 12};

int mode = 0;
bool lastTouchState = LOW;

// Turn OFF all LEDs
void allOff()
{
  for (int i = 0; i < 6; i++)
    digitalWrite(leds[i], LOW);
}

// Turn ON all LEDs
void allOn()
{
  for (int i = 0; i < 6; i++)
    digitalWrite(leds[i], HIGH);
}

// Mode 2: Left to Right Chaser
void chaserForward()
{
  for (int i = 0; i < 6; i++)
  {
    allOff();
    digitalWrite(leds[i], HIGH);
    delay(150);
  }
}

// Mode 3: Right to Left Chaser
void chaserReverse()
{
  for (int i = 5; i >= 0; i--)
  {
    allOff();
    digitalWrite(leds[i], HIGH);
    delay(150);
  }
}

// Mode 4: Converging
void converge()
{
  allOff();
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[5], HIGH);
  delay(200);

  allOff();
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[4], HIGH);
  delay(200);

  allOff();
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[3], HIGH);
  delay(200);
}

// Mode 5: Diverging
void diverge()
{
  allOff();
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[3], HIGH);
  delay(200);

  allOff();
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[4], HIGH);
  delay(200);

  allOff();
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[5], HIGH);
  delay(200);
}

// Mode 6: Blink All LEDs
void blinkAll()
{
  allOn();
  delay(300);

  allOff();
  delay(300);
}

void setup()
{
  Serial.begin(115200);

  pinMode(touchPin, INPUT);

  for (int i = 0; i < 6; i++)
  {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  Serial.println("Touch Sensor LED Effects");
}

void loop()
{
  bool touchState = digitalRead(touchPin);

  // Detect Touch
  if (touchState == HIGH && lastTouchState == LOW)
  {
    mode++;

    if (mode > 7)
      mode = 1;

    Serial.print("Mode = ");
    Serial.println(mode);

    delay(250); // debounce
  }

  lastTouchState = touchState;

  switch (mode)
  {
    case 1:
      allOn();
      break;

    case 2:
      chaserForward();
      break;

    case 3:
      chaserReverse();
      break;

    case 4:
      converge();
      break;

    case 5:
      diverge();
      break;

    case 6:
      blinkAll();
      break;

    case 7:
      allOff();
      break;
  }
}