import sqlite3

conn = sqlite3.connect('lightdata.db')
print ("Opened database successfully")

conn.execute('''CREATE TABLE lightdata
         (ID INTEGER PRIMARY KEY AUTOINCREMENT,
         DATE           timestamp    NOT NULL,
         VALUE            INT     NOT NULL);''')
print ("Table created successfully")

conn.close()