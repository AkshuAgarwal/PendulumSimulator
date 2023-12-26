# Pendulum Simulator

A basic Simple Pendulum Simluator made in C++ using SDL2.

## Features

- Variable Parameters (to be implemented)
- Trailing path lines
- Damping (to be implemented)
- GUI Controls (to be implemented)
- Draggable Pendulum (to be implemented)

> Note: The parameter values are hard-coded until the CLI/GUI Controls gets implemented.
> The parameters are marked using a comment "`// Pendulum Parameters`" and can be customized from there.

## Setup

The program requires [CMake](https://cmake.org/) Version 3.7 or above to build and [SDL2](https://www.libsdl.org/) to run.

Install the dependencies:

```sh
# In the root directory, create a directory named "lib" and clone the SDL2 repository

>> mkdir lib
>> cd lib
>> git clone https://github.com/libsdl-org/SDL.git -b SDL2
```

Build the project:

```sh
# In the root directory, create another directory named "build"

>> mkdir build
>> cd build
>> cmake ..
>> make
```

Execute:

```sh
# Run the executable

>> ./pendulum
```

## Arguments:

_To be updated later_

## License

MIT
