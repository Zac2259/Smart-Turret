 ```mermaid
 flowchart TD
 %%standby logic
terminalStart([Button])
 terminalEnd([End])
Buttontrigger{Has button been pressed?}
activateturret(Activate Turret)
activatesensor(Activate sensor)
remainoff(Remain off)
loop(Wait 1 second)
%%Tracking logic
Readline(digitalRead(lineSensor))

terminalStart --> Buttontrigger
Buttontrigger --> activateturret
activateturret --> activatesensor
Buttontrigger --> remainoff
remainoff --> loop

 ```