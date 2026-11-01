# DLD_Smart_Dustbin
This is the open ended DLD project. We were free to make whatever we wanted, so I tried to make a Smart Dustbin with a few features.

# Idea
In this project, I aimed to construct an automatic dustbin whose Lid would open when it detects that someone wants to put trash in the bin and would sound an alarm when it detects that the bin is almost full with trash.

# Components
-	2 Ultrasonic sensors
-	Female to Female and Male to Female wires
-	Esp8266 Nodemcu
-	Generic buzzer
-	9V Battery
-	9g Microservo
-	Cardboard
-	Tape
-	Washer
-	String

# Working
At the start of every loop, the ultrasonic sensor inside the basket, attached to the side, checks the distance to the bottom, and if it detects anything less than 1.5 inches away, it sends a signal to the generic buzzer to start sounding at a frequency of 1kHz. This means that the trash bin is almost full, and the owner needs to empty the bin. It then checks the distance through the ultrasonic sensor fitted at the front of the basket, and if the distance is less than 30cm, then it means that someone is nearby and is attempting to drop some trash in the bin. The lid lifts up, and as soon as the person drops the trash the lid moves back tot the original position. This duration is 3000 milliseconds or 3 seconds. The lid is lifted up by a 9g microservo attached at the top of the lid. The lid has 2 parts joined together by tape. The 9g servo pulls up the front half of the lid by using a string and a washer. The washer stops the string from being fully pulled out of the bin and due to this the lid is lifted up. Every other component, including the wires, is attached at the walls inside the bin.

