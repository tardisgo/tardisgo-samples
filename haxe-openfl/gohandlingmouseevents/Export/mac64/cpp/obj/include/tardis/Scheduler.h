#ifndef INCLUDED_tardis_Scheduler
#define INCLUDED_tardis_Scheduler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS1(tardis,Interface)
HX_DECLARE_CLASS1(tardis,Scheduler)
HX_DECLARE_CLASS1(tardis,StackFrame)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Scheduler_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Scheduler_obj OBJ_;
		Scheduler_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Scheduler_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Scheduler_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Scheduler"); }

		static bool doneInit;
		static Array< ::Dynamic > grStacks;
		static Array< bool > grInPanic;
		static Array< ::Dynamic > grPanicMsg;
		static ::String panicStackDump;
		static int entryCount;
		static int currentGR;
		static Void timerEventHandler( Dynamic dummy);
		static Dynamic timerEventHandler_dyn();

		static Void runAll( );
		static Dynamic runAll_dyn();

		static Void runOne( int gr,int entryCount);
		static Dynamic runOne_dyn();

		static Void run1( int gr);
		static Dynamic run1_dyn();

		static int makeGoroutine( );
		static Dynamic makeGoroutine_dyn();

		static ::tardis::StackFrame pop( int gr);
		static Dynamic pop_dyn();

		static Void push( int gr,::tardis::StackFrame sf);
		static Dynamic push_dyn();

		static ::String stackDump( );
		static Dynamic stackDump_dyn();

		static Void traceStackDump( );
		static Dynamic traceStackDump_dyn();

		static Void panic( int gr,::tardis::Interface err);
		static Dynamic panic_dyn();

		static ::tardis::Interface recover( int gr);
		static Dynamic recover_dyn();

		static Void panicFromHaxe( ::String err);
		static Dynamic panicFromHaxe_dyn();

		static Void bbi( );
		static Dynamic bbi_dyn();

		static Void ioor( );
		static Dynamic ioor_dyn();

		static int NumGoroutine( );
		static Dynamic NumGoroutine_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Scheduler */ 
