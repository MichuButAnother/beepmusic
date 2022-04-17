# beepmusic
Originally made by maniek207.

A simple linux program that plays patterns from OpenMPT (even from MIDI) on the PC's speaker (buzzer).
# Usage
beepmusic [file] [tempo] 

Example of file is show in /examples.
Tempo is delay before next note (lower=faster). For first time i recommend 50.

NOT WORKING IN TERMINAL EMULATOR! Switch to console mode before using it! also check your PC speaker (onboard) is connected if there is still no sound.
# Making music
Select in OpenMPT channel and copy it to a new .txt file.
If you have problems try looking at the examples.
# Building
Linux:
```
cmake .
make
```
Result file will appear in the same directory as project.

For now i am not planning to make Windows port.
If your terminal does not support color, change line `set(beepmusic_NOGRAPHICS 0)` to `set(beepmusic_NOGRAPHICS 1)` to avoid garbage.
