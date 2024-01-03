# STM32 GUI PoC for Pervasive Displays EPDs
 
STM32 CubeHAL proof of concept for [this driver](https://github.com/Estylos/EPD_SmallSized_Driver_HAL) used to control small-sized EPDs from [Pervasive Displays Inc](https://www.pervasivedisplays.com/) ( 1.54", 2.06", 2.13", 2.66", 2.71", 2.87", 2.90", 3.70", 4.17", 4.37") with internal driving (iTC). This project also uses [the µGUI library](https://github.com/0x3333/UGUI/) to create a minimalist graphical interface on the ePaper screen.

This project is based on a NUCLEO-F103RB, but can be adapted to any STM32 with at least one SPI peripheral and 4 GPIOs. The GUI related files are the `main.c` and `ugui_sim.c` files in the `Drivers > UGUI` directory.

For more information on controlling the ePaper screen with STM32, see : 
- [STM32 CubeHAL driver](https://github.com/Estylos/EPD_SmallSized_Driver_HAL) for controlling small-sized EPDs from Pervasive Displays
- [STM32 CubeHAL example](https://github.com/Estylos/EPD_SmallSized_Example_HAL) for controlling small-sized EPDs from Pervasive Displays

## Related projects and documentation
- [PDI Wiki](https://docs.pervasivedisplays.com/) 
- [EPD_Driver_GF_small](https://github.com/PervasiveDisplays/EPD_Driver_GF_small/) : Officiel driver from PDI using the Arduino framework for PS/KS-type small-sized 1.54", 2.13", 2.66", 2.71", 2.87", 2.92", 3.70", 4.17" and 4.37" screens
- [µGUI fork from 0x3333](https://github.com/0x3333/UGUI/) : a free and open source graphic library for embedded systems

## Disclaimer

This project is in no way affiliated with Pervasive Displays Inc.