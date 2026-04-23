# 5-Bar Linkage Robot – Inverse Kinematics, Plotting & Applications

## Overview

This project implements a **5-bar parallel robot** capable of converting (x, y) coordinates into real-world motion using inverse kinematics.

The system is designed as a **2D plotter**, where the end-effector can trace shapes such as polygons within its reachable workspace.

---


### Prototype 



https://github.com/user-attachments/assets/ca069497-f3ad-4e33-bab9-e6bb1ae5c59c

<img width="781" height="679" alt="five_bar2" src="https://github.com/user-attachments/assets/b9a010c5-b6a0-4775-8fcc-ca679d9c6dc9" />



<img width="840" height="719" alt="five_bar1" src="https://github.com/user-attachments/assets/86631399-2264-4a1f-886e-16c4b56d256f" />


### CAD Simulation (Fusion 360)

* Revolute joint motion
* Mechanism validation

<img width="703" height="315" alt="image" src="https://github.com/user-attachments/assets/87d96b93-b9ba-47cb-8b73-0852c626cb31" />


https://github.com/user-attachments/assets/1a615db3-73a6-40ac-87b4-f45e631faadc




---

## Workspace Analysis

The reachable workspace of the robot was computed to understand motion limits and avoid singularities.

* Outer boundary → maximum reach
* Inner region → unreachable zone (singularity constraints)
<img width="571" height="399" alt="image" src="https://github.com/user-attachments/assets/9db9b547-1543-475b-b794-c3f2fc5fedbf" />


---

## Plotting Capability

The mechanism can function as a **2D drawing/plotting robot**:

* Converts trajectory points → joint angles (IK)
* Executes paths such as:

  * Lines
  * Polygons
  * Custom trajectories

Current limitation:

* Accuracy is affected by servo backlash and calibration and plauge.

---

## Inverse Kinematics

The IK solution is derived analytically using:

* Cosine rule for joint angles
* `atan2()` for correct quadrant handling
* Fixed configuration (elbow-down) for stability

This ensures smooth and continuous motion within the workspace.

---

## Hardware Setup

* 2x Servo motors
* Symmetric 5-bar linkage (equal upper and lower links)
* 3D printed links and joints
* Microcontroller (Arduino)
* M3-35mm x1
* M5-40mm x8

---

## Features

* Real-time inverse kinematics
* Workspace validation
* 2D trajectory execution 
* Fusion 360 simulation + physical prototype

---

## Challenges

* Accuracy limitations due to:

* Servo backlash
* Mechanical tolerances
* Instability near singular regions
* Calibration required for precise plotting

---

## Future Improvements


* Trajectory smoothing (linear interpolation / splines)
* Servo calibration for higher precision
* Error analysis (desired vs actual path)



* Closed-loop control (feedback-based correction)
* Higher precision actuators

### Extension: Quadruped Robotics 🐾

The same kinematic principles can be extended to **quadruped robot legs**, where:

* The 5-bar mechanism acts as a leg linkage
* Provides compact and efficient motion
* Enables controlled foot trajectory generation

This opens up applications in:

* Legged robotics
* Bio-inspired mechanisms
* Dynamic locomotion systems

---

## Repository Structure

```
scripts/ : arduino code
STL/     : Assembly and part files
URDF_info/ : ROS implementation files         
```

---

## Status

Working prototype with functional IK and plotting capability.
Currently improving motion accuracy and control.

---
