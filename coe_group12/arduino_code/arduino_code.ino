// Define the pin numbers for each lane's traffic lights
const int lane1Green = 2;
const int lane1Yellow = 3;
const int lane1Red = 4;

const int lane2Green = 5;
const int lane2Yellow = 6;
const int lane2Red = 7;

const int lane3Green = 8;
const int lane3Yellow = 9;
const int lane3Red = 10;

const int lane4Green = 11;
const int lane4Yellow = 12;
const int lane4Red = 13;

// Define the duration for each cycle (in milliseconds)
const int greenDuration = 3000; // 3 seconds for green
const int yellowDuration = 1000; // 1 second for yellow

void setup() {
  // Set all pins as OUTPUT
  pinMode(lane1Green, OUTPUT);
  pinMode(lane1Yellow, OUTPUT);
  pinMode(lane1Red, OUTPUT);

  pinMode(lane2Green, OUTPUT);
  pinMode(lane2Yellow, OUTPUT);
  pinMode(lane2Red, OUTPUT);

  pinMode(lane3Green, OUTPUT);
  pinMode(lane3Yellow, OUTPUT);
  pinMode(lane3Red, OUTPUT);

  pinMode(lane4Green, OUTPUT);
  pinMode(lane4Yellow, OUTPUT);
  pinMode(lane4Red, OUTPUT);

  // Initialize all lights to RED
  digitalWrite(lane1Red, HIGH);
  digitalWrite(lane2Red, HIGH);
  digitalWrite(lane3Red, HIGH);
  digitalWrite(lane4Red, HIGH);
}

void loop() {
  // Cycle 1: Lane 1 Green, Lane 2 Red, Lane 3 Red, Lane 4 Red
  digitalWrite(lane1Green, HIGH);
  digitalWrite(lane1Yellow, LOW);
  digitalWrite(lane1Red, LOW);

  digitalWrite(lane2Green, LOW);
  digitalWrite(lane2Yellow, LOW);
  digitalWrite(lane2Red, HIGH);

  digitalWrite(lane3Green, LOW);
  digitalWrite(lane3Yellow, LOW);
  digitalWrite(lane3Red, HIGH);

  digitalWrite(lane4Green, LOW);
  digitalWrite(lane4Yellow, LOW);
  digitalWrite(lane4Red, HIGH);

  delay(greenDuration);

  // Cycle 2: Lane 1 Yellow, Lane 2 Red and Yellow, Lane 3 Red, Lane 4 Red
  digitalWrite(lane1Green, LOW);
  digitalWrite(lane1Yellow, HIGH);

  digitalWrite(lane2Yellow, HIGH);
  digitalWrite(lane2Red, LOW);


  delay(yellowDuration);

  // Cycle 3: Lane 1 Red, Lane 2 Green, Lane 3 Red, Lane 4 Red
  digitalWrite(lane1Yellow, LOW);
  digitalWrite(lane1Red, HIGH);

  digitalWrite(lane2Yellow, LOW);
  digitalWrite(lane2Red, LOW);
  digitalWrite(lane2Green, HIGH);

  delay(greenDuration);

  // Cycle 4: Lane 1 Red, Lane 2 Yellow, Lane 3 Red and Yellow, Lane 4 Red
  digitalWrite(lane2Green, LOW);
  digitalWrite(lane2Yellow, HIGH);

  digitalWrite(lane3Yellow, HIGH);
  digitalWrite(lane3Red, LOW);


  delay(yellowDuration);

  // Cycle 5: Lane 1 Red, Lane 2 Red, Lane 3 Green, Lane 4 Red
  digitalWrite(lane2Yellow, LOW);
  digitalWrite(lane2Red, HIGH);

  digitalWrite(lane3Yellow, LOW);
  digitalWrite(lane3Red, LOW);
  digitalWrite(lane3Green, HIGH);

  delay(greenDuration);

  // Cycle 6: Lane 1 Red, Lane 2 Red, Lane 3 Yellow, Lane 4 Red and Yellow
  digitalWrite(lane3Green, LOW);
  digitalWrite(lane3Yellow, HIGH);

  digitalWrite(lane4Yellow, HIGH);
  digitalWrite(lane4Red, LOW);

  delay(yellowDuration);

  // Cycle 7: Lane 1 Red, Lane 2 Red, Lane 3 Red, Lane 4 Green
  digitalWrite(lane3Yellow, LOW);
  digitalWrite(lane3Red, HIGH);

  digitalWrite(lane4Yellow, LOW);
  digitalWrite(lane4Red, LOW);
  digitalWrite(lane4Green, HIGH);

  delay(greenDuration);

  // Cycle 8: Lane 1 Red and Yellow, Lane 2 Red, Lane 3 Red, Lane 4 Yellow
  digitalWrite(lane4Green, LOW);
  digitalWrite(lane4Yellow, HIGH);

  digitalWrite(lane1Yellow, HIGH);
  digitalWrite(lane1Red, LOW);

  delay(yellowDuration);

  // Reset to Cycle 1
  digitalWrite(lane1Yellow, LOW);
  digitalWrite(lane1Red, HIGH);

  digitalWrite(lane4Yellow, LOW);
  digitalWrite(lane4Red, HIGH);
}
