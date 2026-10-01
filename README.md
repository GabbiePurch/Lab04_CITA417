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




# Lab 05 - Obstacle Course Integration

## Overview

This lab extends the reusable moving obstacle system from the previous lab into a short playable obstacle course. The course uses multiple obstacle configurations, a new pause behavior, a custom C++ GameMode, a failure condition, and a completion condition.

The main goal was to keep reusable gameplay behavior in C++ while using Blueprints and the Unreal Editor for level configuration, triggers, and visual setup.

## New Obstacle Behavior

The existing `MovingObstacle` C++ class was extended with a configurable pause behavior.

A new `PauseDuration` property allows an obstacle to pause when it reaches either endpoint before reversing direction. The pause duration can be changed in the Unreal Editor without modifying the underlying C++ code.

A pause duration of `0` preserves the original movement behavior, while a value greater than `0` causes the obstacle to wait at each endpoint.

The obstacle system still supports configurable:

- Movement offset
- Movement speed
- Rotation rate
- Pause duration

This allows several obstacle configurations to use the same reusable C++ class.

## Obstacle Course

The graybox obstacle course contains at least three differently configured obstacles using the reusable C++ obstacle system.

Examples include:

- A platform that moves horizontally
- A rotating obstacle
- A platform that moves vertically and rotates
- A moving platform that pauses at its endpoints

These behaviors are created through configuration rather than duplicating the core movement logic in separate Blueprints.

## Custom C++ GameMode

A custom C++ GameMode named `ObstacleCourseGameMode` was created to manage course gameplay state.

The GameMode is responsible for:

- Tracking the player's attempt count
- Handling player failure notifications
- Handling course completion
- Preventing the course from being completed multiple times
- Reporting meaningful gameplay information to the Output Log

A Blueprint child, `BP_ObstacleCourseGameMode`, is used to configure the appropriate Third Person Pawn and Player Controller while inheriting the gameplay rules implemented in C++.

## Failure Condition

A `BP_FailureZone` Blueprint uses a Box Collision trigger underneath the obstacle course.

When the player falls into the Failure Zone:

1. The Blueprint verifies that the overlapping Actor is the player.
2. It gets the custom obstacle course GameMode.
3. It calls the C++ `PlayerFailed()` function.
4. The GameMode increases the attempt count and logs the new attempt.
5. The player's transform is reset to the Player Start so the course can be attempted again.

Example Output Log message:

`Player Failed - Starting Attempt 2`

## Completion Condition

A `BP_FinishZone` Blueprint is placed at the end of the course.

When the player reaches the Finish Zone, the Blueprint verifies the player and calls the C++ GameMode's `CourseCompleted()` function.

The GameMode records the completion state and reports the attempt on which the course was completed.

Example Output Log message:

`COURSE COMPLETE! Finished on Attempt 2`

## Independent Architecture Improvement

An additional completion-state check was added to the custom GameMode using `bCourseCompleted`.

The GameMode checks this state before processing a course completion. Once the course has been completed, additional calls to `CourseCompleted()` are ignored.

This is an architectural improvement because the completion rule is protected and centralized inside the GameMode rather than relying on individual Blueprint triggers to prevent duplicate completion events. This makes the system easier to maintain and reduces the possibility of inconsistent course state.

## C++ and Blueprint Responsibilities

### C++

C++ is responsible for:

- Reusable obstacle movement
- Rotation behavior
- Endpoint pause behavior
- Obstacle runtime state
- Attempt tracking
- Course completion state
- GameMode gameplay functions
- Runtime logging

### Blueprint / Editor

Blueprints and the Unreal Editor are responsible for:

- Obstacle mesh and visual configuration
- Movement, rotation, and pause parameter configuration
- Course layout
- Failure trigger placement
- Finish trigger placement
- Player Start placement
- Calling the appropriate C++ GameMode functions

This separation allows the core gameplay rules to remain reusable while designers can change the course layout and obstacle configurations without rewriting the underlying C++ logic.

## Testing

The completed course was tested to verify that:

- The player spawns correctly using the custom GameMode.
- At least three obstacle configurations use the reusable C++ obstacle system.
- Existing movement and rotation behavior still works.
- The new endpoint pause behavior works correctly.
- Changing `PauseDuration` in the Editor changes the behavior without modifying C++.
- Falling into the Failure Zone increases the attempt count and returns the player to the start.
- Reaching the Finish Zone reports successful course completion.
- Entering the Finish Zone again does not process completion multiple times.
- The Output Log provides useful gameplay information without per-frame log spam.
