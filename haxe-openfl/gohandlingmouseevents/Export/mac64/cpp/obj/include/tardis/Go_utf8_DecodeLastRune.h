#ifndef INCLUDED_tardis_Go_utf8_DecodeLastRune
#define INCLUDED_tardis_Go_utf8_DecodeLastRune

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_DecodeLastRune)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_DecodeLastRune_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_DecodeLastRune_obj OBJ_;
		Go_utf8_DecodeLastRune_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_p);

	public:
		static hx::ObjectPtr< Go_utf8_DecodeLastRune_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_DecodeLastRune_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_DecodeLastRune_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_DecodeLastRune"); }

		virtual Void SubFn12( );
		Dynamic SubFn12_dyn();

		virtual Void SubFn11( );
		Dynamic SubFn11_dyn();

		virtual Void SubFn10( );
		Dynamic SubFn10_dyn();

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
		bool _t24;
		int _t23;
		int _t22;
		int _t21;
		Dynamic _t20;
		::tardis::StackFrame _SF2;
		::tardis::Slice _t19;
		int _t18;
		int _t17;
		bool _t16;
		int _t15;
		bool _t14;
		bool _t13;
		::tardis::StackFrame _SF1;
		int _t12;
		::tardis::Pointer _t11;
		int _t10;
		int _t9;
		bool _t8;
		int _t7;
		bool _t6;
		int _t5;
		int _t4;
		::tardis::Pointer _t3;
		int _t2;
		bool _t1;
		int _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		Dynamic _res;
		::tardis::Slice p_p;
		static Dynamic callFromHaxe( ::tardis::Slice p_p);
		static Dynamic callFromHaxe_dyn();

		static Dynamic callFromRT( int _gr,::tardis::Slice p_p);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_DecodeLastRune call( int gr,Dynamic _bds,::tardis::Slice p_p);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_DecodeLastRune */ 
