package ;

import tardis.Go;
import cpp.vm.Profiler;


class Profile {
	public static function main () {
     	cpp.vm.Profiler.start("log.txt");
    	tardis.Go.main();
   		cpp.vm.Profiler.stop();
  	}
 }
