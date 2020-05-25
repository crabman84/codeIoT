import serial
import MySQLdb

device = '/dev/ttyACM0'
#ser = serial.Serial('/dev/ttyACM1', 9600)


arduino = serial.Serial(device, 9600)

data = arduino.readline()
print('Encoded Serial Databyte'+ data)
temp = data.decode('UTF-8')
print(temp)

#Make DB connection

dbConn = MySQLdb.connect("localhost", "root", "password", "tempdb") or die("Could not connect to the database")

print(dbConn)

#with dbConn:
try: 
    cursor = dbConn.cursor()
    cursor.execute("INSERT INTO tempLog (Temperature) VALUES (%s)" % (temp))
except (MySQLdb.Error) as e:
    print(e)
    dbConn.rollback()
else:
    dbConn.commit()
finally:
    cursor.close()
    