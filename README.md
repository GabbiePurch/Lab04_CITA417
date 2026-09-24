# Lab04_CITA417

###Overview

This project implements a reusable moving obstacle system in Unreal Engine 5 using C++ and Blueprints. The system allows obstacles to move between two positions, rotate at configurable speeds, and interact with the player through collision.


###Features
- Back-and-forth movement: Obstacles travel between their starting position and a destination determined by a configurable movement offset.
- Configurable rotation: Obstacles can rotate around the Pitch, Yaw, and Roll axes.
- Frame-rate-independent behavior: Movement and rotation use DeltaTime to maintain consistent speeds.
- Blueprint customization: Blueprint children can use different meshes, materials, and movement settings without changing the underlying C++ class.
- Player collision: Obstacles block the player and provide surfaces the player can walk on.

###C++ and Blueprint Responsibilities

C++ handles the obstacle's core behavior. BeginPlay() records its starting location, while Tick() updates its position and rotation. C++ also defines the mesh component, collision settings, and editable movement and rotation variables.

Blueprints handle the obstacle's appearance and configuration. Each Blueprint child can use a different mesh or material and customize movement offset, movement speed, and rotation rate through the Unreal Editor.


###Obstacle	Behavior

Moving platform	Moves back and forth horizontally.
Spinning sphere	Rotates in place with a movement offset of zero.
Vertical platform	Moves up and down while rotating.


###Testing

I tested the obstacle system in the Third Person level and confirmed that:

- All three obstacles demonstrate different behaviors.
- Movement and rotation work during gameplay.
- The player can collide with and walk on the obstacles.
- The spinning sphere remains in place when its movement offset is zero.
- Initialization messages appear in the Output Log without logging every frame.

###How DeltaTime Is Used

DeltaTime represents the amount of time elapsed since the previous frame. The obstacle uses it when calculating movement and rotation so that its speed is based on elapsed time rather than the number of frames rendered.
