# Flicker_Fusion_Threshold-Project-1
## AIM

Set up a prototype of an Embedded System for the measurement of a person’s subjective flicker fusion threshold. A flashing LED(50% duty cycle) should serve as the visual stimulus. A potentiometer (instead of potentiometer use Serial Communication or Loop )should be used to allow for the adjustment of the LED’s blink frequency. A button should be part of the system. If pressed a hardware interrupt should be triggered and the currently set blink frequency should be displayed in a serial monitor on a connected PC .



## ABSTRACT

**The  **flicker fusion threshold**, or  **flicker fusion rate**, is a concept in the  [psychophysics](https://en.wikipedia.org/wiki/Psychophysics "Psychophysics")  of  [vision](https://en.wikipedia.org/wiki/Visual_perception "Visual perception"). It is defined as the frequency at which an intermittent light stimulus appears to be completely steady to the average human  [observer](https://en.wikipedia.org/wiki/Observation "Observation"). Flicker fusion threshold is related to  [persistence of vision](https://en.wikipedia.org/wiki/Persistence_of_vision "Persistence of vision"). Although flicker can be detected for many waveforms representing time-variant fluctuations of intensity, it is conventionally, and most easily, studied in terms of sinusoidal modulation of intensity. There are seven parameters that determine the ability to detect the flicker:
1.  the frequency of the modulation;
2.  the amplitude or depth of the modulation (i.e., what is the maximum percent decrease in the illumination intensity from its peak value);
3.  the average (or maximum—these can be inter-converted if modulation depth is known) illumination intensity;
4.  the wavelength (or wavelength range) of the illumination (this parameter and the illumination intensity can be combined into a single parameter for humans or other animals for which the sensitivities of rods and cones are known as a function of wavelength using the  [luminous flux](https://en.wikipedia.org/wiki/Luminous_flux "Luminous flux")  function);
5.  the position on the retina at which the stimulation occurs (due to the different distribution of photo receptor types at different positions);
6.  the degree of light or dark adaptation, i.e., the duration and intensity of previous exposure to background light, which affects both the intensity sensitivity and the time resolution of vision;
7.  physiological factors such as age and fatigue.**[[https://en.wikipedia.org/wiki/Flicker_fusion_threshold](https://en.wikipedia.org/wiki/Flicker_fusion_threshold)

For this project we were using Teensy 3.1 controller and a mini push button for use as a external Interrupt. The flicker fusion frequency is displayed using the serial monitor in Vscode when the push button is pressed.

## COMPONENTS DESCRIPTION

1.Teensy 3.1/3.2
2.Mini Push Button
3.Wires
4.Breadboard

## CIRCUIT
In this circuit , Teensy board connected to  the bread board .And , mini push button pin 1 is connected to the Teensy board A7 and another end of push button at the GND pin in Teensy. 
![enter image description here](https://github.com/Ananthakrishnan210/Flicker_Fusion_Threshold-Project-1/blob/master/Connection%20Diagram/ananthakrishnan%20schematic.png)

## WORKING
Main aim of this project is working of led in toggle condition and test the persistence of human vision, for that we provide an time period using serial communication method.Then , it produce a led toggle with respect to the time period and we can figure out the frequency and time period that we can observe the blinking.

While the toggle is happen we can know the frequency of the toggling with the help of external interrupt(mini push button)which connected to the teensy board .

## OUTPUT
The Output wave we can observe with application -Serialplot

![enter image description here](https://github.com/Ananthakrishnan210/Flicker_Fusion_Threshold-Project-1/blob/master/OUTPUT%20GRAPH.png)


## CONCLUSION
Human flicker fusion threshold was tested successfully using this project. After a number outputs assume that human eye persistence of vision is between 37-39.5Hz.

This project gave me the opportunity to get into GitHub, Teensy 3.2 ,Serial Communication and different IDEs etc.

## REFERENCE
1.Wikipedia contributors. (2020, January 29). Flicker fusion threshold. Retrieved from[https://en.wikipedia.org/wiki/Flicker_fusion_threshold](https://en.wikipedia.org/wiki/Flicker_fusion_threshold)



2.Teensyduino: Using the UART (real serial) with Teensy on the Arduino IDE. (2020). Retrieved from [https://www.pjrc.com/teensy/td_uart.html](https://www.pjrc.com/teensy/td_uart.html)


3.To know the using of serial communication and ASCII converstion.
[https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html](https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html)

##Video
Youtube Link :-https://www.youtube.com/watch?v=ufNscfYshCA















