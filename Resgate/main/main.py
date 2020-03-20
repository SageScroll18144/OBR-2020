import serial as little_board

#it's just an example. Change please the name mainly for job with SO Windown and Linux
name_board = '/dev/ttyUSB0'
value_of_baudRate= 9600

b = little_board.Board(name_board, value_of_baudRate)

b.begin()

while True:
	movement = "S"
    #byte from send. It's a form to say 'you can send... '
    b.send(movement)
b.finalize()