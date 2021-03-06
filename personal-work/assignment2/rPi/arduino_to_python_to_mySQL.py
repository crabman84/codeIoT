import serial
import io
import MySQLdb

device = '/dev/ttyACM1'
#ser = serial.Serial('/dev/ttyACM1', 9600)


arduino = serial.Serial(device, 9600)

#dataTemp = arduino.readline()

temp = 5
motorPos = 50
hIndex = 4

i = 0
while(i<3):
    dataIndicator = arduino.readline()
    indicator = dataIndicator.decode().strip()
    ind = indicator
    print("ind: " + ind)
    #print(dataIndicator)
    if(ind == 'temp'):
#         print('test 1st if in while loop')
        dataTemp = arduino.readline()
        temp = dataTemp.decode('UTF-8')
        i = i + 1
    elif(indicator == "index"):
        dataHeatIndex = arduino.readline()
        hIndex = dataHeatIndex.decode('UTF-8')
        i = i + 1
    elif(indicator == "pos"):
        dataMotorPos = arduino.readline()
        motorPos = dataMotorPos.decode('UTF-8')
        i = i + 1

print('Encoded Serial Temp: '+ temp)
print('Encoded Serial Heat Index: '+ hIndex)
print('Encoded Serial Motor Position: '+ motorPos)



#Make DB connection

dbConn = MySQLdb.connect("localhost", "root", "password", "tempdb") or die("Could not connect to the database")

print(dbConn)

#with dbConn:
try: 
    cursor = dbConn.cursor()
    #cursor.execute("INSERT INTO tempLog (Temperature) VALUES (%s)" % (temp))
except (MySQLdb.Error) as e:
    print(e)
    dbConn.rollback()
else:
    dbConn.commit()
finally:
    cursor.close()
    