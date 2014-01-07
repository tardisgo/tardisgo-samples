#ifndef INCLUDED_tardis_Go_utf8_EncodeRune
#define INCLUDED_tardis_Go_utf8_EncodeRune

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf8_EncodeRune)
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_EncodeRune_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_EncodeRune_obj OBJ_;
		Go_utf8_EncodeRune_obj();
		Void __construct(int gr,Dynamic _bds,::tardis::Slice p_p,int p_r);

	public:
		static hx::ObjectPtr< Go_utf8_EncodeRune_obj > __new(int gr,Dynamic _bds,::tardis::Slice p_p,int p_r);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_EncodeRune_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_EncodeRune_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_EncodeRune"); }

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
		int _t52;
		int _t51;
		int _t50;
		::tardis::Pointer _t49;
		int _t48;
		int _t47;
		int _t46;
		int _t45;
		::tardis::Pointer _t44;
		int _t43;
		int _t42;
		int _t41;
		int _t40;
		::tardis::Pointer _t39;
		int _t38;
		int _t37;
		int _t36;
		::tardis::Pointer _t35;
		int _t34;
		int _t33;
		int _t32;
		::tardis::Pointer _t31;
		int _t30;
		int _t29;
		int _t28;
		int _t27;
		::tardis::Pointer _t26;
		int _t25;
		int _t24;
		int _t23;
		::tardis::Pointer _t22;
		bool _t21;
		bool _t20;
		int _t19;
		int _t18;
		bool _t17;
		int _t16;
		bool _t15;
		int _t14;
		int _t13;
		int _t12;
		int _t11;
		::tardis::Pointer _t10;
		int _t9;
		int _t8;
		int _t7;
		::tardis::Pointer _t6;
		bool _t5;
		int _t4;
		int _t3;
		::tardis::Pointer _t2;
		bool _t1;
		int _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		int _res;
		int p_r;
		::tardis::Slice p_p;
		static int callFromHaxe( ::tardis::Slice p_p,int p_r);
		static Dynamic callFromHaxe_dyn();

		static int callFromRT( int _gr,::tardis::Slice p_p,int p_r);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf8_EncodeRune call( int gr,Dynamic _bds,::tardis::Slice p_p,int p_r);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf8_EncodeRune */ 
