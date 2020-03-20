import serial

class Board:
    def __init__(self, port_arduino, baud_rate):
        self.port_arduino = port_arduino
        self.baud_rate = baud_rate

    def begin(self):
        self.arduino = serial.Serial(self.port_arduino, self.baud_rate)

    def read(self):
        return self.arduino.readline()

    def send(self, command):
        self.arduino.write(command.encode())
        
    def finalize(self):
        self.arduino.close()

port_name = 'dev/sdjodsih'

b = Board(port_name, 9600)

b.begin()

for i in range(100000):
	b.send("hi")
	print(b.read())
b.finalize() 
