#ifndef INCLUDED_tardis_Go_haxegoruntime_StringCompare
#define INCLUDED_tardis_Go_haxegoruntime_StringCompare

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_haxegoruntime_StringCompare)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_StringCompare_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_StringCompare_obj OBJ_;
		Go_haxegoruntime_StringCompare_obj();
		Void __construct(int gr,Dynamic _bds,::String p_a,::String p_b);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_StringCompare_obj > __new(int gr,Dynamic _bds,::String p_a,::String p_b);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_StringCompare_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_StringCompare_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_StringCompare"); }

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
		bool _t23;
		int _t22;
		int _t21;
		int _t20;
		bool _t19;
		int _t18;
		::tardis::Pointer _t17;
		int _t16;
		::tardis::Pointer _t15;
		bool _t14;
		int _t13;
		bool _t12;
		int _t11;
		int _t10;
		bool _t9;
		int _t8;
		int _t7;
		bool _t6;
		int _t5;
		::tardis::Pointer _t4;
		int _t3;
		::tardis::Pointer _t2;
		::tardis::Slice _t1;
		::tardis::Slice _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		int _res;
		::String p_b;
		::String p_a;
		static int callFromHaxe( ::String p_a,::String p_b);
		static Dynamic callFromHaxe_dyn();

		static int callFromRT( int _gr,::String p_a,::String p_b);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_haxegoruntime_StringCompare call( int gr,Dynamic _bds,::String p_a,::String p_b);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_haxegoruntime_StringCompare */ 
