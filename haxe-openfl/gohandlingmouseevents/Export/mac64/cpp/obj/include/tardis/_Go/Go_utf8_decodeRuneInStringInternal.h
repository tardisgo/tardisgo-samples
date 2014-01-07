#ifndef INCLUDED_tardis__Go_Go_utf8_decodeRuneInStringInternal
#define INCLUDED_tardis__Go_Go_utf8_decodeRuneInStringInternal

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
HX_DECLARE_CLASS2(tardis,_Go,Go_utf8_decodeRuneInStringInternal)
namespace tardis{
namespace _Go{


class HXCPP_CLASS_ATTRIBUTES  Go_utf8_decodeRuneInStringInternal_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf8_decodeRuneInStringInternal_obj OBJ_;
		Go_utf8_decodeRuneInStringInternal_obj();
		Void __construct(int gr,Dynamic _bds,::String p_s);

	public:
		static hx::ObjectPtr< Go_utf8_decodeRuneInStringInternal_obj > __new(int gr,Dynamic _bds,::String p_s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf8_decodeRuneInStringInternal_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf8_decodeRuneInStringInternal_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf8_decodeRuneInStringInternal"); }

		virtual Void SubFn21( );
		Dynamic SubFn21_dyn();

		virtual Void SubFn20( );
		Dynamic SubFn20_dyn();

		virtual Void SubFn19( );
		Dynamic SubFn19_dyn();

		virtual Void SubFn18( );
		Dynamic SubFn18_dyn();

		virtual Void SubFn17( );
		Dynamic SubFn17_dyn();

		virtual Void SubFn16( );
		Dynamic SubFn16_dyn();

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
		bool _t56;
		bool _t55;
		int _t54;
		int _t53;
		int _t52;
		int _t51;
		int _t50;
		int _t49;
		int _t48;
		int _t47;
		int _t46;
		int _t45;
		int _t44;
		int _t43;
		int _t42;
		int _t41;
		bool _t40;
		bool _t39;
		bool _t38;
		int _t37;
		bool _t36;
		bool _t35;
		bool _t34;
		bool _t33;
		int _t32;
		int _t31;
		int _t30;
		int _t29;
		int _t28;
		int _t27;
		int _t26;
		int _t25;
		int _t24;
		int _t23;
		bool _t22;
		bool _t21;
		bool _t20;
		int _t19;
		bool _t18;
		bool _t17;
		int _t16;
		int _t15;
		int _t14;
		int _t13;
		int _t12;
		int _t11;
		bool _t10;
		bool _t9;
		bool _t8;
		int _t7;
		bool _t6;
		bool _t5;
		int _t4;
		bool _t3;
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

		static ::tardis::_Go::Go_utf8_decodeRuneInStringInternal call( int gr,Dynamic _bds,::String p_s);
		static Dynamic call_dyn();

};

} // end namespace tardis
} // end namespace _Go

#endif /* INCLUDED_tardis__Go_Go_utf8_decodeRuneInStringInternal */ 
