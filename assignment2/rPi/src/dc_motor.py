import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
PIN = 2
GPIO.setup(PIN, GPIO.OUT)
my_pwm = GPIO.PWM(PIN, 100)


my_pwm.start(0)

def motorON():
    my_pwm.start(97)

def motorOFF():
    my_pwm.start(0)