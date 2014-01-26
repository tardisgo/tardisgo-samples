package;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.utils.Timer;
import openfl.Assets;
import flash.text.TextField;
import flash.text.TextFieldAutoSize;

import tardis.Go; // import of the Go code


class Main extends Sprite {
	
	private var bigpile:Sprite;
	private var oven:Sprite;
	private var Code:Sprite;
	private var Logo1:Sprite;
	private var Logo2:Sprite;
	
	private var Sprite1:Sprite;
	private var s1x = 90;
	private var s1y = 45;
	
	private var Sprite2:Sprite;
	private var s2x = 420;
	private var s2y = 45;
	
	private var Books:Sprite;
	private var bx = 390;
	private var by = 50; 
	
	private var goTimer:Timer;
	
	private var textField:TextField;
	private var whatToDo:TextField;

	public function new () {
		
		super ();

		// Explation text on the left
		whatToDo = new TextField ();
		whatToDo.selectable = false;
		whatToDo.x = 10;
		whatToDo.y = 140;
		whatToDo.width = 200;
		whatToDo.height = 200;
		whatToDo.text = "Both animated gophers are \nrunning the code on the right.\nThe 2 logos show where they\neach are in that code now.\nThis code is running live,\ntargeting: "+Go.Platform();
		whatToDo.textColor = 0x008000;		
		addChild (whatToDo);

		// big pile of books on the left
		bigpile = new Sprite ();
		bigpile.addChild (new Bitmap (Assets.getBitmapData ("assets/bigpile.png")));
		bigpile.x = 10;
		bigpile.y = 20;
		addChild(bigpile);

		// oven on the right
		oven = new Sprite ();
		oven.addChild (new Bitmap (Assets.getBitmapData ("assets/oven.png")));
		oven.x = 690;
		oven.y = 0;
		addChild(oven);
		
		// books (sometimes) in the middle
		Books = new Sprite ();
		Books.addChild (new Bitmap (Assets.getBitmapData ("assets/smallpile.png")));
		Books.x = bx;
		Books.y = by;
		addChild(Books);
		
		// the left hand gopher
		Sprite1 = new Sprite ();
		Sprite1.addChild ( new Bitmap (Assets.getBitmapData ("assets/pick.png")));
		Sprite1.x = s1x;
		Sprite1.y = s1y;
		addChild(Sprite1);
		
		// the right hand gopher
		Sprite2 = new Sprite ();
		Sprite2.addChild ( new Bitmap (Assets.getBitmapData ("assets/pick.png")));
		Sprite2.x = s2x;
		Sprite2.y = s2y;
		addChild(Sprite2);
		
		// the code extract in the centre
		Code = new Sprite ();
		Code.addChild (new Bitmap (Assets.getBitmapData ("assets/function.png")));
		Code.x = 200;
		Code.y = 110;
		addChild (Code);
		
		// the left hand code indicator
		Logo1 = new Sprite ();
		Logo1.addChild (new Bitmap (Assets.getBitmapData ("assets/gophercolor16x16.png")));
		Logo1.x = 230;
		Logo1.y = 140;
		addChild (Logo1);

		// the right hand code indicator
		Logo2 = new Sprite ();
		Logo2.addChild (new Bitmap (Assets.getBitmapData ("assets/gophercolor16x16flipped.png")));
		Logo2.x = 540;
		Logo2.y = 140;
		addChild (Logo2);
	
		// the "inspired by"" text
		textField = new TextField ();
		textField.selectable = true;
		textField.x = 420;
		textField.y = 195;
		textField.width = 400;
		textField.height = 50;
		textField.textColor = 0x008000;		
		textField.text = "Inspired by \"Concurrency is not Parallelism (it's better)\" - Rob Pike\nhttp://concur.rspace.googlecode.com/hg/talk/concur.html";
		addChild (textField);
		
		// off we go...
		Go.init(); // initialise the Go environment
		Go_main_StartGophers.callFromHaxe(); // start the gopher animation goroutines
		goTimer=new Timer(25); // 25 ms per run
		goTimer.addEventListener ( "timer", goTimerEvent); // schedule some go every so often
		goTimer.start();
	}
	

	private var s1laststatus:Int=0;
	private var s2laststatus:Int=0;
	private var bookslaststatus:Bool=true;

	private function goTimerEvent(e:Dynamic):Void { // the entry point for every tick
		
		Scheduler.timerEventHandler(e); // schedule the Go code

		if(Go.main_smallpile.load().hasContents()!=bookslaststatus){
			bookslaststatus=Go.main_smallpile.load().hasContents();
			Books.removeChildAt(0);		
			if(Go.main_smallpile.load().hasContents()==true){		
				Books.addChild (new Bitmap (Assets.getBitmapData ("assets/smallpile.png")));			
			} else {
				Books.addChild (new Bitmap (Assets.getBitmapData ("assets/emptypile.png")));			
			}
		}
		
		if((Go.main_Sprite1state.load()|0)!=s1laststatus){
			
			// make sure we don't leave any stray pixels unset and flag for GC
			Sprite1.removeChildAt(0);
			
			s1laststatus = Go.main_Sprite1state.load()|0; // switch to the new state
			Logo1.y = 140 + (15*s1laststatus); // move the logo to reflect the new state
			
			// add the new image
			if(s1laststatus==Go.main_Pick) {
				Sprite1.addChild (new Bitmap (Assets.getBitmapData ("assets/pick.png")));
			}
			if(s1laststatus==Go.main_Full) {
				Sprite1.addChild (new Bitmap (Assets.getBitmapData ("assets/full.png")));
			}
			if(s1laststatus==Go.main_Shovel) {
				Sprite1.addChild (new Bitmap (Assets.getBitmapData ("assets/shovel.png")));
			}
			if(s1laststatus==Go.main_Empty) {
				Sprite1.addChild (new Bitmap (Assets.getBitmapData ("assets/empty.png")));
			}
		}
		Sprite1.x = s1x + Go.main_Sprite1X.load();
		Sprite1.y = s1y + Go.main_Sprite1Y.load();
		
		if((Go.main_Sprite2state.load()|0)!=s2laststatus){
			
			// make sure we don't leave any stray pixels unset and flag for GC
			Sprite2.removeChildAt(0);
			
			s2laststatus = Go.main_Sprite2state.load()|0; // switch to the new state
			Logo2.y = 140 + (15*s2laststatus); // move the logo to reflect the new state
			
			// add the new image
			if(s2laststatus==Go.main_Pick) {
				Sprite2.addChild (new Bitmap (Assets.getBitmapData ("assets/pick.png")));
			}
			if(s2laststatus==Go.main_Full) {
				Sprite2.addChild (new Bitmap (Assets.getBitmapData ("assets/full.png")));
			}
			if(s2laststatus==Go.main_Shovel) {
				Sprite2.addChild (new Bitmap (Assets.getBitmapData ("assets/shovel.png")));
			}
			if(s2laststatus==Go.main_Empty) {
				Sprite2.addChild (new Bitmap (Assets.getBitmapData ("assets/empty.png")));
			}
		}
		Sprite2.x = s2x + Go.main_Sprite2X.load();
		Sprite2.y = s2y + Go.main_Sprite2Y.load();
		
	}
		
}