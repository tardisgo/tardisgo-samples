#ifndef INCLUDED_tardis_Go_haxegoruntime_RunesToUTF8
#define INCLUDED_tardis_Go_haxegoruntime_RunesToUTF8

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_haxegoruntime_RunesToUTF8)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_haxegoruntime_RunesToUTF8_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_haxegoruntime_RunesToUTF8_obj OBJ_;
		Go_haxegoruntime_RunesToUTF8_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_r);

	public:
		static hx::ObjectPtr< Go_haxegoruntime_RunesToUTF8_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_r);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_haxegoruntime_RunesToUTF8_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_haxegoruntime_RunesToUTF8_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_haxegoruntime_RunesToUTF8"); }

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
		::tardis::Slice _t13;
		::tardis::StackFrame _SF2;
		int _t11;
		::tardis::Pointer _t10;
		::tardis::Slice _t9;
		int _t8;
		::tardis::StackFrame _SF1;
		int _t7;
		::tardis::Pointer _t6;
		bool _t5;
		int _t4;
		int _t3;
		::tardis::Slice _t2;
		int _t1;
		::tardis::Slice _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::tardis::Slice _res;
		::tardis::Slice p_r;
		static ::tardis::Slice callFromHaxe( ::tardis::Slice p_r);
		static Dynamic callFromHaxe_dyn();

		static ::tardis::Slice callFromRT( int _gr,::tardis::Slice p_r);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_haxegoruntime_RunesToUTF8 call( int gr,Dynamic _bds,::tardis::Slice p_r);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_haxegoruntime_RunesToUTF8 */ 
