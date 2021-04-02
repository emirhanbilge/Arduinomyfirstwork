EXPERIMENT 1: You are required to create a circuit with an Arduino board, 4 LEDs and a push down button using Arduino Software (IDE). 



DO NOT FORGET TO USE RESISTORS TO AVOID BURNING YOUR CIRCUIT COMPONENTS! After you correctly assemble your circuit using the components mentioned above, you will need to write a source code and use Arduino IDE software to load it into your Arduino Board. The first operation is counting from 0 to 15 (and returning to 0 to repeat again) using your 4 LEDs. A table showing this operation is given below.

 

Your second operation is to create a sliding LED from first to last and back to first again. A table showing this operation is given below.

 

TIME_LED_COUNTER = 500 A variable used to store waiting time between steps in LED counter operation given above. It should be 500 milliseconds to denote 0.5 seconds. TIME_LED_SLIDER = 250 A variable used to store waiting time between steps in LED slider operation given above. It should be 200 milliseconds to denote 0.2 seconds. A push down button should be used to change currently executed operation (from LED counter to slider and vice versa). Take care that you should only change it once for every press and not repeatedly. For example, you press the button and it changes from counter to slider. However you keep pressing it and it changes back counter at the next sliding step. Try to figure it out yourself how you can make sure this does not happen. In addition, when you press a push down button and change the current running operation, that operation should start from 0 or initial state, disregarding previously counter or slider state, if there was one.
