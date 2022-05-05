 ```mermaid
 flowchart TD
terminalStart([Button])
 terminalEnd([End])
Buttontrigger{Has button been pressed?}
activateturret(Activate Turret and sensor)
remainoff(Remain off)
loop(Wait 1 second)

terminalStart --> Buttontrigger
 ```