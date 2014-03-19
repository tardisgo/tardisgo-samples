
// COPY of https://raw.github.com/openfl/openfl-html5-dom/master/flash/utils/Timer.hx

package myutils;

import flash.events.EventDispatcher;
//import flash.events.TimerEvent;


import flash.events.Event;


class TimerEvent extends Event {
	
	
	public static inline var TIMER:String = "timer";
	public static inline var TIMER_COMPLETE:String = "timerComplete";
	
	
	public function new (type:String, bubbles:Bool = false, cancelable:Bool = false):Void {
		
		super(type, bubbles, cancelable);
		
	}
	
	
	public function updateAfterEvent ():Void {
		
		
		
	}
	
	
}

class Timer extends EventDispatcher {
	
	
	public var currentCount (default, null):Int;
	public var delay (default, set_delay):Float;
	public var repeatCount (default, set_repeatCount):Int;
	public var running (default, null):Bool;

	private var timerId:Int;
	

	public function new (delay:Float, repeatCount:Int = 0):Void {
		
		super ();
		
		this.running = false;
		this.delay = delay;
		this.repeatCount = repeatCount;
		this.currentCount = 0;
		
	}
	
	
	public function reset ():Void {
		
		stop();
		currentCount = 0;
		
	}
	
	
	public function start ():Void {
		
		if (running) return;
		
		running = true;
		timerId = untyped window.setInterval (__onInterval, Std.int (delay));
		
	}
	
	
	public function stop ():Void {
		
		if (timerId != null) {
			
			untyped window.clearInterval (timerId);
			timerId = null;
			
		}
		
		running = false;
		
	}
	
	
	
	
	// Event Handlers
	
	
	
	
	private function __onInterval ():Void {
		
		currentCount ++;
		
		if (repeatCount > 0 && currentCount >= repeatCount) {
			
			stop ();
			dispatchEvent (new TimerEvent (TimerEvent.TIMER));
			dispatchEvent (new TimerEvent (TimerEvent.TIMER_COMPLETE));
			
		} else {
			
			dispatchEvent (new TimerEvent (TimerEvent.TIMER));
			
		}
		
	}
	
	
	
	
	// Getters & Setters
	
	
	
	
	private function set_delay (v:Float):Float {
		
		if (v != delay) {
			
			var wasRunning = running;
			
			if (running) stop ();
			
			this.delay = v;
			
			if (wasRunning) start ();
			
		}
		
		return v;
		
	}
	
	
	private function set_repeatCount (v:Int):Int {
		
		if (running && v != 0 && v <= currentCount) {
			
			stop ();
			
		}
		
		repeatCount = v;
		return v;
		
	}
	
	
}
