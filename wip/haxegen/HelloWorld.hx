class HelloWorld {
  static public function main():Void {
  	var hw ="Hello World";
  	hw += "..."; 
	var fortytwo = 84;
	fortytwo = Std.int(fortytwo/2);
	trace(hw);
	for(i in 0...10) trace(i);
	trace(fortytwo);
  }
}