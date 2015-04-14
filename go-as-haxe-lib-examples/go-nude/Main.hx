package ;

import tardis.*; // import the generated Go code
import js.html.*;

class Main {
	static var fName:String;

 	public static function main(){
		trace("Starting...");
 		tardis.Go_main_main.hx();
		trace("Go nude detection library ready");
		js.Browser.document.getElementById("inputFileToLoad").onchange = encodeImageFileAsURL; 
	}
	public static function writeFile(b:haxe.io.Bytes,typ:String):Void{
		var sl=tardis.Slice.fromBytes(b); // make a Go byte slice
		trace(typ,sl.len());
		var p="temp."+typ; // the name of our file
		// write the file in the pseudo file system
		var err=tardis.Go_io_47_ioutil_WWriteFFile.hx(p,sl,438 /*0666*/); 
	    if(err!=null){
			trace(p," ioutil.WriteFile() had error: ",err);
		} 
		trace("wrote file ",p);
	 	fName=p;
	}
	public static function isNude():Bool {
	    var ret=tardis.Go_github_dot_com_47_koyachi_47_go_45_nude_IIsNNude.hx(fName);
	    if(ret.r1!=null){
			trace("nude.IsNude() had error: ",ret.r1);
			return false;
		} 
	    return ret.r0;
	}
	public static function encodeImageFileAsURL(){

	    var filesSelected = cast(js.Browser.document.getElementById("inputFileToLoad"),js.html.InputElement).files;
	    if (filesSelected.length > 0)
	    {
	        var fileToLoad = filesSelected.item(0);

	        var fileReader = new FileReader();

	        fileReader.onload = function(fileLoadedEvent) {
	            var srcData = fileLoadedEvent.target.result; // <--- data: base64

	            var newImage = cast(js.Browser.document.createElement('img'),js.html.ImageElement);
	            newImage.src = srcData;

	            js.Browser.document.getElementById("imgTest").innerHTML = newImage.outerHTML;
	            js.Browser.document.getElementById("result").innerHTML = 
	            	"Processing in go-nude... (please note that large images take a very long time to process)";
	  
	            var bits = srcData.split(","); // split the header from the base64 data
	            var typ = bits[0].substr(11).split(";")[0]; // get the file extension
	            trace(typ);
	       		
	       		var byts = haxe.crypto.Base64.decode(bits[1]);
	       		trace(byts.length);
	       		writeFile(byts,typ);
				
				haxe.Timer.delay(function() {
						trace("start isNude");
				       	var nude = isNude();
			       		if(nude)
				            js.Browser.document.getElementById("result").innerHTML = "<font style=\"background:red\"  >Image looks nude!</font>";
				        else
				            js.Browser.document.getElementById("result").innerHTML = "<font style=\"background:green\">Image looks fine.</font>";
				    },100);

	        }
	        fileReader.readAsDataURL(fileToLoad);
	    }

	}

}