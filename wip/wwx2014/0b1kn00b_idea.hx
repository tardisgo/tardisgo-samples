
// https://gist.github.com/0b1kn00b/202e71a5764c7264fc57
//  0b1kn00b / Proxy.hx

enum Proxy<A,B,X,Y,R>{
  Await(v:A,arw:B->Proxy<A,B,X,Y,R>);
  Yield(v:Y,arw:X->Proxy<A,B,X,Y,R>);
  Ended(res:R);
}
