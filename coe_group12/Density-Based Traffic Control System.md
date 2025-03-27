# Traffic Control System with Density-Based Priority

## Overview
This project simulates a traffic control system for a 4-lane intersection. Each lane has a traffic light with green, yellow, and red signals. The lights are controlled using an Arduino and simulated in Proteus.

## Traffic Light Connections
### Lane 1:
- **Green**: Pin 2 of the Arduino
- **Yellow**: Pin 3 of the Arduino
- **Red**: Pin 4 of the Arduino

### Lane 2:
- **Green**: Pin 5 of the Arduino
- **Yellow**: Pin 6 of the Arduino
- **Red**: Pin 7 of the Arduino

### Lane 3:
- **Green**: Pin 8 of the Arduino
- **Yellow**: Pin 9 of the Arduino
- **Red**: Pin 10 of the Arduino

### Lane 4:
- **Green**: Pin 11 of the Arduino
- **Yellow**: Pin 12 of the Arduino
- **Red**: Pin 13 of the Arduino

## Timed Traffic Cycle
The traffic light system follows an 8-step timed sequence:
1. **Cycle 1**: Lane 1 Green, Lane 2 Red, Lane 3 Red, Lane 4 Red  
2. **Cycle 2**: Lane 1 Green and Yellow, Lane 2 Red and Yellow, Lane 3 Red, Lane 4 Red  
3. **Cycle 3**: Lane 1 Red, Lane 2 Green, Lane 3 Red, Lane 4 Red  
4. **Cycle 4**: Lane 1 Red, Lane 2 Green and Yellow, Lane 3 Red and Yellow, Lane 4 Red  
5. **Cycle 5**: Lane 1 Red, Lane 2 Red, Lane 3 Green, Lane 4 Red  
6. **Cycle 6**: Lane 1 Red, Lane 2 Red, Lane 3 Green and Yellow, Lane 4 Red and Yellow  
7. **Cycle 7**: Lane 1 Red, Lane 2 Red, Lane 3 Red, Lane 4 Green  
8. **Cycle 8**: Lane 1 Red and Yellow, Lane 2 Red, Lane 3 Red, Lane 4 Green and Yellow  

## Density-Based Control
To optimize traffic flow, an IR sensor is used for density-based priority assignment. However, in Proteus simulation, we use logic toggles to simulate high and low traffic densities.

### Key Specifications:
1. **Default Behavior**: When no lane has priority, the system follows the timed cycle.
2. **Priority Handling**:
   - When a lane is prioritized, the timed cycle proceeds, but the next lane must be the prioritized lane.
   - If the priority switches, the cycle jumps to the new prioritized lane.
   - When priority is removed and not assigned to another lane, the timed cycle resumes normally.
3. **Lane Transition**:
   - The current lane's green light turns off, and its yellow light turns on.
   - Simultaneously, the red light of the next lane turns off, and its yellow light turns on.
   - Finally, both yellow lights turn off, the current lane's red light comes on, and the next lane's green light comes on.

## Handling Multiple Density Toggles
When multiple toggles are ON (high density), the system decides lane priority using a fair, deterministic policy. Options include:
1. **Fixed Priority**: Lane 1 > Lane 2 > Lane 3 > Lane 4.
2. **Round-Robin**: Cycle through lanes with high density in a fixed order.
3. **First-Come-First-Served**: The first toggle turned ON gets priority.

### Implementation
A priority-based approach was implemented, following the fixed priority order:
1. **Lane 1** has the highest priority.
2. Followed by **Lane 2**, then **Lane 3**, and finally **Lane 4**.

This ensures smooth operation and fairness in handling traffic densities.

---