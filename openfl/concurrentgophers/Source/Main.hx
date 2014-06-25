package ;
import tardis.Go; // import of the Go code
class Main extends openfl.display.Sprite {
	public function new () {
		super ();
		tardis.Go_main_Start.callFromHaxe(this);
	}
}