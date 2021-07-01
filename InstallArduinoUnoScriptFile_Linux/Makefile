FILENAME = Arduino_uno.ino
PORT = /dev/ttyACM0

upload:
	arduino-cli compile -b arduino:avr:uno arduino-cli_${FILENAME} -u -p ${PORT}
