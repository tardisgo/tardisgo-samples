package ;
import tardis.*; // import the generated Go code
class Main {
 	public static function main(){
		trace("Go unicode normalization library example");
		// for documentation see https://godoc.org/golang.org/x/text/unicode/norm
		compare("aaa","aaa");                                   // aaa == aaa ? true
		compare("aaa","aab");                                   // aaa == aab ? false
		compare("a\u0300a", "\u00E0a");                         // àa == àa ? true
		compare("a\u0300\u0320b", "a\u0320\u0300b");            // à̠b == à̠b ? true
		compare("\u1E0A\u0323", "\x44\u0323\u0307");            // Ḍ̇ == Ḍ̇ ? true
		// A character that decomposes into multiple segments spans several iterations.
		compare("\u3304", "\u30A4\u30CB\u30F3\u30AF\u3099");    // ㌄ == イニング ? true
	}
	static function compare(a1:String,b1:String):Bool{		
		// create the Go type
		var form:GoType_golang_dot_org_47_x_47_text_47_unicode_47_norm_dot_FForm;
		// set the type to translate strings to NFKD normal form
		form = Go.golang_dot_org_47_x_47_text_47_unicode_47_norm_NNFFKKDD;
		// translate
		var a2 = form._String(a1); 
		var b2 = form._String(b1);
		// test if the same
		var ret = a2 == b2;
		// show that we've done it for debug purposes
		trace(a1,"==",b1,"?",ret);
		return ret;
	}
} 