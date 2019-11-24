# Wireless Sensor Network NRF24L0
### Introduction
This is a tutorial on getting started with **"Wireless Sensor Network"** using **"NRF24L0"** transreceiver module. I have written three examples to cover general scenarios to use the wireless module. We will cover below examples:
1. **One way Communication (NRF_Control_Device) :** In this example we will be configuring Node1 with push buttons & Node2 with LED. When push button on Node1 is pressed, it will turn on the led on Node2. When you push the same button again, it will turn off the LED.
2. **Two way Communication (NRF_Chatapp):** In this example we will configure Node1 & Node2 with unique address. You can open two serial ports simultaneously on windows on different serial ports. You can chat through the serial terminal with each other.
3. **One way data stream (NRF_Stream_Python_Plotgraph) :** In this example we will configure Node1 with LDR. We will stream data to Node2 which receives the data and stores that in the database by sending it to the computer through serial terminal. A python code runs to ingest that data and push that in SQLITE. User can use the other python script to see the data store in a graph. **Important :** Please make sure that you have python3 installed along with the libraries use in this example. You can install the libraries by using **"pip install <library_name>"**. In python code **code.py**, change the line to the serial port on which Node1 is connected:
```python
ser = serial.Serial('YOUR_SERIAL_PORT_NUMBER', 9600)
```
Start by running **"create_database.py"** file. Then run **"code.py"** file. If you want to see the graph, run **"plotgraph.py"** file.

### Bill of Materials
This tutorial covers how to connect two nodes powered by **"NRF24L0"** and **"Arduino Nano"**.
You will need below BOM to create two nodes:
1. Arduino Nano - 2
2. NRF24L0 - 2 (Either of modules will work. Long range (1 KM) & Short range (300 M approx))
3. Resistor 10 K - 3
4. Resistor 220 Ohm or 270 Ohm - 2
5. 5mm LED - 2
6. Push button - 2
7. Breadboard (Full Size) - 2

### Circuit Diagram
#### Arduino Nano -> NRF24L0 Pin Connection:
| Arduino Nano        | NRF24L0       |
| ------------------- |:-------------:|
| D7                  | CE            |
| D8                  | CSN           |
| D11                 | MOSI          |
| D12                 | MISO          |
| D13                 | SCK           |

#### Node 1 Circuit Diagram
![alt text](https://github.com/vikkey321/Wireless-Sensor-Network-NRF240L/blob/master/Node1.png)

#### Node 2 Circuit Diagram
![alt text](https://github.com/vikkey321/Wireless-Sensor-Network-NRF240L/blob/master/Node2.png)

