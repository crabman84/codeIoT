from writeToDB import *
from readSerialData import *
from runFan import *

if __name__ == "__main__":
    
    while(True):
        temp, isHot, motorPos = readSerialData()
        writeToDB(temp, isHot, motorPos)
        runFan(float(temp))
        
    #def main():

