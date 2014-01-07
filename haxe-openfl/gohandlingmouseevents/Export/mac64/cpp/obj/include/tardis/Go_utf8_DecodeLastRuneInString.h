#ifndef INCLUDED_tardis_Go_utf8_DecodeLastRuneInString
#define INCLUDED_tardis_Go_utf8_DecodeLastRuneInString

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_DecodeLastRuneInString)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_DecodeLastRuneInString_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_DecodeLastRuneInString_obj OBJ_;
		Go_utf8_DecodeLastRuneInString_obj();
		Void __construct(int gr,Dynamic _bds,::String p_s);

	public:
		static hx::ObjectPtr< Go_utf8_DecodeLastRuneInString_obj > __new(int gr,Dynamic _bds,::String p_s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_DecodeLastRuneInString_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_DecodeLastRuneInString_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_DecodeLastRuneInString"); }

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
		bool _t22;
		int _t21;
		int _t20;
		int _t19;
		Dynamic _t18;
		::tardis::StackFrame _SF2;
		::String _t17;
		int _t16;
		int _t15;
		bool _t14;
		int _t13;
		bool _t12;
		bool _t11;
		::tardis::StackFrame _SF1;
		int _t10;
		int _t9;
		int _t8;
		bool _t7;
		int _t6;
		bool _t5;
		int _t4;
		int _t3;
		int _t2;
		bool _t1;
		int _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		Dynamic _res;
		::String p_s;
		static Dynamic callFromHaxe( ::String p_s);
		static Dynamic callFromHaxe_dyn();

		static Dynamic callFromRT( int _gr,::String p_s);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_DecodeLastRuneInString call( int gr,Dynamic _bds,::String p_s);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_DecodeLastRuneInString */ 
