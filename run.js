var GPIO = require('./build/Release/gpio.node')

var in1 = GPIO.pin("PA",6);
var in2 = GPIO.pin("PC",0);
var in3 = GPIO.pin("PC",1);
var in4 = GPIO.pin("PC",2);
var in5 = GPIO.pin("PC",3);
var BTN = GPIO.pin("PG",7);
var LED = GPIO.pin("PG",6);
var JP = GPIO.pin("PG",8)
var AUX = GPIO.pin("PG",11)

GPIO.init();

GPIO.dir(in1, "IN");
GPIO.dir(in2, "IN");
GPIO.dir(in3, "IN");
GPIO.dir(in4, "IN");
GPIO.dir(in5, "IN");
GPIO.dir(LED, "OUT");





setInterval(function(){ 
	
	console.log("IN1",GPIO.read(in1),"IN2",GPIO.read(in2),"IN3",GPIO.read(in3),"IN4",GPIO.read(in4),"IN5",GPIO.read(in5));

}, 1000);

function high(){
	setTimeout(function(){ 
		var ret = GPIO.write(LED, 1);
		//console.log(ret);
		low();
	}, 1000);

}

function low(){
	setTimeout(function(){ 
		var ret = GPIO.write(LED, 0);
		//console.log(ret);
		high();
	}, 1000);

}

high();