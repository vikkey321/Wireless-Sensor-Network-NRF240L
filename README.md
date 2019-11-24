# Wireless Sensor Network NRF240L
This is a tutorial on getting started with **"Wireless Sensor Network"** using **"NRF240L"** transreceiver module. I have written three examples to cover general scenarios to use the wireless module. We will cover below examples:
**1. One way Communication (NRF_Control_Device) :** In this example we will be configuring Node1 with push buttons & Node2 with LED. When push button on Node1 is pressed, it will turn on the led on Node2. When you push the same button again, it will turn off the LED.
**2. Two way Communication (NRF_Chatapp):** In this example we will configure Node1 & Node2 with unique address. You can open two serial ports simultaneously on windows on different serial ports. You can chat through the serial terminal with each other.
**3. One way data stream (NRF_Stream_Python_Plotgraph) :** In this example we will configure Node1 with LDR. We will stream data to Node2 which receives the data and stores that in the database by sending it to the computer through serial terminal. A python code runs to ingest that data and push that in SQLITE. User can use the other python script to see the data store in a graph.

This tutorial covers how to connect two nodes powered by **"NRF240L"** and **"Arduino Nano"**.
You will need below BOM to create two nodes:
1. Arduino Nano - 2
2. NRF240L - 2 (Either of modules will work. Long range (1 KM) & Short range (300 M approx))
3. Resistor 10 K - 3
4. Resistor 220 Ohm or 270 Ohm - 2
5. 5mm LED - 2
6. Push button - 2
7. Breadboard (Full Size) - 2


![alt text](https://github.com/vikkey321/Wireless-Sensor-Network-NRF240L/blob/master/Node1.png)
