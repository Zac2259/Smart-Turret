 ```mermaid
 flowchart TD
 %%standby logic
terminalStart([Standby Logic])
 terminalEnd([Activate Buzzer])
 Button(Button)
Buttontrigger{digitalRead Button}
activateturret(Activate Turret)
activatesensor(Activate line sensor)
loop(Wait 1 second)
%%Tracking logic
Tracking(Tracking Logic)
Readline{digitalRead lineSensor}
activatepir(Activate PIR)
activatedistance(Activate Distance Sensor)
activateLED(Activate LED)
loop2(Wait 1 second)
distance(DistanceThreshold = 30)
ReadPIR{digitalRead PIR}
track(Track target)
loop3(wait 1 minute)
%%Firing
firelogic(Firing Logic)
readdistance{readDistance}
fire(Led turns red)
Keeptrack(Track target)
loop4(wait one second)
terminalStart --> Button
Button --> Buttontrigger
Buttontrigger --> activateturret
activateturret --> activatesensor
Buttontrigger --> loop
loop -->Buttontrigger
Tracking --> Readline
Readline --> activatepir
activatepir --> activateLED
Readline --> loop2
loop2 --> Readline
activateLED --> activatedistance
activatedistance --> distance
distance --> ReadPIR
ReadPIR --> track
ReadPIR --> loop3
loop3 --> Readline
firelogic --> readdistance
readdistance --> fire
fire --> terminalEnd
readdistance --> Keeptrack
Keeptrack --> loop4 
loop4 --> readdistance

 ```