 Behaviour 1/Standby Logic: When the button on the remote is pressed the turret shall be activated the turret and the line sensor shall be activated. At this point you shall also be able to adjust the angle of the turret using a pontonmeiter. This is also located on the remote. 

 ```mermaid
 flowchart TD
 %%standby logic
 activateserv(Actviate servo motor)
ReadPo{analogRead Poteniometer}
terminalStart1([Standby Logic])
 terminalEnd1([Activate line sensor])
 Button(Button)
Buttontrigger{digitalRead Button}
activateturret(Activate Turret)
loop(Wait 1 second)
terminalStart1 --> Button
Button --> Buttontrigger
Buttontrigger --> |True| activateturret
activateturret --> terminalEnd1
Buttontrigger --> |False| loop
loop -->Buttontrigger
terminalEnd1 --> activateserv
activateserv --> ReadPo
```
Behaviour 2/Tracking Logic: If the line sensor has been triggered the PIR sensor, distance sensor and LED shall be activated. Also once the sensor has been triggered the turret shall begin to start to search for moving targets using the PIR sensor. If the PIR sensor detects a moving target then the turret shall phyisclly track the target. If not then it shall continue to search for the target for a further minute. If no targets are detected by then the turret shall stop searching for targets and return to the beginning of the tracking logic. 
```mermaid
flowchart TD
%%Tracking logic
terminalStart2([Tracking Logic])
terminalEnd2([Track Target])
Readline{digitalRead lineSensor}
activatepir(Activate PIR)
activatedistance(Activate Distance Sensor)
activateLED(Activate LED)
activateDC(Activate DC motor)
loop2(Wait 1 second)
distance(DistanceThreshold = 30)
ReadPIR{digitalRead PIR}
loop3(wait 1 minute)
terminalStart2 --> Readline
Readline --> |True| activatepir
activatepir --> activateLED
Readline --> |False| loop2
loop2 --> Readline
activateLED --> activateDC
activateDC --> activatedistance
activatedistance --> distance
distance --> ReadPIR
ReadPIR --> |True| terminalEnd2
ReadPIR --> |False| loop3
loop3 --> Readline
```
Behavior 3/Firing: If the target has reached the distance threshold then the led shall turn red the buzzer shall be activated indicating that the turret is firing upon the target. If the target hasn't reached the distance threshold then the turret shall keep tracking the target until the target isn't dectected aka is no longer moving.
```mermaid
flowchart TD
%%Firing logic
terminalStart3([Firing Logic])
terminalEnd3([Activate buzzer])
readdistance{readDistance}
fire(Led turns red) 
Keeptrack(Track target)
loop4(wait 1 second)
terminalStart3 --> readdistance
readdistance --> |True| fire
fire --> terminalEnd3
readdistance --> |False| Keeptrack
Keeptrack --> loop4 
loop4 --> readdistance
```