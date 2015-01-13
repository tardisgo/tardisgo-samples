package;
import tardis.Go; // import of the Go code
class Main extends flash.display.Sprite {
	public function new () {
		super ();
		Go_main_SStart.callFromHaxe(this);
	}	
}