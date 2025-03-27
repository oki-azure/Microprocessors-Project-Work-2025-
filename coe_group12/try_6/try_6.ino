// Pin definitions for traffic lights
const int lane1Green = 2; const int lane1Yellow = 3; const int lane1Red = 4;

const int lane2Green = 5; const int lane2Yellow = 6; const int lane2Red = 7;

const int lane3Green = 8; const int lane3Yellow = 9; const int lane3Red = 10;

const int lane4Green = 11; const int lane4Yellow = 12; const int lane4Red = 13;

// Pin definitions for IR sensor test pins
const int lane1Sensor = A0; const int lane2Sensor = A1; const int lane3Sensor = A2; const int lane4Sensor = A3;

// Timing durations (milliseconds)
const int greenDuration = 1000;  // Green light duration (reduced for simulation)
const int yellowDuration = 500;  // Yellow light duration (reduced for simulation)
const int initialDelay = 500;    // Delay before first transition (reduced for simulation)

// Variables to track priority and current lane
int prioritizedLane = 0;  // 0 = no priority, 1-4 = prioritized lane number
int currentLane = 1;      // Current lane in the cycle

// Constants for light states
const int GREEN = 1;
const int YELLOW = 2;
const int RED = 3;

void setup() {
  // Traffic light pins as OUTPUT
  for (int pin = 2; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); // Initialize all lights OFF
  }
  // IR sensor pins as INPUT
  pinMode(lane1Sensor, INPUT); pinMode(lane2Sensor, INPUT); pinMode(lane3Sensor, INPUT); pinMode(lane4Sensor, INPUT);

  // Check for initial priority
  prioritizedLane = getPriorityLane();

  // Set initial state based on priority
  setAllLightsToRed();
  if (prioritizedLane > 0) {
    setLaneLight(prioritizedLane, GREEN);
    currentLane = prioritizedLane;
  } else {
    // Default to Lane 1 if no priority
    setLaneLight(1, GREEN);
  }

  // Wait for a short delay before the first transition
  delay(initialDelay);
}

void loop() {
  // Check sensors for prioritized lane
  int newPrioritizedLane = getPriorityLane();

  // If priority has changed, handle the transition
  if (newPrioritizedLane != prioritizedLane) {
    if (prioritizedLane > 0) {
      // Transition from the previous priority lane to the new one
      transitionLane(prioritizedLane, newPrioritizedLane > 0 ? newPrioritizedLane : getNextLane(prioritizedLane));
    } else if (newPrioritizedLane > 0) {
      // Transition from the current lane to the new priority lane
      transitionLane(currentLane, newPrioritizedLane);
    }
    prioritizedLane = newPrioritizedLane;
  }

  // If no lane has priority, follow the normal sequence
  if (prioritizedLane == 0) {
    int nextLane = getNextLane(currentLane); // Move to the next lane in the cycle
    transitionLane(currentLane, nextLane);
    currentLane = nextLane;
  }
}

// Function to get the priority lane when multiple toggles are ON
int getPriorityLane() {
  // Check toggles in priority order (Lane 1 > Lane 2 > Lane 3 > Lane 4)
  if (digitalRead(lane1Sensor) == HIGH) return 1;
  if (digitalRead(lane2Sensor) == HIGH) return 2;
  if (digitalRead(lane3Sensor) == HIGH) return 3;
  if (digitalRead(lane4Sensor) == HIGH) return 4;

  // If no toggles are ON, return 0 (no priority)
  return 0;
}

void transitionLane(int fromLane, int toLane) {
  // Turn off the current lane's active light and activate YELLOW
  setLaneLight(fromLane, YELLOW);

  // Turn off the next lane's RED light and activate YELLOW
  setLaneLight(toLane, YELLOW);

  delay(yellowDuration);

  // Turn off YELLOWs, set current lane to RED, and next lane to GREEN
  setLaneLight(fromLane, RED);
  setLaneLight(toLane, GREEN);

  delay(greenDuration);
}

// Helper function to set a lane's light (RED, YELLOW, or GREEN)
void setLaneLight(int lane, int light) {
  // Turn off all lights in the lane
  digitalWrite(getGreenPin(lane), LOW);
  digitalWrite(getYellowPin(lane), LOW);
  digitalWrite(getRedPin(lane), LOW);

  // Turn on the specified light
  switch (light) {
    case GREEN:
      digitalWrite(getGreenPin(lane), HIGH);
      break;
    case YELLOW:
      digitalWrite(getYellowPin(lane), HIGH);
      break;
    case RED:
      digitalWrite(getRedPin(lane), HIGH);
      break;
  }
}

// Helper function to get the next lane in the cycle
int getNextLane(int lane) {
  return (lane % 4) + 1; // Cycle through lanes 1-4
}

// Helper functions to get pin numbers
int getGreenPin(int lane) {
  return (lane - 1) * 3 + 2;
}

int getYellowPin(int lane) {
  return (lane - 1) * 3 + 3;
}

int getRedPin(int lane) {
  return (lane - 1) * 3 + 4;
}

// Function to set all non-active lanes to RED
void setAllLightsToRed() {
  for (int lane = 1; lane <= 4; lane++) {
    if (lane != prioritizedLane) {
      setLaneLight(lane, RED);
    }
  }
}
