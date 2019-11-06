import matplotlib.pyplot as plt
import sqlite3

conn = sqlite3.connect('lightdata.db')
c = conn.cursor()

print ("Opened database successfully")
c.execute('SELECT DATE, VALUE from (SELECT ID, DATE, VALUE from lightdata ORDER BY ID DESC LIMIT 10) lightdata ORDER BY ID ASC')
data = c.fetchall()
DATE = []
VALUE = []
for row in data:
    DATE.append((row[0]))
    VALUE.append(row[1])
conn.close()
print(DATE)
print(VALUE)
plt.plot(DATE,VALUE)
plt.xlabel('value')
plt.ylabel('date')
plt.xticks(rotation=65, fontsize=5)

plt.show()