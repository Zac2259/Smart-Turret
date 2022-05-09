 ```mermaid
 flowchart TD
 %%standby logic
terminalStart([Standby Logic])
 terminalEnd([End])
 Button(Button)
Buttontrigger{digitalRead Button}
activateturret(Activate Turret)
activatesensor(Activate line sensor)
remainoff(Remain off)
loop(Wait 1 second)
%%Tracking logic
Tracking(Tracking Logic)
Readline{digitalRead lineSensor}
activatepir(Activate PIR)
activatedistance(Activate Distance Sensor)
loop2(Wait 1 second)
distance(DistanceThreshold = 30)
ReadPIR{digitalRead PIR}
track(Track target)
loop3(wait 1 minute)
%%Firing
terminalStart --> Button
Button --> Buttontrigger
Buttontrigger --> activateturret
activateturret --> activatesensor
Buttontrigger --> remainoff
remainoff --> loop
loop -->Buttontrigger
Tracking --> Readline
Readline --> activatepir
Readline --> loop2
loop2 --> Readline
activatepir --> activatedistance
activatedistance --> distance
distance --> ReadPIR
ReadPIR --> track
ReadPIR --> loop3
loop3 --> Readline
 ```