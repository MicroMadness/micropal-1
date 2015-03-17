import serial
ser = serial.Serial('/dev/ttyUSB0', 57600)



class _Getch:
    def __init__(self):
        import tty, sys

    def __call__(self):
        import sys, tty, termios
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch



getch = _Getch()

moving = 1

while moving:
	
	import time	

	gech = getch()
	
	if (gech == 'q'):
                moving = 0

	elif (gech == 'h'):
		ser.write("1")

	elif (gech == 's'):
		ser.write("2")

        elif (gech == 'o'):        
                ser.write("3")

	time.sleep(.1)

