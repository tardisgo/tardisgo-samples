#ifndef INCLUDED_tardis_Go_haxegoruntime_UTF8toRunes
#define INCLUDED_tardis_Go_haxegoruntime_UTF8toRunes

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_haxegoruntime_UTF8toRunes)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_UTF8toRunes_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_UTF8toRunes_obj OBJ_;
		Go_haxegoruntime_UTF8toRunes_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_s);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_UTF8toRunes_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_UTF8toRunes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_UTF8toRunes_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_UTF8toRunes"); }

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
		bool _t25;
		int _t24;
		int _t23;
		int _t22;
		int _t21;
		int _t20;
		::tardis::Pointer _t19;
		int _t18;
		int _t17;
		Dynamic _t16;
		::tardis::StackFrame _SF2;
		int _t15;
		int _t14;
		::tardis::Pointer _t13;
		int _t12;
		::tardis::Pointer _t11;
		bool _t10;
		int _t9;
		bool _t8;
		int _t7;
		int _t6;
		int _t5;
		::tardis::Slice _t4;
		int _t3;
		int _t2;
		::tardis::Slice _t1;
		int _t0;
		::tardis::StackFrame _SF1;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::tardis::Slice _res;
		::tardis::Slice p_s;
		static ::tardis::Slice callFromHaxe( ::tardis::Slice p_s);
		static Dynamic callFromHaxe_dyn();

		static ::tardis::Slice callFromRT( int _gr,::tardis::Slice p_s);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_haxegoruntime_UTF8toRunes call( int gr,Dynamic _bds,::tardis::Slice p_s);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_haxegoruntime_UTF8toRunes */ 
