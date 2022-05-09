 ```mermaid
 flowchart TD
 %%standby logic
terminalStart([Button])
 terminalEnd([End])
Buttontrigger{Has button been pressed?}
activateturret(Activate Turret)
activatesensor(Activate line sensor)
remainoff(Remain off)
loop(Wait 1 second)
%%Tracking logic
Readline(digitalRead lineSensor)
activatepir(Activate PIR)
activatedistance(Activate Distance Sensor)
loop2(Wait one second)
distance(DistanceThreshold = 30)
ReadPIR(digitalRead PIR)
track(Track target)
loop3(wait one minute)
terminalStart --> Buttontrigger
Buttontrigger --> activateturret
activateturret --> activatesensor
Buttontrigger --> remainoff
remainoff --> loop
activatesensor --> Readline
Readline --> activatepir
Readline --> loop2
activatepir --> activatedistance

 ```