#ifndef INCLUDED_tardis__Go_Go_main_handleMouse
#define INCLUDED_tardis__Go_Go_main_handleMouse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Channel)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
HX_DECLARE_CLASS2(tardis,_Go,Go_main_handleMouse)
namespace tardis{
namespace _Go{


class HXCPP_CLASS_ATTRIBUTES  Go_main_handleMouse_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_main_handleMouse_obj OBJ_;
		Go_main_handleMouse_obj();
		Void __construct(int gr,Dynamic _bds);

	public:
		static hx::ObjectPtr< Go_main_handleMouse_obj > __new(int gr,Dynamic _bds);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_main_handleMouse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_main_handleMouse_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_main_handleMouse"); }

		virtual Void SubFn9( );
		Dynamic SubFn9_dyn();

		virtual Void SubFn8( );
		Dynamic SubFn8_dyn();

		virtual Void SubFn7( );
		Dynamic SubFn7_dyn();

		virtual Void SubFn6( );
		Dynamic SubFn6_dyn();

		virtual Void SubFn5( );
		Dynamic SubFn5_dyn();

		virtual Void SubFn4( );
		Dynamic SubFn4_dyn();

		virtual Void SubFn3( );
		Dynamic SubFn3_dyn();

		virtual Void SubFn2( );
		Dynamic SubFn2_dyn();

		virtual Void SubFn1( );
		Dynamic SubFn1_dyn();

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		int _Phi;
		bool _t10;
		bool _t7;
		bool _t6;
		int _t5;
		::tardis::Channel _t4;
		bool _t2;
		int _t1;
		::tardis::Channel _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		static Void callFromHaxe( );
		static Dynamic callFromHaxe_dyn();

		static Void callFromRT( int _gr);
		static Dynamic callFromRT_dyn();

		static ::tardis::_Go::Go_main_handleMouse call( int gr,Dynamic _bds);
		static Dynamic call_dyn();

};

} // end namespace tardis
} // end namespace _Go

#endif /* INCLUDED_tardis__Go_Go_main_handleMouse */ 
