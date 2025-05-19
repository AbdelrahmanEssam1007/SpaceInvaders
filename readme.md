# SpaceInvaders 👾

## Overview

SpaceInvaders is not-so-faithful recreation of the classic arcade game Space Invaders. Built from scratch using C++,
utilising the raylib for rending, audio and input. This project aims to create a fun and engaging game experience for
players of all ages, while also providing a solid foundation for learning C++ programming.

This project is being still being developed and is subject to change. Please report any issues or suggestions to the
GitHub repository.

## Completed Features

### Player

* Player can move left and right
* Player can fire lasers
* Player starts with 3 lives and loses a life when hit by an alien
* Player Gains a life when clearing the screen of aliens

### Aliens

* Aliens move left and right
* Aliens move down the screen
* Aliens fire lasers
* Aliens can be hit by player's laser
* Aliens damage player and obstacles when colliding

### Obstacles

* Static obstacles are placed between the player and the alien army

* Can absorb a limited number of hits from both alien and player lasers

* Break apart progressively upon impact, providing temporary cover

* Designed to encourage strategic positioning and movement

### Projectiles

* Two types of lasers: player laser and alien laser

* Only one player laser can exist on screen at a time to mimic the original game

* Alien lasers are fired randomly by living aliens

* Lasers travel in straight lines and disappear upon collision

### Scoring

* Player receives points for each alien destroyed
* Score is displayed on the screen in real-time
* High score is saved and loaded from a file

### Mystery Ship

* Appears occasionally at the top of the screen, moving horizontally

* Spawns at random intervals to add variety and tension

* Can be destroyed by the player for bonus points

* Plays a distinct sound while on screen

* Only one UFO can exist at a time

### WIP Features
* Main Menu
* Updated music and sound effects
* Improved AI for aliens
* Sprite animations

## Controls
* Move Left 
    * A or Left Arrow
* Move Right
    * D or Right Arrow
* Fire
    * Space
* Pause Game
    * ESC
* Restart Game (must be in Game Over screen)
    * Enter
* Quit Game
    * SHIFT + ESC (Hold Shift and press ESC)

## Technical Details

* Language: C++
* Library: raylib v5.5
* Cmake v3.31

## Contributing

* Contributions are welcome! Feel free to contribute by submitting a pull request. For major changes, please open an issue first to discuss what you would like to change.
