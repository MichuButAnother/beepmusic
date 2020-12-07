# beepmusic
Simple linux program that plays patterns (from even midi) from OpenMPT on PC speaker.
# Usage
beepmusic [file] [tempo] 

Example of file is show in /examples.
Tempo is delay before next note (lower=faster). For first time i recommend 50.

NOT WORKING IN TERMINAL EMULATOR! Switch to console mode before using it! also check your pc speaker (onboard) is connected if there still no sounds.
# Making music
Select in OpenMPT channel and copy it to new .txt file.
If you have problems try look at examples.
# Building
Linux :
```
cmake .
make
```
Result file will appear in the same directory as project.

For now i not planning make Windows port.
If your terminal not support color, change line `set(beepmusic_NOGRAPHICS 0)` to `set(beepmusic_NOGRAPHICS 1)` to avoid garbage.
