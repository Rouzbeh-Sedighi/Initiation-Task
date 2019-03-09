from flask import Flask, render_template , request
import serial

app = Flask(__name__)

@app.before_first_request
def setupSerial():
	global ArduinoCon
	ArduinoCon = serial.Serial('com4',9600)


@app.route('/')
def index():
	return render_template('layout.html')

@app.route('/state')	
def getState():
	distance=""
	if ArduinoCon.inWaiting()>0 :
		distance=ArduinoCon.readline().decode('utf-8')
	return distance

@app.route('/ChColor',methods=['POST'])
def ChangeColor():

	colorValue=request.form['txtColor'].encode();
	ArduinoCon.write(colorValue)
	
	return render_template('layout.html')

        
        
        

if __name__ == '__main__':
	app.run(debug=True)
