import serial
ser = serial.Serial('/dev/ttyACM0', 9600)


#test READ from serial OUTPUT arduino
while 1:
        if(ser.in_waiting > 0):
            line = ser.readline()
            line2 = ser.readline()
            line3 = ser.readline()
            str1 = line.decode('UTF-8')
            str2 = str(line2, 'UTF-8')
            str3 = str(line3, 'UTF-8')
            #print(line2)
            #print(line)
            print(str1)
            print(str2)
            print(str3)
            print('---------')
#             print(line.rstrip().lstrip())
#             print(line.strip('b/rn'))