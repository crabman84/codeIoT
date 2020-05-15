from dc_motor import *
    

def runFan(pTemp):
    if (pTemp > 20):
        motorON()
    elif (pTemp < 20):
        motorOFF()
    else:
        motorOFF()            



if __name__ == "__main__":
    runFan(20)