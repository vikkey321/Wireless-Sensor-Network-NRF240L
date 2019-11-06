from time import sleep
import serial 
import sqlite3

import numpy as np
import matplotlib.pyplot as plt
from datetime import datetime

conn = sqlite3.connect('lightdata.db')
print ("Opened database successfully")

ser = serial.Serial('com6', 9600) # Establish the connection on a specific port

while True:
    x = ser.readline()
    y = x.decode("utf-8")
    y = y.rstrip('\n')
    y = y.replace('\r','')
    print (y)
    conn = sqlite3.connect('lightdata.db')
    conn.execute('''INSERT INTO lightdata(DATE,VALUE) VALUES(?,?)''', (datetime.now(),y))
    conn.commit()
    print ("Records created successfully")
    conn.close()
    sleep(.1)