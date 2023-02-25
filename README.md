# On-demand Traffic light control
An On-demand Traffic light control system that in normal mode the green LED turns on for 5 seconds then yellow LED blinks for another 5 seconds then red LED turns on for other 5 seconds then yellow blinks again then repeats itself from green.
<br>But if pedestrian button is pressed the pedestrian LEDs starts to work as follows:
<br>-If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
<br>-If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
<br>-At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
<br>-After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
<br>-Traffic lights signals are going to the normal mode again.
