#ifndef INCLUDED_tardis__Go_Go_haxegoruntime_init_36_1
#define INCLUDED_tardis__Go_Go_haxegoruntime_init_36_1

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
HX_DECLARE_CLASS2(tardis,_Go,Go_haxegoruntime_init_36_1)
namespace tardis{
namespace _Go{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_init_36_1_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_init_36_1_obj OBJ_;
		Go_haxegoruntime_init_36_1_obj();
		Void __construct(int gr,Dynamic _bds);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_init_36_1_obj > __new(int gr,Dynamic _bds);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_init_36_1_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_init_36_1_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_init_36_1"); }

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		int _t1;
		Dynamic _t0;
		::tardis::StackFrame _SF1;
		virtual Dynamic res( );
		Dynamic res_dyn();

		static Void callFromHaxe( );
		static Dynamic callFromHaxe_dyn();

		static Void callFromRT( int _gr);
		static Dynamic callFromRT_dyn();

		static ::tardis::_Go::Go_haxegoruntime_init_36_1 call( int gr,Dynamic _bds);
		static Dynamic call_dyn();

};

} // end namespace tardis
} // end namespace _Go

#endif /* INCLUDED_tardis__Go_Go_haxegoruntime_init_36_1 */ 
