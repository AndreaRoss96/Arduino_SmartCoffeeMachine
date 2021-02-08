# Arduino_SmartCoffeeMachine

An embedded system implementing a smart coffee machine is to be realised. 





HW components

![alt text](https://github.com/AndreaRoss96/Arduino_SmartCoffeeMachine/blob/master/res/general_scheme.png)


3 green LEDs (L1, L2, L3)
1 T1 touch button and 1 Pot potentiometer
1 PIR motion sensor and 1 SDist sonar
Serial connection with PC

Detailed system behaviour


The machine starts in a STAND BY mode, in which it is assumed to have low power consumption.  When the presence of someone nearby is detected then it exits the saving mode and enters an ON mode.


If someone is detected at a distance of less than DIST1 cm for a certain number DT1 seconds, a "Welcome!" message is displayed on the PC side GUI and the machine enters a READY mode, where it can accept commands.  If the machine no longer detects anyone within that distance for DT2a seconds, the machine returns to the ON mode. From ON mode, the machine returns to STAND BY mode if no one is detected for DT2b seconds.


In READY mode, the user can adjust the sugar with the POT knob. Whenever the sugar level changes, the PC side will display the updated sugar level appropriately (by means of graphic component or text message).


The user can make coffee by pressing the T1 button. When he presses the button, the process represented by the progressive switching on of the 3 LEDs, lasting DT3 seconds, starts. On the PC side, the message "Making a coffee" is displayed and then "The coffee is ready" when the coffee is ready.


The user has time DT4 seconds to take the coffee - in this case we simulate with distance below DIST2 cm, i.e.: I detect distance below DIST2 cm, it means the user has taken the coffee. If you do not take your coffee within DT4 seconds, in any case the machine returns to READY mode (and the PC-side message is removed).


Finally, the coffee machine may run out of coffee material. It is supposed to be loaded to make NMAX coffee. After making NMAX coffee, the message "No more coffee. Waiting for recharge" and enters the MAINTENANCE mode.  In this mode, the system waits for recharging, which can be done by a PC-side action (e.g. recharge button) corresponding to a certain amount of NC doses. After refilling, the message "Coffee refilled: "+NC is displayed on the PC side and the machine returns to STAND BY mode.




Implement the system on Arduino + PC connected via serial line, implementing the program on Arduino in C++ and the program on PC in Java.  Use a task-based approach, with a behaviour model based on synchronous finite state machines.


Assume as values to simulate the system:


DIST1 (Engagement distance) = 0.3 m

DIST2 (Take coffee) = 0.1 m

 

DT1 (Min engagement time) = 1 s

DT2a (Max time with no engagement) = 5 s

DT2b (Max time with no presence) = 5 s

DT3 (Coffee making process duration) = 3 s

DT4 (Max time to remove coffee) = 5 s


![alt text](https://github.com/AndreaRoss96/Arduino_SmartCoffeeMachine/blob/master/res/fritzing_scheme.jpg)


