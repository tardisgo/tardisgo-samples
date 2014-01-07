#ifndef INCLUDED_tardis_Go_utf16_Encode
#define INCLUDED_tardis_Go_utf16_Encode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf16_Encode)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf16_Encode_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf16_Encode_obj OBJ_;
		Go_utf16_Encode_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_s);

	public:
		static hx::ObjectPtr< Go_utf16_Encode_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf16_Encode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf16_Encode_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf16_Encode"); }

		virtual Void SubFn15( );
		Dynamic SubFn15_dyn();

		virtual Void SubFn14( );
		Dynamic SubFn14_dyn();

		virtual Void SubFn13( );
		Dynamic SubFn13_dyn();

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
		int _t37;
		int _t36;
		::tardis::Pointer _t35;
		int _t34;
		int _t33;
		::tardis::Pointer _t32;
		int _t31;
		int _t30;
		Dynamic _t29;
		::tardis::StackFrame _SF1;
		bool _t28;
		bool _t27;
		bool _t26;
		bool _t25;
		bool _t24;
		int _t23;
		int _t22;
		::tardis::Pointer _t21;
		int _t20;
		::tardis::Slice _t19;
		bool _t18;
		int _t17;
		::tardis::Pointer _t16;
		bool _t15;
		int _t14;
		int _t13;
		int _t12;
		int _t11;
		int _t10;
		::tardis::Slice _t9;
		bool _t8;
		int _t7;
		::tardis::Pointer _t6;
		bool _t5;
		int _t4;
		int _t3;
		int _t2;
		int _t1;
		int _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		::tardis::Slice _res;
		::tardis::Slice p_s;
		static ::tardis::Slice callFromHaxe( ::tardis::Slice p_s);
		static Dynamic callFromHaxe_dyn();

		static ::tardis::Slice callFromRT( int _gr,::tardis::Slice p_s);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf16_Encode call( int gr,Dynamic _bds,::tardis::Slice p_s);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf16_Encode */ 
