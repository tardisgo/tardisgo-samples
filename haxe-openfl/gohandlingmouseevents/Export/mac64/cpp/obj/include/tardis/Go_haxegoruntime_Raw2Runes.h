#ifndef INCLUDED_tardis_Go_haxegoruntime_Raw2Runes
#define INCLUDED_tardis_Go_haxegoruntime_Raw2Runes

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_haxegoruntime_Raw2Runes)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_Raw2Runes_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_Raw2Runes_obj OBJ_;
		Go_haxegoruntime_Raw2Runes_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_s);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_Raw2Runes_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_Raw2Runes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_Raw2Runes_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_Raw2Runes"); }

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
		::tardis::Slice _t27;
		::tardis::StackFrame _SF3;
		int _t26;
		int _t25;
		::tardis::Pointer _t24;
		::tardis::Pointer _t23;
		bool _t22;
		int _t21;
		int _t20;
		::tardis::Slice _t19;
		::tardis::Pointer _t18;
		::tardis::StackFrame _SF2;
		::tardis::Slice _t16;
		::tardis::StackFrame _SF1;
		int _t15;
		int _t14;
		::tardis::Pointer _t13;
		::tardis::Pointer _t12;
		bool _t11;
		int _t10;
		int _t9;
		bool _t8;
		int _t7;
		::tardis::Slice _t6;
		int _t5;
		int _t4;
		::tardis::Slice _t3;
		int _t2;
		bool _t1;
		int _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::tardis::Slice _res;
		::tardis::Slice p_s;
		static ::tardis::Slice callFromHaxe( ::tardis::Slice p_s);
		static Dynamic callFromHaxe_dyn();

		static ::tardis::Slice callFromRT( int _gr,::tardis::Slice p_s);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_haxegoruntime_Raw2Runes call( int gr,Dynamic _bds,::tardis::Slice p_s);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_haxegoruntime_Raw2Runes */ 
