# Smart Traffic Light System Code Overview
Objective: Simulate a 4-lane intersection with adaptive traffic control using Arduino and Proteus.

---

## 1. Hardware Setup
- Traffic Lights: 
  - Each lane has 3 LEDs (Red, Yellow, Green)
  - Pins 2-13 on Arduino control the lights (4 lanes × 3 lights)
- Sensors: 
  - Toggle switches on analog pins A0-A3 simulate IR sensors
  - HIGH = High traffic density (priority), LOW = Normal traffic

---

## 2. Core Components

### Key Variables:
int prioritizedLane = 0; // Tracks which lane has priority (0 = none)
int currentLane = 1;    // Tracks current green light lane

### Timing Settings:

```
const int greenDuration = 1000;  // 1 second green light
const int yellowDuration = 500;  // 0.5 second yellow transition
```
---

## 3. How It Works

### Normal Operation:
1. Cycles through lanes in order: 1 → 2 → 3 → 4 → 1...
2. Each lane gets 1 second of green time.

### Priority Mode:
- If a toggle switch is ON (HIGH):
  - That lane gets extended green time
  - Overrides normal sequence
- Priority order: Lane 1 > Lane 2 > Lane 3 > Lane 4

### Transitions:
1. Current lane turns yellow
2. Next lane also turns yellow (brief overlap)
3. After 0.5 seconds:
   - Both yellows turn off
   - Current lane turns red
   - Next lane turns green

---

## 4. Key Functions

### setLaneLight(lane, light):
- Ensures only one light is on per lane
- Turns off all lights in the lane first
- Then turns on the specified light (RED/YELLOW/GREEN)

### transitionLane(from, to):
- Handles the yellow transition between lanes
- Ensures smooth, collision-free switching

### getPriorityLane():
- Checks toggle switches in priority order
- Returns which lane should get priority (or 0 if none)

---

## 5. Safety Features
- No overlapping greens: 
  - setAllLightsToRed() ensures only priority lane stays green
- Clean transitions: 
  - Yellow lights warn drivers before changes
- Stable startup: 
  - All non-priority lanes start with red lights

---

## 6. Simulation Example
1. Normal Mode: Lights cycle automatically
2. Toggle Lane 2: 
   - Lane 2 gets green until toggle is OFF
   - Other lanes show red
3. Toggle OFF: System resumes normal cycle

---

### Why This Matters
- Mimics real-world adaptive traffic systems
- Demonstrates:
  - Priority handling for emergency vehicles
  - Smart response to traffic congestion
  - Safe transition logic

---