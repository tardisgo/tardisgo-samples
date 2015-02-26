package ;

import tardis.*;

class TestGoLib {
  static public function main():Void {
    trace("Hello World",
    	Go_math_SSqrt.hx(2),
    	Go_strconv_IItoa.hx(42));
  }
}