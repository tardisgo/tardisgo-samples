package;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.MouseEvent;
import flash.utils.Timer;
import openfl.Assets;
import flash.text.TextField;
import flash.text.TextFieldAutoSize;

import tardis.Go; // import of the Go code


class Main extends Sprite {
	
	private var Code:Sprite;
	private var Logo:Sprite;
	private var Destination:Sprite;
	
	private var goTimer:Timer;
	
	private var textField:TextField;
	private var whatToDo:TextField;

	public function new () {
		
		super ();

		whatToDo = new TextField ();
		whatToDo.selectable = false;
		whatToDo.x = 50;
		whatToDo.y = 90;
		whatToDo.width = 350;
		whatToDo.text = "USE YOUR MOUSE TO PUT THE GOPHER IN THE BOX";
		whatToDo.textColor = 0xff0000;		
		addChild (whatToDo);


		Code = new Sprite ();
		Code.addChild (new Bitmap (Assets.getBitmapData ("assets/code.png")));
		Code.x = 400;
		Code.y = 10;

		Logo = new Sprite ();
		Logo.addChild (new Bitmap (Assets.getBitmapData ("assets/gopher.png")));
		Logo.x = 100;
		Logo.y = 150;
		Logo.buttonMode = true;
	
		Destination = new Sprite ();
		Destination.graphics.beginFill (0xF5F5F5);
		Destination.graphics.lineStyle (1, 0xCCCCCC);
		Destination.graphics.drawRect (0, 0, Logo.width + 10, Logo.height + 10);
		Destination.x = 300;
		Destination.y = 145;
		
		addChild (Code);
		addChild (Destination);
		addChild (Logo);
		
		Logo.addEventListener (MouseEvent.MOUSE_DOWN, Logo_onMouseDown);
		stage.addEventListener (MouseEvent.MOUSE_MOVE, stage_onMouseMove);
		stage.addEventListener (MouseEvent.MOUSE_UP, stage_onMouseUp);

		textField = new TextField ();
		textField.selectable = false;
		textField.x = 305;
		textField.y = 260;
		textField.width = 200;
		textField.textColor = 0x008000;		
		textField.text = "(initialising)";
		addChild (textField);

		
		Go.init(); // initialise the Go environment
		Go_main_MouseGoroutine.callFromHaxe(); // start the mouse handling goroutine
		goTimer=new Timer(200); // 200 ms so that the MOUSE_UP Status can be read
		goTimer.addEventListener ( "timer", goTimerEvent); // schedule some go every so oftern
		goTimer.start();
	}
	
	private var UseGopher:Bool=true;
	private var lastStatus:String="";

	private function goTimerEvent(e:Dynamic):Void {
		Scheduler.timerEventHandler(e); // schedule the Go code
		Logo.x=Go.main_SpriteX.load(); // load the X and Y sprite values from Go
		Logo.y=Go.main_SpriteY.load();
		if(lastStatus!=Go.main_Status.load()) { // change the Go status code if required
			lastStatus=Go.main_Status.load();
			textField.text=lastStatus;
		}
		if (Destination.hitTestPoint (Logo.x, Logo.y)) { // this is just to make it look pretty
			if(UseGopher) {
				Logo.addChild (new Bitmap (Assets.getBitmapData ("assets/openfl.png")));
				UseGopher=false;
			}
		} else {
			if(!UseGopher) {
				Logo.addChild (new Bitmap (Assets.getBitmapData ("assets/gopher.png")));
				UseGopher=true;
			}
		}
	}
	
	
	// Event Handlers
	

	
	private function Logo_onMouseDown (event:MouseEvent):Void {

		Go_main_MouseDown.callFromHaxe(event.stageX,event.stageY);
		
	}
	
	
	private function stage_onMouseMove (event:MouseEvent):Void {
		
		Go_main_MouseMove.callFromHaxe(event.stageX,event.stageY);
		
	}
	
	
	private function stage_onMouseUp (event:MouseEvent):Void {

		Go_main_MouseUp.callFromHaxe(event.stageX,event.stageY);
		
	}
	
	
}