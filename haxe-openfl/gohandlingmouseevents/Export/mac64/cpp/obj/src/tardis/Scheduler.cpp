#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_TypeInfo
#include <tardis/TypeInfo.h>
#endif
namespace tardis{

Void Scheduler_obj::__construct()
{
	return null();
}

Scheduler_obj::~Scheduler_obj() { }

Dynamic Scheduler_obj::__CreateEmpty() { return  new Scheduler_obj; }
hx::ObjectPtr< Scheduler_obj > Scheduler_obj::__new()
{  hx::ObjectPtr< Scheduler_obj > result = new Scheduler_obj();
	result->__construct();
	return result;}

Dynamic Scheduler_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Scheduler_obj > result = new Scheduler_obj();
	result->__construct();
	return result;}

bool Scheduler_obj::doneInit;

Array< ::Dynamic > Scheduler_obj::grStacks;

Array< bool > Scheduler_obj::grInPanic;

Array< ::Dynamic > Scheduler_obj::grPanicMsg;

::String Scheduler_obj::panicStackDump;

int Scheduler_obj::entryCount;

int Scheduler_obj::currentGR;

Void Scheduler_obj::timerEventHandler( Dynamic dummy){
{
		HX_STACK_PUSH("Scheduler::timerEventHandler","tardis/Go.hx",1275);
		HX_STACK_ARG(dummy,"dummy");
		HX_STACK_LINE(1275)
		::tardis::Scheduler_obj::runAll();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Scheduler_obj,timerEventHandler,(void))

Void Scheduler_obj::runAll( ){
{
		HX_STACK_PUSH("Scheduler::runAll","tardis/Go.hx",1279);
		HX_STACK_LINE(1280)
		int cg = (int)0;		HX_STACK_VAR(cg,"cg");
		HX_STACK_LINE(1281)
		(::tardis::Scheduler_obj::entryCount)++;
		HX_STACK_LINE(1282)
		if (((::tardis::Scheduler_obj::entryCount > (int)2))){
			HX_STACK_LINE(1282)
			hx::Throw ((HX_CSTRING("Scheduler.runAll() entryCount exceeded - ") + ::tardis::Scheduler_obj::stackDump()));
		}
		HX_STACK_LINE(1287)
		if ((::tardis::Scheduler_obj::grStacks->__get((int)0).StaticCast< ::List >()->isEmpty())){
			HX_STACK_LINE(1287)
			if (((::tardis::Scheduler_obj::grStacks->length <= (int)1))){
				HX_STACK_LINE(1288)
				hx::Throw ((HX_CSTRING("Scheduler: there is only one goroutine and its stack is empty\n") + ::tardis::Scheduler_obj::stackDump()));
			}
		}
		else{
			HX_STACK_LINE(1291)
			if ((::tardis::Scheduler_obj::grInPanic->__get((int)0))){
				HX_STACK_LINE(1292)
				if (((::tardis::Scheduler_obj::entryCount != (int)1))){
					HX_STACK_LINE(1292)
					if (((::tardis::Scheduler_obj::grStacks->__get((int)0).StaticCast< ::List >()->first() == null()))){
						HX_STACK_LINE(1292)
						hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + (int)0) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
					}
					else{
						HX_STACK_LINE(1292)
						::tardis::Scheduler_obj::currentGR = (int)0;
						HX_STACK_LINE(1292)
						::tardis::Scheduler_obj::grStacks->__get((int)0).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
					}
				}
				else{
					HX_STACK_LINE(1292)
					while((::tardis::Scheduler_obj::grInPanic->__get((int)0))){
						HX_STACK_LINE(1292)
						if ((::tardis::Scheduler_obj::grStacks->__get((int)0).StaticCast< ::List >()->isEmpty())){
							HX_STACK_LINE(1292)
							hx::Throw ((((HX_CSTRING("Panic in goroutine ") + (int)0) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::panicStackDump));
						}
						else{
							HX_STACK_LINE(1292)
							::tardis::StackFrame sf = ::tardis::Scheduler_obj::grStacks->__get((int)0).StaticCast< ::List >()->pop();		HX_STACK_VAR(sf,"sf");
							HX_STACK_LINE(1292)
							while((!(sf->__Field(HX_CSTRING("_deferStack"),true)->__Field(HX_CSTRING("isEmpty"),true)()))){
								HX_STACK_LINE(1292)
								::tardis::StackFrame def = sf->__Field(HX_CSTRING("_deferStack"),true)->__Field(HX_CSTRING("pop"),true)();		HX_STACK_VAR(def,"def");
								HX_STACK_LINE(1292)
								::tardis::Scheduler_obj::push((int)0,def);
								HX_STACK_LINE(1292)
								while((def->__Field(HX_CSTRING("_incomplete"),true))){
									HX_STACK_LINE(1292)
									::tardis::Scheduler_obj::runAll();
								}
							}
						}
					}
				}
			}
			else{
				HX_STACK_LINE(1292)
				if (((::tardis::Scheduler_obj::grStacks->__get((int)0).StaticCast< ::List >()->first() == null()))){
					HX_STACK_LINE(1292)
					hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + (int)0) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
				}
				else{
					HX_STACK_LINE(1292)
					::tardis::Scheduler_obj::currentGR = (int)0;
					HX_STACK_LINE(1292)
					::tardis::Scheduler_obj::grStacks->__get((int)0).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
				}
			}
		}
		HX_STACK_LINE(1295)
		if (((bool(::tardis::Scheduler_obj::doneInit) && bool((::tardis::Scheduler_obj::entryCount == (int)1))))){
			HX_STACK_LINE(1297)
			{
				HX_STACK_LINE(1297)
				int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
				int _g = ::tardis::Scheduler_obj::grStacks->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1297)
				while(((_g1 < _g))){
					HX_STACK_LINE(1297)
					int cg1 = (_g1)++;		HX_STACK_VAR(cg1,"cg1");
					HX_STACK_LINE(1298)
					if ((!(::tardis::Scheduler_obj::grStacks->__get(cg1).StaticCast< ::List >()->isEmpty()))){
						HX_STACK_LINE(1298)
						if ((::tardis::Scheduler_obj::grInPanic->__get(cg1))){
							HX_STACK_LINE(1299)
							if (((::tardis::Scheduler_obj::entryCount != (int)1))){
								HX_STACK_LINE(1299)
								if (((::tardis::Scheduler_obj::grStacks->__get(cg1).StaticCast< ::List >()->first() == null()))){
									HX_STACK_LINE(1299)
									hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + cg1) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
								}
								else{
									HX_STACK_LINE(1299)
									::tardis::Scheduler_obj::currentGR = cg1;
									HX_STACK_LINE(1299)
									::tardis::Scheduler_obj::grStacks->__get(cg1).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
								}
							}
							else{
								HX_STACK_LINE(1299)
								while((::tardis::Scheduler_obj::grInPanic->__get(cg1))){
									HX_STACK_LINE(1299)
									if ((::tardis::Scheduler_obj::grStacks->__get(cg1).StaticCast< ::List >()->isEmpty())){
										HX_STACK_LINE(1299)
										hx::Throw ((((HX_CSTRING("Panic in goroutine ") + cg1) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::panicStackDump));
									}
									else{
										HX_STACK_LINE(1299)
										::tardis::StackFrame sf = ::tardis::Scheduler_obj::grStacks->__get(cg1).StaticCast< ::List >()->pop();		HX_STACK_VAR(sf,"sf");
										HX_STACK_LINE(1299)
										while((!(sf->__Field(HX_CSTRING("_deferStack"),true)->__Field(HX_CSTRING("isEmpty"),true)()))){
											HX_STACK_LINE(1299)
											::tardis::StackFrame def = sf->__Field(HX_CSTRING("_deferStack"),true)->__Field(HX_CSTRING("pop"),true)();		HX_STACK_VAR(def,"def");
											HX_STACK_LINE(1299)
											::tardis::Scheduler_obj::push(cg1,def);
											HX_STACK_LINE(1299)
											while((def->__Field(HX_CSTRING("_incomplete"),true))){
												HX_STACK_LINE(1299)
												::tardis::Scheduler_obj::runAll();
											}
										}
									}
								}
							}
						}
						else{
							HX_STACK_LINE(1299)
							if (((::tardis::Scheduler_obj::grStacks->__get(cg1).StaticCast< ::List >()->first() == null()))){
								HX_STACK_LINE(1299)
								hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + cg1) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
							}
							else{
								HX_STACK_LINE(1299)
								::tardis::Scheduler_obj::currentGR = cg1;
								HX_STACK_LINE(1299)
								::tardis::Scheduler_obj::grStacks->__get(cg1).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
							}
						}
					}
				}
			}
			HX_STACK_LINE(1303)
			while(((::tardis::Scheduler_obj::grStacks->length > (int)1))){
				HX_STACK_LINE(1303)
				if ((::tardis::Scheduler_obj::grStacks->__get((::tardis::Scheduler_obj::grStacks->length - (int)1)).StaticCast< ::List >()->isEmpty())){
					HX_STACK_LINE(1305)
					::tardis::Scheduler_obj::grStacks->pop().StaticCast< ::List >();
				}
				else{
					HX_STACK_LINE(1307)
					break;
				}
			}
		}
		HX_STACK_LINE(1310)
		(::tardis::Scheduler_obj::entryCount)--;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Scheduler_obj,runAll,(void))

Void Scheduler_obj::runOne( int gr,int entryCount){
{
		HX_STACK_PUSH("Scheduler::runOne","tardis/Go.hx",1312);
		HX_STACK_ARG(gr,"gr");
		HX_STACK_ARG(entryCount,"entryCount");
		HX_STACK_LINE(1312)
		if ((::tardis::Scheduler_obj::grInPanic->__get(gr))){
			HX_STACK_LINE(1313)
			if (((entryCount != (int)1))){
				HX_STACK_LINE(1314)
				if (((::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first() == null()))){
					HX_STACK_LINE(1316)
					hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
				}
				else{
					HX_STACK_LINE(1316)
					::tardis::Scheduler_obj::currentGR = gr;
					HX_STACK_LINE(1316)
					::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
				}
			}
			else{
				HX_STACK_LINE(1317)
				while((::tardis::Scheduler_obj::grInPanic->__get(gr))){
					HX_STACK_LINE(1318)
					if ((::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->isEmpty())){
						HX_STACK_LINE(1320)
						hx::Throw ((((HX_CSTRING("Panic in goroutine ") + gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::panicStackDump));
					}
					else{
						HX_STACK_LINE(1322)
						::tardis::StackFrame sf = ::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->pop();		HX_STACK_VAR(sf,"sf");
						HX_STACK_LINE(1323)
						while((!(sf->__Field(HX_CSTRING("_deferStack"),true)->__Field(HX_CSTRING("isEmpty"),true)()))){
							HX_STACK_LINE(1326)
							::tardis::StackFrame def = sf->__Field(HX_CSTRING("_deferStack"),true)->__Field(HX_CSTRING("pop"),true)();		HX_STACK_VAR(def,"def");
							HX_STACK_LINE(1327)
							::tardis::Scheduler_obj::push(gr,def);
							HX_STACK_LINE(1328)
							while((def->__Field(HX_CSTRING("_incomplete"),true))){
								HX_STACK_LINE(1329)
								::tardis::Scheduler_obj::runAll();
							}
						}
					}
				}
			}
		}
		else{
			HX_STACK_LINE(1334)
			if (((::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(1335)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(1335)
				::tardis::Scheduler_obj::currentGR = gr;
				HX_STACK_LINE(1335)
				::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Scheduler_obj,runOne,(void))

Void Scheduler_obj::run1( int gr){
{
		HX_STACK_PUSH("Scheduler::run1","tardis/Go.hx",1338);
		HX_STACK_ARG(gr,"gr");
		HX_STACK_LINE(1338)
		if (((::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(1339)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(1342)
			::tardis::Scheduler_obj::currentGR = gr;
			HX_STACK_LINE(1343)
			::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Scheduler_obj,run1,(void))

int Scheduler_obj::makeGoroutine( ){
	HX_STACK_PUSH("Scheduler::makeGoroutine","tardis/Go.hx",1346);
	HX_STACK_LINE(1347)
	{
		HX_STACK_LINE(1347)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::tardis::Scheduler_obj::grStacks->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1347)
		while(((_g1 < _g))){
			HX_STACK_LINE(1347)
			int r = (_g1)++;		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(1348)
			if ((::tardis::Scheduler_obj::grStacks->__get(r).StaticCast< ::List >()->isEmpty())){
				HX_STACK_LINE(1350)
				::tardis::Scheduler_obj::grInPanic[r] = false;
				HX_STACK_LINE(1351)
				::tardis::Scheduler_obj::grPanicMsg[r] = null();
				HX_STACK_LINE(1352)
				return r;
			}
		}
	}
	HX_STACK_LINE(1354)
	int l = ::tardis::Scheduler_obj::grStacks->length;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1355)
	::tardis::Scheduler_obj::grStacks[l] = ::List_obj::__new();
	HX_STACK_LINE(1356)
	::tardis::Scheduler_obj::grInPanic[l] = false;
	HX_STACK_LINE(1357)
	::tardis::Scheduler_obj::grPanicMsg[l] = null();
	HX_STACK_LINE(1358)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Scheduler_obj,makeGoroutine,return )

::tardis::StackFrame Scheduler_obj::pop( int gr){
	HX_STACK_PUSH("Scheduler::pop","tardis/Go.hx",1360);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_LINE(1361)
	if (((bool((gr >= ::tardis::Scheduler_obj::grStacks->length)) || bool((gr < (int)0))))){
		HX_STACK_LINE(1362)
		hx::Throw (HX_CSTRING("Scheduler.pop() invalid goroutine"));
	}
	HX_STACK_LINE(1363)
	return ::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->pop();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Scheduler_obj,pop,return )

Void Scheduler_obj::push( int gr,::tardis::StackFrame sf){
{
		HX_STACK_PUSH("Scheduler::push","tardis/Go.hx",1365);
		HX_STACK_ARG(gr,"gr");
		HX_STACK_ARG(sf,"sf");
		HX_STACK_LINE(1366)
		if (((bool((gr >= ::tardis::Scheduler_obj::grStacks->length)) || bool((gr < (int)0))))){
			HX_STACK_LINE(1367)
			hx::Throw (HX_CSTRING("Scheduler.push() invalid goroutine"));
		}
		HX_STACK_LINE(1368)
		::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->push(sf);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Scheduler_obj,push,(void))

::String Scheduler_obj::stackDump( ){
	HX_STACK_PUSH("Scheduler::stackDump","tardis/Go.hx",1371);
	HX_STACK_LINE(1372)
	::String ret = HX_CSTRING("");		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(1373)
	int gr;		HX_STACK_VAR(gr,"gr");
	HX_STACK_LINE(1374)
	hx::AddEq(ret,((HX_CSTRING("runAll() entryCount=") + ::tardis::Scheduler_obj::entryCount) + HX_CSTRING("\n")));
	HX_STACK_LINE(1375)
	{
		HX_STACK_LINE(1375)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::tardis::Scheduler_obj::grStacks->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1375)
		while(((_g1 < _g))){
			HX_STACK_LINE(1375)
			int gr1 = (_g1)++;		HX_STACK_VAR(gr1,"gr1");
			HX_STACK_LINE(1376)
			hx::AddEq(ret,((((HX_CSTRING("Goroutine ") + gr1) + HX_CSTRING(" ")) + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg->__get(gr1).StaticCast< ::tardis::Interface >())) + HX_CSTRING("\n")));
			HX_STACK_LINE(1377)
			if ((::tardis::Scheduler_obj::grStacks->__get(gr1).StaticCast< ::List >()->isEmpty())){
				HX_STACK_LINE(1377)
				hx::AddEq(ret,HX_CSTRING("Stack is empty\n"));
			}
			else{
				HX_STACK_LINE(1380)
				hx::AddEq(ret,((HX_CSTRING("Stack has ") + ::tardis::Scheduler_obj::grStacks->__get(gr1).StaticCast< ::List >()->length) + HX_CSTRING(" entries:\n")));
				HX_STACK_LINE(1381)
				Dynamic it = ::tardis::Scheduler_obj::grStacks->__get(gr1).StaticCast< ::List >()->iterator();		HX_STACK_VAR(it,"it");
				HX_STACK_LINE(1382)
				while((it->__Field(HX_CSTRING("hasNext"),true)())){
					HX_STACK_LINE(1383)
					::tardis::StackFrame ent = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(ent,"ent");
					HX_STACK_LINE(1384)
					if (((ent == null()))){
						HX_STACK_LINE(1384)
						hx::AddEq(ret,HX_CSTRING("\tStack entry is null\n"));
					}
					else{
						HX_STACK_LINE(1387)
						hx::AddEq(ret,(((HX_CSTRING("\t") + ent->__Field(HX_CSTRING("_functionName"),true)) + HX_CSTRING(" starting at ")) + ::tardis::Go_obj::CPos(ent->__Field(HX_CSTRING("_functionPH"),true))));
						HX_STACK_LINE(1388)
						hx::AddEq(ret,(HX_CSTRING(" latest position ") + ::tardis::Go_obj::CPos(ent->__Field(HX_CSTRING("_latestPH"),true))));
						HX_STACK_LINE(1389)
						hx::AddEq(ret,((HX_CSTRING(" latest block ") + ent->__Field(HX_CSTRING("_latestBlock"),true)) + HX_CSTRING("\n")));
					}
				}
			}
		}
	}
	HX_STACK_LINE(1394)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Scheduler_obj,stackDump,return )

Void Scheduler_obj::traceStackDump( ){
{
		HX_STACK_PUSH("Scheduler::traceStackDump","tardis/Go.hx",1397);
		HX_STACK_LINE(1397)
		::haxe::Log_obj::trace(::tardis::Scheduler_obj::stackDump(),hx::SourceInfo(HX_CSTRING("Go.hx"),1397,HX_CSTRING("tardis.Scheduler"),HX_CSTRING("traceStackDump")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Scheduler_obj,traceStackDump,(void))

Void Scheduler_obj::panic( int gr,::tardis::Interface err){
{
		HX_STACK_PUSH("Scheduler::panic","tardis/Go.hx",1399);
		HX_STACK_ARG(gr,"gr");
		HX_STACK_ARG(err,"err");
		HX_STACK_LINE(1400)
		if (((bool((gr >= ::tardis::Scheduler_obj::grStacks->length)) || bool((gr < (int)0))))){
			HX_STACK_LINE(1401)
			hx::Throw (HX_CSTRING("Scheduler.panic() invalid goroutine"));
		}
		HX_STACK_LINE(1402)
		if ((!(::tardis::Scheduler_obj::grInPanic->__get(gr)))){
			HX_STACK_LINE(1403)
			::tardis::Scheduler_obj::grInPanic[gr] = true;
			HX_STACK_LINE(1404)
			::tardis::Scheduler_obj::grPanicMsg[gr] = err;
			HX_STACK_LINE(1405)
			::tardis::Scheduler_obj::panicStackDump = ::tardis::Scheduler_obj::stackDump();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Scheduler_obj,panic,(void))

::tardis::Interface Scheduler_obj::recover( int gr){
	HX_STACK_PUSH("Scheduler::recover","tardis/Go.hx",1408);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_LINE(1409)
	if (((bool((gr >= ::tardis::Scheduler_obj::grStacks->length)) || bool((gr < (int)0))))){
		HX_STACK_LINE(1410)
		hx::Throw (HX_CSTRING("Scheduler.recover() invalid goroutine"));
	}
	HX_STACK_LINE(1411)
	::tardis::Scheduler_obj::grInPanic[gr] = false;
	HX_STACK_LINE(1412)
	return ::tardis::Scheduler_obj::grPanicMsg->__get(gr).StaticCast< ::tardis::Interface >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Scheduler_obj,recover,return )

Void Scheduler_obj::panicFromHaxe( ::String err){
{
		HX_STACK_PUSH("Scheduler::panicFromHaxe","tardis/Go.hx",1414);
		HX_STACK_ARG(err,"err");
		HX_STACK_LINE(1414)
		if (((bool((::tardis::Scheduler_obj::currentGR >= ::tardis::Scheduler_obj::grStacks->length)) || bool((::tardis::Scheduler_obj::currentGR < (int)0))))){
			HX_STACK_LINE(1417)
			::tardis::Scheduler_obj::panic((int)0,::tardis::Interface_obj::__new(::tardis::TypeInfo_obj::getId(HX_CSTRING("string")),((HX_CSTRING("Runtime panic, unknown goroutine, ") + err) + HX_CSTRING(" "))));
		}
		else{
			HX_STACK_LINE(1419)
			::tardis::Scheduler_obj::panic(::tardis::Scheduler_obj::currentGR,::tardis::Interface_obj::__new(::tardis::TypeInfo_obj::getId(HX_CSTRING("string")),((HX_CSTRING("Runtime panic, ") + err) + HX_CSTRING(" "))));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Scheduler_obj,panicFromHaxe,(void))

Void Scheduler_obj::bbi( ){
{
		HX_STACK_PUSH("Scheduler::bbi","tardis/Go.hx",1421);
		HX_STACK_LINE(1421)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("bad block ID (internal phi error)"));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Scheduler_obj,bbi,(void))

Void Scheduler_obj::ioor( ){
{
		HX_STACK_PUSH("Scheduler::ioor","tardis/Go.hx",1424);
		HX_STACK_LINE(1424)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("index out of range"));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Scheduler_obj,ioor,(void))

int Scheduler_obj::NumGoroutine( ){
	HX_STACK_PUSH("Scheduler::NumGoroutine","tardis/Go.hx",1427);
	HX_STACK_LINE(1427)
	return ::tardis::Scheduler_obj::grStacks->length;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Scheduler_obj,NumGoroutine,return )


Scheduler_obj::Scheduler_obj()
{
}

void Scheduler_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Scheduler);
	HX_MARK_END_CLASS();
}

void Scheduler_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Scheduler_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pop") ) { return pop_dyn(); }
		if (HX_FIELD_EQ(inName,"bbi") ) { return bbi_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"run1") ) { return run1_dyn(); }
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		if (HX_FIELD_EQ(inName,"ioor") ) { return ioor_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"panic") ) { return panic_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"runAll") ) { return runAll_dyn(); }
		if (HX_FIELD_EQ(inName,"runOne") ) { return runOne_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"recover") ) { return recover_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"doneInit") ) { return doneInit; }
		if (HX_FIELD_EQ(inName,"grStacks") ) { return grStacks; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"grInPanic") ) { return grInPanic; }
		if (HX_FIELD_EQ(inName,"currentGR") ) { return currentGR; }
		if (HX_FIELD_EQ(inName,"stackDump") ) { return stackDump_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"grPanicMsg") ) { return grPanicMsg; }
		if (HX_FIELD_EQ(inName,"entryCount") ) { return entryCount; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"NumGoroutine") ) { return NumGoroutine_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"makeGoroutine") ) { return makeGoroutine_dyn(); }
		if (HX_FIELD_EQ(inName,"panicFromHaxe") ) { return panicFromHaxe_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"panicStackDump") ) { return panicStackDump; }
		if (HX_FIELD_EQ(inName,"traceStackDump") ) { return traceStackDump_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"timerEventHandler") ) { return timerEventHandler_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Scheduler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"doneInit") ) { doneInit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"grStacks") ) { grStacks=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"grInPanic") ) { grInPanic=inValue.Cast< Array< bool > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentGR") ) { currentGR=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"grPanicMsg") ) { grPanicMsg=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"entryCount") ) { entryCount=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"panicStackDump") ) { panicStackDump=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Scheduler_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("doneInit"),
	HX_CSTRING("grStacks"),
	HX_CSTRING("grInPanic"),
	HX_CSTRING("grPanicMsg"),
	HX_CSTRING("panicStackDump"),
	HX_CSTRING("entryCount"),
	HX_CSTRING("currentGR"),
	HX_CSTRING("timerEventHandler"),
	HX_CSTRING("runAll"),
	HX_CSTRING("runOne"),
	HX_CSTRING("run1"),
	HX_CSTRING("makeGoroutine"),
	HX_CSTRING("pop"),
	HX_CSTRING("push"),
	HX_CSTRING("stackDump"),
	HX_CSTRING("traceStackDump"),
	HX_CSTRING("panic"),
	HX_CSTRING("recover"),
	HX_CSTRING("panicFromHaxe"),
	HX_CSTRING("bbi"),
	HX_CSTRING("ioor"),
	HX_CSTRING("NumGoroutine"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Scheduler_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Scheduler_obj::doneInit,"doneInit");
	HX_MARK_MEMBER_NAME(Scheduler_obj::grStacks,"grStacks");
	HX_MARK_MEMBER_NAME(Scheduler_obj::grInPanic,"grInPanic");
	HX_MARK_MEMBER_NAME(Scheduler_obj::grPanicMsg,"grPanicMsg");
	HX_MARK_MEMBER_NAME(Scheduler_obj::panicStackDump,"panicStackDump");
	HX_MARK_MEMBER_NAME(Scheduler_obj::entryCount,"entryCount");
	HX_MARK_MEMBER_NAME(Scheduler_obj::currentGR,"currentGR");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Scheduler_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Scheduler_obj::doneInit,"doneInit");
	HX_VISIT_MEMBER_NAME(Scheduler_obj::grStacks,"grStacks");
	HX_VISIT_MEMBER_NAME(Scheduler_obj::grInPanic,"grInPanic");
	HX_VISIT_MEMBER_NAME(Scheduler_obj::grPanicMsg,"grPanicMsg");
	HX_VISIT_MEMBER_NAME(Scheduler_obj::panicStackDump,"panicStackDump");
	HX_VISIT_MEMBER_NAME(Scheduler_obj::entryCount,"entryCount");
	HX_VISIT_MEMBER_NAME(Scheduler_obj::currentGR,"currentGR");
};

Class Scheduler_obj::__mClass;

void Scheduler_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Scheduler"), hx::TCanCast< Scheduler_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Scheduler_obj::__boot()
{
	doneInit= false;
	grStacks= Array_obj< ::Dynamic >::__new();
	grInPanic= Array_obj< bool >::__new();
	grPanicMsg= Array_obj< ::Dynamic >::__new();
	panicStackDump= HX_CSTRING("");
	entryCount= (int)0;
	currentGR= (int)0;
}

} // end namespace tardis
