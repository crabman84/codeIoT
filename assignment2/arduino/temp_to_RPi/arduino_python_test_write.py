#test write to Arduino
import serial
ser = serial.Serial('/dev/ttyACM2', 9600)

int_encode = b'2'
float_encode = b'42.3'

string1 = "Hello!"
string1_encode = string1.encode()

int1 = 1
int1_encode = b'%d' %int1  # %d is used for integer data types. float  = %f

#ser.write(b'3')
#ser.write(b'5')
#ser.write(b'7')
ser.write(int1_encode)


        
        